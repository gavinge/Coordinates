#ifndef __RULEMAN_BASEVIEW_H_
#define __RULEMAN_BASEVIEW_H_

#include "MVC.h"
#include "global/global_define.h"
class CRuleManBaseView:
	public IBaseView
{
public:
	CRuleManBaseView();
	virtual ~CRuleManBaseView();
public:
	//通过类型更新规则列表
	virtual bool UpdateRuleList(int nRuleType);

	//更新某一条规则
	virtual bool UpdateRule(int nRuleType, int nRuleID);
};

#endif
