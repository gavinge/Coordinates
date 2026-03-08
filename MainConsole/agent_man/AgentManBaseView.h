#ifndef __AGENTMAN_BASEVIEW_H_
#define __AGENTMAN_BASEVIEW_H_

#include "MVC.h"
#include "global/global_define.h"
#include "bin-interface/AgentManagerInterface/CAgentManagerHelper.h"
class CAgentManBaseView:
	public IBaseView
{
public:
	CAgentManBaseView();
	virtual ~CAgentManBaseView();
public:
	//更新所有组信息
	virtual bool UpdateGroupInfo();

	//删除某一个分组信息
	virtual bool DeleteGroupInfo(long nGroupID);

	//更新某一个分组信息
	virtual bool UpdateGroupInfo(long nGroupID, std::string strGroupName);

	//更新AgentInfo信息，如果nGroupID为0，则更新所有。
	virtual bool UpdateAgentInfo(int nGroupID);

	//从当前也删除某个Agent的信息
	virtual bool DeleteAgentFromCurrentAgentList(int nAgentID);

	//从当前list中更新某个Agent的信息
	virtual bool UpdateAgentFromCurrentAgentList(const AgentManagement::AgentInfo& agentInfo);

	virtual bool OnLineNotifyView(long nGroupID);
};

#endif
