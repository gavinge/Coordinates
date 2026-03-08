/** 
* @file IBaseView.hpp
* @brief MVC基础接口定义:IBaseView
* @author Gavin geshan@hotmail.com
* @time： 2024-05-26
* @comment: MVC模型之View基础定义。支持跨平台(win/linux/mac)
* @version: V1.5
*/

#ifndef __MVC_IBaseView_H_
#define __MVC_IBaseView_H_


#include "IBaseObject.hpp"
#include "IBaseModelObserver.hpp"
#include "IBaseController.hpp"


class IBaseView : 
	public IModelObserver
{
public:
	IBaseView():m_pController(NULL), m_pModel(NULL){};
	IBaseView(IBaseController* pController, IBaseModel* pModel) {
		m_pController = pController;
		m_pModel = pModel;
		m_pModel->AttachView(this);
	};
	virtual ~IBaseView() {}
public:
	///@brief 更新自身View显示
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool UpdateView()  {
		return true;
	}

	///@brief 绑定View的Controller组件
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool BindController(IBaseController* pController) {

		VERIFY_POINTER(pController, false);
		m_pController = pController;
		return m_pController != NULL;
	}

	///@brief 绑定View的Model组件
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool BindModel(IBaseModel* pModel) {

		VERIFY_POINTER(pModel, false);
		
		
		//解绑上次已经绑定的View
		if (m_pModel != NULL && m_pModel != pModel) {
			m_pModel->DetachView(this);
		}

		m_pModel = pModel;
		m_pModel->AttachView(this);

		return m_pModel != NULL;
	}

protected:
	///@brief MVC中的View中的Controller、Model组件
	IBaseController* m_pController;
	IBaseModel* m_pModel;
};

#endif