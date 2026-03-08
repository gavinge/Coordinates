/***********************************************************************
* @file    *.h
* @brief   进程创建防御规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_PROCESS_CREATION_DEFINE_H__
#define __RULE_PROCESS_CREATION_DEFINE_H__
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
	///进程创建防御规则
	///

	/*
	{
		"OperationCode": 0,
		"RuleType": 1,
		"ChildProcessInfoType": 0,
		"ChildProcessInfo": "*calc.exe",
		"ParentProcessInfoType": 0,
		"ParentProcessInfo": "*",
		"Enabled": 1,
		"Log": 1,
		"Remark": "123123123123123123123123",
		"OsVersion": 3
	}
	*/
	class RuleProcessCreation {
	public:
		int RID;
		int RuleGroupID;  
		int OperationCode;
		int RuleType;
		int ChildProcessInfoType;
		std::string ChildProcessInfo;
		int ParentProcessInfoType;
		std::string ParentProcessInfo;
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

		RuleProcessCreation() {
			memset(this, 0, sizeof(RuleProcessCreation));
		}
		~RuleProcessCreation() {}
		RuleProcessCreation(int rid, int rule_group_id, int operation_code, int rule_type, int child_process_info_type, const std::string& child_process_info,
			int parent_process_info_type, const std::string& parent_process_info, int inner_ID, int inner_flg, int enabled, int log,
			const std::string& remark, int os_version, int priority, int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: RID(rid),
			RuleGroupID(rule_group_id),
			OperationCode(operation_code),
			RuleType(rule_type),
			ChildProcessInfoType(child_process_info_type),
			ChildProcessInfo(child_process_info),
			ParentProcessInfoType(parent_process_info_type),
			ParentProcessInfo(parent_process_info),
			InnerID(inner_ID),
			InnerFlg(inner_flg),
			Enabled(enabled),
			Log(log),
			Remark(remark),
			OsVersion(os_version), Priority(priority), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		RuleProcessCreation(const RuleProcessCreation& other)
			: RID(other.RID),
			RuleGroupID(other.RuleGroupID),
			OperationCode(other.OperationCode),
			RuleType(other.RuleType),
			ChildProcessInfoType(other.ChildProcessInfoType),
			ChildProcessInfo(other.ChildProcessInfo),
			ParentProcessInfoType(other.ParentProcessInfoType),
			ParentProcessInfo(other.ParentProcessInfo),
			InnerID(other.InnerID),
			InnerFlg(other.InnerFlg),
			Enabled(other.Enabled),
			Log(other.Log),
			Remark(other.Remark),
			OsVersion(other.OsVersion), Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleProcessCreation& operator=(const RuleProcessCreation& other) {
			if (this != &other) {
				RID = other.RID;
				RuleGroupID = other.RuleGroupID;
				OperationCode = other.OperationCode;
				RuleType = other.RuleType;
				ChildProcessInfoType = other.ChildProcessInfoType;
				ChildProcessInfo = other.ChildProcessInfo;
				ParentProcessInfoType = other.ParentProcessInfoType;
				ParentProcessInfo = other.ParentProcessInfo;
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
			root["OperationCode"] = OperationCode;
			root["RuleType"] = RuleType;
			root["ChildProcessInfoType"] = ChildProcessInfoType;
			root["ChildProcessInfo"] = ChildProcessInfo;
			root["ParentProcessInfoType"] = ParentProcessInfoType;
			root["ParentProcessInfo"] = ParentProcessInfo;
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
			OperationCode = root.get("OperationCode", 0).asInt();
			RuleType = root.get("RuleType", 0).asInt();
			ChildProcessInfoType = root.get("ChildProcessInfoType", 0).asInt();
			ChildProcessInfo = root.get("ChildProcessInfo", "").asString();
			ParentProcessInfoType = root.get("ParentProcessInfoType", 0).asInt();
			ParentProcessInfo = root.get("ParentProcessInfo", "").asString();
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