
/***********************************************************************
* @file    communication_server_ext.hpp
* @brief   对通信模块进行全局封装单实例
* @author  abcdefgjinwu@outlook.com
* @time    2024/05/17
***********************************************************************/

#ifndef __COMMUNICATION_SERVER_EXT_H__
#define __COMMUNICATION_SERVER_EXT_H__

#include "base/singleton_template.h"
#include "global/global_define.h"
#include "bin-interface/CommunicationServerInterface/CCommunicationServerHelper.h"

class CommunicationServerExt : public public_common::Singleton<CommunicationServerExt> {

	friend class public_common::Singleton<CommunicationServerExt>;

private:
	ICommunicationServer* pCommnicationServer;
private:
	CommunicationServerExt() :pCommnicationServer(NULL) {
		CCommunicationServerHelper m_apiHelper;

		std::string strDllPath = global_path->GetCurrentExePath() + "CommunicationServer.dll";
		pCommnicationServer = m_apiHelper.LoadDll((PCHAR)strDllPath.c_str());
	};
public:
	~CommunicationServerExt() {};

public:
	/// <summary>
	/// 获取指针
	/// </summary>
	/// <returns> >0:成功  ==0: 失败 </returns>
	inline ICommunicationServer* GetServerPtr() {
		return pCommnicationServer;
	}
};

#define global_communication_server SINGLETON_MAKER(CommunicationServerExt)

//#define ICOMMUNICATIONSERVER global_communication_server->GetInstance()->GetServerPtr()

#endif //__COMMUNICATION_SERVER_EXT_H__