/***********************************************************************
* @file    *.h
* @brief   通信服务回调接口
* @author  geshan@hotmail.com
*/

#ifndef __Communication_Server_Def_H__
#define __Communication_Server_Def_H__


///下发命令类型定义
enum DeliverCommandType {
	UNKNOWN = -1,
	CommandRule = 2, //普通规则
	CommandProcRuleCreationListLog = 50,
	CommandProcRuleWriteProtectListLog = 51,
	CommandProcRuleTerminateProtectListLog = 52,
	CommandProcRuleLdrModuleProtectListLog = 53
};



/*

RuleDomainProtect
RuleFileProtect
RuleInjectProtect
RuleKernelCallbackProtect
RuleKernelProtect
RuleModuleProtect
RuleNetworkProtect
RuleProcessCreation
RuleProcProtect
RuleRegisterProtect
RuleThreadCreation

	switch(nType)
	case 2:
	从输入缓存中解析出userid,barid,pcid,ip,驱动备份目录,isrun,isrulelog,isdebug,isrunpm,timestamp标志
	从输入缓存中解析出 规则，设置到驱动中
	从输入缓存中解析出 插件，设置到驱动中

	case 3:
	1.根据输入的文件的 MD5值，在FileMd5SendList 找到匹配的项
	对输入的数据进行解压，如果解压后长度小于等于512,解压后的数据是个json，解析file_state标志，如果这个标志为0，从
	FileMd5SendList中删除文件信息,如果长度大于512，把解压后的数据加入FileMd5SendList中
	2.枚举FileMd5SendList,把其中的信息发送

	case 4:
	从输入缓存中解析出命令，执行重启，关机操作
	case 5:
	1.清除所有规则，从输入缓存中解析出规则，设置到驱动中
	2.设置规则生效标志
	case 6:
	1.从输入缓存中解析出Patch channel
	2.把Patch channel的文件MD5信息 上报
	3.把Patch channel 列表中的所有 注入Explorer 进程
	case 16：
	case 18：
	case 36：
		1.如果SendProcInfoList不为空，把它的信息发送
		2.如果SendProcInfoList为空，从驱动备份数据库文件中解析出数据填充到SendProcInfoList,然后发送出去。
	case 50：
		把SendProcRuleCreationList表中的数据发送出去
	case 51：
		把SendProcRuleWriteProtectList表中的数据发送出去
	case 52：
		把SendProcRuleTerminateProtectList发送出去
	case 53：
		把SendProcRuleLdrModuleProtectList发送出去
	case 54：
		把SendProcRuleFileProtectList发送出去
	case 55：
		把SendProcRuleRegProtectList发送出去
	case 56：
		把SendLdrDrvRuleProtectList发送出去
	case 57：
		把SendNetConnectRuleProtectList发送出去
	case 58：
		把SendDomainRuleProtectList发送出去
	case 59：
		把SendDebugRuleProtectList发送出去
	case 60：
		把注册表"\Registry\Machine\SOFTWARE\FWindow_Log\WindowRule_Log"的数据发送
	case 61：
		把SendThreadRuleCreationList发送出去
	case 62：
		把SendDriverCallbackRuleProtectList发送出去
*/

#endif // 