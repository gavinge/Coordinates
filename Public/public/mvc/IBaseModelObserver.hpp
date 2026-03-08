/** 
* @file IBaseModel.hpp
* @brief MVC基础接口定义:IModelObserver
* @author Gavin geshan@hotmail.com  
* @time：  2024-05-26
* @comment: MVC模型之Model观察者基础定义。支持跨平台(win/linux/mac)
* @version: V1.5
*/

#ifndef __MVC_IBaseModelObserver_H_
#define __MVC_IBaseModelObserver_H_

#include "IBaseObject.hpp"

class IModelObserver {
public:
	virtual ~IModelObserver() {}
	virtual bool UpdateView() = 0;
};

#endif