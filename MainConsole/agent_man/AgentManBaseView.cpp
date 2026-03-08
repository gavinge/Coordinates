#include "AgentManBaseView.h"

CAgentManBaseView::CAgentManBaseView() {
	
};

CAgentManBaseView::~CAgentManBaseView() {

}

bool CAgentManBaseView::UpdateGroupInfo() {
	return true;
}

bool CAgentManBaseView::UpdateAgentInfo(int nGroupID) {
	return true;
}

bool CAgentManBaseView::DeleteGroupInfo(long nGroupID) {
	return true;
}

bool CAgentManBaseView::UpdateGroupInfo(long nGroupID, std::string strGroupName) {
	return true;
}

bool CAgentManBaseView::DeleteAgentFromCurrentAgentList(int nAgentID) {
	return true;
}

bool CAgentManBaseView::UpdateAgentFromCurrentAgentList(const AgentManagement::AgentInfo& agentInfo) {
	return true;
}

bool CAgentManBaseView::OnLineNotifyView(long nGroupID) {
	return true;
}
