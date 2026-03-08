/***********************************************************************
* @file    *.hpp
* @brief   内部(调试)规则定义
* @author  geshan@hotmail.com
*/

#ifndef __INNER_RULE_INFO_DEFINE_H__
#define __INNER_RULE_INFO_DEFINE_H__
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
	///内部(调试)规则定义
	///
	/*
	{
		"DefaultID": 23,
		"Name": "基础广告",
		"DefaultType": 12,
		"DetailRuleType":9,
		"DetailRuleID":34,
		"Des": "拦截桌面广告图标、广告进程等",
		"Ver": "23.12.11",
		"Remark": "描述"
	}
	*/

	class InnerRuleInfo {
	public:
		int ID;  
		int DefaultID;      //默认规则ID(官方维护)
		int DefaultType;    //自定义规则类型(官方维护)
		std::string Name;   //自定义规则名称
		std::string Des;    //描述
		std::string Ver;    //版本
		std::string Remark; //标记

		InnerRuleInfo() {
			memset(this, 0, sizeof(InnerRuleInfo));
		}
		~InnerRuleInfo() {}

		InnerRuleInfo(int id, int defaultID, const std::string& name, int defaultType, 
			const std::string& des, const std::string& ver, const std::string& remark)
			: ID(id),
			DefaultID(defaultID),
			Name(name),
			DefaultType(defaultType),
			Des(des),
			Ver(ver),
			Remark(remark) {}

		InnerRuleInfo(const InnerRuleInfo& other)
			: ID(other.ID),
			DefaultID(other.DefaultID),
			Name(other.Name),
			DefaultType(other.DefaultType),
			Des(other.Des),
			Ver(other.Ver),
			Remark(other.Remark) {}

		InnerRuleInfo& operator=(const InnerRuleInfo& other) {
			if (this != &other) {
				ID = other.ID;
				DefaultID = other.DefaultID;
				Name = other.Name;
				DefaultType = other.DefaultType;
				Des = other.Des;
				Ver = other.Ver;
				Remark = other.Remark;
			}
			return *this;
		}

		///
		///对象转换成Json格式
		///
		void toJson(Json::Value& root) const {
			root["ID"] = ID;
			root["DefaultID"] = DefaultID;
			root["Name"] = Name;
			root["DefaultType"] = DefaultType;
			root["Des"] = Des;
			root["Ver"] = Ver;
			root["Remark"] = Remark;
		}

		///
		///Json格式转换成对象
		///
		void fromJson(const Json::Value& root) {
			ID = root.get("ID", 0).asInt();
			DefaultID = root.get("DefaultID", 0).asInt();
			Name = root.get("Name", "").asString();
			DefaultType = root.get("DefaultType", 0).asInt();
			Des = root.get("Des", "").asString();
			Ver = root.get("Ver", "").asString();
			Remark = root.get("Remark", "").asString();
		}
	};


	///自定义规则是否选择对应关系
	class InnerRuleEnabledRelation : public InnerRuleInfo {
	public:
		int AgentGroupID;  //Agent分组ID
		int Enabled;       //是否已经开启

		InnerRuleEnabledRelation() : InnerRuleInfo(), AgentGroupID(0), Enabled(0) {}

		InnerRuleEnabledRelation(int ID, int DefaultID, const std::string& Name, int DefaultType,const std::string& Des,
			const std::string& Ver, const std::string& Remark,
			int AgentGroupID, int Enabled)
			: InnerRuleInfo(ID, DefaultID, Name, DefaultType, Des, Ver, Remark),
			AgentGroupID(AgentGroupID), Enabled(Enabled) {}

		InnerRuleEnabledRelation(const InnerRuleEnabledRelation& other)
			: InnerRuleInfo(other), AgentGroupID(other.AgentGroupID), Enabled(other.Enabled) {}

		InnerRuleEnabledRelation& operator=(const InnerRuleEnabledRelation& other) {
			if (this != &other) {
				InnerRuleInfo::operator=(other);
				AgentGroupID = other.AgentGroupID;
				Enabled = other.Enabled;
			}
			return *this;
		}

		~InnerRuleEnabledRelation() {}
	};
	
}
#endif // 