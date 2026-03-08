/***********************************************************
	Created:	   2024年2月25日 17:12
	Filename: 	   global_define.h
	File ext:	   h
	CXX_STANDARD:  11
	Platform:      支持Windows/Linux平台
	Purpose:	   全局支持的相关定义放这里, 方便：其余的代码里面可以只包含这一个头文件就可以
	               直接引用这一类了。
***********************************************************/


#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

#include "log\log.h"
#include "log\logger_helper.h"
#include "base\singleton_template.h"
#include "os_info\path_info.hpp"

namespace global_utility {

		///路径全局定义
#define global_path SINGLETON_MAKER(JwUtility::PathInfo)

}  // namespace base_info

#endif //GLOBAL_DEFINE_H