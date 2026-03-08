/*
* 文件名:  win_proc.h
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: CWinProc 头文件，Windows平台下常用进程操作
*/

#ifndef __UTILITY_PROC_H__
#define	__UTILITY_PROC_H__
#include <windows.h>
#include <string>
#include <vector>

#pragma warning(disable:4996)

namespace JwUtility
{
	class  CWinProc
	{
	public:

		/**
		* @brief	返回的错误码
		*/
		enum	EC
		{
			EC_SUCCESS = 0,					/*成功返回*/
			EC_PARAM_ERROR,					/*参数错误*/
			EC_SETPRIVILEGE_ERROR,			/*设置进程权限失败*/
			EC_CREATETOOL_ERROR,			/*创建进程快照失败*/
			EC_CREATE_PROCESS_ERROR,		/*创建进程失败*/
			EC_OPEN_PROCESS_ERROR,			/*打开进程失败*/
			EC_TERMINATE_PROCESS_ERROR,		/*结束进程失败*/
			EC_GET_PROCESS_MEM_ERROR,		/*获取进程内存失败*/
			EC_OPEN_PROCESS_TOKEN_ERROR,	/*打开进程标记失败*/
			EC_SET_PROCESS_WORKSET_ERROR,   /*设置进程工作集失败*/
			EC_SET_PROCESS_PRI_ERROR,		/*设置进程优先级*/
			EC_NEW_MEM_ERROR,				/*申请内存失败*/
			EC_LOOKUP_ACCOUNT_SID_ERROR,	/*通过SID获取进程用户名失败*/
			EC_GET_PROCESS_TIMES_ERROR,		/*获取进程时间失败*/
			EC_GET_MODULEFILE_NAMEEX_ERROR,	/*获取进程路径失败*/
			EC_NO_EXIST_PID_ERROR,			/*不存在的PID*/
			EC_DEAL_CALLBACK_FUN_ERROR		/*回调函数调用失败*/
		};

		//结构体WIN_PROC_DATA的定义
		struct WIN_PROC_DATA
		{
			DWORD p_pid;					/*进程ID*/
			DWORD p_memsize;				/*占用内存*/
			std::string p_strPname;			/*进程名*/
			std::string p_strUname;			/*用户名*/
			std::string p_strCmdline;		/*进程命令行*/
			std::string p_strStime;			/*进程启动时间*/

			bool operator<(JwUtility::CWinProc::WIN_PROC_DATA  &b) const{
				return p_strCmdline < b.p_strCmdline;
			}

			bool operator==(JwUtility::CWinProc::WIN_PROC_DATA  &b) const{
				return 0 == stricmp(p_strCmdline.c_str(), b.p_strCmdline.c_str());
			}
		};


		enum 
		{
			Buf256 = 256,					/*256常量缓冲区*/
			Buf512 = 512,					/*512常量缓冲区*/
			Buf1024 = 1024,					/*1024常量缓冲区*/
			TIME_FORMAT_LEN = 32,			/*时间格式成"xxxx-xx-xx xx:xx:xx"的串长度*/
			SIZE_1K = 1024					/*将Byte单位换算成KB*/

		};

		/**
		*
		*@brief  获得进程ID回调函数
		*@param param 调用回调函数的默认参数
		*@param dwID  获得的进程ID
		*@return 0表示成功，非0表示失败
		*/
		typedef int (*ProcPidFun)( void *param, DWORD dwID);

		/**
		*@brief 获得所有进程中对每WIN_PROC_DATA处理回调函数的定义
		*
		*@param param 调用回调函数的默认参数
		*@param dwID  获得的进程ID
		*@return 0表示成功，非0表示失败
		*/
		typedef int (*ProcDataFun)( void *param, const WIN_PROC_DATA &data);

		/**
		* @brief	获得系统所有进程的pid,如果回调函数处理失败，将会立即返回
		* @param pid_deal 输入参数，函数指针处理每一个pid
		* @param param   输入参数，pid_deal回调函数的默认第一个参数
		* @return	成功返回EC_SUCCESS, 否则返回对应的错误码
		*/	
		static int get_all_proc_pids( ProcPidFun pid_deal, void *param);

		/**
		* @brief 获得系统所有进程信息,如果回调函数处理失败，将会立即返回
		* @param proc_data_deal 输入参数，函数指针处理每一个pid
		* @param param   输入参数，pid_deal回调函数的默认第一个参数
		* @return				成功返回EC_SUCCESS, 否则返回对应的错误码
		*/	
		static int get_all_proc_data( ProcDataFun proc_data_deal, void *param);

