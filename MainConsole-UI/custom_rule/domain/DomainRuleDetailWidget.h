#ifndef DOMAINRULEDETAILWIDGET_H
#define DOMAINRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class DomainRuleDetailWidget;
}

class RuleDomainProtect {
    public:
        int RID;
        int RuleGroupID;
        int RuleType;
        int OperationCode;
        std::string DomainName;
        std::string ProcessInfo;
        int ProcessInfoType;
        std::string IP;
        int Enabled;
        int OsVersion;
        int Log;
        int InnerID;
        int InnerFlg;
        std::string Remark;

        RuleDomainProtect() {}
        ~RuleDomainProtect() {}

        RuleDomainProtect(int rid, int ruleGroupID, int ruleType, int operationCode, const std::string& domainName, const std::string& processInfo,
            int processInfoType, const std::string& ip, int enabled, int osVersion, int log, int innerID,int innerFlg,
            const std::string& remark)
            : RID(rid),
            RuleGroupID(ruleGroupID),
            RuleType(ruleType),
            OperationCode(operationCode),
            DomainName(domainName),
            ProcessInfo(processInfo),
            ProcessInfoType(processInfoType),
            IP(ip),
            Enabled(enabled),
            OsVersion(osVersion),
            Log(log),
            InnerID(innerID),
            InnerFlg(innerFlg),
            Remark(remark) {}

        RuleDomainProtect(const RuleDomainProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            RuleType(other.RuleType),
            OperationCode(other.OperationCode),
            DomainName(other.DomainName),
            ProcessInfo(other.ProcessInfo),
            ProcessInfoType(other.ProcessInfoType),
            IP(other.IP),
            Enabled(other.Enabled),
            OsVersion(other.OsVersion),
            Log(other.Log),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Remark(other.Remark) {}

        RuleDomainProtect& operator=(const RuleDomainProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                OperationCode = other.OperationCode;
                RuleType = other.RuleType;
                DomainName = other.DomainName;
                ProcessInfo = other.ProcessInfo;
                ProcessInfoType = other.ProcessInfoType;
                IP = other.IP;
                Enabled = other.Enabled;
                OsVersion = other.OsVersion;
                Log = other.Log;
                InnerID = other.InnerID;
                InnerFlg = other.InnerFlg;
                Remark = other.Remark;
            }
            return *this;
        }
};

class DomainRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DomainRuleDetailWidget(QWidget *parent = nullptr);
    explicit DomainRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~DomainRuleDetailWidget();

private:
    Ui::DomainRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // DOMAINRULEDETAILWIDGET_H
