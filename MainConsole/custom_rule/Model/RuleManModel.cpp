#include "RuleManModel.h"
#include "../common/RuleType.h"
CRuleManModel::CRuleManModel() {
	CRuleManagerHelper m_apiHelper;

	std::string strDllPath = global_path->GetCurrentExePath() + "RuleManager.dll";
	pRuleManager = m_apiHelper.LoadDll((PCHAR)strDllPath.c_str());
	LOGGER_INFO("pRuleManager ptr: " << pRuleManager);
};

CRuleManModel::~CRuleManModel() {

}

int CRuleManModel::deleteRule(long ruleType, long ruleID) {
	VERIFY_POINTER(pRuleManager, false);
	int nret = -1;
	switch ((RuleType)ruleType) {
	case RuleType::ProcessRuleType:
	{
		RuleManagement::RuleProcessCreation ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_ProcessCreation(ruleDel);
	}
	break;
	case RuleType::FileRuleType:
	{
		RuleManagement::RuleFileProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_FileProtect(ruleDel);
	}
	break;
	case RuleType::ModuleRuleType:
	{
		RuleManagement::RuleModuleProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_ModuleProtect(ruleDel);
	}
	break;
	case RuleType::KernelRuleType:
	{
		RuleManagement::RuleKernelProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_KernelProtect(ruleDel);
	}
	break;
	case RuleType::NetworkRuleType:
	{
		RuleManagement::RuleNetworkProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_NetworkProtect(ruleDel);
	}
	break;
	case RuleType::DomainRuleType:
	{
		RuleManagement::RuleDomainProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_DomainProtect(ruleDel);
	}
	break;
	case RuleType::WindowRuleType:
	{
		/*RuleManagement::RuleProcessCreation ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_ProcessCreation(ruleDel);*/
	}
	break;
	case RuleType::RegistryRuleType:
	{
		RuleManagement::RuleRegisterProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_RegisterProtect(ruleDel);
	}
	break;
	case RuleType::ProtectionRuleType:
	{
		RuleManagement::RuleProcProtect ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_ProcProtect(ruleDel);
	}
	break;
	case RuleType::ThreadRuleType:
	{
		RuleManagement::RuleThreadCreation ruleDel;
		ruleDel.RID = ruleID;
		nret = pRuleManager->deleteRule_ThreadCreation(ruleDel);
	}
	break;
	default:
		break;
	}

	if (nret > 0)
	{
		NotifyViewUpdateRuleList(ruleType);
	}
	LOGGER_INFO("deleteRule...ret: " << nret);
	return nret;
}


int CRuleManModel::customEnabledInfo(const RuleManagement::AgentEnabledRuleInfo& info) {
	VERIFY_POINTER(pRuleManager, false);
	int nret = pRuleManager->enabledInfo(info);
	if (nret > 0) {
		//NotifyViewUpdateRuleList(info.RuleType);
	}
	LOGGER_INFO("customEnabledInfo...ret: " << nret);
	return nret;
}

int CRuleManModel::customDisableInfo(const RuleManagement::AgentEnabledRuleInfo& info) {
	VERIFY_POINTER(pRuleManager, false);
	int nret = pRuleManager->disableInfo(info);
	if (nret > 0) {
		//NotifyViewUpdateRuleList(info.RuleType);
	}
	LOGGER_INFO("customDisableInfo...ret: " << nret);
	return nret;
}


