#ifndef MODULERULEDETAILWIDGET_H
#define MODULERULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class ModuleRuleDetailWidget;
}

class RuleModuleProtect {
    public:
        int RID;
        int RuleGroupID;
        int OperationCode;
        int RuleType;
        int ProcessInfoType;
        std::string ProcessInfo;
        int ModuleInfoType;
        std::string ModuleInfo;
        int InnerID;
        int InnerFlg;
        int Enabled;
        int Log;
        std::string Remark;
        int OsVersion;

        RuleModuleProtect() {}
        ~RuleModuleProtect() {}

        RuleModuleProtect(int rid, int rule_group_id, int operation_code, int rule_type, int process_info_type, const std::string& process_info,
            int module_info_type, const std::string& module_info, int inner_ID, int inner_flg, int enabled, int log,
            const std::string& remark, int os_version)
            : RID(rid),
            RuleGroupID(rule_group_id),
            OperationCode(operation_code),
            RuleType(rule_type),
            ProcessInfoType(process_info_type),
            ProcessInfo(process_info),
            ModuleInfoType(module_info_type),
            ModuleInfo(module_info),
            InnerID(inner_ID),
            InnerFlg(inner_flg),
            Enabled(enabled),
            Log(log),
            Remark(remark),
            OsVersion(os_version) {}

        RuleModuleProtect(const RuleModuleProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            OperationCode(other.OperationCode),
            RuleType(other.RuleType),
            ProcessInfoType(other.ProcessInfoType),
            ProcessInfo(other.ProcessInfo),
            ModuleInfoType(other.ModuleInfoType),
            ModuleInfo(other.ModuleInfo),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Log(other.Log),
            Remark(other.Remark),
            OsVersion(other.OsVersion) {}

        RuleModuleProtect& operator=(const RuleModuleProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                OperationCode = other.OperationCode;
                RuleType = other.RuleType;
                ProcessInfoType = other.ProcessInfoType;
                ProcessInfo = other.ProcessInfo;
                ModuleInfoType = other.ModuleInfoType;
                ModuleInfo = other.ModuleInfo;
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

class ModuleRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModuleRuleDetailWidget(QWidget *parent = nullptr);
    explicit ModuleRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ModuleRuleDetailWidget();

private:
    Ui::ModuleRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // MODULERULEDETAILWIDGET_H
