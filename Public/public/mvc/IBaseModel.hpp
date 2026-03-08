/** 
* @file IBaseModel.hpp
* @brief MVC基础接口定义:IBaseModel
* @author Gavin geshan@hotmail.com  
* @time：  2024-05-26
* @comment: MVC模型之Model基础定义。支持跨平台(win/linux/mac)
* @version: V1.5
*/

#ifndef __MVC_IBaseModel_H_
#define __MVC_IBaseModel_H_

#include "IBaseView.hpp"
#include "IBaseObject.hpp"

class  IBaseModel 
{
public:
	IBaseModel() {};
	virtual ~IBaseModel() {};
public:
	///@brief 添加View到Model中
	///@param IBaseOject* 指针. 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool AttachView(void* pView) {

		VERIFY_POINTER(pView, false);

		iterMvcValue itor = find(m_ViewList.begin(), m_ViewList.end(), pView);

		if (itor != m_ViewList.end())
		{
			return false;
		}
		m_ViewList.push_back(pView);
		return true;
	}

	///@brief 删除View到Model中
	///@param IBaseOject* 指针. 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool  DetachView(void* pView) {

		bool bRet = false;
		iterMvcValue itor = find(m_ViewList.begin(), m_ViewList.end(), pView);

		if (itor != m_ViewList.end())
		{
			m_ViewList.remove(pView);
			bRet = true;
		}
		return bRet;
	}
	///@brief 当Model中有变化时,通知m_ViewList中的所有View更新显示
	///@param 无.
	///@return 成功返回TRUE，失败返回FALSE 
	virtual bool NotifyViewObservers() {

		iterMvcValue itor = m_ViewList.begin();
		for (; itor != m_ViewList.end(); itor++)
		{
			IModelObserver* p = DYNAMIC_CAST(IModelObserver*,*itor);
			if (p)
			{
				p->UpdateView();
			}
		}
		return true;
	}

protected:
	///@brief MVC中的Model中的维护的View的列表
	MvcList m_ViewList;
};

#endif