/***********************************************************************
* @file    *.h
* @brief   导出去给第外面用的准接口定义
* @author  geshan@hotmail.com
*/

#ifndef CRuleManager_INTERFACE_H
#define CRuleManager_INTERFACE_H
#ifdef _WIN32
#pragma once
#endif


#ifdef API_EXPORTS
#define EXTERN_API extern "C" __declspec(dllexport)
#else
#define EXTERN_API extern "C" __declspec(dllimport)
#endif

#define API_CALLTYPE	  __stdcall
#define NO_VTABLE __declspec(novtable)

#include "RuleProcessCreation.hpp"
#include "RuleFileProtect.hpp"
#include "RuleModuleProtect.hpp"
#include "RuleKernelProtect.hpp"
#include "RuleNetworkProtect.hpp"
#include "RuleRegisterProtect.hpp"
#include "RuleProcProtect.hpp"
#include "RuleDomainProtect.hpp"
#include "RuleInjectProtect.hpp"
#include "RuleKernelCallbackProtect.hpp"
#include "RuleThreadCreation.hpp"
#include "RuleGroupInfo.hpp"
#include "AgentEnabledRuleInfo.hpp"
#include "InnerRuleInfo.hpp"
#include "InnerRuleInfoDetail.hpp"

/**************************************************************************************************/
/*****************************以下为一些回调上的约定***************************************/
#ifndef MIN
#define MIN(x,y) (x)<(y)?(x) : (y) 
#endif


//普通构造函数(结构体,类都可试用)
#ifndef DECLARE_DEFAULT_CONSTRUCTOR
#define DECLARE_DEFAULT_CONSTRUCTOR(ClassName)\
	ClassName()\
{\
	RtlZeroMemory(this,sizeof(ClassName));\
	this->dwSize = sizeof(ClassName);\
}
#endif


//拷贝构造函数(结构体,类都可试用)
#ifndef DECLARE_COPY_CONSTRUCTOR
#define DECLARE_COPY_CONSTRUCTOR(ClassName)\
	ClassName(const ClassName & ref)\
{\
	DWORD dwSize    = sizeof(ClassName);\
	DWORD dwSizeOld = this->dwSize;\
	DWORD nMinSize  = MIN(dwSizeOld,ref.dwSize);\
	RtlZeroMemory(this,dwSize);\
	RtlCopyMemory(this,&ref,nMinSize);\
	this->dwSize    = dwSizeOld;\
}
#endif

#ifndef DECLARE_OPERATOR_EQUAL
#define DECLARE_OPERATOR_EQUAL(ClassName)\
	ClassName & operator = (const ClassName &ref)\
{\
	if (this == &ref){return *this;}\
	DWORD dwSize    = sizeof(ClassName);\
	DWORD dwSizeOld = this->dwSize;\
	DWORD nMinSize  = MIN(dwSizeOld,ref.dwSize);\
	RtlZeroMemory(this,dwSize);\
	RtlCopyMemory(this,&ref,nMinSize);\
	this->dwSize    = dwSizeOld;\
	return *this;\
}
#endif

#ifndef DEF_NO_VTABLE
#define DEF_NO_VTABLE __declspec(novtable)
#endif

//typedef int (__stdcall *LPFunCallBackDemo)(int uID,HWND& hParentWnd,const DWORD dwContext);

//回调函数指针集合
typedef struct RuleManager_CALLBACKFUNC_PTR_SET
{
	DECLARE_DEFAULT_CONSTRUCTOR(RuleManager_CALLBACKFUNC_PTR_SET);
	DECLARE_COPY_CONSTRUCTOR(RuleManager_CALLBACKFUNC_PTR_SET);
	DECLARE_OPERATOR_EQUAL(RuleManager_CALLBACKFUNC_PTR_SET);

	DWORD dwSize;                           //CALLBACKFUNC 结构大小
	///!!这里函数指针描述，请按照顺序描述(加了就站位，不要换顺序或者删除)。否则会出现新老版本函数地址错乱的问题。
	//LPFunCallBackDemo lpFunCallBackDemo;
}RuleManager_CALLBACKFUNC_PTR_SET, *LPRuleManager_CALLBACKFUNC_PTR_SET;


