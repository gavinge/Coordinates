/***********************************************************************
* @file    *.h
* @brief   规则下发数据组装
* @author  geshan@hotmail.com
*/

#ifndef __RULE_DELIVER_ENCAPSULATION_H__
#define __RULE_DELIVER_ENCAPSULATION_H__


#include <iostream>
#include <vector>
#include <string>
#include <jsoncpp/json.h>


class RuleDetail {
public:
	int Enabled;
	std::string StartIp;
	std::string EndIp;
	int RuleType;
	int IsPlugin;
	int Source;
	std::string Content;

	RuleDetail() : Enabled(0), RuleType(0), IsPlugin(0), Source(0) {}

	RuleDetail(const RuleDetail& other)
		: Enabled(other.Enabled), StartIp(other.StartIp), EndIp(other.EndIp),
		RuleType(other.RuleType), IsPlugin(other.IsPlugin), Source(other.Source),
		Content(other.Content) {}

	RuleDetail& operator=(const RuleDetail& other) {
		if (this != &other) {
			Enabled = other.Enabled;
			StartIp = other.StartIp;
			EndIp = other.EndIp;
			RuleType = other.RuleType;
			IsPlugin = other.IsPlugin;
			Source = other.Source;
			Content = other.Content;
		}
		return *this;
	}

	void fromJson(const Json::Value& root) {
		Enabled = root.get("Enabled", 0).asInt();
		StartIp = root.get("StartIp", "").asString();
		EndIp = root.get("EndIp", "").asString();
		RuleType = root.get("ruletype", 0).asInt();
		IsPlugin = root.get("isplugin", 0).asInt();
		Source = root.get("source", 0).asInt();
		Content = root.get("content", "").asString();
	}
	void toJson(Json::Value& root) const {
		root["Enabled"] = Enabled;
		root["StartIp"] = StartIp;
		root["EndIp"] = EndIp;
		root["ruletype"] = RuleType;
		root["isplugin"] = IsPlugin;
		root["source"] = Source;
		root["content"] = Content;
	}
};

class PluginDetail {
public:
	std::string PlugMark;
	std::string FileMD5;
	std::string ProcessValue;
	std::string Parameter;
	std::string FileFullPath;
	std::string Comm;
	std::vector<std::string> MoreProcess;
	int FileType;
	int ProcessType;
	int DelayTime;
	int RunOnce;
	int ProcessOptions;

	PluginDetail() : FileType(0), ProcessType(0), DelayTime(0), RunOnce(0), ProcessOptions(0) {}

	PluginDetail(const PluginDetail& other)
		: PlugMark(other.PlugMark), FileMD5(other.FileMD5), ProcessValue(other.ProcessValue),
		Parameter(other.Parameter), FileFullPath(other.FileFullPath), Comm(other.Comm),
		MoreProcess(other.MoreProcess), FileType(other.FileType), ProcessType(other.ProcessType),
		DelayTime(other.DelayTime), RunOnce(other.RunOnce), ProcessOptions(other.ProcessOptions) {}

	PluginDetail& operator=(const PluginDetail& other) {
		if (this != &other) {
			PlugMark = other.PlugMark;
			FileMD5 = other.FileMD5;
			ProcessValue = other.ProcessValue;
			Parameter = other.Parameter;
			FileFullPath = other.FileFullPath;
			Comm = other.Comm;
			MoreProcess = other.MoreProcess;
			FileType = other.FileType;
			ProcessType = other.ProcessType;
			DelayTime = other.DelayTime;
			RunOnce = other.RunOnce;
			ProcessOptions = other.ProcessOptions;
		}
		return *this;
	}

	void fromJson(const Json::Value& root) {
		PlugMark = root.get("plugmark", "").asString();
		FileMD5 = root.get("file_md5", "").asString();
		ProcessValue = root.get("processvalue", "").asString();
		Parameter = root.get("parameter", "").asString();
		FileFullPath = root.get("filefullpath", "").asString();
		Comm = root.get("comm", "").asString();
		FileType = root.get("filetype", 0).asInt();
		ProcessType = root.get("processtype", 0).asInt();
		DelayTime = root.get("delaytime", 0).asInt();
		RunOnce = root.get("runonce", 0).asInt();
		ProcessOptions = root.get("processoptions", 0).asInt();

		const Json::Value& moreProcess = root["moreprocess"];
		for (const auto& val : moreProcess) {
			MoreProcess.push_back(val.asString());
		}
	}

