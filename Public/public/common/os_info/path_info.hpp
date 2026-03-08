/***********************************************************
	Created:	   2020年12月24日 11:40
	Filename: 	   path_info.h
	File ext:	   h
	CXX_STANDARD:  11
	Platform:      支持Windows/Linux平台
	Purpose:	   主进程用到的所有和路径相关的信息.用类
***********************************************************/


#ifndef BASE_PATH_INFO_H
#define BASE_PATH_INFO_H

//通用平台
#include <string.h>

//跨平台相关包含
#ifdef _WIN32
#include <Shlobj.h>
#include <Shlwapi.h>
#include <Windows.h>
#pragma comment(lib, "Shlwapi.lib")
#define MAX_PATH_LENG MAX_PATH        //不同平台长度
#else
#include <limits.h>
#include <unistd.h>
#define MAX_PATH_LENG PATH_MAX        //不同平台长度
#endif

//单模
#include "base/singleton_template.h"

namespace JwUtility {

	/// <summary>
	/// 一个跨win/linux 平台的文件路径获取单实例类
	/// </summary>
	class PathInfo : public public_common::Singleton<PathInfo> {

		friend class public_common::Singleton<PathInfo>;

	private:

		/// <summary>
		/// 当前exe文件路径
		/// </summary>
		std::string current_exe_path;

		/// <summary>
		/// 当前进程的文件名称
		/// </summary>
		std::string current_exe_file;

	public:

		inline std::string GetCurrentExeFile() {
			if (current_exe_file.size())
			{
				return current_exe_file;
			}

#ifdef _WIN32
			//windows..........................................................
			char szPath[MAX_PATH_LENG] = { 0 };
			GetModuleFileNameA(NULL, szPath, MAX_PATH_LENG);
			current_exe_file = PathFindFileNameA(szPath);
			//windows end......................................................
#else         
			//linux............................................................
			char current_path[MAX_PATH_LENG] = { 0 };
			int cnt = readlink("/proc/self/exe", current_path, MAX_PATH_LENG);
			if (cnt < 0 || cnt >= MAX_PATH_LENG)
			{
				if (NULL == realpath("./", current_path))
				{
					return "";
				}
			}

			char* name = strrchr(current_path, '/');
			if (name != NULL)
			{
				current_exe_file = name;
			}
			//linux end........................................................
#endif		
			return current_exe_file;
		}
		inline std::string GetCurrentExePath() {
			if (current_exe_path.size())
			{
				return current_exe_path;
			}
			char tmp_path[MAX_PATH_LENG] = { 0 };

#ifdef _WIN32
			//windows..........................................................
			::GetModuleFileNameA(NULL, tmp_path, MAX_PATH_LENG);
			::PathCombineA(tmp_path,tmp_path,"..\\");
			current_exe_path = tmp_path;
			//windows end......................................................
#else         
			//linux............................................................
			int cnt = readlink("/proc/self/exe", tmp_path, PATH_MAX);
			if (cnt < 0 || cnt >= PATH_MAX)
			{
				if (NULL == realpath("./", tmp_path))
				{
					return "";
				}

				strcat(tmp_path, "/");
				current_exe_path = tmp_path;
				return current_exe_path;
			}

			int i;
			for (i = cnt; i >= 0; --i)
			{
				if (tmp_path[i] == '/')
				{
					tmp_path[i + 1] = '\0';
					break;
				}
			}
			current_exe_path = tmp_path;
			//linux end........................................................
#endif		
			return current_exe_path;
		}

		inline std::string GetFilePath(const std::string& combine = "") {

			return current_exe_path.size() > 0 ? (current_exe_path + combine) : (GetCurrentExePath() + combine);
		}

	private:
		PathInfo() {};
	public:
		~PathInfo() {};

		/// <summary>
		/// 初始化
		/// </summary>
		/// <returns> 0:成功  <0: 失败 </returns>
		int  Init()
		{
			return 0;
		}
	};
}  // namespace base_info

#endif //BASE_PATH_INFO_H