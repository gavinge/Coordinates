
/*
* 文件名:  os_info.cpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: COS_info类实现，Windows平台下操作系统相关信息
*/

#include "os_info.h"

#if defined(_AIX) || defined(__sun__) || defined(__hpux__)
#include <unistd.h>
#include <sys/utsname.h>
#endif

#if defined(__sun__)
#include <sys/systeminfo.h>
#include <stdio.h>
#endif

#ifdef linux
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <string.h>
#include <publib/utility/encoding_convert.h>
#include <publib/utility/unix_tools.h>
#endif


#include "os_info.h"

#include <sstream>
#include <string>
#include <vector>

using namespace JwUtility;


/**
* @brief			获取操作系统版本
* @param os_vesion	输出参数，返回一个包含标识操作系统版本的32位整数
* @return			成功返回EC_SUCCESS 
* 					否则返回对应的错误码
**/
int COS_info::get_os_vesion(int& os_vesion)
{
	os_version info = {0};

#ifdef WIN32

	OSVERSIONINFOEX ver;
	ver.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);


	typedef NTSTATUS (WINAPI *FnRtlGetVersion)(_Out_ PRTL_OSVERSIONINFOW);
	RTL_OSVERSIONINFOEXW osvi;  
	ZeroMemory(&osvi, sizeof(RTL_OSVERSIONINFOEXW));
	osvi.dwOSVersionInfoSize = sizeof( osvi );  
	FnRtlGetVersion fnRtlGetVersion = (FnRtlGetVersion)GetProcAddress( GetModuleHandle( "ntdll.dll" ), "RtlGetVersion" );  
	
	
	if (fnRtlGetVersion)
	{
		fnRtlGetVersion((PRTL_OSVERSIONINFOW)&osvi);
	}
	else
	{
		if(!GetVersionEx((POSVERSIONINFO)&ver))
			return EC_GETVERSION_ERROR;
	}
	
	BOOL bIsWow64 = FALSE;
	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;
	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
	if (NULL != fnIsWow64Process)
	{
		fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
	}

	info.dwPlatformId = ePLANTFORM_WINDOWS;
	info.wProcessorArchitecture	= bIsWow64 ? ePROCESSORARCHITECTURE_X64 : ePROCESSORARCHITECTURE_X32;
	
	if (fnRtlGetVersion)
	{
		info.dwMajorVersion = osvi.dwMajorVersion;
		info.dwMinorVersion = osvi.dwMinorVersion;
		info.wProductType   = osvi.wProductType;
		info.wSuiteMask     = osvi.wSuiteMask;
	}
	else
	{
		info.dwMajorVersion = ver.dwMajorVersion;
		info.dwMinorVersion = ver.dwMinorVersion;
		info.wProductType   = ver.wProductType;
		info.wSuiteMask     = ver.wSuiteMask;
	}

	
#endif

#ifdef _AIX

	struct utsname tuname;
	uname(&tuname);
	std::string sysname = tuname.sysname;

	if (sysname.find("AIX") != std::string::npos)
	{
		info.dwPlatformId = ePLANTFORM_AIX;
	}

	info.dwMajorVersion = atoi(tuname.version);
	info.dwMinorVersion = atoi(tuname.release);
	
	if (sysconf(_SC_AIX_HARDWARE_BITMODE) == 64)
	{
		info.wProcessorArchitecture = ePROCESSORARCHITECTURE_POWER64;

	} else
	{
		info.wProcessorArchitecture = ePROCESSORARCHITECTURE_POWER32;
	}

#endif