/**************************************************************************************************/
/*****************************以下为一些业务上用到的约定***************************************/

///接口内部版本号控制(每次发正式版dll出去该值都应该变化)
#define  MAX_RuleManager_VERSION  1       //接口版本(高)
#define  MIN_RuleManager_VERSION  0       //接口版本(低)



///对外的公共接口（自定义+公共Base接口）
class DEF_NO_VTABLE IRuleManager
{
public:

	///@brief  当前接口版本号
	///@param1 dwMaxVersion 高版本
	///@param2 dwMaxVersion 低版本
	///@return int 成功>0
	STDMETHOD_(int, QueryVerSion)(DWORD & dwMaxVersion, DWORD & dwMinVersion) PURE;

	///@brief 初始化函数,这里如果没有要回调的函数直接当Init函数用就行
	///@param 相关回调函数地址(struct连续地址描述). 
	///@return int 成功>0
	STDMETHOD_(int, InitCallBack)(const RuleManager_CALLBACKFUNC_PTR_SET & callback_ptr_set) PURE;

	///@brief这是一个类似于com接口的扩展,目的是可以用函数名称完成所有的执行体的扩展执行.
	///!!!请之后维护dll的人员将扩展的函数标记做详细说明。
	///@param1  LPCWSTR   函数标记
	///@param2  VARIANT*  参数地址
	///@param3  int       参数个数
	///@param4  VARIANT*  返回结果参数
	///@return  HRESULT   成功返回S_OK，失败返回S_FALSE
	STDMETHOD_(HRESULT, InVokeN)(const LPCWSTR, VARIANT*, int, VARIANT*) PURE;

	///@brief  是否本接口中所有的信息(内存)
	///@param  无
	///@return 无
	STDMETHOD_(void,   Release)() PURE;   
	
	///!!!在这里添加自己需要扩展的接口

	///进程创建防护相关规则操作
	virtual int addRule_ProcessCreation(const RuleManagement::RuleProcessCreation& rule) PURE;
	virtual int updateRule_ProcessCreation(const RuleManagement::RuleProcessCreation& rule)PURE;
	virtual int deleteRule_ProcessCreation(const RuleManagement::RuleProcessCreation& rule)PURE;
	virtual bool queryRecords_ProcessCreation(int ruleType, std::vector<RuleManagement::RuleProcessCreation>& queryResult)PURE;
	virtual int ruleCount_ProcessCreation(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_ProcessCreation(int ruleType, int innerFlg, std::vector<RuleManagement::RuleProcessCreation>& queryResult)PURE;
	virtual bool queryRecord_ProcessCreation(int rid, RuleManagement::RuleProcessCreation& rule) PURE;
	virtual bool queryRecords_ProcessCreation_WithEnable(int agentGroupID,int ruleType,int innerFlg, std::vector<RuleManagement::RuleProcessCreation>& queryResult)PURE;
	virtual bool queryRecords_ProcessCreation_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleProcessCreation>& queryResult)PURE;

