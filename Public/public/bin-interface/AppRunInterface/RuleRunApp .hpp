/***********************************************************************
* @file    *.hpp
* @brief   维护通道规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_RUN_APP_DEFINE_H__
#define __RULE_RUN_APP_DEFINE_H__
#ifdef _WIN32
#pragma once
#endif

#include <iostream>
#include <vector>
#include <string>

#include "jsoncpp\json.h"


namespace AppRunManagement
{
	///
	///域名防御规则
	///
	/*
	{
	  "StartIp": "0.0.0.0",
	  "Enabled": 1,
	  "Name": "KmdManager_En.exe",
	  "Type": 1,
	  "Data": "25f3e6cea332d0acf143c6f91aa97aed",
	  "DelayTime": 4,
	  "Remark": "222222222222222",
	  "IsShow": 1,
	  "RuleType": 12,
	  "RunTime": "",
	  "EndIp": "255.255.255.255",
	  "ModifyTime": "2021-05-18 00:45:32",
	  "OsVersion": 3,
	  "IsMD5": 1
	}
	*/

	class RuleRunApp {
	public:
		int TID;
		std::string StartIp;
		int Enabled;
		std::string Name;
		int Type;
		std::string Data;
		int DelayTime;
		std::string Remark;
		int IsShow;
		int RuleType;
		std::string RunTime;
		std::string EndIp;
		std::string ModifyTime;
		int OsVersion;
		int IsMD5;

		int Priority;
		int CreateTime;
		int UpdateTime;
		int Reserved1;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		RuleRunApp() {
			memset(this, 0, sizeof(RuleRunApp));
		}
		~RuleRunApp() {}
		RuleRunApp(int tid, const std::string& startIp, int enabled, const std::string& name, int type,
			const std::string& data, int delayTime, const std::string& remark, int isShow, int ruleType,
			const std::string& runTime, const std::string& endIp, const std::string& modifyTime, int osVersion, int isMD5,
			int priority, int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: TID(tid), StartIp(startIp), Enabled(enabled), Name(name), Type(type), Data(data),
			DelayTime(delayTime), Remark(remark), IsShow(isShow), RuleType(ruleType),
			RunTime(runTime), EndIp(endIp), ModifyTime(modifyTime), OsVersion(osVersion), IsMD5(isMD5),
			Priority(priority), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		RuleRunApp(const RuleRunApp& other)
			: TID(other.TID), StartIp(other.StartIp), Enabled(other.Enabled), Name(other.Name),
			Type(other.Type), Data(other.Data), DelayTime(other.DelayTime), Remark(other.Remark),
			IsShow(other.IsShow), RuleType(other.RuleType), RunTime(other.RunTime),
			EndIp(other.EndIp), ModifyTime(other.ModifyTime), OsVersion(other.OsVersion), IsMD5(other.IsMD5),
			Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleRunApp& operator=(const RuleRunApp& other) {
			if (this != &other) {
				TID = other.TID;
				StartIp = other.StartIp;
				Enabled = other.Enabled;
				Name = other.Name;
				Type = other.Type;
				Data = other.Data;
				DelayTime = other.DelayTime;
				Remark = other.Remark;
				IsShow = other.IsShow;
				RuleType = other.RuleType;
				RunTime = other.RunTime;
				EndIp = other.EndIp;
				ModifyTime = other.ModifyTime;
				OsVersion = other.OsVersion;
				IsMD5 = other.IsMD5;

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
			root["TID"] = TID;
			root["StartIp"] = StartIp;
			root["Enabled"] = Enabled;
			root["Name"] = Name;
			root["Type"] = Type;
			root["Data"] = Data;
			root["DelayTime"] = DelayTime;
			root["Remark"] = Remark;
			root["IsShow"] = IsShow;
			root["RuleType"] = RuleType;
			root["RunTime"] = RunTime;
			root["EndIp"] = EndIp;
			root["ModifyTime"] = ModifyTime;
			root["OsVersion"] = OsVersion;
			root["IsMD5"] = IsMD5;

			root["Priority"] = Priority;
			root["CreateTime"] = CreateTime;
			root["UpdateTime"] = UpdateTime;
			root["Reserved1"] = Reserved1;
			root["Reserved2"] = Reserved2;
			root["Reserved3"] = Reserved3;
			root["Reserved4"] = Reserved4;
			root["Reserved5"] = Reserved5;
			root["Reserved6"] = Reserved6;
		}

		void fromJson(const Json::Value& root) {
			TID = root.get("TID", 0).asInt();
			StartIp = root.get("StartIp", "").asString();
			Enabled = root.get("Enabled", 0).asInt();
			Name = root.get("Name", "").asString();
			Type = root.get("Type", 0).asInt();
			Data = root.get("Data", "").asString();
			DelayTime = root.get("DelayTime", 0).asInt();
			Remark = root.get("Remark", "").asString();
			IsShow = root.get("IsShow", 0).asInt();
			RuleType = root.get("RuleType", 0).asInt();
			RunTime = root.get("RunTime", "").asString();
			EndIp = root.get("EndIp", "").asString();
			ModifyTime = root.get("ModifyTime", "").asString();
			OsVersion = root.get("OsVersion", 0).asInt();
			IsMD5 = root.get("IsMD5", 0).asInt();
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