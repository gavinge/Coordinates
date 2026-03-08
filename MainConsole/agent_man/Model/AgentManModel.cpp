#include "AgentManModel.h"

CAgentManModel::CAgentManModel() {
	CAgentManagerHelper m_apiHelper;

	std::string strDllPath = global_path->GetCurrentExePath() + "AgentManager.dll";
	pAgentManager = m_apiHelper.LoadDll((PCHAR)strDllPath.c_str());

	LOGGER_INFO("pAgentManager ptr: " << pAgentManager);

	CCommunicationServerHelper m_apiHelper2;

	strDllPath = global_path->GetCurrentExePath() + "CommunicationServer.dll";
	pCommnicationServer = m_apiHelper2.LoadDll((PCHAR)strDllPath.c_str());

	LOGGER_INFO("pCommnicationServer ptr: " << pCommnicationServer);

	if (pAgentManager) {
		pAgentManager->queryGroups(m_groups);  //初始化时候把数据获取一次，以后做为缓存数据。
	}
};

CAgentManModel::~CAgentManModel() {

}

//服务开始
int CAgentManModel::StartServer(ICommunicationServerNotify* notify) {

	VERIFY_POINTER(pCommnicationServer, 0);

	int nret = pCommnicationServer->InitServer(notify);
	LOGGER_INFO("init network...ret: " << nret);
	nret = pCommnicationServer->StartServer();
	LOGGER_INFO("srart server...ret: " << nret);

	return nret;
}
//服务停止
int CAgentManModel::StopServer() {

	VERIFY_POINTER(pCommnicationServer, 0);
	int nret = pCommnicationServer->StopServer();
		LOGGER_INFO("stop server...ret: " << nret);

	return nret;
}

bool CAgentManModel::SendDataToAllClients(const std::string & strRule){
	VERIFY_POINTER(pCommnicationServer, false);
	bool nret = pCommnicationServer->SendDataToAllClients((const BYTE*)strRule.c_str(), strRule.length());
	LOGGER_INFO("SendDataToAllClients...ret: " << nret);

	return nret;
}
bool CAgentManModel::SendDataToClient(DeliverCommandType commandType,const char* strMAC, const std::string & strRule) {
	VERIFY_POINTER(pCommnicationServer, false);
	bool nret = pCommnicationServer->SendDataToClient(commandType,strMAC, (const BYTE*)strRule.c_str(), strRule.length());
	LOGGER_INFO("SendDataToClient...ret: " << nret);

	return nret;
}


//void CAgentManModel::OnLineNotify(const char* byte, unsigned long ulength) {
//
//	LOGGER_INFO("OnLineNotify data: [%s],[%d] !" << byte << ulength);
//	VERIFY_POINTER_NULL_RET(pAgentManager);
//
//	//先把上线的数据初始化成object
//	AgentManagement::AgentInfo agentInfo;
//	std::string data(byte, ulength);
//	JwUtility::JsonUtility::jsonToObject<AgentManagement::AgentInfo>(data, agentInfo);
//
//	if (!agentInfo.IP.length()) {
//		return;
//	}
//
//	AgentManagement::AgentInfo agentInfoNew;
//
//	//若已经存在
//	if (pAgentManager->queryAgentInfoByMac(agentInfo.Mac, agentInfoNew)) {
//
//		LOGGER_INFO("Exist AgentInfo");
//
//		agentInfoNew.Status = 1;
//		std::time_t now_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//		agentInfoNew.UpdateTime = now_time_t;
//
//		std::string strInfo;
//		JwUtility::JsonUtility::objectToJson<AgentManagement::AgentInfo>(agentInfoNew, strInfo);
//		LOGGER_INFO("Exist AgentInfo data: [%s]" << strInfo.c_str());
//
//		pAgentManager->updateAgentInfo(agentInfoNew);
//	}
//	else {
//		agentInfo.GroupID = 1;
//		agentInfo.Status = 1;
//		std::string strInfo;
//		JwUtility::JsonUtility::objectToJson<AgentManagement::AgentInfo>(agentInfo, strInfo);
//		LOGGER_INFO("New AgentInfo data: [%s]" << strInfo.c_str());
//		pAgentManager->addAgentInfo(agentInfo);
//
//		//通知列表刷新
//		//NotifyViewUpdateAgentInfo(agentInfo.GroupID);
//		//OnLineNofityUpdateView(agentInfo.GroupID);
//	}
//
//	//根据Mac查询
//}
//
//void CAgentManModel::OffLineNotify(const char* byte, unsigned long ulength) {
//
//	LOGGER_INFO("OffLineNotify data: [%s],[%d] !" << byte << ulength);
//	VERIFY_POINTER_NULL_RET(pAgentManager);
//
//	std::string strMac(byte, ulength);
//
//	if (!strMac.length()) {
//		return;
//	}
//
//	AgentManagement::AgentInfo agentInfo;
//	if (pAgentManager->queryAgentInfoByMac(strMac, agentInfo)) {
//		agentInfo.Status = 0;
//		std::time_t now_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//		agentInfo.UpdateTime = now_time_t;
//
//		std::string strInfo;
//		JwUtility::JsonUtility::objectToJson<AgentManagement::AgentInfo>(agentInfo, strInfo);
//		LOGGER_INFO("update offline AgentInfo data:" << strInfo.c_str());
//
//		pAgentManager->updateAgentInfo(agentInfo);
//
//		//通知列表刷新
//		//NotifyViewUpdateAgentInfo(agentInfo.GroupID);
//	}
//}
//
//void CAgentManModel::RuleDomainProtectLogReportNotify(const char* byte, unsigned long ulength) {
//
//}
//void CAgentManModel::RuleFileProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleInjectProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleKernelCallbackProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleKernelProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleModuleProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleNetworkProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleProcessCreationLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleProcProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleRegisterProtectLogReportNotify(const char* byte, unsigned long ulength) {
//}
//void CAgentManModel::RuleThreadCreationLogReportNotify(const char* byte, unsigned long ulength) {
//}

