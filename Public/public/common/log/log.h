
#ifndef __UTILITY_LOG_H__
#define __UTILITY_LOG_H__
#include <stdio.h>
#include <stdarg.h>

/*根据需要定义多个日志函数*/
#undef LOG_DEBUG
#undef LOG_ERROR
#undef LOG_DUMP

#define LOG_DEBUG(X) //RUNLOG_DEBUG_F(X)
#define LOG_ERROR(X) //RUNLOG_ERROR_F(X)
#define LOG_DUMP(X)  //utility::CDump::dump X

#endif //__UTILITY_LOG_H__

