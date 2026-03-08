#ifndef REGISTERRULEDETAILWIDGET_H
#define REGISTERRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class RegisterRuleDetailWidget;
}

class RuleRegisterProtect {
    public:
        int RID;
        int RuleGroupID;
        int OperationCode;
        int RuleType;
        std::string ProcessInfo;
        int ProcessInfoType;
        int Options;
        std::string RegistryPath;
        int InnerID;
        int InnerFlg;
        int Enabled;
        int Log;
        std::string Remark;
        int OsVersion;

        RuleRegisterProtect() {}
        ~RuleRegisterProtect() {}

        RuleRegisterProtect(int rid, int rule_group_id, int operation_code, int rule_type, const std::string& process_info, int process_info_type,
            int options, const std::string& registry_path, int inner_ID, int inner_flg, int enabled, int log, const std::string& remark, int os_version)
            : RID(rid),
            RuleGroupID(rule_group_id),
            OperationCode(operation_code),
            RuleType(rule_type),
            ProcessInfo(process_info),
            ProcessInfoType(process_info_type),
            Options(options),
            RegistryPath(registry_path),
            InnerID(inner_ID),
            InnerFlg(inner_flg),
            Enabled(enabled),
            Log(log),
            Remark(remark),
            OsVersion(os_version) {}

        RuleRegisterProtect(const RuleRegisterProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            OperationCode(other.OperationCode),
            RuleType(other.RuleType),
            ProcessInfo(other.ProcessInfo),
            ProcessInfoType(other.ProcessInfoType),
            Options(other.Options),
            RegistryPath(other.RegistryPath),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Log(other.Log),
            Remark(other.Remark),
            OsVersion(other.OsVersion) {}

        RuleRegisterProtect& operator=(const RuleRegisterProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                OperationCode = other.OperationCode;
                RuleType = other.RuleType;
                ProcessInfo = other.ProcessInfo;
                ProcessInfoType = other.ProcessInfoType;
                Options = other.Options;
                RegistryPath = other.RegistryPath;
                InnerID = other.InnerID;
                InnerFlg = other.InnerFlg;
                Enabled = other.Enabled;
                Log = other.Log;
                Remark = other.Remark;
                OsVersion = other.OsVersion;
            }
            return *this;
        }
};

class RegisterRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    explicit RegisterRuleDetailWidget(QWidget *parent = nullptr);
    ~RegisterRuleDetailWidget();

private:
    Ui::RegisterRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // REGISTERRULEDETAILWIDGET_H
