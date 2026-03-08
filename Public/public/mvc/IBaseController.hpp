/** 
* @file IBaseController.hpp
* @brief MVC基础接口定义:IBaseController
* @author Gavin geshan@hotmail.com   
* @time： 2024-05-26
* @comment: MVC模型之Controller基础定义。 支持跨平台(win/linux/mac)
* @version: V1.5
*/

#ifndef __MVC_IBaseController_H_
#define __MVC_IBaseController_H_

#include "IBaseObject.hpp"
#include "IBaseModel.hpp"

class IBaseController /*: public IBaseObject*/
{
public:
	IBaseController(){};
	IBaseController(IBaseModel* pModel) {
		m_pModel = pModel;
	};
	virtual ~IBaseController() {};
	
public:
	///@brief 绑定Model
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool BindModel(IBaseModel* pModel) {
		VERIFY_POINTER(pModel, false);
		m_pModel = pModel;
		return m_pModel != NULL;
	}

	///@brief 获取绑定的Model
	///@param 无 
	///@return 返回绑定之后的Model
	virtual IBaseModel* GetBindModel() {
		return m_pModel;
	}

protected:
	///@brief MVC中的Controll中的组件
	IBaseModel* m_pModel;
};

#endif