	///文件防护规则操作
	virtual int addRule_FileProtect(const RuleManagement::RuleFileProtect& rule) PURE;
	virtual int updateRule_FileProtect(const RuleManagement::RuleFileProtect& rule)PURE;
	virtual int deleteRule_FileProtect(const RuleManagement::RuleFileProtect& rule)PURE;
	virtual bool queryRecords_FileProtect(int ruleType, std::vector<RuleManagement::RuleFileProtect>& queryResult)PURE;
	virtual int ruleCount_FileProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_FileProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleFileProtect>& queryResult)PURE;
	virtual bool queryRecord_FileProtect(int rid, RuleManagement::RuleFileProtect& rule) PURE;
	virtual bool queryRecords_FileProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleFileProtect>& queryResult)PURE;
	virtual bool queryRecords_FileProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleFileProtect>& queryResult)PURE;

	///模块防护规则操作
	virtual int addRule_ModuleProtect(const RuleManagement::RuleModuleProtect& rule) PURE;
	virtual int updateRule_ModuleProtect(const RuleManagement::RuleModuleProtect& rule)PURE;
	virtual int deleteRule_ModuleProtect(const RuleManagement::RuleModuleProtect& rule)PURE;
	virtual bool queryRecords_ModuleProtect(int ruleType, std::vector<RuleManagement::RuleModuleProtect>& queryResult)PURE;
	virtual int ruleCount_ModuleProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_ModuleProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleModuleProtect>& queryResult)PURE;
	virtual bool queryRecord_ModuleProtect(int rid, RuleManagement::RuleModuleProtect& rule) PURE;
	virtual bool queryRecords_ModuleProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleModuleProtect>& queryResult)PURE;
	virtual bool queryRecords_ModuleProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleModuleProtect>& queryResult)PURE;

	///内核防护规则操作
	virtual int addRule_KernelProtect(const RuleManagement::RuleKernelProtect& rule) PURE;
	virtual int updateRule_KernelProtect(const RuleManagement::RuleKernelProtect& rule)PURE;
	virtual int deleteRule_KernelProtect(const RuleManagement::RuleKernelProtect& rule)PURE;
	virtual bool queryRecords_KernelProtect(int ruleType, std::vector<RuleManagement::RuleKernelProtect>& queryResult)PURE;
	virtual int ruleCount_KernelProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_KernelProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleKernelProtect>& queryResult)PURE;
	virtual bool queryRecord_KernelProtect(int rid, RuleManagement::RuleKernelProtect& rule) PURE;
	virtual bool queryRecords_KernelProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleKernelProtect>& queryResult)PURE;
	virtual bool queryRecords_KernelProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleKernelProtect>& queryResult)PURE;

	///网络防护规则操作
	virtual int addRule_NetworkProtect(const RuleManagement::RuleNetworkProtect& rule) PURE;
	virtual int updateRule_NetworkProtect(const RuleManagement::RuleNetworkProtect& rule)PURE;
	virtual int deleteRule_NetworkProtect(const RuleManagement::RuleNetworkProtect& rule)PURE;
	virtual bool queryRecords_NetworkProtect(int ruleType, std::vector<RuleManagement::RuleNetworkProtect>& queryResult)PURE;
	virtual int ruleCount_NetworkProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_NetworkProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleNetworkProtect>& queryResult)PURE;
	virtual bool queryRecord_NetworkProtect(int rid, RuleManagement::RuleNetworkProtect& rule) PURE;
	virtual bool queryRecords_NetworkProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleNetworkProtect>& queryResult)PURE;
	virtual bool queryRecords_NetworkProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleNetworkProtect>& queryResult)PURE;

	///注册表防护规则操作
	virtual int addRule_RegisterProtect(const RuleManagement::RuleRegisterProtect& rule) PURE;
	virtual int updateRule_RegisterProtect(const RuleManagement::RuleRegisterProtect& rule)PURE;
	virtual int deleteRule_RegisterProtect(const RuleManagement::RuleRegisterProtect& rule)PURE;
	virtual bool queryRecords_RegisterProtect(int ruleType, std::vector<RuleManagement::RuleRegisterProtect>& queryResult)PURE;
	virtual int ruleCount_RegisterProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_RegisterProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleRegisterProtect>& queryResult)PURE;
	virtual bool queryRecord_RegisterProtect(int rid, RuleManagement::RuleRegisterProtect& rule) PURE;
	virtual bool queryRecords_RegisterProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleRegisterProtect>& queryResult)PURE;
	virtual bool queryRecords_RegisterProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleRegisterProtect>& queryResult)PURE;

	///进程防护规则操作
	virtual int addRule_ProcProtect(const RuleManagement::RuleProcProtect& rule) PURE;
	virtual int updateRule_ProcProtect(const RuleManagement::RuleProcProtect& rule)PURE;
	virtual int deleteRule_ProcProtect(const RuleManagement::RuleProcProtect& rule)PURE;
	virtual bool queryRecords_ProcProtect(int ruleType, std::vector<RuleManagement::RuleProcProtect>& queryResult)PURE;
	virtual int ruleCount_ProcProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_ProcProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleProcProtect>& queryResult)PURE;
	virtual bool queryRecord_ProcProtect(int rid, RuleManagement::RuleProcProtect& rule) PURE;
	virtual bool queryRecords_ProcProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleProcProtect>& queryResult)PURE;
	virtual bool queryRecords_ProcProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleProcProtect>& queryResult)PURE;

	///域名防护规则操作
	virtual int addRule_DomainProtect(const RuleManagement::RuleDomainProtect& rule) PURE;
	virtual int updateRule_DomainProtect(const RuleManagement::RuleDomainProtect& rule)PURE;
	virtual int deleteRule_DomainProtect(const RuleManagement::RuleDomainProtect& rule)PURE;
	virtual bool queryRecords_DomainProtect(int ruleType, std::vector<RuleManagement::RuleDomainProtect>& queryResult)PURE;
	virtual bool queryEnabledByRuleType_DomainProtect(int ruleType, std::vector<RuleManagement::RuleDomainProtect>& queryResult)PURE;
	virtual int ruleCount_DomainProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_DomainProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleDomainProtect>& queryResult)PURE;
	virtual bool queryRecord_DomainProtect(int rid, RuleManagement::RuleDomainProtect& rule) PURE;
	virtual bool queryRecords_DomainProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleDomainProtect>& queryResult)PURE;
	virtual bool queryRecords_DomainProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleDomainProtect>& queryResult)PURE;

	///防注入防护规则操作
	virtual int addRule_InjectProtect(const RuleManagement::RuleInjectProtect& rule) PURE;
	virtual int updateRule_InjectProtect(const RuleManagement::RuleInjectProtect& rule)PURE;
	virtual int deleteRule_InjectProtect(const RuleManagement::RuleInjectProtect& rule)PURE;
	virtual bool queryRecords_InjectProtect(int ruleType, std::vector<RuleManagement::RuleInjectProtect>& queryResult)PURE;
	virtual int ruleCount_InjectProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_InjectProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleInjectProtect>& queryResult)PURE;
	virtual bool queryRecord_InjectProtect(int rid, RuleManagement::RuleInjectProtect& rule) PURE;
	virtual bool queryRecords_InjectProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleInjectProtect>& queryResult)PURE;
	virtual bool queryRecords_InjectProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleInjectProtect>& queryResult)PURE;

	///内核回调防护规则操作
	virtual int addRule_KernelCallbackProtect(const RuleManagement::RuleKernelCallbackProtect & rule) PURE;
	virtual int updateRule_KernelCallbackProtect(const RuleManagement::RuleKernelCallbackProtect& rule)PURE;
	virtual int deleteRule_KernelCallbackProtect(const RuleManagement::RuleKernelCallbackProtect& rule)PURE;
	virtual bool queryRecords_KernelCallbackProtect(int ruleType, std::vector<RuleManagement::RuleKernelCallbackProtect>& queryResult)PURE;
	virtual int ruleCount_KernelCallbackProtect(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_KernelCallbackProtect(int ruleType, int innerFlg, std::vector<RuleManagement::RuleKernelCallbackProtect>& queryResult)PURE;
	virtual bool queryRecord_KernelCallbackProtect(int rid, RuleManagement::RuleKernelCallbackProtect& rule) PURE;
	virtual bool queryRecords_KernelCallbackProtect_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleKernelCallbackProtect>& queryResult)PURE;
	virtual bool queryRecords_KernelCallbackProtect_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleKernelCallbackProtect>& queryResult)PURE;


	///进程创建防护规则
	virtual int addRule_ThreadCreation(const RuleManagement::RuleThreadCreation & rule) PURE;
	virtual int updateRule_ThreadCreation(const RuleManagement::RuleThreadCreation& rule)PURE;
	virtual int deleteRule_ThreadCreation(const RuleManagement::RuleThreadCreation& rule)PURE;
	virtual bool queryRecords_ThreadCreation(int ruleType, std::vector<RuleManagement::RuleThreadCreation>& queryResult)PURE;
	virtual int ruleCount_ThreadCreation(int ruleType, int innerFlg)PURE;
	virtual bool queryRecords_ThreadCreation(int ruleType, int innerFlg, std::vector<RuleManagement::RuleThreadCreation>& queryResult)PURE;
	virtual bool queryRecord_ThreadCreation(int rid, RuleManagement::RuleThreadCreation& rule) PURE;
	virtual bool queryRecords_ThreadCreation_WithEnable(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleThreadCreation>& queryResult)PURE;
	virtual bool queryRecords_ThreadCreation_WithEnable2(int agentGroupID, int ruleType, int innerFlg, std::vector<RuleManagement::RuleThreadCreation>& queryResult)PURE;


	///内建规则>>>>>
	virtual int addRule_InnerRuleInfo(const RuleManagement::InnerRuleInfo & rule) PURE;
	virtual int updateRule_InnerRuleInfo(const RuleManagement::InnerRuleInfo& rule)PURE;
	virtual int deleteRule_InnerRuleInfo(const RuleManagement::InnerRuleInfo& rule)PURE;
	virtual bool queryRecordsByType_InnerRuleInfo(int defaultType, std::vector<RuleManagement::InnerRuleInfo>& queryResult)PURE;
	virtual bool fuzzyQueryRecords_InnerRuleInfo(int defaultType, const std::string& fuzzyValue, std::vector<RuleManagement::InnerRuleInfo>& queryResult)PURE;
	///内建规则详情>>>>>
	virtual int addRule_InnerRuleInfoDetail(const RuleManagement::InnerRuleInfoDetail & rule) PURE;
	virtual int updateRule_InnerRuleInfoDetail(const RuleManagement::InnerRuleInfoDetail& rule)PURE;
	virtual int deleteRule_InnerRuleInfoDetail(const RuleManagement::InnerRuleInfoDetail& rule)PURE;


	//规则分组操作和维护
	virtual int addGroup(const RuleManagement::RuleGroupInfo& group) PURE;
	virtual int updateGroup(const RuleManagement::RuleGroupInfo& group) PURE;
	virtual int deleteGroup(const RuleManagement::RuleGroupInfo& group) PURE;
	virtual bool queryGroups(std::vector<RuleManagement::RuleGroupInfo>& queryResult) PURE;
	virtual bool queryGroupByName(const std::string& groupName, std::vector<RuleManagement::RuleGroupInfo>& queryResult) PURE;


	//规则主机对应关系
	virtual int enabledInfo(const RuleManagement::AgentEnabledRuleInfo& info)PURE;
	virtual int disableInfo(const RuleManagement::AgentEnabledRuleInfo& info)PURE;
	virtual bool queryEnabledInfos(int agentGroupID, int ruleType, std::vector<RuleManagement::AgentEnabledRuleInfo>& queryResult)PURE;
	virtual bool isEnabled(const RuleManagement::AgentEnabledRuleInfo& info)PURE;
};

///dll统一导出接个接口.
EXTERN_API BOOL API_CALLTYPE CreateInstance(IRuleManager**);

#endif // 