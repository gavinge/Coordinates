#ifndef PROCESSRULEDETAILWIDGET_H
#define PROCESSRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"


namespace Ui {
class ProcessRuleDetailWidget;
}


class RuleProcessCreation {
    public:
        int RID;
        int RuleGroupID;
        int OperationCode;
        int RuleType;
        int ChildProcessInfoType;
        std::string ChildProcessInfo;
        int ParentProcessInfoType;
        std::string ParentProcessInfo;
        int InnerID;
        int InnerFlg;
        int Enabled;
        int Log;
        std::string Remark;
        int OsVersion;

        RuleProcessCreation() {}
        ~RuleProcessCreation() {}
        RuleProcessCreation(int rid, int rule_group_id, int operation_code, int rule_type, int child_process_info_type, const std::string& child_process_info,
            int parent_process_info_type, const std::string& parent_process_info, int inner_ID, int inner_flg, int enabled, int log,
            const std::string& remark, int os_version)
            : RID(rid),
            RuleGroupID(rule_group_id),
            OperationCode(operation_code),
            RuleType(rule_type),
            ChildProcessInfoType(child_process_info_type),
            ChildProcessInfo(child_process_info),
            ParentProcessInfoType(parent_process_info_type),
            ParentProcessInfo(parent_process_info),
            InnerID(inner_ID),
            InnerFlg(inner_flg),
            Enabled(enabled),
            Log(log),
            Remark(remark),
            OsVersion(os_version) {}

        RuleProcessCreation(const RuleProcessCreation& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            OperationCode(other.OperationCode),
            RuleType(other.RuleType),
            ChildProcessInfoType(other.ChildProcessInfoType),
            ChildProcessInfo(other.ChildProcessInfo),
            ParentProcessInfoType(other.ParentProcessInfoType),
            ParentProcessInfo(other.ParentProcessInfo),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Log(other.Log),
            Remark(other.Remark),
            OsVersion(other.OsVersion) {}

        RuleProcessCreation& operator=(const RuleProcessCreation& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                OperationCode = other.OperationCode;
                RuleType = other.RuleType;
                ChildProcessInfoType = other.ChildProcessInfoType;
                ChildProcessInfo = other.ChildProcessInfo;
                ParentProcessInfoType = other.ParentProcessInfoType;
                ParentProcessInfo = other.ParentProcessInfo;
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
class ProcessRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessRuleDetailWidget(QWidget *parent = nullptr);
    explicit ProcessRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ProcessRuleDetailWidget();

private:
    Ui::ProcessRuleDetailWidget *ui;
    void initData();
    int innerType;

private:
    RuleViewModel ruleViewModel;
};

#endif // PROCESSRULEDETAILWIDGET_H