#ifdef __sun__

	struct utsname tuname;
	uname(&tuname);
	std::string sysname = tuname.sysname;

	if (sysname.find("SunOS") != std::string::npos)
	{
		info.dwPlatformId = ePLANTFORM_SOLARIS;
	}

	char major = tuname.release[0];

	info.dwMajorVersion = major - 0x30;
	info.dwMinorVersion = atoi(&tuname.release[2]);


	char tmp = 0;
	size_t bufsize = sysinfo(SI_ISALIST, &tmp, 1);

	char* buf = (char*)malloc(bufsize);
	
	if (buf)
	{
		if (sysinfo(SI_ISALIST, buf, bufsize) == bufsize) 
		{
			if (strstr(buf, "ia64"))
			{
				info.wProcessorArchitecture = ePROCESSORARCHITECTURE_IA64;
			
			}else if (strstr(buf, "sparcv9"))
			{
				//printf("sparcv9\n");
				info.wProcessorArchitecture = ePROCESSORARCHITECTURE_SPARC64;
			
			}else if (strstr(buf, "i386"))
			{
				info.wProcessorArchitecture = ePROCESSORARCHITECTURE_X32;
			}else
			{
				info.wProcessorArchitecture = ePROCESSORARCHITECTURE_SPARC32;
			}
		}
		free(buf);
	}
	
#endif

#ifdef __hpux__

	struct utsname tuname;
	uname(&tuname);
	std::string sysname = tuname.sysname;

	if (sysname.find("HP-UX") != std::string::npos)
	{
		info.hp_info.dwPlatformId = ePLANTFORM_HPUX;
	}

	tuname.release[4] = 0;
	info.hp_info.dwMajorVersion = atoi(&tuname.release[2]);
	info.hp_info.dwMinorVersion = atoi(&tuname.release[5]);
	
	long cpu_version = sysconf(_SC_CPU_VERSION);
	
	if (CPU_IS_PA_RISC(cpu_version))
	{
		info.hp_info.wProcessorArchitecture = ePROCESSORARCHITECTURE_PARISC;
	}
	
	std::string model = tuname.machine;
	if (model == "ia64")
	{
		info.hp_info.wProcessorArchitecture = ePROCESSORARCHITECTURE_IA64;
	}

#endif



#ifdef linux
	
	struct utsname uts;

	memset(&uts, 0, sizeof(uts));
	uname(&uts);
	std::string sysname = uts.sysname;

	if ( sysname.find("Linux") != std::string::npos ) 
	{
		info.dwPlatformId = ePLANTFORM_LINUX;
	}

	char major = uts.release[0];
	char minor = uts.release[2];

	info.dwMajorVersion = major - 0x30;
	info.dwMinorVersion = minor - 0x30;

	std::string machine = uts.machine;

	if ( machine.find("x64") != std::string::npos )
	{
		info.wProcessorArchitecture = ePROCESSORARCHITECTURE_X64;
	}
	else
	{
		info.wProcessorArchitecture = ePROCESSORARCHITECTURE_X32;
	}

#endif


	os_vesion = info.version;

	return EC_SUCCESS;
}

#ifdef WIN32
std::string COS_info::get_ProductName()
{
	std::string pn;
	CWinReg::get_subitem_string_value("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion","ProductName",pn,true);
	if(!pn.empty())
	{
		int ifind = pn.find_last_of(' ');
		if(ifind != std::string::npos)
		{
			pn = pn.substr(0,ifind + 1);
		}
	}
	return pn;
}
#endif

