/***********************************************************************
* @file    *.hpp
* @brief   agent和规则对应关系
* @author  geshan@hotmail.com
*/

#ifndef __AGENT_ENABLED_RULE_INFO_DEFINE_H__
#define __AGENT_ENABLED_RULE_INFO_DEFINE_H__
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
	///对应关系
	///
	/*
	{
		"AgentGroupID": 22,
		"RuleType": 12,
		"RuleID": 23,
		"EnabledType":1,
		"Remark": "描述"
	}
	*/

	class AgentEnabledRuleInfo {
	public:
		int AgentGroupID;  //agent分组
		int RuleType;      //规则类型（当EnabledType为1时 表示:InnerRuleInfo的DefaultType，否则为具体规则的RuleType）
		int RuleID;        //规则ID （当EnabledType为1时 表示:InnerRuleInfo的DefaultID，否则为具体规则的ID）
		int EnabledType;   //生效类型（1：默认规则  2：自定义规则)
		int Reserved;      //预留字段
		std::string Remark;
		int CreateTime;
		int UpdateTime;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		AgentEnabledRuleInfo() {
			memset(this, 0, sizeof(AgentEnabledRuleInfo));
		}
		~AgentEnabledRuleInfo() {}
		AgentEnabledRuleInfo(int agentGroupID, int ruleType, int ruleID, int enabledType, int Reserved,const std::string& remark, int createTime, int updateTime, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: AgentGroupID(agentGroupID),
			RuleType(ruleType),
			RuleID(ruleID),
			EnabledType(enabledType),
			Reserved(Reserved),
			Remark(remark),
			CreateTime(createTime), UpdateTime(updateTime), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		AgentEnabledRuleInfo(const AgentEnabledRuleInfo& other)
			: AgentGroupID(other.AgentGroupID),
			RuleType(other.RuleType),
			RuleID(other.RuleID),
			EnabledType(other.EnabledType),
			Reserved(other.Reserved),
			Remark(other.Remark),
			CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		AgentEnabledRuleInfo& operator=(const AgentEnabledRuleInfo& other) {
			if (this != &other) {
				AgentGroupID = other.AgentGroupID;
				RuleType = other.RuleType;
				RuleID = other.RuleID;
				EnabledType = other.EnabledType;
				Reserved = other.Reserved;
				Remark = other.Remark;
				CreateTime = other.CreateTime;
				UpdateTime = other.UpdateTime;
				Reserved2 = other.Reserved2;
				Reserved3 = other.Reserved3;
				Reserved4 = other.Reserved4;
				Reserved5 = other.Reserved5;
				Reserved6 = other.Reserved6;
			}
			return *this;
		}

		void toJson(Json::Value& root) const {
			root["AgentGroupID"] = AgentGroupID;
			root["RuleType"] = RuleType;
			root["RuleID"] = RuleID;
			root["EnabledType"] = EnabledType;
			root["Reserved"] = Reserved;
			root["Remark"] = Remark;
			root["CreateTime"] = CreateTime;
			root["UpdateTime"] = UpdateTime;
			root["Reserved2"] = Reserved2;
			root["Reserved3"] = Reserved3;
			root["Reserved4"] = Reserved4;
			root["Reserved5"] = Reserved5;
			root["Reserved6"] = Reserved6;
		}

		void fromJson(const Json::Value& root) {
			AgentGroupID = root.get("AgentGroupID", 0).asInt();
			RuleType = root.get("RuleType", 0).asInt();
			RuleID = root.get("RuleID", 0).asInt();
			EnabledType = root.get("EnabledType", 0).asInt();
			Reserved = root.get("Reserved", 0).asInt();
			Remark = root.get("Remark", "").asString();
			CreateTime = root.get("CreateTime", 0).asInt();
			UpdateTime = root.get("UpdateTime", 0).asInt();
			Reserved2 = root.get("Reserved2", 0).asInt();
			Reserved3 = root.get("Reserved3", 0).asInt();
			Reserved4 = root.get("Reserved4", "").asString();
			Reserved5 = root.get("Reserved5", "").asString();
			Reserved6 = root.get("Reserved6", "").asString();
		}
	};
}
#endif // 