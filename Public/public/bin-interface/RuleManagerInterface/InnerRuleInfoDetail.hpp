/***********************************************************************
* @file    *.hpp
* @brief   内部(调试)规则详情对应关系定义
* @author  geshan@hotmail.com
*/

#ifndef __INNER_RULE_INFO_DETAIL_DEFINE_H__
#define __INNER_RULE_INFO_DETAIL_DEFINE_H__
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
	///内部(调试)规则详情对应关系定义
	///
	/*
	{
		"InnerDefaultType": 1,
		"InnerDefaultID": 10,
		"DetailType": 9,
		"DetailID": 40,
		 "Reserved1":0,
		 "Reserved2":0
    }
	*/

	class InnerRuleInfoDetail {
	public:
		int InnerDefaultType;
		int InnerDefaultID;
		int DetailType;
		int DetailID;
		int Reserved1;
		int Reserved2;

		InnerRuleInfoDetail() {
			memset(this, 0, sizeof(InnerRuleInfoDetail));
		}
		~InnerRuleInfoDetail() {}
		InnerRuleInfoDetail(int inner_default_type, int inner_default_id, int detail_type, int detail_id, int reserved1, int reserved2)
			: InnerDefaultType(inner_default_type),
			InnerDefaultID(inner_default_id),
			DetailType(detail_type),
			DetailID(detail_id),
			Reserved1(reserved1),
			Reserved2(reserved2) {}

		InnerRuleInfoDetail(const InnerRuleInfoDetail& other)
			: InnerDefaultType(other.InnerDefaultType),
			InnerDefaultID(other.InnerDefaultID),
			DetailType(other.DetailType),
			DetailID(other.DetailID),
			Reserved1(other.Reserved1),
			Reserved2(other.Reserved2) {}

		InnerRuleInfoDetail& operator=(const InnerRuleInfoDetail& other) {
			if (this != &other) {
				InnerDefaultType = other.InnerDefaultType;
				InnerDefaultID = other.InnerDefaultID;
				DetailType = other.DetailType;
				DetailID = other.DetailID;
				Reserved1 = other.Reserved1;
				Reserved2 = other.Reserved2;
			}
			return *this;
		}

		///
		///对象转换成Json格式
		///
		void toJson(Json::Value& root) const {
			root["InnerDefaultType"] = InnerDefaultType;
			root["InnerDefaultID"] = InnerDefaultID;
			root["DetailType"] = DetailType;
			root["DetailID"] = DetailID;
			root["Reserved1"] = Reserved1;
			root["Reserved2"] = Reserved2;
		}

		///
		///Json格式转换成对象
		///
		void fromJson(const Json::Value& root) {
			InnerDefaultType = root.get("InnerDefaultType", 0).asInt();
			InnerDefaultID = root.get("InnerDefaultID", 0).asInt();
			DetailType = root.get("DetailType", 0).asInt();
			DetailID = root.get("DetailID", 0).asInt();
			Reserved1 = root.get("Reserved1", 0).asInt();
			Reserved2 = root.get("Reserved2", 0).asInt();
		}
	};
	
}
#endif // 