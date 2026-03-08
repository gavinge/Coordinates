
/***********************************************************************
* @file    communication_server_ext.hpp
* @brief   对agent管理全局封装单实例
* @author  abcdefgjinwu@outlook.com
* @time    2024/05/17
***********************************************************************/

#ifndef __AGENT_MANAGER_EXT_H__
#define __AGENT_MANAGER_EXT_H__

#include "base/singleton_template.h"
#include "global/global_define.h"
#include "bin-interface/AgentManagerInterface/CAgentManagerHelper.h"

class AgentManagerExt : public public_common::Singleton<AgentManagerExt> {

	friend class public_common::Singleton<AgentManagerExt>;

private:
	IAgentManager* pAgentManager;
private:
	AgentManagerExt() :pAgentManager(NULL) {
		CAgentManagerHelper m_apiHelper;

		std::string strDllPath = global_path->GetCurrentExePath() + "AgentManager.dll";
		pAgentManager = m_apiHelper.LoadDll((PCHAR)strDllPath.c_str());
	};
public:
	~AgentManagerExt() {};

public:
	/// <summary>
	/// 获取指针
	/// </summary>
	/// <returns> >0:成功  ==0: 失败 </returns>
	inline IAgentManager* GetAgentManagerPtr() {
		return pAgentManager;
	}
};


#define global_agent_manager SINGLETON_MAKER(AgentManagerExt)

//#define IAGENTMANAGER global_agent_manager->GetInstance()->GetAgentManagerPtr()

#endif //__AGENT_MANAGER_EXT_H__