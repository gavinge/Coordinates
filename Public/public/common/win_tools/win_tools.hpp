/*
* 文件名: win_tools.hpp
* 作者: geshan@hotmail.com
* 创建日期: 2023-12-25
* 描述: 通用工具类
*/
#ifndef _UTILITY_WIN_TOOLS_
#define _UTILITY_WIN_TOOLS_

#include <Windows.h>
#include "redirection\disable_file_redirection.h"
#include "win_proc\win_proc.h"


namespace JwUtility
{
	class CWinTools
	{
	public:
		static std::string get_yunsuo_path()
		{
			static std::string install_path;

			if (install_path.empty())
			{
				HKEY  hKEY; 
				//char*   reg_path;
				char	reg_path[256] = { 0 };
				unsigned long  type = REG_SZ;
				unsigned long  len = 80; 
				char setup_path[MAX_PATH] = {0};

#ifdef _X86_
				strcpy(reg_path, "SOFTWARE\\JwServer");
				//reg_path = "SOFTWARE\\JwServer";
#else
				strcpy(reg_path, "SOFTWARE\\Wow6432Node\\JwServer");
				//reg_path = "SOFTWARE\\Wow6432Node\\JwServer";
#endif

				// win获取产品安装目录
				if (ERROR_SUCCESS == RegOpenKeyExA(HKEY_LOCAL_MACHINE, reg_path, 0, KEY_READ, &hKEY))
				{
					if (ERROR_SUCCESS ==  RegQueryValueExA(hKEY, "apppath", NULL, &type, (LPBYTE)setup_path, &len))
					{
						install_path = setup_path;
					}
				}
			}

			return install_path;
		}
	};
}


#endif //_UTILITY_WIN_TOOLS_