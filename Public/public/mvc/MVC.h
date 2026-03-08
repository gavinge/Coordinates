/** 
* @file MVC.h
* @brief 基础库统一定义包含文件
* @author Gavin geshan@hotmail.com
* @time： 2024-05-26
* @comment: 
* @version: V1.5
*/
#ifndef __MVC_H__
#define __MVC_H__

#include "IBaseView.hpp"
#include "IBaseModel.hpp"
#include "IBaseController.hpp"

/*
int main() {
	UserModel userModel;
	UserController userController(&userModel);  // 直接传递UserModel给UserController
	UserView userView(&userController,&userModel);

	   //这行代码应该在UserView中执行
	   userController.ChangeUserName(1, "Alice Updated");  // 模拟view变化，调用UserController的方法

	return 0;
}
*/
#endif