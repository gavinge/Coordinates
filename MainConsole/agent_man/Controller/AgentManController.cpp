#include "AgentManController.h"

CAgentManController::CAgentManController() {
	m_pCustomRuleModel = NULL;
	m_pInnerRuleModel = NULL;
};

CAgentManController::~CAgentManController() {

}

bool CAgentManController::BindCustomRuleModel(IBaseModel* pModel) {
	m_pCustomRuleModel = pModel;
	
		/*AgentManagement::AgentInfo agentInfo;
		agentInfo.Mac = "00-50-56-38-29-7c";
		agentInfo.IP = "192.168.56.165";
		agentInfo.GroupID = 1;
		ReDeliverAgentRule(agentInfo);*/
	
	return true;
}
IBaseModel* CAgentManController::GetBindCustomRuleModel() {
	return m_pCustomRuleModel;
}

bool CAgentManController::BindInnerRuleModel(IBaseModel* pModel){
	m_pInnerRuleModel = pModel;
	return true;
}
IBaseModel* CAgentManController::GetBindInnerRuleModel() {
	return m_pInnerRuleModel;
}

int CAgentManController::StartServer() {

	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->StartServer(this);
	}
	return 0;
}
int CAgentManController::StopServer() {

	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->StopServer();
	}
	return 0;
}
bool CAgentManController::SendDataToClient(DeliverCommandType commandType, const char* strMAC, const std::string & strRule) {
	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->SendDataToClient(commandType, strMAC, strRule);
	}
	return 0;
}

//bool CAgentManController::queryAgentInfoByIP(const std::string& IP, AgentManagement::AgentInfo& agentInfo) {
//	
//	VERIFY_POINTER(m_pModel, 0);
//
//	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
//	if (pModel) {
//		return pModel->GetAgentManager()->queryAgentInfoByIP(IP, agentInfo);
//	}
//	return 0;
//}

bool CAgentManController::queryAgentInfoByMac(const std::string& Mac, AgentManagement::AgentInfo& agentInfo) {

	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->GetAgentManager()->queryAgentInfoByMac(Mac, agentInfo);
	}
	return 0;
}

bool CAgentManController::queryGroups(std::vector<AgentManagement::AgentGroupInfo>& queryResult) {
	
	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->queryGroups(queryResult);
	}
	return 0;
}
bool CAgentManController::queryAgentInfoByGroupId(int groupID, std::vector<AgentManagement::AgentInfo>& queryResult) {

	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->GetAgentManager()->queryAgentInfoByGroupId(groupID, queryResult);
	}
	return 0;
}

bool CAgentManController::queryAgentInfoByPattern(const std::string& pattern, long nGroupID, std::vector<AgentManagement::AgentInfo>& queryResult) {
	VERIFY_POINTER(m_pModel, 0);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->GetAgentManager()->queryAgentInfoByPattern(pattern, nGroupID, queryResult);
	}
	return 0;
}
int  CAgentManController::moveAgent2NewGroup(const AgentManagement::AgentInfo& agentInfo) {

	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->moveAgent2NewGroup(agentInfo);
	}
	return 0;
}

int  CAgentManController::disableAgentInfo(const AgentManagement::AgentInfo& agentInfo) {
	VERIFY_POINTER(m_pModel, 0);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->disableAgentInfo(agentInfo);
	}
	return 0;
}

int  CAgentManController::delAgentInfo(const AgentManagement::AgentInfo& agentInfo) {
	VERIFY_POINTER(m_pModel, 0);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->delAgentInfo(agentInfo);
	}
	return 0;
}


int CAgentManController::addGroup(AgentManagement::AgentGroupInfo& group) {

	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->addGroup(group);
	}
	return 0;
}

bool CAgentManController::queryGroupInfoByGroupId(int groupID, AgentManagement::AgentGroupInfo& groupInfo) {
	VERIFY_POINTER(m_pModel, 0);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->queryGroupInfoByGroupId(groupID, groupInfo);
	}
	return false;
}

int  CAgentManController::deleteGroup(const AgentManagement::AgentGroupInfo& group) {
	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->deleteGroup(group);
	}
	return 0;
}

int  CAgentManController::renameGroupName(const AgentManagement::AgentGroupInfo& group) {
	VERIFY_POINTER(m_pModel, 0);

	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	if (pModel) {
		return pModel->renameGroupName(group);
	}
	return 0;
}


