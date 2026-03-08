#ifndef PROTECTIONRULEDETAILWIDGET_H
#define PROTECTIONRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class ProtectionRuleDetailWidget;
}

class RuleProcProtect {
    public:
        int RID;
        int RuleGroupID;
        int RuleType;
        int OperationCode;
        int ProcessInfoType;
        std::string ProcessInfo;
        int ProtectProcessInfoType;
        std::string ProtectProcessInfo;
        int Log;
        int InnerID;
        int InnerFlg;
        int Enabled;
        std::string Remark;
        int OsVersion;

        RuleProcProtect() {}
        ~RuleProcProtect() {}

        RuleProcProtect(int rid, int rule_group_id, int rule_type, int operation_code, int process_info_type, const std::string& process_info,
            int protect_process_info_type, const std::string& protect_process_info, int log, int inner_ID, int inner_flg, int enabled,
            const std::string& remark, int os_version)
            : RID(rid),
            RuleGroupID(rule_group_id),
            RuleType(rule_type),
            OperationCode(operation_code),
            ProcessInfoType(process_info_type),
            ProcessInfo(process_info),
            ProtectProcessInfoType(protect_process_info_type),
            ProtectProcessInfo(protect_process_info),
            Log(log),
            InnerID(inner_ID),
            InnerFlg(inner_flg),
            Enabled(enabled),
            Remark(remark),
            OsVersion(os_version) {}

        RuleProcProtect(const RuleProcProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            RuleType(other.RuleType),
            OperationCode(other.OperationCode),
            ProcessInfoType(other.ProcessInfoType),
            ProcessInfo(other.ProcessInfo),
            ProtectProcessInfoType(other.ProtectProcessInfoType),
            ProtectProcessInfo(other.ProtectProcessInfo),
            Log(other.Log),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Remark(other.Remark),
            OsVersion(other.OsVersion) {}

        RuleProcProtect& operator=(const RuleProcProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                RuleType = other.RuleType;
                OperationCode = other.OperationCode;
                ProcessInfoType = other.ProcessInfoType;
                ProcessInfo = other.ProcessInfo;
                ProtectProcessInfoType = other.ProtectProcessInfoType;
                ProtectProcessInfo = other.ProtectProcessInfo;
                Log = other.Log;
                InnerID = other.InnerID;
                InnerFlg = other.InnerFlg;
                Enabled = other.Enabled;
                Remark = other.Remark;
                OsVersion = other.OsVersion;
            }
            return *this;
        }
};
class ProtectionRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProtectionRuleDetailWidget(QWidget *parent = nullptr);
    explicit ProtectionRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ProtectionRuleDetailWidget();

private:
    Ui::ProtectionRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // PROTECTIONRULEDETAILWIDGET_H
