/***********************************************************************
* @file    *.hpp
* @brief   注入防御规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_INJECT_PROTECT_DEFINE_H__
#define __RULE_INJECT_PROTECT_DEFINE_H__
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
	///注入防御规则
	///
	/*
	{
	"RuleType": 11,
	"OperationCode": 0,
	"ProcessInfoType": 0,
	"ProcessInfo": "*",
	"ProtectProcessInfoType": 0,
	"ProtectProcessInfo": "*run",
	"Log": 1,
	"Remark": "123123123123123123123123123123",
	"Enabled": 1,
	"OsVersion": 3
	}
	*/
	class RuleInjectProtect {
	public:
		int RID;
		int RuleGroupID;
		int RuleType;
		int OperationCode;
		int ProcessInfoType;
		std::string ProcessInfo;
		int ProtectProcessInfoType;
		std::string ProtectProcessInfo;
		int Log;
		std::string Remark;
		int InnerID;
		int InnerFlg;
		int Enabled;
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

		RuleInjectProtect() {
			memset(this, 0, sizeof(RuleInjectProtect));
		}
		~RuleInjectProtect() {}

		RuleInjectProtect(int rid, int ruleGroupID, int ruleType, int operationCode, int processInfoType, const std::string& processInfo,
			int protectProcessInfoType, const std::string& protectProcessInfo, int log,
			const std::string& remark,int innerID, int innerFlg, int enabled, int osVersion, int priority, int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: RID(rid),
			RuleGroupID(ruleGroupID),
			RuleType(ruleType),
			OperationCode(operationCode),
			ProcessInfoType(processInfoType),
			ProcessInfo(processInfo),
			ProtectProcessInfoType(protectProcessInfoType),
			ProtectProcessInfo(protectProcessInfo),
			Log(log),
			Remark(remark),
			InnerID(innerID),
			InnerFlg(innerFlg),
			Enabled(enabled),
			OsVersion(osVersion), Priority(priority), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		RuleInjectProtect(const RuleInjectProtect& other)
			: RID(other.RID),
			RuleGroupID(other.RuleGroupID),
			RuleType(other.RuleType),
			OperationCode(other.OperationCode),
			ProcessInfoType(other.ProcessInfoType),
			ProcessInfo(other.ProcessInfo),
			ProtectProcessInfoType(other.ProtectProcessInfoType),
			ProtectProcessInfo(other.ProtectProcessInfo),
			Log(other.Log),
			Remark(other.Remark),
			InnerID(other.InnerID),
			InnerFlg(other.InnerFlg),
			Enabled(other.Enabled),
			OsVersion(other.OsVersion), Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleInjectProtect& operator=(const RuleInjectProtect& other) {
			if (this != &other) {
				RID = other.RID;
				RuleGroupID = other.RuleGroupID;
				RuleType = other.RuleType;
				OperationCode = other.OperationCode;
				ProcessInfoType = other.ProcessInfoType;
				ProcessInfo = other.ProcessInfo;
				ProtectProcessInfoType = other.ProtectProcessInfoType;
				ProtectProcessInfo = other.ProtectProcessInfo;
				Log = other.Log;
				Remark = other.Remark;
				InnerID = other.InnerID;
				InnerFlg = other.InnerFlg;
				Enabled = other.Enabled;
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
			root["RuleGroupID"] = RuleGroupID;  // Added RuleGroupID
			root["RuleType"] = RuleType;
			root["OperationCode"] = OperationCode;
			root["ProcessInfoType"] = ProcessInfoType;
			root["ProcessInfo"] = ProcessInfo;
			root["ProtectProcessInfoType"] = ProtectProcessInfoType;
			root["ProtectProcessInfo"] = ProtectProcessInfo;
			root["Log"] = Log;
			root["Remark"] = Remark;
			root["InnerID"] = InnerID;
			root["InnerFlg"] = InnerFlg;
			root["Enabled"] = Enabled;
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
			RuleType = root.get("RuleType", 0).asInt();
			OperationCode = root.get("OperationCode", 0).asInt();
			ProcessInfoType = root.get("ProcessInfoType", 0).asInt();
			ProcessInfo = root.get("ProcessInfo", "").asString();
			ProtectProcessInfoType = root.get("ProtectProcessInfoType", 0).asInt();
			ProtectProcessInfo = root.get("ProtectProcessInfo", "").asString();
			Log = root.get("Log", 0).asInt();
			Remark = root.get("Remark", "").asString();
			InnerID = root.get("InnerID", 0).asInt();
			InnerFlg = root.get("InnerFlg", 0).asInt();
			Enabled = root.get("Enabled", 0).asInt();
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