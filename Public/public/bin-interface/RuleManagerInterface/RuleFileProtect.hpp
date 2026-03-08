/***********************************************************************
* @file    *.hpp
* @brief  文件防御规则定义
* @author  geshan@hotmail.com
*/

#ifndef __RULE_FILE_PROTECT_DEFINE_H__
#define __RULE_FILE_PROTECT_DEFINE_H__
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
	///文件防御规则
	///
	/*
	{
		"OperationCode": 0,
		"RuleType": 2,
		"ProcessInfo": "*cmd.exe",
		"ProcessInfoType": 0,
		"FileInfo": "*123.txt",
		"FileInfoType": 0,
		"Enabled": 1,
		"Log": 1,
		"Remark": "123123123123123123123123123123123123123123",
		"Options": 222,
		"OsVersion": 3
	}
	*/


	class RuleFileProtect {
	public:
		int RID;                 //主键
		int RuleGroupID;         //规则分类ID，暂不用
		int OperationCode;       //处置码
		int RuleType;            //规则类，这个固定死。
		int ProcessInfoType;       
		std::string ProcessInfo;
		int FileInfoType;
		std::string FileInfo;
		int Enabled;             //生效标记， ==1：表示生效
		int Log;
		std::string Remark;
		int Options;
		int OsVersion;
		int InnerID;             //内部ID(官方维护)
		int InnerFlg;            //内部标记(官方维护)  ==0：表示内部标记。 ==1：表示用户自定义标记。

		int Priority;
		int CreateTime;
		int UpdateTime;
		int Reserved1;
		int Reserved2;
		int Reserved3;
		std::string Reserved4;
		std::string Reserved5;
		std::string Reserved6;

		RuleFileProtect() {
			memset(this, 0, sizeof(RuleFileProtect));
		}
		~RuleFileProtect() {}

		RuleFileProtect(int rid, int ruleGroupID, int operation_code, int rule_type, int process_info_type,
			const std::string& process_info, int file_info_type, const std::string& file_info,
			int enabled, int log, const std::string& remark, int options, int os_version, int innerID, int inner_flg, int priority, int createTime, int updateTime, int reserved1, int reserved2, int reserved3, const std::string& reserved4, const std::string& reserved5, const std::string& reserved6)
			: RID(rid),
			RuleGroupID(ruleGroupID),
			OperationCode(operation_code),
			RuleType(rule_type),
			ProcessInfoType(process_info_type),
			ProcessInfo(process_info),
			FileInfoType(file_info_type),
			FileInfo(file_info),
			Enabled(enabled),
			Log(log),
			Remark(remark),
			Options(options),
			InnerID(innerID),
			InnerFlg(inner_flg),
			OsVersion(os_version), Priority(priority), CreateTime(createTime), UpdateTime(updateTime), Reserved1(reserved1), Reserved2(reserved2), Reserved3(reserved3), Reserved4(reserved4), Reserved5(reserved5), Reserved6(reserved6) {}

		RuleFileProtect(const RuleFileProtect& other)
			: RID(other.RID),
			RuleGroupID(other.RuleGroupID),
			OperationCode(other.OperationCode),
			RuleType(other.RuleType),
			ProcessInfoType(other.ProcessInfoType),
			ProcessInfo(other.ProcessInfo),
			FileInfoType(other.FileInfoType),
			FileInfo(other.FileInfo),
			Enabled(other.Enabled),
			Log(other.Log),
			Remark(other.Remark),
			Options(other.Options),
			InnerID(other.InnerID),
			InnerFlg(other.InnerFlg),
			OsVersion(other.OsVersion), Priority(other.Priority), CreateTime(other.CreateTime), UpdateTime(other.UpdateTime), Reserved1(other.Reserved1), Reserved2(other.Reserved2), Reserved3(other.Reserved3), Reserved4(other.Reserved4), Reserved5(other.Reserved5), Reserved6(other.Reserved6) {}

		RuleFileProtect& operator=(const RuleFileProtect& other) {
			if (this != &other) {
				RID = other.RID;
				RuleGroupID = other.RuleGroupID;
				OperationCode = other.OperationCode;
				RuleType = other.RuleType;
				ProcessInfoType = other.ProcessInfoType;
				ProcessInfo = other.ProcessInfo;
				FileInfoType = other.FileInfoType;
				FileInfo = other.FileInfo;
				Enabled = other.Enabled;
				Log = other.Log;
				Remark = other.Remark;
				Options = other.Options;
				InnerID = other.InnerID;
				InnerFlg = other.InnerFlg;
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
			root["ProcessInfoType"] = ProcessInfoType;
			root["ProcessInfo"] = ProcessInfo;
			root["FileInfoType"] = FileInfoType;
			root["FileInfo"] = FileInfo;
			root["Enabled"] = Enabled;
			root["Log"] = Log;
			root["Remark"] = Remark;
			root["Options"] = Options;
			root["OsVersion"] = OsVersion;
			root["InnerID"] = InnerID;
			root["InnerFlg"] = InnerFlg;

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
			ProcessInfoType = root.get("ProcessInfoType", 0).asInt();
			ProcessInfo = root.get("ProcessInfo", "").asString();
			FileInfoType = root.get("FileInfoType", 0).asInt();
			FileInfo = root.get("FileInfo", "").asString();
			Enabled = root.get("Enabled", 0).asInt();
			Log = root.get("Log", 0).asInt();
			Remark = root.get("Remark", "").asString();
			Options = root.get("Options", 0).asInt();
			OsVersion = root.get("OsVersion", 0).asInt();
			InnerID = root.get("InnerID", 0).asInt();
			InnerFlg = root.get("InnerFlg", 0).asInt();

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