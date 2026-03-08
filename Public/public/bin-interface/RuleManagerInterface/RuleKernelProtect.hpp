/***********************************************************************
* @file    *.hpp
* @brief   内核模块防御规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_KELNEL_PROTECT_DEFINE_H__
#define __RULE_KELNEL_PROTECT_DEFINE_H__
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
	///内核模块防御规则
	///
	/*
	{
	  "RuleType": 4,
	  "DriverInfoType": 0,
	  "DriverInfo": "*123",
	  "OperationCode": 0,
	  "Enabled": 1,
	  "Log": 1,
	  "Remark": "123123123123123123123123123123",
	  "OsVersion": 3
	}
	*/

	class RuleKernelProtect {
	public:
		int RID;
		int RuleGroupID;
		int RuleType;
		int DriverInfoType;
		std::string DriverInfo;
		int OperationCode;
		int InnerID;
		int InnerFlg;
		int Enabled;
		int Log;
		std::string Remark;
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

		RuleKernelProtect() {
			memset(this, 0, sizeof(RuleKernelProtect));
		}
		~RuleKernelProtect() {}

		RuleKernelProtect(int rid, int ruleGroupID, int rule_type, int driver_info_type, const std::string& driver_info,
			int operation_code, int innerID, int innerFlg, int enabled, int log, const std::string& remark, int os_version, int priority, int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: RID(rid),
			RuleGroupID(ruleGroupID),
			RuleType(rule_type),
			DriverInfoType(driver_info_type),
			DriverInfo(driver_info),
			OperationCode(operation_code),
			InnerID(innerID),
			InnerFlg(innerFlg),
			Enabled(enabled),
			Log(log),
			Remark(remark),
			OsVersion(os_version), Priority(priority), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		RuleKernelProtect(const RuleKernelProtect& other)
			: RID(other.RID),
			RuleGroupID(other.RuleGroupID),
			RuleType(other.RuleType),
			DriverInfoType(other.DriverInfoType),
			DriverInfo(other.DriverInfo),
			OperationCode(other.OperationCode),
			InnerID(other.InnerID),
			InnerFlg(other.InnerFlg),
			Enabled(other.Enabled),
			Log(other.Log),
			Remark(other.Remark),
			OsVersion(other.OsVersion), Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleKernelProtect& operator=(const RuleKernelProtect& other) {
			if (this != &other) {
				RID = other.RID;
				RuleGroupID = other.RuleGroupID;
				RuleType = other.RuleType;
				DriverInfoType = other.DriverInfoType;
				DriverInfo = other.DriverInfo;
				OperationCode = other.OperationCode;
				InnerID = other.InnerID;
				InnerFlg = other.InnerFlg;
				Enabled = other.Enabled;
				Log = other.Log;
				Remark = other.Remark;
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
			root["RuleType"] = RuleType;
			root["DriverInfoType"] = DriverInfoType;
			root["DriverInfo"] = DriverInfo;
			root["OperationCode"] = OperationCode;
			root["InnerID"] = InnerID;
			root["InnerFlg"] = InnerFlg;
			root["Enabled"] = Enabled;
			root["Log"] = Log;
			root["Remark"] = Remark;
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
			DriverInfoType = root.get("DriverInfoType", 0).asInt();
			DriverInfo = root.get("DriverInfo", "").asString();
			OperationCode = root.get("OperationCode", 0).asInt();
			InnerID = root.get("InnerID", 0).asInt();
			InnerFlg = root.get("InnerFlg", 0).asInt();
			Enabled = root.get("Enabled", 0).asInt();
			Log = root.get("Log", 0).asInt();
			Remark = root.get("Remark", "").asString();
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