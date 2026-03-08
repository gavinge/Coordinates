#ifndef KERNELRULEDETAILWIDGET_H
#define KERNELRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class KernelRuleDetailWidget;
}

class RuleKernelProtect {
    public:
        int RID;
        int RuleGroupID;
        int RuleType;
        int DriverInfoType;
        std::string DriverInfo;
        int OperationCode;
        int InnerID;
        int InnerFlg;
        int Enabled;
        int Log;
        std::string Remark;
        int OsVersion;

        RuleKernelProtect() {}
        ~RuleKernelProtect() {}

        RuleKernelProtect(int rid, int ruleGroupID, int rule_type, int driver_info_type, const std::string& driver_info,
            int operation_code, int innerID, int innerFlg, int enabled, int log, const std::string& remark, int os_version)
            : RID(rid),
            RuleGroupID(ruleGroupID),
            RuleType(rule_type),
            DriverInfoType(driver_info_type),
            DriverInfo(driver_info),
            OperationCode(operation_code),
            InnerID(innerID),
            InnerFlg(innerFlg),
            Enabled(enabled),
            Log(log),
            Remark(remark),
            OsVersion(os_version) {}

        RuleKernelProtect(const RuleKernelProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            RuleType(other.RuleType),
            DriverInfoType(other.DriverInfoType),
            DriverInfo(other.DriverInfo),
            OperationCode(other.OperationCode),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Log(other.Log),
            Remark(other.Remark),
            OsVersion(other.OsVersion) {}

        RuleKernelProtect& operator=(const RuleKernelProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                RuleType = other.RuleType;
                DriverInfoType = other.DriverInfoType;
                DriverInfo = other.DriverInfo;
                OperationCode = other.OperationCode;
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

class KernelRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KernelRuleDetailWidget(QWidget *parent = nullptr);
    explicit KernelRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~KernelRuleDetailWidget();

private:
    Ui::KernelRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // KERNELRULEDETAILWIDGET_H
