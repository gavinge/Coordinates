#ifndef THREADRULEDETAILWIDGET_H
#define THREADRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class ThreadRuleDetailWidget;
}

class RuleThreadCreation {
    public:
        int RID;
        int RuleGroupID;
        int RuleType;
        int OperationCode;
        int ProcessInfoType;
        std::string ProcessInfo;
        int ExpressInfoType;
        std::string ExpressInfo;
        int Log;
        int InnerID;
        int InnerFlg;
        int Enabled;
        std::string Remark;
        int OsVersion;

        RuleThreadCreation() {}
        ~RuleThreadCreation() {}

        RuleThreadCreation(int rid, int ruleGroupID, int ruleType, int operationCode, int processInfoType, const std::string& processInfo,
            int expressInfoType, const std::string& expressInfo, int log, int innerID, int innerFlg, int enabled,
            const std::string& remark, int osVersion)
            : RID(rid),
            RuleGroupID(ruleGroupID),
            RuleType(ruleType),
            OperationCode(operationCode),
            ProcessInfoType(processInfoType),
            ProcessInfo(processInfo),
            ExpressInfoType(expressInfoType),
            ExpressInfo(expressInfo),
            Log(log),
            InnerID(innerID),
            InnerFlg(innerFlg),
            Enabled(enabled),
            Remark(remark),
            OsVersion(osVersion) {}

        RuleThreadCreation(const RuleThreadCreation& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            RuleType(other.RuleType),
            OperationCode(other.OperationCode),
            ProcessInfoType(other.ProcessInfoType),
            ProcessInfo(other.ProcessInfo),
            ExpressInfoType(other.ExpressInfoType),
            ExpressInfo(other.ExpressInfo),
            Log(other.Log),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Remark(other.Remark),
            OsVersion(other.OsVersion) {}

        RuleThreadCreation& operator=(const RuleThreadCreation& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                RuleType = other.RuleType;
                OperationCode = other.OperationCode;
                ProcessInfoType = other.ProcessInfoType;
                ProcessInfo = other.ProcessInfo;
                ExpressInfoType = other.ExpressInfoType;
                ExpressInfo = other.ExpressInfo;
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


class ThreadRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadRuleDetailWidget(QWidget *parent = nullptr);
    explicit ThreadRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ThreadRuleDetailWidget();

private:
    Ui::ThreadRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // THREADRULEDETAILWIDGET_H
