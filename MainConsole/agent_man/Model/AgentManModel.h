#ifndef __AGENTMAN_MODEL_H_
#define __AGENTMAN_MODEL_H_

#include "MVC.h"
#include "base/singleton_template.h"
#include "global/global_define.h"
#include "bin-interface/AgentManagerInterface/CAgentManagerHelper.h"
#include "bin-interface/CommunicationServerInterface/CCommunicationServerHelper.h"
#include "..\AgentManBaseView.h"
#include "cap_json\json_util.hpp"
#include "RuleDeliverEncapsulation.hpp"

class CAgentManBaseView;
class CAgentManModel:
	//public ICommunicationServerNotify,
	public IBaseModel
{
public:
	CAgentManModel();
	virtual ~CAgentManModel();
private:
	IAgentManager* pAgentManager;
	ICommunicationServer* pCommnicationServer;
	std::vector<AgentManagement::AgentGroupInfo> m_groups;  //做个缓存，这个在group有更新的时候再获取一次。
public:
	/// <summary>
	/// 获取AgentManagerService指针，这里这么做，少给一层封装，直接用dll的导出接口。
	/// </summary>
	/// <returns> >0:成功  ==0: 失败 </returns>
	inline IAgentManager* GetAgentManager() {
		return pAgentManager;
	}

	//服务开始
	int StartServer(ICommunicationServerNotify* notify);
	//服务停止
	int StopServer();
	// 批量给所有客户端下发规则
	bool SendDataToAllClients(const std::string & strRule);
	// 给指定客户端下发规则
	bool SendDataToClient(DeliverCommandType commandType,const char* strMAC, const std::string & strRule);



	//查询groups，这里单独拿出来，做个缓存。
	bool queryGroups(std::vector<AgentManagement::AgentGroupInfo>& queryResult);
	int  moveAgent2NewGroup(const AgentManagement::AgentInfo& agentInfo);
	int  disableAgentInfo(const AgentManagement::AgentInfo& agentInfo);
	int  delAgentInfo(const AgentManagement::AgentInfo& agentInfo);

	int addGroup(AgentManagement::AgentGroupInfo& group);
	bool queryGroupInfoByGroupId(int groupID, AgentManagement::AgentGroupInfo& groupInfo);
	int  deleteGroup(const AgentManagement::AgentGroupInfo& group);
	int  renameGroupName(const AgentManagement::AgentGroupInfo& group);

//public:  //ICommunicationServerNotify override
//	virtual void OnLineNotify(const char* byte, unsigned long ulength) override;
//	virtual void OffLineNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleDomainProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleFileProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleInjectProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleKernelCallbackProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleKernelProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleModuleProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleNetworkProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleProcessCreationLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleProcProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleRegisterProtectLogReportNotify(const char* byte, unsigned long ulength) override;
//	virtual void RuleThreadCreationLogReportNotify(const char* byte, unsigned long ulength) override;

private:
	virtual bool NotifyViewUpdateGroupInfo();
	virtual bool NotifyViewUpdateAgentInfo(int nGroupID);
	virtual bool NotifyViewDeleteGroupInfoByGroupID(int nGroupID);
	virtual bool NotifyViewUpdateGroupInfoByGroupID(int nGroupID, std::string strGroupName);
	virtual bool NotifyViewDeleteAgentFromCurrentAgentList(int nAgentID);
	virtual bool NotifyViewUpdateAgentFromCurrentAgentList(const AgentManagement::AgentInfo& agentInfo);

	virtual bool OnLineNofityUpdateView(int nGroupID);
};

#endif
