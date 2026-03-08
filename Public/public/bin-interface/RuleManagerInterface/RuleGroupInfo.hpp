/***********************************************************************
* @file    *.hpp
* @brief   规则分类定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_GROUP_INFO_DEFINE_H__
#define __RULE_GROUP_INFO_DEFINE_H__
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
	///规则分组
	///
	/*
	{
	"RuleGroupName": "分组1",
	"RuleGroupParentID": 2,
	"Disable": 1,
	"Remark": "描述"
    }
	*/

	class RuleGroupInfo {
	public:
		int RuleGroupID;
		std::string RuleGroupName;
		int RuleGroupParentID;
		int Disable;
		std::string Remark;

		RuleGroupInfo() {
			memset(this, 0, sizeof(RuleGroupInfo));
		}
		~RuleGroupInfo() {}

		RuleGroupInfo(int ruleGroupID, const std::string& ruleGroupName, int ruleGroupParentID, int disable, const std::string& remark)
			: RuleGroupID(ruleGroupID),
			RuleGroupName(ruleGroupName),
			RuleGroupParentID(ruleGroupParentID),
			Disable(disable),
			Remark(remark) {}

		RuleGroupInfo(const RuleGroupInfo& other)
			: RuleGroupID(other.RuleGroupID),
			RuleGroupName(other.RuleGroupName),
			RuleGroupParentID(other.RuleGroupParentID),
			Disable(other.Disable),
			Remark(other.Remark) {}

		RuleGroupInfo& operator=(const RuleGroupInfo& other) {
			if (this != &other) {
				RuleGroupID = other.RuleGroupID;
				RuleGroupName = other.RuleGroupName;
				RuleGroupParentID = other.RuleGroupParentID;
				Disable = other.Disable;
				Remark = other.Remark;
			}
			return *this;
		}

		void toJson(Json::Value& root) const {
			root["RuleGroupID"] = RuleGroupID;
			root["RuleGroupName"] = RuleGroupName;
			root["RuleGroupParentID"] = RuleGroupParentID;
			root["Disable"] = Disable;
			root["Remark"] = Remark;
		}

		void fromJson(const Json::Value& root) {
			RuleGroupID = root.get("RuleGroupID", 0).asInt();
			RuleGroupName = root.get("RuleGroupName", "").asString();
			RuleGroupParentID = root.get("RuleGroupParentID", 0).asInt();
			Disable = root.get("Disable", 0).asInt();
			Remark = root.get("Remark", "").asString();
		}
	};
}
#endif // 