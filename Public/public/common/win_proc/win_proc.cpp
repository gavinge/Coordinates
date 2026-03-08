
/*
* 文件名:  win_proc.cpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CWinProc类实现，Windows平台下常用进程操作
*/

#include "../log/log.h"
#include "win_proc.h"
#include <Tlhelp32.h>
#include <Psapi.h>
#include <tchar.h>

#pragma comment (lib,"psapi")

#pragma warning(disable:4996)

namespace JwUtility
{
	int CWinProc::get_all_proc_pids( ProcPidFun pid_deal, void *param)
	{
		int  rt = EC_SUCCESS;					//返回值
		HANDLE hSnapShot = INVALID_HANDLE_VALUE;//进程快照句柄

		//提升进程操作权限
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("进程提权失败"));
			return EC_SETPRIVILEGE_ERROR;
		}

		do 
		{
			//参数检查
			if( NULL == pid_deal )
			{
				LOG_ERROR(("参数错误, pid_deal[0x00]"));	
				rt = EC_PARAM_ERROR;
				break;
			}
			//创建进程快照
			hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapShot == INVALID_HANDLE_VALUE)
			{
				LOG_ERROR(("创建进程快照失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_CREATETOOL_ERROR;
				break;
			}

			//枚举进程列表
			PROCESSENTRY32 procentry;
			procentry.dwSize = sizeof(PROCESSENTRY32);
			BOOL bFlag = Process32First(hSnapShot, &procentry);
			DWORD iPid = 0;
			while (bFlag) 
			{
				iPid = procentry.th32ProcessID;
				if(  0 != pid_deal( param, iPid) )
				{
					LOG_ERROR(("处理回调函数失败"));	
					rt = EC_DEAL_CALLBACK_FUN_ERROR;
					break;
				}

				procentry.dwSize = sizeof(PROCESSENTRY32);
				bFlag = Process32Next(hSnapShot, &procentry);
			}

			if( EC_SUCCESS != rt )
			{
				break;		
			}

		} while (false);

		//关闭句柄
		if (INVALID_HANDLE_VALUE != hSnapShot )
		{
			CloseHandle(hSnapShot);
		}

		//权限恢复
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE) )
		{
			rt = EC_SETPRIVILEGE_ERROR;
		}
		return rt;
	}

	int CWinProc::get_all_proc_data( ProcDataFun proc_data_deal, void *param)
	{
		int  rt = EC_SUCCESS;					//返回值
		HANDLE hSnapShot = INVALID_HANDLE_VALUE;//进程快照句柄

		//提升进程操作权限
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("提升进程操作权限失败"));
			return EC_SETPRIVILEGE_ERROR;
		}

		do 
		{
			//参数检查
			if( NULL == proc_data_deal )
			{
				LOG_ERROR(("参数错误proc_data_deal[0x00]"));	
				rt = EC_PARAM_ERROR;
				break;
			}

			//创建进程快照
			PROCESSENTRY32 procentry;
			hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapShot == INVALID_HANDLE_VALUE)
			{
				LOG_ERROR(("调用创建进程快照API失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_CREATETOOL_ERROR;
				break;
			}

			//枚举快照进程信息
			procentry.dwSize = sizeof(PROCESSENTRY32);
			BOOL bFlag = Process32First(hSnapShot, &procentry);
			WIN_PROC_DATA sys;
			while (bFlag) 
			{
				//获得进程ID
				sys.p_pid = procentry.th32ProcessID;

				//获得进程的执行文件
				sys.p_strPname = procentry.szExeFile;

				//获取进程占用内存大小
				sys.p_memsize = 0;
				int nrt = GetMemStat(sys.p_pid, sys.p_memsize);
				if ( EC_SUCCESS != nrt) 
				{
					sys.p_memsize = 0;
				}

				//获取进程所属用户
				std::string struname;
				nrt = GetProcUser(sys.p_pid, struname);
				if ( EC_SUCCESS != nrt) 
				{
					if ( sys.p_pid ==0 || sys.p_pid == 4 || sys.p_pid == 8 )
					{
						sys.p_strUname = "SYSTEM";
					}
					else
					{
						sys.p_strUname = "";
					}
				}
				else
				{
					sys.p_strUname = struname;
				}

				//获取进程启动时间
				std::string strtime;
				nrt = GetProcStartTime(sys.p_pid, strtime);
				if ( EC_SUCCESS != nrt) 
				{
					sys.p_strStime = "";
				}
				else
				{
					sys.p_strStime = strtime;
				}

				//获取进程执行路径
				std::string strpath;
				nrt = get_proc_path(sys.p_pid, strpath);
				if ( EC_SUCCESS != nrt) 
				{
					sys.p_strCmdline = "";
				}
				else
				{
					sys.p_strCmdline = strpath;
				}

				if( 0 != proc_data_deal( param, sys ) )
				{
					LOG_ERROR(("处理回调函数失败"));	
					rt = EC_DEAL_CALLBACK_FUN_ERROR;
					break;
				}

				procentry.dwSize = sizeof(PROCESSENTRY32);
				bFlag = Process32Next(hSnapShot, &procentry);
			}

			if( EC_SUCCESS != rt )
			{
				break;		
			}

		} while (false);

		//无效句柄
		if ( INVALID_HANDLE_VALUE != hSnapShot )
		{
			CloseHandle(hSnapShot);
		}

		//权限恢复
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE) )
		{
			LOG_ERROR(("进程操作权限恢复失败"));
			rt = EC_SETPRIVILEGE_ERROR;
		}
		return rt;
	}

	int CWinProc::get_proc_data(DWORD pid, WIN_PROC_DATA &data)
	{
		int  rt = EC_SUCCESS;					//返回值
		HANDLE hSnapShot = INVALID_HANDLE_VALUE;//快照进程句柄

		//提权
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("提升进程操作权限失败"));
			return EC_SETPRIVILEGE_ERROR;
		}

		do 
		{
			//创建进程快照
			PROCESSENTRY32 procentry;
			hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hSnapShot == INVALID_HANDLE_VALUE)
			{
				LOG_ERROR(("调用创建进程快照API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_CREATETOOL_ERROR;
				break;
			}

			//枚举指定
			procentry.dwSize = sizeof(PROCESSENTRY32);
			BOOL bFlag = Process32First(hSnapShot, &procentry);
			bool bfind =false;	//查找标志位
			while (bFlag) 
			{
				if (procentry.th32ProcessID != pid)
				{
					bFlag = Process32Next(hSnapShot, &procentry);
					continue;
				}

				//查找到指定的进程
				bfind = true;	
				data.p_pid = pid;
				data.p_memsize = 0;
				data.p_strPname = procentry.szExeFile;

				//获取进程占用内存大小
				int nrt = GetMemStat(pid,data.p_memsize);
				if ( EC_SUCCESS != nrt) 
				{
					data.p_memsize = 0;
				}
				//获取进程所属用户
				std::string struname;
				nrt = GetProcUser(pid, struname);
				if ( EC_SUCCESS != nrt) 
				{
					if ( pid ==0 || pid == 4 || pid == 8 )
					{
						data.p_strUname = "SYSTEM";
					}
					else
					{
						data.p_strUname = "";
					}
				}
				else
				{
					data.p_strUname = struname;
				}

				//获取进程启动时间
				std::string strtime;
				nrt = GetProcStartTime(pid, strtime);
				if ( EC_SUCCESS != nrt) 
				{
					data.p_strStime = "";
				}
				else
				{
					data.p_strStime = strtime;
				}

				//获取进程执行路径
				std::string strpath;
				nrt = get_proc_path(pid, strpath);
				if ( EC_SUCCESS != nrt) 
				{
					data.p_strCmdline = "";
				}
				else
				{
					data.p_strCmdline = strpath;
				}
				break;
			}
			if (!bfind)
			{
				LOG_ERROR(("未找到指定PID的进程, PID[%d]", ::GetLastError()));
				rt = EC_NO_EXIST_PID_ERROR;
				break;
			}
		} while (false);

		//关闭句柄
		if ( INVALID_HANDLE_VALUE != hSnapShot )
		{
			CloseHandle(hSnapShot);
		}

		//权限恢复
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE) )
		{
			LOG_ERROR(("进程权限恢复失败"));
			rt = EC_SETPRIVILEGE_ERROR;
		}
		return rt;
	}

	int CWinProc::create_proc(const std::string &path, const std::string &args, const std::string &cwd, bool is_show_ui/* = true*/)
	{

		//参数检查
		if( path.empty() )
		{
			LOG_ERROR(("参数错误, path[]"));		
			return EC_PARAM_ERROR;
		}
		
		int  rt = EC_SUCCESS;			//返回值

		//初始化进程信息结构
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory( &si, sizeof(si) );
		si.cb = sizeof(si);
		if (!is_show_ui)
		{
			si.dwFlags = STARTF_USESHOWWINDOW;
			si.wShowWindow = SW_HIDE;
		}

		ZeroMemory( &pi, sizeof(pi) );

		std::string strComdLine = "\"" + path + "\" " + args;
		BOOL result = FALSE;
		if (cwd.empty())
		{
			result = CreateProcess(NULL, (char *)strComdLine.c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &si,&pi);
		}
		else
		{
			result = CreateProcess(NULL, (char *)strComdLine.c_str(), NULL, NULL, FALSE, NULL, NULL, (char *)cwd.c_str(), &si,&pi);
		}
		if ( !result )
		{
			LOG_ERROR(("创建新的进程失败, 进程命令行[%s], windows系统错误码[%d]", strComdLine.c_str(), ::GetLastError()));
			rt = EC_CREATE_PROCESS_ERROR;
		}
		else
		{
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
		}
		return rt;
	}
	

	int CWinProc::create_proc_wait_exit(const std::string &path, const std::string &args, const std::string &cwd, bool is_show_ui/* = true*/)
	{
		//参数检查
		if( path.empty() )
		{
			LOG_ERROR(("参数错误, path[]"));		
			return -1;
		}

		int  rt = EC_SUCCESS;			//返回值

		//初始化进程信息结构
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory( &si, sizeof(si) );
		si.cb = sizeof(si);
		if (!is_show_ui)
		{
			si.dwFlags = STARTF_USESHOWWINDOW;
			si.wShowWindow = SW_HIDE;
		}

		ZeroMemory( &pi, sizeof(pi) );

		std::string strComdLine = "\"" + path + "\" " + args;
		BOOL result = FALSE;
		if (cwd.empty())
		{
			result = CreateProcess(NULL, (char *)strComdLine.c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &si,&pi);
		}
		else
		{
			result = CreateProcess(NULL, (char *)strComdLine.c_str(), NULL, NULL, FALSE, NULL, NULL, (char *)cwd.c_str(), &si,&pi);
		}
		if ( !result )
		{
			LOG_ERROR(("创建新的进程失败, 进程命令行[%s], windows系统错误码[%d]", strComdLine.c_str(), ::GetLastError()));
			rt = -1;
		}
		else
		{
			WaitForSingleObject(pi.hThread, INFINITE);

			DWORD ret_proc = 0;
			GetExitCodeProcess(pi.hProcess, &ret_proc);

			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);

			rt = ret_proc;
		}

		return rt;
	}


	int CWinProc::kill_proc(DWORD pid)
	{
		int  rt = EC_SUCCESS;				//返回值
		HANDLE hProcess = NULL;				//打开进程的进程句柄 

		//提权
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("提升进程操作权限失败"));
			return  EC_SETPRIVILEGE_ERROR;
		}

		do 
		{
			//打开进程
			hProcess = OpenProcess(  PROCESS_TERMINATE | PROCESS_QUERY_INFORMATION ,FALSE, pid );
			if ( hProcess == NULL )
			{
				LOG_ERROR(("打开进程失败,PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt = EC_OPEN_PROCESS_ERROR;
				break;
			}

			//结束进程
			if ( !TerminateProcess(hProcess, /*STILL_ACTIVE*/0) )
			{
				LOG_ERROR(("结束进程失败,PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt = EC_TERMINATE_PROCESS_ERROR;
				break;
			}

		} while (false);

		//关闭句柄
		if (hProcess != NULL)
		{
			CloseHandle(hProcess);
		}

		//恢复权限
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE) )
		{
			rt = EC_SETPRIVILEGE_ERROR;
		}
		return rt;
	}


	int CWinProc::GetMemStat( DWORD pid, DWORD& mem_size )
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打开的进程句柄 

		do 
		{
			//打开进程
			hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |	PROCESS_VM_READ,
									FALSE,
									pid );
			if (NULL == hProcess)
			{
				LOG_ERROR(("打开进程失败,PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt = EC_OPEN_PROCESS_ERROR;
				break;
			}

			//获得进程占用的内存大小
			PROCESS_MEMORY_COUNTERS pmc;
			memset(&pmc, 0, sizeof(PROCESS_MEMORY_COUNTERS));
			if ( GetProcessMemoryInfo( hProcess, &pmc, sizeof(pmc)) )
			{
				mem_size = pmc.WorkingSetSize ;
				mem_size = mem_size / SIZE_1K;
			}
			else
			{
				LOG_ERROR(("获得进程内存信息失败,PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt = EC_GET_PROCESS_MEM_ERROR;
				break;
			}	
		} while (false);

		if (hProcess != NULL)
		{
			CloseHandle(hProcess);
		}
		return rt;
	}

	int CWinProc::GetProcUser( DWORD pid, std::string& user_name )
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打进程的进程句柄
		HANDLE hAccessToken = NULL;		//进程访问标记句柄
		char *Buf = NULL;
		char *szAccountName = NULL;
		char *szDomainName = NULL;
		do 
		{
			//打开进程
			hProcess = OpenProcess(  PROCESS_QUERY_INFORMATION, FALSE, pid );

			if ( hProcess == NULL )
			{
				LOG_ERROR(("打开进程失败,PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt  = EC_OPEN_PROCESS_ERROR;
				break;
			}

			//打开进程标记
			if ( OpenProcessToken(hProcess, TOKEN_READ, &hAccessToken) == FALSE)
			{
				LOG_ERROR(("调用打开进程失败,PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt = EC_OPEN_PROCESS_TOKEN_ERROR;
				break;
			}

			Buf = new(std::nothrow) char [Buf1024 + 1];
			if (Buf == NULL)
			{
				LOG_ERROR(("申请内存失败, Buf[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(Buf, 0, Buf1024 + 1);

			DWORD dwNumBytesRet = 0;
			GetTokenInformation(hAccessToken, TokenUser, Buf, Buf1024,   &dwNumBytesRet); 

			TOKEN_USER* pUser = (TOKEN_USER*)(Buf);

			DWORD dwAccountSize = Buf512;
			DWORD dwDomainSize = Buf512;
			szAccountName = new(std::nothrow) char [Buf512 + 1];
			if (szAccountName == NULL)
			{
				LOG_ERROR(("申请内存失败, szAccountName[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(szAccountName, 0, Buf512 + 1);

			szDomainName = new(std::nothrow) char [Buf512 + 1];
			if (szDomainName == NULL)
			{
				LOG_ERROR(("申请内存失败, szDomainName[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(szDomainName, 0, Buf512 + 1);

			//通过SID获取进程用户名
			SID_NAME_USE snu;
			if ( LookupAccountSid(NULL, pUser->User.Sid, szAccountName, &dwAccountSize,   
									szDomainName,  &dwDomainSize, &snu) )
			{
				user_name = szAccountName;
			}
			else
			{
				LOG_ERROR(("调用通过SID获得进程用户信息失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_LOOKUP_ACCOUNT_SID_ERROR;
				break;
			}

		} while (false);

		if (hAccessToken != NULL)
		{
			CloseHandle(hAccessToken);
		}
		if (hProcess != NULL)
		{
			CloseHandle(hProcess);
		}
		if (szAccountName != NULL)
		{
			delete[] szAccountName;
		}
		if (szDomainName != NULL)
		{
			delete[] szDomainName;
		}
		if (Buf != NULL)
		{
			delete[] Buf;
		}
		return rt;
	}


	BOOL CWinProc::SetPrivilege(HANDLE hProcess, LPCTSTR pName, BOOL bEnable)
	{
		BOOL              bResult = TRUE;			//返回值
		HANDLE            hToken;					//进程标记句柄
		TOKEN_PRIVILEGES  TokenPrivileges;			//权限标记
		DWORD dwRet;

		if (NULL == hProcess)
		{
			LOG_ERROR(("修改进程权限API失败，传入的进程句柄为NULL"));
			return FALSE;
		}

		if (NULL == pName)
		{
			LOG_ERROR(("修改进程权限API失败，传入的权限名为NULL"));
			return FALSE;
		}

		if(OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken) == 0)
		{
			dwRet = ::GetLastError();

			LOG_ERROR(("调用打开进程标记API失败，windows系统错误码[%d]", ::GetLastError()));
			return FALSE;
		}

		TokenPrivileges.PrivilegeCount     = 1;
		TokenPrivileges.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : SE_PRIVILEGE_USED_FOR_ACCESS;

		LUID luid;
		if (!LookupPrivilegeValue(NULL, pName, &luid))
		{
			dwRet = ::GetLastError();

			LOG_ERROR(("查询进程权限标记API失败，windows系统错误码[%d]", ::GetLastError()));
			return FALSE;		
		}

		TokenPrivileges.Privileges[0].Luid = luid;
		AdjustTokenPrivileges(hToken, FALSE,&TokenPrivileges, sizeof(TOKEN_PRIVILEGES), NULL, NULL);
		if( (dwRet = GetLastError()) != ERROR_SUCCESS)
		{
			LOG_ERROR(("调用权限修改API失败，windows系统错误码[%d]", ::GetLastError()));
			bResult = FALSE;
		}

		CloseHandle(hToken);

		return bResult;
	}

	int CWinProc::GetProcStartTime(DWORD pid, std::string& proc_time )
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打开的进程句柄
		char *buf = NULL;				//返回值

		do 
		{
			//打开进程
			hProcess = OpenProcess(  PROCESS_QUERY_INFORMATION,FALSE, pid );
		if(hProcess==NULL)hProcess = OpenProcess(  PROCESS_QUERY_LIMITED_INFORMATION,FALSE, pid );
			if ( hProcess == NULL )
			{
				LOG_ERROR(("打开进程失败, PID[%d], windows系统错误码[%d]", pid, ::GetLastError()));
				rt  = EC_OPEN_PROCESS_ERROR;
				break;
			}

			//获取进程时间
		FILETIME   lcreatetime,lexittime,lkerneltime,lusertime,lft;  
			if ( GetProcessTimes(hProcess,&lcreatetime,&lexittime,&lkerneltime,&lusertime)==FALSE )
			{
				LOG_ERROR(("获得进程时间失败,windows系统错误码[%d]", ::GetLastError()));
				rt = EC_GET_PROCESS_TIMES_ERROR;
				break;
			}
			FileTimeToLocalFileTime(&lcreatetime,&lft);
			SYSTEMTIME sysct;
			::FileTimeToSystemTime( &lft, &sysct);

			buf = new(std::nothrow) char[ TIME_FORMAT_LEN + 1];
			if ( NULL == buf)
			{
				LOG_ERROR(("申请内存失败, buf[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(buf, 0x00, TIME_FORMAT_LEN + 1);
			_snprintf(buf, TIME_FORMAT_LEN, TEXT("%04d-%02d-%02d %02d:%02d:%02d"), 
				sysct.wYear, sysct.wMonth, sysct.wDay,
				sysct.wHour, sysct.wMinute, sysct.wSecond);

			proc_time = buf; 

		} while (false);
		if(buf != NULL)
		{
			delete [] buf;
		}
		if (hProcess != NULL)
		{
			CloseHandle(hProcess);
		}	
		return rt;
	}

	BOOL CWinProc::GetProcCmdLine( DWORD pid, TCHAR* pCmdLine, DWORD dwBufLen )
	{
		HANDLE hProc = OpenProcess(PROCESS_VM_READ,FALSE,pid);
		if(hProc == NULL)
		{
			return FALSE;
		}

		DWORD dwRet = -1;
		DWORD dwAddr = *(DWORD*)((DWORD)GetCommandLine + 1);//第2个字节开始才是我们要读的地址
		//TCHAR tcBuf[512] = {0};
		TCHAR *tcBuf = new(std::nothrow) TCHAR [Buf512];
		if( NULL == tcBuf )
		{
			CloseHandle(hProc);
			return FALSE;
		}

		memset(tcBuf, 0, sizeof(TCHAR) * Buf512);
		SIZE_T dwRead = 0;

		//判断平台
		DWORD dwVer = GetVersion();
		try
		{
			if(dwVer < 0x80000000) // Windows NT/2000/XP
			{
				if(ReadProcessMemory(hProc,(LPVOID)dwAddr,&dwAddr,4,&dwRead))
				{
					if(ReadProcessMemory(hProc,(LPVOID)dwAddr,tcBuf,Buf512,&dwRead))
					{
						_tcsncpy(pCmdLine,tcBuf,dwBufLen); //最好检查一下dwRead和dwBufLen的大小，使用较小的那个
						dwRet = TRUE;
					}
				}
			}
			else // Windows 95/98/Me and Win32s
			{
				while(true) //使用while是为了出错时方便跳出循环
				{
					if(!ReadProcessMemory(hProc,(LPVOID)dwAddr,&dwAddr,4,&dwRead)) break;
					if(!ReadProcessMemory(hProc,(LPVOID)dwAddr,&dwAddr,4,&dwRead)) break;

					if(!ReadProcessMemory(hProc,(LPVOID)(dwAddr + 0xC0),tcBuf,Buf512,&dwRead)) break;
					if(*tcBuf == 0)
					{
						if(!ReadProcessMemory(hProc,(LPVOID)(dwAddr + 0x40),&dwAddr,4,&dwRead)) break;
						if(!ReadProcessMemory(hProc,(LPVOID)(dwAddr + 0x8),&dwAddr,4,&dwRead)) break;
						if(!ReadProcessMemory(hProc,(LPVOID)dwAddr,tcBuf,Buf512,&dwRead)) break;
					}
					_tcsncpy(pCmdLine,tcBuf,dwBufLen);  //最好检查一下dwRead和dwBufLen的大小，使用较小的那个
					dwRet = TRUE;
					break;
				}
			}
		}
		catch(...)
		{
			dwRet = FALSE; //exception
		}
		if( NULL != tcBuf )
		{
			delete[] tcBuf;
		}
		if( NULL != hProc )
		{
			CloseHandle(hProc);
		}
		return dwRet;

	}

	/////\\Device\对象转换到全路径名 包括网络mup路径 utc \\192.168.1.2\cc\xx.exe
	DWORD DosDevPathConvert(const char* ddp,char* path,int maxlen)
	{
		if(!path || maxlen<=0)return 0;
		const ULONGLONG header = *(ULONGLONG*)"\\Device\\";
		const ULONG mup = *(ULONG*)"Mup\\";


		if(header!=*(ULONGLONG*)ddp)
		{
			return _snprintf(path,maxlen,"%s",ddp);;
		}
		else if(mup==*(ULONG*)(ddp+8))
		{
			return _snprintf(path,maxlen,"\\\\%s",ddp+12);;
		}

		path[0] = 0;
		for(int i = 'A'; i<='Z'; i++)
		{
			char drv[4];
			drv[0] = (char)i;
			drv[1] = ':';
			drv[2] = 0;

			char tmp[MAX_PATH];

			if(QueryDosDevice(drv,tmp,MAX_PATH))
			{
				if(strncmp(ddp,tmp,strlen(tmp))==0)
				{
					return _snprintf(path,maxlen,"%s%s",drv,ddp+strlen(tmp));
				}
			}
		}
		
		return 0;
	}

	int CWinProc::get_proc_path( DWORD pid, std::string& procpath )
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打开的进程句柄
		char *pszModName = NULL;

		do	
		{
			pszModName = new(std::nothrow) char[MAX_PATH + 1];
			if ( NULL == pszModName )
			{
				LOG_ERROR(("申请内存失败, pszModName[0x00]"));
				rt = EC_NEW_MEM_ERROR;
				break;
			}
			memset(pszModName, 0, MAX_PATH + 1);


			HMODULE hMod;
			DWORD   cbNeededMod = 0;
			hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid );
			if (NULL == hProcess ) 
			{
				LOG_ERROR(("调用打开进程API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_OPEN_PROCESS_ERROR;
				break;
			}

			//获取进程路径失败
			DWORD dwMaxPath = MAX_PATH;
			if(GetProcessImageFileName(hProcess,pszModName,dwMaxPath))
			{
				CHAR	name[MAX_PATH];
				DosDevPathConvert(pszModName,name,MAX_PATH);

				procpath = transform_procpath(name);
			}
			else
			{
				LOG_ERROR(("调用获得模块路径API失败，windows系统错误码[%d]", ::GetLastError()));
				rt = EC_GET_MODULEFILE_NAMEEX_ERROR;
				break;
			}
	
		} while (false);
		
		if (pszModName != NULL)
		{
			delete[] pszModName;
		}
		if (hProcess != NULL)
		{
			CloseHandle( hProcess );
		}
		return rt;
	}
	

	std::string CWinProc::transform_procpath(std::string strpath)
	{
		std::string s_head(strpath);
		if (0 == strnicmp("\\??\\", strpath.c_str(), strlen("\\??\\")))
		{
			s_head.assign(strpath.c_str(), strlen("\\??\\"), s_head.size());
		}

		if (0 == strnicmp("\\SystemRoot", strpath.c_str(), strlen("\\SystemRoot")))
		{
			char szsysdir[MAX_PATH] = {0};
			GetWindowsDirectory(szsysdir,MAX_PATH);
			s_head.replace(s_head.begin(), s_head.begin() + strlen("\\SystemRoot"), szsysdir);
		}

		return s_head;
	}


	int CWinProc::set_proc_workset(IN DWORD pid)
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打开的进程句柄


		if (pid < 0)
		{
			LOG_ERROR(("参数错误, pid"));		
			return EC_PARAM_ERROR;
		}

		//先将本进程提升至DEBUG权限，否则有些进程无法打开
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("进程提升权限失败"));
			return EC_SETPRIVILEGE_ERROR;
		}

		do
		{
			//以设置内存配额的方式打开目标进程
			hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_SET_QUOTA, FALSE, pid);
			if (NULL == hProcess ) 
			{
				LOG_ERROR(("调用打开进程API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_OPEN_PROCESS_ERROR;
				break;
			}
 
			//降低进程内存使用率，将来有更好的方法
			//应重写此功能。
			//
			// 按照 MSDN 的解释，函数的后两个参数设置 "-1" 表示将进程的
		    // 内存交换到页面文件中去，这样做在资源管理器中可以看到进程
			// 内存减少，但实际上此种做法会引起“缺页中断”从而降低系统
			// 性能。
			//

			BOOL bRet = FALSE;
			bRet = SetProcessWorkingSetSize(hProcess, -1, -1);
			if(FALSE == bRet)
			{
				LOG_ERROR(("设置进程内存Working Set API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_SET_PROCESS_WORKSET_ERROR;
				break;			
			}

		}while (false);

		if (!SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE))
		{
			LOG_ERROR(("恢复进程权限失败"));
			rt = EC_SETPRIVILEGE_ERROR;
		}

		if (NULL != hProcess)
		{
			CloseHandle(hProcess);
		}

		return rt;
	}


	int CWinProc::set_proc_priority(IN DWORD pid, IN DWORD pri)
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打开的进程句柄

		if (pid < 0 || pri < 0)
		{
			LOG_ERROR(("参数错误, pid pri"));		
			return EC_PARAM_ERROR;
		}

		//先将本进程提升至DEBUG权限，否则有些进程无法打开
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("进程提升权限失败"));
			return EC_SETPRIVILEGE_ERROR;
		}

		do
		{
			hProcess = OpenProcess(PROCESS_SET_INFORMATION, FALSE, pid);
			if (NULL == hProcess ) 
			{
				LOG_ERROR(("调用打开进程API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_OPEN_PROCESS_ERROR;
				break;
			}

			// 设置进程优先级
			BOOL bRet = FALSE;
			bRet = SetPriorityClass(hProcess,  pri);
			if(FALSE == bRet)
			{
				LOG_ERROR(("设置进程优先级API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_SET_PROCESS_PRI_ERROR;
				break;			
			}

		}while (false);	

		if (!SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE))
		{
			LOG_ERROR(("恢复进程权限失败"));
			rt = EC_SETPRIVILEGE_ERROR;
		}

		if (NULL != hProcess)
		{
			CloseHandle(hProcess);
		}

		return rt;
	}
	

	int CWinProc::get_proc_priority(IN DWORD pid, OUT LPDWORD p_pri)
	{
		int  rt = EC_SUCCESS;			//返回值
		HANDLE hProcess = NULL;			//打开的进程句柄

		if (NULL == p_pri)
		{
			LOG_ERROR(("参数错误, pid pri"));		
			return EC_PARAM_ERROR;
		}

		//先将本进程提升至DEBUG权限，否则有些进程无法打开
		if ( !SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, TRUE) )
		{
			LOG_ERROR(("进程提升权限失败"));
			return EC_SETPRIVILEGE_ERROR;
		}

		do
		{
			hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
			if (NULL == hProcess ) 
			{
				LOG_ERROR(("调用打开进程API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_OPEN_PROCESS_ERROR;
				break;
			}

			// 获得进程优先级
			DWORD pri_tmp; 
			pri_tmp = GetPriorityClass(hProcess);
			if(0 == pri_tmp)
			{
				LOG_ERROR(("获得进程优先级API失败, windows系统错误码[%d]", ::GetLastError()));
				rt = EC_SET_PROCESS_PRI_ERROR;
				break;			
			}

			*p_pri = pri_tmp;

		}while (false);	

		if (!SetPrivilege(GetCurrentProcess(), SE_DEBUG_NAME, FALSE))
		{
			LOG_ERROR(("恢复进程权限失败"));
			rt = EC_SETPRIVILEGE_ERROR;
		}

		if (NULL != hProcess)
		{
			CloseHandle(hProcess);
		}

		return rt;
	}
}

