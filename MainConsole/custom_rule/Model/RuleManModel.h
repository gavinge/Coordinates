#ifndef __RULEMAN_MODEL_H_
#define __RULEMAN_MODEL_H_

#include "MVC.h"
#include "base/singleton_template.h"
#include "global/global_define.h"
#include "bin-interface/RuleManagerInterface/CRuleManagerHelper.h"
#include "..\RuleManBaseView.h"
#include "cap_json\json_util.hpp"

class CRuleManBaseView;
class CRuleManModel:
	public IBaseModel
{
public:
	CRuleManModel();
	virtual ~CRuleManModel();
private:
	IRuleManager* pRuleManager;
public:
	int deleteRule(long ruleType, long ruleID);
	int customEnabledInfo(const RuleManagement::AgentEnabledRuleInfo& info);
	int customDisableInfo(const RuleManagement::AgentEnabledRuleInfo& info);


	bool queryProcessCreationEnabled(int agentGroupID, std::vector<RuleManagement::RuleProcessCreation>& queryResult);
	bool queryProcessCreation(int agentGroupID, std::vector<RuleManagement::RuleProcessCreation>& queryResult);
	bool queryProcessCreation(int rid, RuleManagement::RuleProcessCreation &rule);
	int  queryProcessCreationCount();
	int  addProcessCreation(const RuleManagement::RuleProcessCreation& rule);
	int  updateProcessCreation(const RuleManagement::RuleProcessCreation& rule);


	bool queryThreadCreationEnabled(int agentGroupID, std::vector<RuleManagement::RuleThreadCreation>& queryResult);
	bool queryThreadCreation(int agentGroupID, std::vector<RuleManagement::RuleThreadCreation>& queryResult);
	bool queryThreadCreation(int rid, RuleManagement::RuleThreadCreation &rule);
	int  queryThreadCreationCount();
	int  addThreadCreation(const RuleManagement::RuleThreadCreation& rule);
	int  updateThreadCreation(const RuleManagement::RuleThreadCreation& rule);


	bool queryFileProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleFileProtect>& queryResult);
	bool queryFileProtect(int agentGroupID, std::vector<RuleManagement::RuleFileProtect>& queryResult);
	bool queryFileProtect(int rid, RuleManagement::RuleFileProtect &rule);
	int  queryFileProtectCount();
	int  addFileProtect(const RuleManagement::RuleFileProtect& rule);
	int  updateFileProtect(const RuleManagement::RuleFileProtect& rule);


	bool queryModuleProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleModuleProtect>& queryResult);
	bool queryModuleProtect(int agentGroupID, std::vector<RuleManagement::RuleModuleProtect>& queryResult);
	bool queryModuleProtect(int rid, RuleManagement::RuleModuleProtect &rule);
	int  queryModuleProtectCount();
	int  addModuleProtect(const RuleManagement::RuleModuleProtect& rule);
	int  updateModuleProtect(const RuleManagement::RuleModuleProtect& rule);


	bool queryKernelProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleKernelProtect>& queryResult);
	bool queryKernelProtect(int agentGroupID, std::vector<RuleManagement::RuleKernelProtect>& queryResult);
	bool queryKernelProtect(int rid, RuleManagement::RuleKernelProtect &rule);
	int  queryKernelProtectCount();
	int  addKernelProtect(const RuleManagement::RuleKernelProtect& rule);
	int  updateKernelProtect(const RuleManagement::RuleKernelProtect& rule);


	bool queryNetworkProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleNetworkProtect>& queryResult);
	bool queryNetworkProtect(int agentGroupID, std::vector<RuleManagement::RuleNetworkProtect>& queryResult);
	bool queryNetworkProtect(int rid, RuleManagement::RuleNetworkProtect &rule);
	int  queryNetworkProtectCount();
	int  addNetworkProtect(const RuleManagement::RuleNetworkProtect& rule);
	int  updateNetworkProtect(const RuleManagement::RuleNetworkProtect& rule);


	bool queryDomainProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleDomainProtect>& queryResult);
	bool queryDomainProtect(int agentGroupID, std::vector<RuleManagement::RuleDomainProtect>& queryResult);
	bool queryDomainProtect(int rid, RuleManagement::RuleDomainProtect &rule);
	int  queryDomainProtectCount();
	int  addDomainProtect(const RuleManagement::RuleDomainProtect& rule);
	int  updateDomainProtect(const RuleManagement::RuleDomainProtect& rule);


	bool queryRegisterProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleRegisterProtect>& queryResult);
	bool queryRegisterProtect(int agentGroupID, std::vector<RuleManagement::RuleRegisterProtect>& queryResult);
	bool queryRegisterProtect(int rid, RuleManagement::RuleRegisterProtect &rule);
	int  queryRegisterProtectCount();
	int  addRegisterProtect(const RuleManagement::RuleRegisterProtect& rule);
	int  updateRegisterProtect(const RuleManagement::RuleRegisterProtect& rule);


	bool queryProcProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleProcProtect>& queryResult);
	bool queryProcProtect(int agentGroupID, std::vector<RuleManagement::RuleProcProtect>& queryResult);
	bool queryProcProtect(int rid, RuleManagement::RuleProcProtect &rule);
	int  queryProcProtectCount();
	int  addProcProtect(const RuleManagement::RuleProcProtect& rule);
	int  updateProcProtect(const RuleManagement::RuleProcProtect& rule);

private:
	virtual bool NotifyViewUpdateRuleList(int nRuleType);
	virtual bool NotifyViewUpdateRule(int nRuleType, int nRuleID);
};

#endif
