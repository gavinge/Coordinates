/***********************************************************************
* @file    *.hpp
* @brief   agent详细信息
* @author  geshan@hotmail.com
*/

#ifndef __AGENT_INFO_DEFINE_H__
#define __AGENT_INFO_DEFINE_H__
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
	///agent详细信息字段
	///
	/*
	{
		"Status": 1,
		"GroupID": 2,
		"Debug": 1,
		"DisableRule": 1,
		"DisableCharge": 1,
		"DisableGameMenu": 1,
		"IsSuper": 0,
		"PcName": "WIN-2GEB8B29VGO",
		"IP": "0.0.0.0",
		"Mac": "00-0C-29-93-FD-47",
		"VersionType": 1,
		"VersionName": 7601,
		"X64": 1,
		"Cpu": "Intel(R) Core(TM) i7-9700K CPU @ 3.60GHz",
		"DisplayCard": "VMware SVGA 3D",
		"BaseBoard": "Intel Corporation 440BX Desktop Reference Platform",
		"MemorySize": "2047",
		"NetworkSpeed": 1000,
		"Logincs": 0,
		"Drvlog": 0,
		"BootTime": 410,
		"Token": "svYqy78p2r",
		"Ver": "Aug 17 2020 01:28:43"
    }

	{
	"issuper": 0,
	"pcname": "DESKTOP-KFNP15Q",
	"ip": "192.168.56.161",
	"mac": "00-0c-29-14-a4-f4",
	"versiontype": 2,
	"versionname": 19045,
	"x64": 1,
	"cpu": "13th Gen Intel(R) Core(TM) i7-13700HX",
	"displaycard": "VMware SVGA 3D",
	"baseboard": "",
	"memorysize": "8031",
	"networkspeed": 1000,
	"logincs": 0,
	"drvlog": 0,
	"boottime": 152,
	"token": "RSNHq5",
	"ver": "Aug 17 2023 01:28:43",
	"groupname": ""
	}
	*/

	class AgentInfo {
	public:
		int ID;
		std::string Mid;
		int Status;
		int GroupID;
		int Debug;
		int DisableRule;      //禁止全部规则
		int DisableInnerRule; //禁止调试规则
		int DisableCustomRule;//禁止防御规则
		int DisableCharge;    //禁止计费
		int DisableGameMenu;  //禁止游戏菜单
		int IsSuper;          //超级无盘
		std::string PcName;
		std::string IP;     
		std::string Mac;
		int VersionType;
		int VersionName;
		int X64;
		std::string Cpu;
		std::string DisplayCard;
		std::string BaseBoard;
		std::string MemorySize;
		int NetworkSpeed;
		int Logincs;
		int Drvlog;
		int BootTime;
		std::string Token;
		std::string Ver;

		int CreateTime;
		int UpdateTime;
		int Reserved1;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		AgentInfo() {
			memset(this, 0, sizeof(AgentInfo));
		}
		~AgentInfo() {}

		AgentInfo(int id,const std::string& mid, int status, int groupID, int debug, int disableRule,int disableInnerRule,int disableCustomRule, int disableCharge, int disableGameMenu,
			int isSuper, const std::string& pcName, const std::string& ip, const std::string& mac, int versionType,
			int versionName, int x64, const std::string& cpu, const std::string& displayCard,
			const std::string& baseBoard, const std::string& memorySize, int networkSpeed, int logincs, int drvlog,
			int bootTime, const std::string& token, const std::string& ver,
			int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: ID(id), Mid(mid), Status(status), GroupID(groupID), Debug(debug), DisableRule(disableRule), DisableInnerRule(disableInnerRule), DisableCustomRule(disableCustomRule), DisableCharge(disableCharge),
			DisableGameMenu(disableGameMenu), IsSuper(isSuper), PcName(pcName), IP(ip), Mac(mac),
			VersionType(versionType), VersionName(versionName), X64(x64), Cpu(cpu), DisplayCard(displayCard),
			BaseBoard(baseBoard), MemorySize(memorySize), NetworkSpeed(networkSpeed), Logincs(logincs),
			Drvlog(drvlog), BootTime(bootTime), Token(token), Ver(ver),
			CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		AgentInfo(const AgentInfo& other)
			: ID(other.ID),Mid(other.Mid), Status(other.Status), GroupID(other.GroupID), Debug(other.Debug),
			DisableRule(other.DisableRule), DisableInnerRule(other.DisableInnerRule), DisableCustomRule(other.DisableCustomRule), DisableCharge(other.DisableCharge),
			DisableGameMenu(other.DisableGameMenu), IsSuper(other.IsSuper), PcName(other.PcName),
			IP(other.IP), Mac(other.Mac), VersionType(other.VersionType), VersionName(other.VersionName),
			X64(other.X64), Cpu(other.Cpu), DisplayCard(other.DisplayCard), BaseBoard(other.BaseBoard),
			MemorySize(other.MemorySize), NetworkSpeed(other.NetworkSpeed), Logincs(other.Logincs),
			Drvlog(other.Drvlog), BootTime(other.BootTime), Token(other.Token), Ver(other.Ver),
			CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		AgentInfo& operator=(const AgentInfo& other) {
			if (this != &other) {
				ID = other.ID;
				Mid = other.Mid;
				Status = other.Status;
				GroupID = other.GroupID;
				Debug = other.Debug;
				DisableRule = other.DisableRule;
				DisableInnerRule = other.DisableInnerRule;
				DisableCustomRule = other.DisableCustomRule;
				DisableCharge = other.DisableCharge;
				DisableGameMenu = other.DisableGameMenu;
				IsSuper = other.IsSuper;
				PcName = other.PcName;
				IP = other.IP;
				Mac = other.Mac;
				VersionType = other.VersionType;
				VersionName = other.VersionName;
				X64 = other.X64;
				Cpu = other.Cpu;
				DisplayCard = other.DisplayCard;
				BaseBoard = other.BaseBoard;
				MemorySize = other.MemorySize;
				NetworkSpeed = other.NetworkSpeed;
				Logincs = other.Logincs;
				Drvlog = other.Drvlog;
				BootTime = other.BootTime;
				Token = other.Token;
				Ver = other.Ver;

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
			root["ID"] = ID;
			root["Mid"] = Mid;
			root["Status"] = Status;
			root["GroupID"] = GroupID;
			root["Debug"] = Debug;
			root["DisableRule"] = DisableRule;
			root["DisableInnerRule"] = DisableInnerRule;
			root["DisableCustomRule"] = DisableCustomRule;
			root["DisableCharge"] = DisableCharge;
			root["DisableGameMenu"] = DisableGameMenu;
			root["IsSuper"] = IsSuper;
			root["PcName"] = PcName;
			root["IP"] = IP;
			root["Mac"] = Mac;
			root["VersionType"] = VersionType;
			root["VersionName"] = VersionName;
			root["X64"] = X64;
			root["Cpu"] = Cpu;
			root["DisplayCard"] = DisplayCard;
			root["BaseBoard"] = BaseBoard;
			root["MemorySize"] = MemorySize;
			root["NetworkSpeed"] = NetworkSpeed;
			root["Logincs"] = Logincs;
			root["Drvlog"] = Drvlog;
			root["BootTime"] = BootTime;
			root["Token"] = Token;
			root["Ver"] = Ver;

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
				ID = root.isMember("ID") ? root.get("ID", 0).asInt() : 0;
				Mid = root.isMember("Mid") ? root.get("Mid", "").asString() : "";
				Status = root.isMember("Status") ? root.get("Status", 0).asInt() : 0;
				GroupID = root.isMember("GroupID") ? root.get("GroupID", 0).asInt() : 0;
				Debug = root.isMember("Debug") ? root.get("Debug", 0).asInt() : 0;
				DisableRule = root.isMember("DisableRule") ? root.get("DisableRule", 0).asInt() : 0;
				DisableInnerRule = root.isMember("DisableInnerRule") ? root.get("DisableInnerRule", 0).asInt() : 0;
				DisableCustomRule = root.isMember("DisableCustomRule") ? root.get("DisableCustomRule", 0).asInt() : 0;
				DisableCharge = root.isMember("DisableCharge") ? root.get("DisableCharge", 0).asInt() : 0;
				DisableGameMenu = root.isMember("DisableGameMenu") ? root.get("DisableGameMenu", 0).asInt() : 0;
				IsSuper = root.isMember("issuper") ? root.get("issuper", 0).asInt() : 0;
				PcName = root.isMember("pcname") ? root.get("pcname", "").asString() : "";
				IP = root.isMember("ip") ? root.get("ip", "").asString() : "";
				Mac = root.isMember("mac") ? root.get("mac", "").asString() : "";
				VersionType = root.isMember("versiontype") ? root.get("versiontype", 0).asInt() : 0;
				VersionName = root.isMember("versionname") ? root.get("versionname", 0).asInt() : 0;
				X64 = root.isMember("x64") ? root.get("x64", 0).asInt() : 0;
				Cpu = root.isMember("cpu") ? root.get("cpu", "").asString() : "";
				DisplayCard = root.isMember("displaycard") ? root.get("displaycard", "").asString() : "";
				BaseBoard = root.isMember("baseboard") ? root.get("baseboard", "").asString() : "";
				MemorySize = root.isMember("memorysize") ? root.get("memorysize", "").asString() : "";
				NetworkSpeed = root.isMember("networkspeed") ? root.get("networkspeed", 0).asInt() : 0;
				Logincs = root.isMember("logincs") ? root.get("logincs", 0).asInt() : 0;
				Drvlog = root.isMember("drvlog") ? root.get("drvlog", 0).asInt() : 0;
				BootTime = root.isMember("boottime") ? root.get("boottime", 0).asInt() : 0;
				Token = root.isMember("token") ? root.get("token", "").asString() : "";
				Ver = root.isMember("ver") ? root.get("ver", "").asString() : "";
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