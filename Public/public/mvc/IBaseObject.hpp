/** 
* @file IBaseObject.hpp
* @brief MVC基础接口定义
* @author Gavin geshan@hotmail.com
* @time： 2024-05-26
* @comment: 定义包含MVC相关组件的所有公共及定义.支持跨平台(win/linux/mac)   
* @version: V1.5
*/

#ifndef __MVC_IBaseDef_H_
#define __MVC_IBaseDef_H_

#include <iostream>
#include <list>
#include <algorithm>
using namespace std; 


typedef std::list<void*>  MvcList;
typedef std::list<void*>::iterator  iterMvcValue;


#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif

#ifndef VERIFY_POINTER
#define VERIFY_POINTER(pt, hr)  {if (!pt) {return hr;}}
#endif

#ifndef VERIFY_POINTER_NULL_RET
#define VERIFY_POINTER_NULL_RET(pt)  {if (!pt) {return ;}}
#endif

#ifndef VERIFY_POINTER_NORET
#define VERIFY_POINTER_NORET(pt)  {if (!pt) {return ;}}
#endif

#ifndef DYNAMIC_CAST
#define DYNAMIC_CAST(ClassPtr, ptr)  dynamic_cast<ClassPtr>((ClassPtr)(ptr))
#endif

#ifndef CONST_CAST
#define CONST_CAST(ClassPtr, ptr)  const_cast<ClassPtr>((ClassPtr)(ptr))
#endif


#endif