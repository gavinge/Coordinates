/***********************************************************************
* @file    *.hpp
* @brief   域名防御规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_DOMAIN_PROTECT_DEFINE_H__
#define __RULE_DOMAIN_PROTECT_DEFINE_H__
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
	///域名防御规则
	///
	/*
	{
	  "RuleType": 9,
	  "DomainName": "*.baidu.com",
	  "ProcessInfo": "*cmd.exe",
	  "ProcessInfoType": 0,
	  "IP": "127.0.0.1",
	  "Enabled": 1,
	  "OsVersion": 3,
	  "Log": 1,
	  "Remark": "123123123123123123123123123123"
	}
	*/

	class RuleDomainProtect {
	public:
		int RID;
		int RuleGroupID;  
		int RuleType;
		std::string DomainName;
		std::string ProcessInfo;
		int ProcessInfoType;
		std::string IP;
		int Enabled;
		int OsVersion;
		int Log;
		int InnerID;
		int InnerFlg;
		std::string Remark;

		int Priority;
		int CreateTime;
		int UpdateTime;
		int Reserved1;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		RuleDomainProtect() {
			memset(this, 0, sizeof(RuleDomainProtect));
		}
		~RuleDomainProtect() {}

		RuleDomainProtect(int rid, int ruleGroupID, int ruleType, const std::string& domainName, const std::string& processInfo,
			int processInfoType, const std::string& ip, int enabled, int osVersion, int log, int innerID,int innerFlg,
			const std::string& remark,int priority, int createTime, int updateTime, int reserved1,int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: RID(rid),
			RuleGroupID(ruleGroupID),
			RuleType(ruleType),
			DomainName(domainName),
			ProcessInfo(processInfo),
			ProcessInfoType(processInfoType),
			IP(ip),
			Enabled(enabled),
			OsVersion(osVersion),
			Log(log),
			InnerID(innerID),
			InnerFlg(innerFlg),
			Remark(remark),Priority(priority),CreateTime(createTime), UpdateTime(updateTime),Reserved1(reserved1),Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6){}

		RuleDomainProtect(const RuleDomainProtect& other)
			: RID(other.RID),
			RuleGroupID(other.RuleGroupID),
			RuleType(other.RuleType),
			DomainName(other.DomainName),
			ProcessInfo(other.ProcessInfo),
			ProcessInfoType(other.ProcessInfoType),
			IP(other.IP),
			Enabled(other.Enabled),
			OsVersion(other.OsVersion),
			Log(other.Log),
			InnerID(other.InnerID),
			InnerFlg(other.InnerFlg),
			Remark(other.Remark),
			Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleDomainProtect& operator=(const RuleDomainProtect& other) {
			if (this != &other) {
				RID = other.RID;
				RuleGroupID = other.RuleGroupID;
				RuleType = other.RuleType;
				DomainName = other.DomainName;
				ProcessInfo = other.ProcessInfo;
				ProcessInfoType = other.ProcessInfoType;
				IP = other.IP;
				Enabled = other.Enabled;
				OsVersion = other.OsVersion;
				Log = other.Log;
				InnerID = other.InnerID;
				InnerFlg = other.InnerFlg;
				Remark = other.Remark;

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
			root["RuleType"] = RuleType;
			root["DomainName"] = DomainName;
			root["ProcessInfo"] = ProcessInfo;
			root["ProcessInfoType"] = ProcessInfoType;
			root["IP"] = IP;
			root["Enabled"] = Enabled;
			root["OsVersion"] = OsVersion;
			root["Log"] = Log;
			root["InnerID"] = InnerID;
			root["InnerFlg"] = InnerFlg;
			root["Remark"] = Remark;

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
			DomainName = root.get("DomainName", "").asString();
			ProcessInfo = root.get("ProcessInfo", "").asString();
			ProcessInfoType = root.get("ProcessInfoType", 0).asInt();
			IP = root.get("IP", "").asString();
			Enabled = root.get("Enabled", 0).asInt();
			OsVersion = root.get("OsVersion", 0).asInt();
			Log = root.get("Log", 0).asInt();
			InnerID = root.get("InnerID", 0).asInt();
			InnerFlg = root.get("InnerFlg", 0).asInt();
			Remark = root.get("Remark", "").asString();

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