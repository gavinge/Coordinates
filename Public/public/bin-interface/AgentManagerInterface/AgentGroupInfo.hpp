/***********************************************************************
* @file    *.hpp
* @brief   agent分组详细信息
* @author  geshan@hotmail.com
*/

#ifndef __AGENT_GROUP_INFO_DEFINE_H__
#define __AGENT_GROUP_INFO_DEFINE_H__
#ifdef _WIN32
#pragma once
#endif

#include <iostream>
#include <vector>
#include <string>

#include "jsoncpp\json.h"


namespace AgentManagement
{
	///
	///agent分组信息字段
	///
	/*
	{
	"GroupName": "分组1",
	"GroupParentID": 2,
	"Disable": 1,
	"Remark": "描述"
    }
	*/

	class AgentGroupInfo {
	public:
		int GroupID;
		std::string GroupName;
		int GroupParentID;
		int Disable;
		std::string Remark;

		int CreateTime;
		int UpdateTime;
		int Reserved1;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		AgentGroupInfo() {
			memset(this, 0, sizeof(AgentGroupInfo));
		}
		AgentGroupInfo(int groupID, const std::string& groupName, int groupParentID, int disable, const std::string& remark,int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: GroupID(groupID), GroupName(groupName), GroupParentID(groupParentID), Disable(disable), Remark(remark), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6)
			{}

		AgentGroupInfo(const AgentGroupInfo& other)
			: GroupID(other.GroupID), GroupName(other.GroupName), GroupParentID(other.GroupParentID), Disable(other.Disable), Remark(other.Remark),
			CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		AgentGroupInfo& operator=(const AgentGroupInfo& other) {
			if (this != &other) {
				GroupID = other.GroupID;
				GroupName = other.GroupName;
				GroupParentID = other.GroupParentID;
				Disable = other.Disable;
				Remark = other.Remark;
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
			root["GroupID"] = GroupID;
			root["GroupName"] = GroupName;
			root["GroupParentID"] = GroupParentID;
			root["Disable"] = Disable;
			root["Remark"] = Remark;
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
			GroupID = root.isMember("GroupID") ? root.get("GroupID", 0).asInt() : 0;
			GroupName = root.isMember("GroupName") ? root.get("GroupName", "").asString() : "";
			GroupParentID = root.isMember("GroupParentID") ? root.get("GroupParentID", 0).asInt() : 0;
			Disable = root.isMember("Disable") ? root.get("Disable", 0).asInt() : 0;
			Remark = root.isMember("Remark") ? root.get("Remark", "").asString() : "";
			CreateTime = root.isMember("CreateTime") ? root.get("CreateTime", 0).asInt() : 0;
			UpdateTime = root.isMember("UpdateTime") ? root.get("UpdateTime", 0).asInt() : 0;
			Reserved1 = root.isMember("Reserved1") ? root.get("Reserved1", 0).asInt() : 0;
			Reserved2 = root.isMember("Reserved2") ? root.get("Reserved2", 0).asInt() : 0;
			Reserved3 = root.isMember("Reserved3") ? root.get("Reserved3", 0).asInt() : 0;
			Reserved4 = root.isMember("Reserved4") ? root.get("Reserved4", "").asString() : "";
			Reserved5 = root.isMember("Reserved5") ? root.get("Reserved5", "").asString() : "";
			Reserved6 = root.isMember("Reserved6") ? root.get("Reserved6", "").asString() : "";
		}
	};

}
#endif // 