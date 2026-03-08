/***********************************************************************
* @file    *.hpp
* @brief   网络防御规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_NETWORK_PROTECT_DEFINE_H__
#define __RULE_NETWORK_PROTECT_DEFINE_H__
#ifdef _WIN32
#pragma once
#endif

#include <iostream>
#include <vector>
#include <string>

#include "jsoncpp\json.h"


namespace RuleManagement
{
	///
	///网络防御规则
	///
	/*
	{
	  "OperationCode": 0,
	  "RuleType": 5,
	  "ProcessInfo": "*cmd.exe",
	  "ProcessInfoType": 0,
	  "IP": "www.baidu.com",
	  "Enabled": 1,
	  "Port": "0",
	  "Log": 1,
	  "Remark": "",
	  "Options": 3,
	  "OsVersion": 3
    }
	*/

	class RuleNetworkProtect {
	public:
		int RID;
		int RuleGroupID;  
		int OperationCode;
		int RuleType;
		std::string ProcessInfo;
		int ProcessInfoType;
		std::string IP;
		int InnerID;
		int InnerFlg;
		int Enabled;
		std::string Port;
		int Log;
		std::string Remark;
		int Options;
		int OsVersion;

		int Priority;
		int CreateTime;
		int UpdateTime;
		int Reserved1;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		RuleNetworkProtect() {
			memset(this, 0, sizeof(RuleNetworkProtect));
		}
		~RuleNetworkProtect() {}

		RuleNetworkProtect(int rid, int rule_group_id, int operation_code, int rule_type, const std::string& process_info, int process_info_type,
			const std::string& ip, int inner_ID, int inner_flg, int enabled, const std::string& port, int log, const std::string& remark,
			int options, int os_version, int priority, int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: RID(rid),
			RuleGroupID(rule_group_id),
			OperationCode(operation_code),
			RuleType(rule_type),
			ProcessInfo(process_info),
			ProcessInfoType(process_info_type),
			IP(ip),
			InnerID(inner_ID),
			InnerFlg(inner_flg),
			Enabled(enabled),
			Port(port),
			Log(log),
			Remark(remark),
			Options(options),
			OsVersion(os_version), Priority(priority), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		RuleNetworkProtect(const RuleNetworkProtect& other)
			: RID(other.RID),
			RuleGroupID(other.RuleGroupID),
			OperationCode(other.OperationCode),
			RuleType(other.RuleType),
			ProcessInfo(other.ProcessInfo),
			ProcessInfoType(other.ProcessInfoType),
			IP(other.IP),
			InnerID(other.InnerID),
			InnerFlg(other.InnerFlg),
			Enabled(other.Enabled),
			Port(other.Port),
			Log(other.Log),
			Remark(other.Remark),
			Options(other.Options),
			OsVersion(other.OsVersion), Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleNetworkProtect& operator=(const RuleNetworkProtect& other) {
			if (this != &other) {
				RID = other.RID;
				RuleGroupID = other.RuleGroupID;
				OperationCode = other.OperationCode;
				RuleType = other.RuleType;
				ProcessInfo = other.ProcessInfo;
				ProcessInfoType = other.ProcessInfoType;
				IP = other.IP;
				InnerID = other.InnerID;
				InnerFlg = other.InnerFlg;
				Enabled = other.Enabled;
				Port = other.Port;
				Log = other.Log;
				Remark = other.Remark;
				Options = other.Options;
				OsVersion = other.OsVersion;

				Priority = other.Priority;
				CreateTime = other.CreateTime;
				UpdateTime = other.UpdateTime;
				Reserved1 = other.Reserved1;
				Reserved2 = other.Reserved2;
				Reserved3 = other.Reserved3;
				Reserved4 = other.Reserved4;
				Reserved5 = other.Reserved5;
				Reserved6 = other.Reserved6;

			}
			return *this;
		}

		void toJson(Json::Value& root) const {
			root["RID"] = RID;
			root["RuleGroupID"] = RuleGroupID;  
			root["OperationCode"] = OperationCode;
			root["RuleType"] = RuleType;
			root["ProcessInfo"] = ProcessInfo;
			root["ProcessInfoType"] = ProcessInfoType;
			root["IP"] = IP;
			root["InnerID"] = InnerID;
			root["InnerFlg"] = InnerFlg;
			root["Enabled"] = Enabled;
			root["Port"] = Port;
			root["Log"] = Log;
			root["Remark"] = Remark;
			root["Options"] = Options;
			root["OsVersion"] = OsVersion;

			root["Priority"] = Priority;
			/*root["CreateTime"] = CreateTime;
			root["UpdateTime"] = UpdateTime;
			root["Reserved1"] = Reserved1;
			root["Reserved2"] = Reserved2;
			root["Reserved3"] = Reserved3;
			root["Reserved4"] = Reserved4;
			root["Reserved5"] = Reserved5;
			root["Reserved6"] = Reserved6;*/
		}

		void fromJson(const Json::Value& root) {
			RID = root.get("RID", 0).asInt();
			RuleGroupID = root.get("RuleGroupID", 0).asInt();  
			OperationCode = root.get("OperationCode", 0).asInt();
			RuleType = root.get("RuleType", 0).asInt();
			ProcessInfo = root.get("ProcessInfo", "").asString();
			ProcessInfoType = root.get("ProcessInfoType", 0).asInt();
			IP = root.get("IP", "").asString();
			InnerID = root.get("InnerID", 0).asInt();
			InnerFlg = root.get("InnerFlg", 0).asInt();
			Enabled = root.get("Enabled", 0).asInt();
			Port = root.get("Port", "").asString();
			Log = root.get("Log", 0).asInt();
			Remark = root.get("Remark", "").asString();
			Options = root.get("Options", 0).asInt();
			OsVersion = root.get("OsVersion", 0).asInt();

			Priority = root.get("Priority", 0).asInt();
			CreateTime = root.get("CreateTime", 0).asInt();
			UpdateTime = root.get("UpdateTime", 0).asInt();
			Reserved1 = root.get("Reserved1", 0).asInt();
			Reserved2 = root.get("Reserved2", 0).asInt();
			Reserved3 = root.get("Reserved3", 0).asInt();
			Reserved4 = root.get("Reserved4", "").asString();
			Reserved5 = root.get("Reserved5", "").asString();
			Reserved6 = root.get("Reserved6", "").asString();
		}
	};
}
#endif // 