bool COS_info::get_os_vesion_str(std::string& s_os_vesion)
{
#ifdef WIN32
	const int BUFSIZE = 256;
	char pszOS[BUFSIZE] = {0};
	typedef void (WINAPI *FnGetNativeSystemInfo)(LPSYSTEM_INFO);

	typedef NTSTATUS (WINAPI *FnRtlGetVersion)(_Out_ PRTL_OSVERSIONINFOW);
	RTL_OSVERSIONINFOEXW osvi;  
	ZeroMemory(&osvi, sizeof(RTL_OSVERSIONINFOEXW));
	osvi.dwOSVersionInfoSize = sizeof( osvi );  
	FnRtlGetVersion fnRtlGetVersion = (FnRtlGetVersion)GetProcAddress( GetModuleHandle( "ntdll.dll" ), "RtlGetVersion" );  
	if (NULL == fnRtlGetVersion)
		return false;

	fnRtlGetVersion((PRTL_OSVERSIONINFOW)&osvi);

	SYSTEM_INFO si;
	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	FnGetNativeSystemInfo fnnGetNativeSystemInfo = (FnGetNativeSystemInfo) GetProcAddress( GetModuleHandle( "kernel32.dll" ), "GetNativeSystemInfo");
	if(NULL != fnnGetNativeSystemInfo)
		fnnGetNativeSystemInfo(&si);
	else GetSystemInfo(&si);

	if(VER_PLATFORM_WIN32_NT != osvi.dwPlatformId ||  osvi.dwMajorVersion < 5)
		return false;

	StringCchCopy(pszOS, BUFSIZE, TEXT("Microsoft "));

	if ( osvi.dwMajorVersion >= 6 )
	{
		if (10 >= osvi.dwMajorVersion)
		{
			std::string pn = get_ProductName();

			if(!pn.empty())
			{
				StringCchCat(pszOS, BUFSIZE,pn.c_str());
			}
			else if( osvi.dwMinorVersion == 0 )
			{
				if (osvi.wProductType == VER_NT_WORKSTATION)
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows 10 "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2016 Technical Preview " ));
			}
		}
		else if (6 == osvi.dwMajorVersion)
		{
			if( osvi.dwMinorVersion == 0 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows Vista "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2008 " ));
			}

			if ( osvi.dwMinorVersion == 1 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows 7 "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2008 R2 " ));
			}

			if ( osvi.dwMinorVersion == 2 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows 8 "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2012 " ));
			}

			if ( osvi.dwMinorVersion == 3 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows 8.1 "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2012 R2 " ));
			}
		}

		typedef BOOL (WINAPI *FnGetProductInfo)(DWORD, DWORD, DWORD, DWORD, PDWORD);
		FnGetProductInfo fnGetProductInfo = (FnGetProductInfo) GetProcAddress( GetModuleHandle( "kernel32.dll" ), "GetProductInfo");
		if (fnGetProductInfo)
		{
			DWORD dwType;
			fnGetProductInfo(osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType);

			switch( dwType )
			{
			case PRODUCT_ULTIMATE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Ultimate Edition" ));
				break;
			case PRODUCT_PROFESSIONAL:
				StringCchCat(pszOS, BUFSIZE, TEXT("Professional" ));
				break;
			case PRODUCT_HOME_PREMIUM:
				StringCchCat(pszOS, BUFSIZE, TEXT("Home Premium Edition" ));
				break;
			case PRODUCT_HOME_BASIC:
				StringCchCat(pszOS, BUFSIZE, TEXT("Home Basic Edition" ));
				break;
			case PRODUCT_ENTERPRISE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition" ));
				break;
			case PRODUCT_BUSINESS:
				StringCchCat(pszOS, BUFSIZE, TEXT("Business Edition" ));
				break;
			case PRODUCT_STARTER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Starter Edition" ));
				break;
			case PRODUCT_CLUSTER_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Cluster Server Edition" ));
				break;
			case PRODUCT_DATACENTER_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Datacenter Edition" ));
				break;
			case PRODUCT_DATACENTER_SERVER_CORE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Datacenter Edition (core installation)" ));
				break;
			case PRODUCT_ENTERPRISE_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition" ));
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition (core installation)" ));
				break;
			case PRODUCT_ENTERPRISE_SERVER_IA64:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition for Itanium-based Systems" ));
				break;
			case PRODUCT_SMALLBUSINESS_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Small Business Server" ));
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
				StringCchCat(pszOS, BUFSIZE, TEXT("Small Business Server Premium Edition" ));
				break;
			case PRODUCT_STANDARD_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Standard Edition" ));
				break;
			case PRODUCT_STANDARD_SERVER_CORE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Standard Edition (core installation)" ));
				break;
			case PRODUCT_WEB_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Web Server Edition" ));
				break;
			}
		}

		if ( si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 )
			StringCchCat(pszOS, BUFSIZE, TEXT( " 64-bit" ));
		else if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL )
			StringCchCat(pszOS, BUFSIZE, TEXT( " 32-bit"));
	}
	if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 )
	{
		if( GetSystemMetrics(SM_SERVERR2) != 0 )
			StringCchCat(pszOS, BUFSIZE, TEXT( "Windows Server 2003 R2 "));
		else if ( osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER )
			StringCchCat(pszOS, BUFSIZE, TEXT( "Windows Storage Server 2003"));
		else if ( osvi.wSuiteMask & VER_SUITE_WH_SERVER )
			StringCchCat(pszOS, BUFSIZE, TEXT( "Windows Home Server"));
		else if( osvi.wProductType == VER_NT_WORKSTATION &&si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			StringCchCat(pszOS, BUFSIZE, TEXT( "Windows XP Professional x64 Edition"));
		else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2003 "));

		//server type.
		if ( osvi.wProductType != VER_NT_WORKSTATION )
		{
			if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_IA64 )
			{
				if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter Edition for Itanium-based Systems" ));
				else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Enterprise Edition for Itanium-based Systems" ));
			}

			else if ( si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 )
			{
				if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter x64 Edition" ));
				else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Enterprise x64 Edition" ));
				else StringCchCat(pszOS, BUFSIZE, TEXT( "Standard x64 Edition" ));
			}
			else
			{
				if ( osvi.wSuiteMask & VER_SUITE_COMPUTE_SERVER )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Compute Cluster Edition 32-bit" ));
				else if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter Edition 32-bit" ));
				else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Enterprise Edition 32-bit" ));
				else if ( osvi.wSuiteMask & VER_SUITE_BLADE )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Web Edition 32-bit" ));
				else StringCchCat(pszOS, BUFSIZE, TEXT( "Standard Edition 32-bit" ));
			}
		}
	}

	if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
	{
		StringCchCat(pszOS, BUFSIZE, TEXT("Windows XP "));
		if( osvi.wSuiteMask & VER_SUITE_PERSONAL )
			StringCchCat(pszOS, BUFSIZE, TEXT( "Home Edition" ));
		else StringCchCat(pszOS, BUFSIZE, TEXT( "Professional" ));
	}

	if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
	{
		StringCchCat(pszOS, BUFSIZE, TEXT("Windows 2000 "));

		if ( osvi.wProductType == VER_NT_WORKSTATION )
		{
			StringCchCat(pszOS, BUFSIZE, TEXT( "Professional" ));
		}
		else 
		{
			if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
				StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter Server" ));
			else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
				StringCchCat(pszOS, BUFSIZE, TEXT( "Advanced Server" ));
			else StringCchCat(pszOS, BUFSIZE, TEXT( "Server" ));
		}
	}

	s_os_vesion = pszOS;

