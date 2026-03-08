
#ifndef __AGENTMAN_CONTROLLER_H_
#define __AGENTMAN_CONTROLLER_H_

#include "MVC.h"
#include "base/singleton_template.h"
#include "global/global_define.h"
#include "bin-interface/AgentManagerInterface/CAgentManagerHelper.h"
#include "bin-interface/CommunicationServerInterface/CCommunicationServerHelper.h"
#include "..\Model\AgentManModel.h"
#include "..\AgentManBaseView.h"
#include "..\custom_rule\Model\RuleManModel.h"
class CAgentManController :
	public IBaseController,
	public ICommunicationServerNotify,
	public public_common::Singleton<CAgentManController>
{
	friend class public_common::Singleton<CAgentManController>;

public:
	CAgentManController();
	virtual ~CAgentManController();

public:
	bool BindCustomRuleModel(IBaseModel* pModel);
	IBaseModel* GetBindCustomRuleModel();

	bool BindInnerRuleModel(IBaseModel* pModel);
	IBaseModel* GetBindInnerRuleModel();
public:

	//服务开始
	int StartServer();
	//服务停止
	int StopServer();
	// 给指定客户端下发规则
	bool SendDataToClient(DeliverCommandType commandType, const char* strMAC, const std::string & strRule);

	//查询数据
	//bool queryAgentInfoByIP(const std::string& IP, AgentManagement::AgentInfo& agentInfo);
	bool queryAgentInfoByMac(const std::string& Mac, AgentManagement::AgentInfo& agentInfo);
	bool queryGroups(std::vector<AgentManagement::AgentGroupInfo>& queryResult) ;
	bool queryAgentInfoByGroupId(int groupID, std::vector<AgentManagement::AgentInfo>& queryResult);
	bool queryAgentInfoByPattern(const std::string& pattern, long nGroupID, std::vector<AgentManagement::AgentInfo>& queryResult);
	int  moveAgent2NewGroup(const AgentManagement::AgentInfo& agentInfo);
	int  disableAgentInfo(const AgentManagement::AgentInfo& agentInfo);
	int  delAgentInfo(const AgentManagement::AgentInfo& agentInfo);

	bool queryGroupInfoByGroupId(int groupID, AgentManagement::AgentGroupInfo& groupInfo);
	int  addGroup(AgentManagement::AgentGroupInfo& group);
	int  deleteGroup(const AgentManagement::AgentGroupInfo& group);
	int  renameGroupName(const AgentManagement::AgentGroupInfo& group);
public:  //ICommunicationServerNotify override
	virtual void OnLineNotify(const char* byte, unsigned long ulength) override;
	virtual void OffLineNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleDomainProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleFileProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleInjectProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleKernelCallbackProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleKernelProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleModuleProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleNetworkProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleProcessCreationLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleProcProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleRegisterProtectLogReportNotify(const char* byte, unsigned long ulength) override;
	virtual void RuleThreadCreationLogReportNotify(const char* byte, unsigned long ulength) override;
private:
	bool ReDeliverAgentRule(const AgentManagement::AgentInfo& agentInfo);
	std::string removeLastIfX(std::string str, char X);
private:
	IBaseModel* m_pCustomRuleModel; //自定义(防御)规则
	IBaseModel* m_pInnerRuleModel;  //内部(调试)规则
};

#define AGENT_MAN_CONTROLLER SINGLETON_MAKER(CAgentManController)

#endif