		/**
		* @brief			获得一个进程的详细信息
		* @param pid		输入参数，进程的pid
		* @param data		输出参数，返回进程的详细信息
		* @return			成功返回EC_SUCCESS, 否则返回对应的错误码
		*/
		static int get_proc_data(DWORD pid, WIN_PROC_DATA	&data);

		/**
		* @brief			创建一个进程
		* @param	path	输入参数，要运行可执行程序的完整路径
		* @param	args	输入参数，运行时的参数列表，多个参数用空格隔开，参数列表不包括执行程序名
		* @param	cwd		输入参数，程序运行的起始目录，空表示当前目录
		* @return			成功返回EC_SUCCESS, 否则返回对应的错误码
		*/
		static int create_proc(const std::string &path, const std::string &args, const std::string &cwd, bool is_show_ui = true);


		/**
		* @brief			创建一个进程并等待其运行结束
		* @param	path	输入参数，要运行可执行程序的完整路径
		* @param	args	输入参数，运行时的参数列表，多个参数用空格隔开，参数列表不包括执行程序名
		* @param	cwd		输入参数，程序运行的起始目录，空表示当前目录
		* @return			成功返回创建的进程的返回值, 进程创建失败返回-1
		*/
		static int create_proc_wait_exit(const std::string &path, const std::string &args, const std::string &cwd, bool is_show_ui = true);

		/**
		* @brief			杀掉一个进程
		* @param pid		输入参数，进程的pid
		* @return			成功返回EC_SUCCESS, 否则返回对应的错误码
		*/
		static int kill_proc(DWORD pid);

		/**
		* @brief 获取进程执行路径
		*
		* @param  pid 进程的PID
		* @param  procpath	进程执行路径
		* 
		* @return 
		*/
		static int get_proc_path( DWORD pid, std::string& procpath);

		/**
		* @brief 设置进程工作集
		*
		* @param  pid 进程的PID
		* 
		* @return 成功返回EC_SUCCESS, 否则返回对应的错误码
		*/
		static int set_proc_workset(IN DWORD pid);

		/**
		* @brief 设置进程优先级
		*
		* @param  pid 进程的PID
		* @param  pri 进程优先级
		* 
		* @return 成功返回EC_SUCCESS, 否则返回对应的错误码
		*/
		static int set_proc_priority(IN DWORD pid, IN DWORD pri);

		/**
		* @brief 获得进程优先级
		*
		* @param  pid 进程的PID
		* @param  pri 输出进程有限级
		*
		* @return 成功返回EC_SUCCESS, 否则返回对应的错误码
		*/
		static int get_proc_priority(IN DWORD pid, OUT LPDWORD p_pri);

		/**
		* @brief 将进程全路径转换为应用层可识别格式("带 \??\ 和 \systemroot的路径 ")
		*
		* @param  strpath 进程的路径
		*
		* @return 返回修改后的路径，如果没有修改，返回原字符串
		*/
		static std::string transform_procpath(std::string strpath);

		/**
		* @brief 获取进程用户名
		*
		* @param  pid 进程的PID
		* @param  user_name	进程用户名
		* 
		* @return 
		*/
		static int GetProcUser( DWORD pid, std::string& user_name );

		/**
		* @brief 改变进程权限
		*
		* @param  hProcess 需要改变权限进程的句柄
		* @param  pName	  权限名称
		* @param  bEnable TRUE为提升权限，FALSE为降低权限 
		*
		* @return 成功返回TRUE，失败返回FALSE
		*/
		static BOOL SetPrivilege(HANDLE hProcess, LPCTSTR pName, BOOL bEnable ) ;

	private:
		/**
		* @brief 获取进程使用内存大小（单位:K）
		*
		* @param  pid 进程的PID
		* @param  mem_size	进程使用内存大小
		* 
		* @return 
		*/
		static int GetMemStat( DWORD pid, DWORD& mem_size );


		/**
		* @brief 获取进程启动时间
		*
		* @param  pid 进程的PID
		* @param  proc_time	进程启动时间
		* 
		* @return 
		*/
		static int  GetProcStartTime( DWORD pid, std::string& proc_time );
		/**
		* @brief 获取进程命令行
		*
		* @param  pid 进程的PID
		* @param  pCmdLine	进程命令行
		* @param dwBufLen 命令行大小
		* 
		* @return 成功返回TRUE，失败返回FALSE
		*/
		static BOOL GetProcCmdLine( DWORD pid, TCHAR* pCmdLine, DWORD dwBufLen );

	};
}

#endif	//!__UTILITY_PROC_H__

