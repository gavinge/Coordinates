#include "RuleManController.h"

CRuleManController::CRuleManController() {

};

CRuleManController::~CRuleManController() {

}


int CRuleManController::deleteRule(long ruleType, long ruleID) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->deleteRule(ruleType, ruleID);
	}
	return 0;
}

int CRuleManController::customEnabledInfo(const RuleManagement::AgentEnabledRuleInfo& info) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->customEnabledInfo(info);
	}
	return 0;
}

int CRuleManController::customDisableInfo(const RuleManagement::AgentEnabledRuleInfo& info) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->customDisableInfo(info);
	}
	return 0;
}

bool CRuleManController::queryProcessCreation(int agentGroupID, std::vector<RuleManagement::RuleProcessCreation>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryProcessCreation(agentGroupID,queryResult);
	}
	return 0;
}

bool CRuleManController::queryProcessCreation(int rid, RuleManagement::RuleProcessCreation &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryProcessCreation(rid, rule);
	}
	return 0;
}

int CRuleManController::queryProcessCreationCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryProcessCreationCount();
	}
	return 0;
}



int CRuleManController::addProcessCreation(const RuleManagement::RuleProcessCreation& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addProcessCreation(rule);
	}
	return 0;
}
int CRuleManController::updateProcessCreation(const RuleManagement::RuleProcessCreation& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateProcessCreation(rule);
	}
	return 0;
}


bool CRuleManController::queryThreadCreation(int agentGroupID, std::vector<RuleManagement::RuleThreadCreation>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryThreadCreation(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryThreadCreation(int rid, RuleManagement::RuleThreadCreation &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryThreadCreation(rid, rule);
	}
	return 0;
}

int CRuleManController::queryThreadCreationCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryThreadCreationCount();
	}
	return 0;
}
int CRuleManController::addThreadCreation(const RuleManagement::RuleThreadCreation& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addThreadCreation(rule);
	}
	return 0;
}
int CRuleManController::updateThreadCreation(const RuleManagement::RuleThreadCreation& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateThreadCreation(rule);
	}
	return 0;
}

bool CRuleManController::queryFileProtect(int agentGroupID, std::vector<RuleManagement::RuleFileProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryFileProtect(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryFileProtect(int rid, RuleManagement::RuleFileProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryFileProtect(rid, rule);
	}
	return 0;
}

int CRuleManController::queryFileProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryFileProtectCount();
	}
	return 0;
}


int CRuleManController::addFileProtect(const RuleManagement::RuleFileProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addFileProtect(rule);
	}
	return 0;
}

int CRuleManController::updateFileProtect(const RuleManagement::RuleFileProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateFileProtect(rule);
	}
	return 0;
}

bool CRuleManController::queryModuleProtect(int agentGroupID, std::vector<RuleManagement::RuleModuleProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryModuleProtect(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryModuleProtect(int rid, RuleManagement::RuleModuleProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryModuleProtect(rid, rule);
	}
	return 0;
}

int CRuleManController::queryModuleProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryModuleProtectCount();
	}
	return 0;
}

int CRuleManController::addModuleProtect(const RuleManagement::RuleModuleProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addModuleProtect(rule);
	}
	return 0;
}

int CRuleManController::updateModuleProtect(const RuleManagement::RuleModuleProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateModuleProtect(rule);
	}
	return 0;
}

bool CRuleManController::queryKernelProtect(int agentGroupID, std::vector<RuleManagement::RuleKernelProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryKernelProtect(agentGroupID, queryResult);
	}
	return 0;
}

bool CRuleManController::queryKernelProtect(int rid, RuleManagement::RuleKernelProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryKernelProtect(rid, rule);
	}
	return 0;
}

int CRuleManController::queryKernelProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryKernelProtectCount();
	}
	return 0;
}
int CRuleManController::addKernelProtect(const RuleManagement::RuleKernelProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addKernelProtect(rule);
	}
	return 0;
}
int CRuleManController::updateKernelProtect(const RuleManagement::RuleKernelProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateKernelProtect(rule);
	}
	return 0;
}

bool CRuleManController::queryNetworkProtect(int agentGroupID, std::vector<RuleManagement::RuleNetworkProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryNetworkProtect(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryNetworkProtect(int rid, RuleManagement::RuleNetworkProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryNetworkProtect(rid, rule);
	}
	return 0;
}


int CRuleManController::queryNetworkProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryNetworkProtectCount();
	}
	return 0;
}
int CRuleManController::addNetworkProtect(const RuleManagement::RuleNetworkProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addNetworkProtect(rule);
	}
	return 0;
}
int CRuleManController::updateNetworkProtect(const RuleManagement::RuleNetworkProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateNetworkProtect(rule);
	}
	return 0;
}

bool CRuleManController::queryDomainProtect(int agentGroupID, std::vector<RuleManagement::RuleDomainProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryDomainProtect(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryDomainProtect(int rid, RuleManagement::RuleDomainProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryDomainProtect(rid, rule);
	}
	return 0;
}

int CRuleManController::queryDomainProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryDomainProtectCount();
	}
	return 0;
}
int CRuleManController::addDomainProtect(const RuleManagement::RuleDomainProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addDomainProtect(rule);
	}
	return 0;
}
int CRuleManController::updateDomainProtect(const RuleManagement::RuleDomainProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateDomainProtect(rule);
	}
	return 0;
}


bool CRuleManController::queryRegisterProtect(int agentGroupID, std::vector<RuleManagement::RuleRegisterProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryRegisterProtect(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryRegisterProtect(int rid, RuleManagement::RuleRegisterProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryRegisterProtect(rid, rule);
	}
	return 0;
}

int CRuleManController::queryRegisterProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryRegisterProtectCount();
	}
	return 0;
}
int CRuleManController::addRegisterProtect(const RuleManagement::RuleRegisterProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addRegisterProtect(rule);
	}
	return 0;
}
int CRuleManController::updateRegisterProtect(const RuleManagement::RuleRegisterProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateRegisterProtect(rule);
	}
	return 0;
}


bool CRuleManController::queryProcProtect(int agentGroupID, std::vector<RuleManagement::RuleProcProtect>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryProcProtect(agentGroupID, queryResult);
	}
	return 0;
}
bool CRuleManController::queryProcProtect(int rid, RuleManagement::RuleProcProtect &rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryProcProtect(rid, rule);
	}
	return 0;
}

int CRuleManController::queryProcProtectCount() {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->queryProcProtectCount();
	}
	return 0;
}
int CRuleManController::addProcProtect(const RuleManagement::RuleProcProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->addProcProtect(rule);
	}
	return 0;
}
int CRuleManController::updateProcProtect(const RuleManagement::RuleProcProtect& rule) {
	VERIFY_POINTER(m_pModel, 0);

	CRuleManModel* pModel = DYNAMIC_CAST(CRuleManModel*, m_pModel);
	if (pModel) {
		return pModel->updateProcProtect(rule);
	}
	return 0;
}