void CAgentManController::OnLineNotify(const char* byte, unsigned long ulength) {

	VERIFY_POINTER_NULL_RET(m_pModel);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	VERIFY_POINTER_NULL_RET(pModel);

	LOGGER_INFO("OnLineNotify data: [%s],[%d] !" << byte << ulength);
	

	//先把上线的数据初始化成object
	AgentManagement::AgentInfo agentInfo;
	std::string data(byte, ulength);
	JwUtility::JsonUtility::jsonToObject<AgentManagement::AgentInfo>(data, agentInfo);

	if (!agentInfo.IP.length()) {
		return;
	}

	AgentManagement::AgentInfo agentInfoNew;

	//若已经存在
	
	if (pModel->GetAgentManager()->queryAgentInfoByMac(agentInfo.Mac, agentInfoNew)) {

		LOGGER_INFO("Exist AgentInfo");

		agentInfoNew.Status = 1;
		std::time_t now_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		agentInfoNew.UpdateTime = now_time_t;

		std::string strInfo;
		JwUtility::JsonUtility::objectToJson<AgentManagement::AgentInfo>(agentInfoNew, strInfo);
		LOGGER_INFO("Exist AgentInfo data: [%s]" << strInfo.c_str());
		agentInfo = agentInfoNew; 

		pModel->GetAgentManager()->updateAgentInfo(agentInfoNew);
	}
	else {
		agentInfo.GroupID = 1;
		agentInfo.Status = 1;
		std::string strInfo;
		JwUtility::JsonUtility::objectToJson<AgentManagement::AgentInfo>(agentInfo, strInfo);
		LOGGER_INFO("New AgentInfo data: [%s]" << strInfo.c_str());
		pModel->GetAgentManager()->addAgentInfo(agentInfo);

		//通知列表刷新
		//NotifyViewUpdateAgentInfo(agentInfo.GroupID);
		//OnLineNofityUpdateView(agentInfo.GroupID);
	}

	ReDeliverAgentRule(agentInfo);
}

std::string CAgentManController::removeLastIfX(std::string str,char X) {
	if (!str.empty() && str.back() == X) {
		return str.substr(0, str.length() - 1);
	}
	return str;
}