bool CAgentManModel::NotifyViewUpdateGroupInfo() {

	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor); 
		if (p)
		{
			p->UpdateGroupInfo();
		}
	}
	return true;
}

bool CAgentManModel::NotifyViewUpdateAgentInfo(int nGroupID) {

	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor);
		if (p)
		{
			p->UpdateAgentInfo(nGroupID);
		}
	}
	return true;
}


bool CAgentManModel::OnLineNofityUpdateView(int nGroupID) {

	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor);
		if (p)
		{
			p->OnLineNotifyView(nGroupID);
		}
	}
	return true;
}


bool CAgentManModel::NotifyViewDeleteGroupInfoByGroupID(int nGroupID) {
	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor);
		if (p)
		{
			p->DeleteGroupInfo(nGroupID);
		}
	}
	return true;
}

bool CAgentManModel::NotifyViewUpdateGroupInfoByGroupID(int nGroupID, std::string strGroupName) {
	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor);
		if (p)
		{
			p->UpdateGroupInfo(nGroupID, strGroupName);
		}
	}
	return true;
}

bool CAgentManModel::NotifyViewDeleteAgentFromCurrentAgentList(int nAgentID) {
	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor);
		if (p)
		{
			p->DeleteAgentFromCurrentAgentList(nAgentID);
		}
	}
	return true;
}


bool CAgentManModel::NotifyViewUpdateAgentFromCurrentAgentList(const AgentManagement::AgentInfo& agentInfo) {
	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		CAgentManBaseView* p = DYNAMIC_CAST(CAgentManBaseView*, *itor);
		if (p)
		{
			p->UpdateAgentFromCurrentAgentList(agentInfo);
		}
	}
	return true;
}

bool CAgentManModel::queryGroups(std::vector<AgentManagement::AgentGroupInfo>& queryResult) {
	queryResult.clear();
	queryResult = m_groups;
	return true;
}

int  CAgentManModel::disableAgentInfo(const AgentManagement::AgentInfo& agentInfo) {
	int nret = pAgentManager->updateAgentInfo(agentInfo);
	if (nret > 0)
	{
		NotifyViewUpdateAgentFromCurrentAgentList(agentInfo);
	}
	return true;
}

int  CAgentManModel::delAgentInfo(const AgentManagement::AgentInfo& agentInfo) {
	int nret = pAgentManager->deleteAgentInfo(agentInfo);
	if (nret > 0)
	{
		NotifyViewDeleteAgentFromCurrentAgentList(agentInfo.ID);
	}
	return true;
}



int  CAgentManModel::moveAgent2NewGroup(const AgentManagement::AgentInfo& agentInfo) {
	
	bool bFindGroupID = false;
	for (size_t idx = 0; idx < m_groups.size(); idx++)
	{
		if (m_groups[idx].GroupID == agentInfo.GroupID)
		{
			bFindGroupID = true;
			break;
		}
	}

	if (!bFindGroupID)
	{
		LOGGER_INFO("moveAgent2Group not found GroupID: " << agentInfo.GroupID);
		return -1;
	}

	int nret = pAgentManager->updateAgentInfo(agentInfo);
	if (nret >0 )
	{
		NotifyViewDeleteAgentFromCurrentAgentList(agentInfo.ID);
	}
	return true;
}

bool CAgentManModel::queryGroupInfoByGroupId(int groupID, AgentManagement::AgentGroupInfo& groupInfo) {
	for (size_t idx = 0; idx < m_groups.size(); ++idx) {
		if (m_groups[idx].GroupID == groupID) {
			groupInfo = m_groups[idx];
			return true;
		}
	}
	return false;
}

int CAgentManModel::addGroup(AgentManagement::AgentGroupInfo& group) {
	VERIFY_POINTER(pAgentManager, 0);

	int nret = pAgentManager->addGroup(group);
	LOGGER_INFO("addGroup ret:" << nret);

	if (nret > 0 ) //表示已经新增完成
	{
		pAgentManager->queryGroups(m_groups);
		NotifyViewUpdateGroupInfo();//通知所有的view进行更新
	}
	return nret;
}


int CAgentManModel::deleteGroup(const AgentManagement::AgentGroupInfo& group) {
	VERIFY_POINTER(pAgentManager, 0);

	int nret = pAgentManager->deleteGroup(group);
	LOGGER_INFO("delGroup ret:" << nret);

	if (nret > 0) //表示已经新增完成
	{
		pAgentManager->queryGroups(m_groups);
		NotifyViewDeleteGroupInfoByGroupID(group.GroupID);//通知所有的view进行更新
	}
	return nret;
}

int CAgentManModel::renameGroupName(const AgentManagement::AgentGroupInfo& group) {
	VERIFY_POINTER(pAgentManager, 0);

	//先判断group中是否存在一样的名字，如果有则直接返回-1；
	for (size_t idx = 0; idx < m_groups.size(); ++idx) {
		if (m_groups[idx].GroupName == group.GroupName) {
			return -1;
		}
	}


	int nret = pAgentManager->updateGroup(group);
	LOGGER_INFO("updateGroup ret:" << nret);

	if (nret > 0) //表示已经新增完成
	{
		pAgentManager->queryGroups(m_groups);
		NotifyViewUpdateGroupInfoByGroupID(group.GroupID, group.GroupName);//通知所有的view进行更新
	}
	return nret;
}