	void toJson(Json::Value& root) const {
		root["plugmark"] = PlugMark;
		root["file_md5"] = FileMD5;
		root["processvalue"] = ProcessValue;
		root["parameter"] = Parameter;
		root["filefullpath"] = FileFullPath;
		root["comm"] = Comm;

		Json::Value processArray;
		for (const auto& process : MoreProcess) {
			processArray.append(process);
		}
		root["moreprocess"] = processArray;

		root["filetype"] = FileType;
		root["processtype"] = ProcessType;
		root["delaytime"] = DelayTime;
		root["runonce"] = RunOnce;
		root["processoptions"] = ProcessOptions;
	}
};

class RuleEncapsulation {
public:
	int isrun;
	std::string ip;
	int isdebug;
	int userid;
	int barid;
	int pcid;
	int isrunpm;
	int isrulelog;
	int timestamp;
	std::vector<RuleDetail> rule;
	std::vector<PluginDetail> plugin;

	RuleEncapsulation() : isrun(0), isdebug(0), userid(0), barid(0), pcid(0), isrunpm(0), isrulelog(0), timestamp(0) {}

	RuleEncapsulation(const RuleEncapsulation& other)
		: isrun(other.isrun), ip(other.ip), isdebug(other.isdebug), userid(other.userid), barid(other.barid),
		pcid(other.pcid), isrunpm(other.isrunpm), isrulelog(other.isrulelog), timestamp(other.timestamp),
		rule(other.rule), plugin(other.plugin) {}

	RuleEncapsulation& operator=(const RuleEncapsulation& other) {
		if (this != &other) {
			isrun = other.isrun;
			ip = other.ip;
			isdebug = other.isdebug;
			userid = other.userid;
			barid = other.barid;
			pcid = other.pcid;
			isrunpm = other.isrunpm;
			isrulelog = other.isrulelog;
			timestamp = other.timestamp;
			rule = other.rule;
			plugin = other.plugin;
		}
		return *this;
	}
	~RuleEncapsulation() {}

	void fromJson(const Json::Value& root) {
		isrun = root.get("isrun", 0).asInt();
		ip = root.get("ip", "").asString();
		isdebug = root.get("isdebug", 0).asInt();
		userid = root.get("userid", 0).asInt();
		barid = root.get("barid", 0).asInt();
		pcid = root.get("pcid", 0).asInt();
		isrunpm = root.get("isrunpm", 0).asInt();
		isrulelog = root.get("isrulelog", 0).asInt();
		timestamp = root.get("timestamp", 0).asInt();

		const Json::Value& rulesJson = root["rule"];
		for (const auto& val : rulesJson) {
			RuleDetail r;
			r.fromJson(val);
			rule.push_back(r);
		}

		const Json::Value& pluginsJson = root["plugin"];
		for (const auto& val : pluginsJson) {
			PluginDetail p;
			p.fromJson(val);
			plugin.push_back(p);
		}
	}

	void toJson(Json::Value& root) const {
		root["isrun"] = isrun;
		root["ip"] = ip;
		root["isdebug"] = isdebug;
		root["userid"] = userid;
		root["barid"] = barid;
		root["pcid"] = pcid;
		root["isrunpm"] = isrunpm;
		root["isrulelog"] = isrulelog;
		root["timestamp"] = timestamp;

		Json::Value rulesArray;
		for (const auto& r : rule) {
			Json::Value ruleJson;
			r.toJson(ruleJson);
			rulesArray.append(ruleJson);
		}
		root["rule"] = rulesArray;

		Json::Value pluginsArray;
		for (const auto& p : plugin) {
			Json::Value pluginJson;
			p.toJson(pluginJson);
			pluginsArray.append(pluginJson);
		}
		root["plugin"] = pluginsArray;
	}
};



#endif // 