bool CAgentManController::ReDeliverAgentRule(const AgentManagement::AgentInfo& agentInfo) {

	VERIFY_POINTER(m_pModel,false);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	VERIFY_POINTER(pModel, false);

	VERIFY_POINTER(m_pCustomRuleModel,false);
	CRuleManModel* pConcreteCustomModel = DYNAMIC_CAST(CRuleManModel*, m_pCustomRuleModel);
	VERIFY_POINTER(pConcreteCustomModel, false);

	LOGGER_INFO("ReDeliverAgentRule mac:" << agentInfo.Mac.c_str() << "  ip:" << agentInfo.IP.c_str());

	std::string strContent = "[";
	std::string strContentEnd = "]";

	//查询10类规则,还差一类：窗口

	std::string strTmp = "";
	std::vector<RuleManagement::RuleProcessCreation> queryProcessCreationEnabledResult;
	pConcreteCustomModel->queryProcessCreationEnabled(agentInfo.GroupID, queryProcessCreationEnabledResult);
	for (auto item : queryProcessCreationEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}
	

	std::vector<RuleManagement::RuleThreadCreation> queryThreadCreationEnabledResult;
	pConcreteCustomModel->queryThreadCreationEnabled(agentInfo.GroupID, queryThreadCreationEnabledResult);
	for (auto item : queryThreadCreationEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}


	std::vector<RuleManagement::RuleFileProtect> queryFileProtectEnabledResult;
	pConcreteCustomModel->queryFileProtectEnabled(agentInfo.GroupID, queryFileProtectEnabledResult);
	for (auto item : queryFileProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}


	std::vector<RuleManagement::RuleModuleProtect> queryModuleProtectEnabledResult;
	pConcreteCustomModel->queryModuleProtectEnabled(agentInfo.GroupID, queryModuleProtectEnabledResult);
	for (auto item : queryModuleProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}


	std::vector<RuleManagement::RuleKernelProtect> queryKernelProtectEnabledResult;
	pConcreteCustomModel->queryKernelProtectEnabled(agentInfo.GroupID, queryKernelProtectEnabledResult);
	for (auto item : queryKernelProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}

	std::vector<RuleManagement::RuleNetworkProtect> queryNetworkProtectEnabledResult;
	pConcreteCustomModel->queryNetworkProtectEnabled(agentInfo.GroupID, queryNetworkProtectEnabledResult);
	for (auto item : queryNetworkProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}

	std::vector<RuleManagement::RuleDomainProtect> queryDomainProtectEnabledResult;
	pConcreteCustomModel->queryDomainProtectEnabled(agentInfo.GroupID, queryDomainProtectEnabledResult);
	for (auto item : queryDomainProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}

	std::vector<RuleManagement::RuleRegisterProtect> queryRegisterProtectEnabledResult;
	pConcreteCustomModel->queryRegisterProtectEnabled(agentInfo.GroupID, queryRegisterProtectEnabledResult);
	for (auto item : queryRegisterProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp, '\n') + ",";
		}
	}

	std::vector<RuleManagement::RuleProcProtect> queryProcProtectEnabledResult;
	pConcreteCustomModel->queryProcProtectEnabled(agentInfo.GroupID, queryProcProtectEnabledResult);
	for (auto item : queryProcProtectEnabledResult)
	{
		strTmp = "";
		JwUtility::JsonUtility::objectToJson(item, strTmp);
		if (strTmp.length() > 10) {
			strContent += removeLastIfX(strTmp,'\n') + ",";
		}
	}
	
	std::string strContentRule = removeLastIfX(strContent, ',') + strContentEnd;
	
	RuleDetail ruleDetail;
	ruleDetail.Enabled = 1;
	ruleDetail.StartIp = agentInfo.IP;
	ruleDetail.EndIp = agentInfo.IP;
	ruleDetail.RuleType = 0; //防禦規則
	ruleDetail.IsPlugin = 1;
	ruleDetail.Source = 0;  //????
	ruleDetail.Content = strContentRule;


	RuleEncapsulation ruleEncapsulation;
	ruleEncapsulation.isrun = 1;
	ruleEncapsulation.ip = agentInfo.IP;
	ruleEncapsulation.isdebug = agentInfo.Debug;
	ruleEncapsulation.userid = 100; //????
	ruleEncapsulation.pcid = agentInfo.ID;
	ruleEncapsulation.isrunpm = 0;
	ruleEncapsulation.isrulelog = 0; //???
	long time = (long)std::time(NULL);
	ruleEncapsulation.timestamp = time;
	ruleEncapsulation.rule.push_back(ruleDetail);

	std::string ruleEncap = "";
	JwUtility::JsonUtility::objectToJson(ruleEncapsulation, ruleEncap);

	//发送......
	LOGGER_INFO("deliver rule----------------\r\n" << ruleEncap << "\r\n---------------");
	return pModel->SendDataToClient(CommandRule,agentInfo.Mac.c_str(), ruleEncap);
}


void CAgentManController::OffLineNotify(const char* byte, unsigned long ulength) {

	VERIFY_POINTER_NULL_RET(m_pModel);
	CAgentManModel* pModel = DYNAMIC_CAST(CAgentManModel*, m_pModel);
	VERIFY_POINTER_NULL_RET(pModel);

	LOGGER_INFO("OffLineNotify data: [%s],[%d] !" << byte << ulength);

	std::string strMac(byte, ulength);

	if (!strMac.length()) {
		return;
	}

	AgentManagement::AgentInfo agentInfo;
	if (pModel->GetAgentManager()->queryAgentInfoByMac(strMac, agentInfo)) {
		agentInfo.Status = 0;
		std::time_t now_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		agentInfo.UpdateTime = now_time_t;

		std::string strInfo;
		JwUtility::JsonUtility::objectToJson<AgentManagement::AgentInfo>(agentInfo, strInfo);
		LOGGER_INFO("update offline AgentInfo data:" << strInfo.c_str());

		pModel->GetAgentManager()->updateAgentInfo(agentInfo);

		//通知列表刷新
		//NotifyViewUpdateAgentInfo(agentInfo.GroupID);
	}
}

void CAgentManController::RuleDomainProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleFileProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleInjectProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleKernelCallbackProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleKernelProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleModuleProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleNetworkProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleProcessCreationLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleProcProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleRegisterProtectLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}
void CAgentManController::RuleThreadCreationLogReportNotify(const char* byte, unsigned long ulength) {
	std::string strLog(byte, ulength);
	LOGGER_INFO("------log:  " << strLog.c_str());
}