bool CRuleManModel::queryProcessCreationEnabled(int agentGroupID, std::vector<RuleManagement::RuleProcessCreation>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ProcessCreation_WithEnable2(agentGroupID, (int)RuleType::ProcessRuleType, 1, queryResult);
	LOGGER_INFO("queryProcessCreationEnabled...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryProcessCreation(int agentGroupID, std::vector<RuleManagement::RuleProcessCreation>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ProcessCreation_WithEnable(agentGroupID,(int)RuleType::ProcessRuleType, 1, queryResult);
	LOGGER_INFO("queryProcessCreation...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryProcessCreation(int rid, RuleManagement::RuleProcessCreation &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_ProcessCreation(rid,rule);
	LOGGER_INFO("queryProcessCreation one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryProcessCreationCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_ProcessCreation((int)RuleType::ProcessRuleType, 1);
	LOGGER_INFO("queryProcessCreationCount...ret: " << nret);
	return nret;
}


int  CRuleManModel::addProcessCreation(const RuleManagement::RuleProcessCreation& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_ProcessCreation(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addProcessCreation...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateProcessCreation(const RuleManagement::RuleProcessCreation& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_ProcessCreation(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateProcessCreation...ret: " << nret);
	return nret;
}



bool CRuleManModel::queryThreadCreationEnabled(int agentGroupID, std::vector<RuleManagement::RuleThreadCreation>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ThreadCreation_WithEnable2(agentGroupID, (int)RuleType::ThreadRuleType, 1, queryResult);
	LOGGER_INFO("queryThreadCreationEnabled...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryThreadCreation(int agentGroupID, std::vector<RuleManagement::RuleThreadCreation>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ThreadCreation_WithEnable(agentGroupID,(int)RuleType::ThreadRuleType, 1, queryResult);
	LOGGER_INFO("queryThreadCreation...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryThreadCreation(int rid, RuleManagement::RuleThreadCreation &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_ThreadCreation(rid, rule);
	LOGGER_INFO("queryThreadCreation one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryThreadCreationCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_ThreadCreation((int)RuleType::ThreadRuleType, 1);
	LOGGER_INFO("queryThreadCreationCount...ret: " << nret);
	return nret;
}

int  CRuleManModel::addThreadCreation(const RuleManagement::RuleThreadCreation& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_ThreadCreation(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addThreadCreation...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateThreadCreation(const RuleManagement::RuleThreadCreation& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_ThreadCreation(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateThreadCreation...ret: " << nret);
	return nret;
}


bool CRuleManModel::queryFileProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleFileProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_FileProtect_WithEnable2(agentGroupID, (int)RuleType::FileRuleType, 1, queryResult);
	LOGGER_INFO("queryFileProtectEnabled...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryFileProtect(int agentGroupID, std::vector<RuleManagement::RuleFileProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_FileProtect_WithEnable(agentGroupID,(int)RuleType::FileRuleType, 1,queryResult);
	LOGGER_INFO("queryFileProtect...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryFileProtect(int rid, RuleManagement::RuleFileProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_FileProtect(rid, rule);
	LOGGER_INFO("queryFileProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryFileProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_FileProtect((int)RuleType::FileRuleType, 1);
	LOGGER_INFO("queryFileProtectCount...ret: " << nret);
	return nret;
}

int  CRuleManModel::addFileProtect(const RuleManagement::RuleFileProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_FileProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addFileProtect...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateFileProtect(const RuleManagement::RuleFileProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_FileProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateFileProtect...ret: " << nret);
	return nret;
}


bool CRuleManModel::queryModuleProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleModuleProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ModuleProtect_WithEnable2(agentGroupID, (int)RuleType::ModuleRuleType, 1, queryResult);
	LOGGER_INFO("queryModuleProtectEnabled...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryModuleProtect(int agentGroupID, std::vector<RuleManagement::RuleModuleProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ModuleProtect_WithEnable(agentGroupID, (int)RuleType::ModuleRuleType, 1, queryResult);
	LOGGER_INFO("queryModuleProtect...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryModuleProtect(int rid, RuleManagement::RuleModuleProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_ModuleProtect(rid, rule);
	LOGGER_INFO("queryModuleProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryModuleProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_ModuleProtect((int)RuleType::ModuleRuleType, 1);
	LOGGER_INFO("queryModuleProtectCount...ret: " << nret);
	return nret;
}

int  CRuleManModel::addModuleProtect(const RuleManagement::RuleModuleProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_ModuleProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addModuleProtect...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateModuleProtect(const RuleManagement::RuleModuleProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_ModuleProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateModuleProtect...ret: " << nret);
	return nret;
}



bool CRuleManModel::queryKernelProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleKernelProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_KernelProtect_WithEnable2(agentGroupID, (int)RuleType::KernelRuleType, 1, queryResult);
	LOGGER_INFO("queryKernelProtectEnabled...ret: " << nret);
	return nret;
}


bool CRuleManModel::queryKernelProtect(int agentGroupID, std::vector<RuleManagement::RuleKernelProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_KernelProtect_WithEnable(agentGroupID,(int)RuleType::KernelRuleType, 1, queryResult);
	LOGGER_INFO("queryKernelProtect...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryKernelProtect(int rid, RuleManagement::RuleKernelProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_KernelProtect(rid, rule);
	LOGGER_INFO("queryKernelProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryKernelProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_KernelProtect((int)RuleType::KernelRuleType, 1);
	LOGGER_INFO("queryKernelProtectCount...ret: " << nret);
	return nret;
}


int  CRuleManModel::addKernelProtect(const RuleManagement::RuleKernelProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_KernelProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addKernelProtect...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateKernelProtect(const RuleManagement::RuleKernelProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_KernelProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateKernelProtect...ret: " << nret);
	return nret;
}


bool CRuleManModel::queryNetworkProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleNetworkProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_NetworkProtect_WithEnable2(agentGroupID, (int)RuleType::NetworkRuleType, 1, queryResult);
	LOGGER_INFO("queryNetworkProtectEnabled...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryNetworkProtect(int agentGroupID,std::vector<RuleManagement::RuleNetworkProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_NetworkProtect_WithEnable(agentGroupID,(int)RuleType::NetworkRuleType, 1, queryResult);
	LOGGER_INFO("queryNetworkProtect...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryNetworkProtect(int rid, RuleManagement::RuleNetworkProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_NetworkProtect(rid, rule);
	LOGGER_INFO("queryNetworkProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryNetworkProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_NetworkProtect((int)RuleType::NetworkRuleType, 1);
	LOGGER_INFO("queryNetworkProtectCount...ret: " << nret);
	return nret;
}


int  CRuleManModel::addNetworkProtect(const RuleManagement::RuleNetworkProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_NetworkProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addNetworkProtect...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateNetworkProtect(const RuleManagement::RuleNetworkProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_NetworkProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateNetworkProtect...ret: " << nret);
	return nret;
}


bool CRuleManModel::queryDomainProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleDomainProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_DomainProtect_WithEnable2(agentGroupID, (int)RuleType::DomainRuleType, 1, queryResult);
	LOGGER_INFO("queryDomainProtectEnabled...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryDomainProtect(int agentGroupID,std::vector<RuleManagement::RuleDomainProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_DomainProtect_WithEnable(agentGroupID,(int)RuleType::DomainRuleType, 1, queryResult);
	LOGGER_INFO("queryDomainProtect...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryDomainProtect(int rid, RuleManagement::RuleDomainProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_DomainProtect(rid, rule);
	LOGGER_INFO("queryDomainProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryDomainProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_DomainProtect((int)RuleType::DomainRuleType, 1);
	LOGGER_INFO("queryDomainProtectCount...ret: " << nret);
	return nret;
}


int  CRuleManModel::addDomainProtect(const RuleManagement::RuleDomainProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_DomainProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addDomainProtect...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateDomainProtect(const RuleManagement::RuleDomainProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_DomainProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateDomainProtect...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryRegisterProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleRegisterProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_RegisterProtect_WithEnable2(agentGroupID, (int)RuleType::RegistryRuleType, 1, queryResult);
	LOGGER_INFO("queryRegisterProtectEnabled...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryRegisterProtect(int agentGroupID,std::vector<RuleManagement::RuleRegisterProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_RegisterProtect_WithEnable(agentGroupID,(int)RuleType::RegistryRuleType, 1, queryResult);
	LOGGER_INFO("queryRegisterProtect...ret: " << nret);
	return nret;
}

bool CRuleManModel::queryRegisterProtect(int rid, RuleManagement::RuleRegisterProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_RegisterProtect(rid, rule);
	LOGGER_INFO("queryRegisterProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryRegisterProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_RegisterProtect((int)RuleType::RegistryRuleType, 1);
	LOGGER_INFO("queryRegisterProtectCount...ret: " << nret);
	return nret;
}


int  CRuleManModel::addRegisterProtect(const RuleManagement::RuleRegisterProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_RegisterProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addRegisterProtect...ret: " << nret);
	return nret;
}
int  CRuleManModel::updateRegisterProtect(const RuleManagement::RuleRegisterProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_RegisterProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateRegisterProtect...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryProcProtectEnabled(int agentGroupID, std::vector<RuleManagement::RuleProcProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ProcProtect_WithEnable2(agentGroupID, (int)RuleType::ProtectionRuleType, 1, queryResult);
	LOGGER_INFO("queryProcProtectEnabled...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryProcProtect(int agentGroupID,std::vector<RuleManagement::RuleProcProtect>& queryResult) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecords_ProcProtect_WithEnable(agentGroupID,(int)RuleType::ProtectionRuleType, 1, queryResult);
	LOGGER_INFO("queryProcProtect...ret: " << nret);
	return nret;
}
bool CRuleManModel::queryProcProtect(int rid, RuleManagement::RuleProcProtect &rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->queryRecord_ProcProtect(rid, rule);
	LOGGER_INFO("queryProcProtect one...ret: " << nret);
	return nret;
}

int CRuleManModel::queryProcProtectCount() {
	VERIFY_POINTER(pRuleManager, 0);
	int nret = pRuleManager->ruleCount_ProcProtect((int)RuleType::ProtectionRuleType, 1);
	LOGGER_INFO("queryProcProtectCount...ret: " << nret);
	return nret;
}



int  CRuleManModel::addProcProtect(const RuleManagement::RuleProcProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->addRule_ProcProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("addProcProtect...ret: " << nret);
	return nret;
}

int  CRuleManModel::updateProcProtect(const RuleManagement::RuleProcProtect& rule) {
	VERIFY_POINTER(pRuleManager, false);
	bool nret = pRuleManager->updateRule_ProcProtect(rule);
	if (nret > 0) {
		NotifyViewUpdateRuleList(rule.RuleType);
	}
	LOGGER_INFO("updateProcProtect...ret: " << nret);
	return nret;
}

bool CRuleManModel::NotifyViewUpdateRuleList(int nRuleType) {

	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CRuleManBaseView* p = DYNAMIC_CAST(CRuleManBaseView*, *itor);
		if (p)
		{
			p->UpdateRuleList(nRuleType);
		}
	}
	return true;
}

bool CRuleManModel::NotifyViewUpdateRule(int nRuleType, int nRuleID) {

	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CRuleManBaseView* p = DYNAMIC_CAST(CRuleManBaseView*, *itor);
		if (p)
		{
			p->UpdateRule(nRuleType, nRuleID);
		}
	}
	return true;
}





