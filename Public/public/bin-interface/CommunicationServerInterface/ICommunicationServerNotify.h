/***********************************************************************
* @file    *.h
* @brief   通信服务回调接口
* @author  geshan@hotmail.com
*/

#ifndef __CommunicationServer_Notify_H__
#define __CommunicationServer_Notify_H__


class ICommunicationServerNotify {
public:
	virtual ~ICommunicationServerNotify() {}
	virtual void OnLineNotify(const char* byte, unsigned long ulength) = 0;                              //agent上线通知
	virtual void OffLineNotify(const char* byte, unsigned long ulength) = 0;                             //gent上线通知
	virtual void RuleDomainProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;          //域名防御规则日志上报通知
	virtual void RuleFileProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;            //文件防御规则日志上报通知
	virtual void RuleInjectProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;          //注入防御规则日志上报通知
	virtual void RuleKernelCallbackProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;  //内核回调防御规则日志上报通知
	virtual void RuleKernelProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;          //内核模块防御规则日志上报通知
	virtual void RuleModuleProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;          //模块防御规则日志上报通知
	virtual void RuleNetworkProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;         //网络防御规则日志上报通知
	virtual void RuleProcessCreationLogReportNotify(const char* byte, unsigned long ulength) = 0;        //进程创建防御规则日志上报通知
	virtual void RuleProcProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;            //进程防御规则日志上报通知
	virtual void RuleRegisterProtectLogReportNotify(const char* byte, unsigned long ulength) = 0;        //注册表防御规则日志上报通知
	virtual void RuleThreadCreationLogReportNotify(const char* byte, unsigned long ulength) = 0;         //线程创建防御规则日志上报通知
};

	
#endif // 