#endif

#ifdef linux
	FILE *fp = NULL;
	char line[512+1] = {0};
	int issue, oem;

	JwUtility::CUnixTools::get_oem_and_issue(oem, issue);

	// ???issue????
	std::string os_file = "/etc/issue";

	if (issue == JwUtility::CUnixTools::ISSUE_SUSE)	// suse
	{
		os_file = "/etc/SuSE-release";
	}
	else if (issue == JwUtility::CUnixTools::ISSUE_CENTOS)	// centos or redhat
	{
		os_file = "/etc/redhat-release";
	}
	else if (issue == JwUtility::CUnixTools::ISSUE_KYLIN)
	{
		os_file = "/etc/kylin-release";
	}

	if ((fp = fopen(os_file.c_str(),"r")) == NULL)
	{
		s_os_vesion = "UNKNOW";
		return true;
	}

	fgets(line, 512, fp);
	line[strlen(line)-1] = '\0';
	fclose(fp);

	// fix ubuntu
	char *ptr = NULL;
	if (ptr = strstr(line,"\\n"))
	{
		while (*ptr != '\0')
		{
			*ptr++ = '\0';
		}
	}

	std::string temp = line;
	s_os_vesion = JwUtility::CConv::utf8_to_gbk_string(temp.c_str());
#endif

	return true; 
}

#ifdef WIN32
BOOL COS_info::is_wow64process()
{
	BOOL bIsWow64 = false;

	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process = NULL;

	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle("kernel32"), "IsWow64Process");
	if (NULL != fnIsWow64Process)
	{
		fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
	}
	
	return bIsWow64;
}
#endif
