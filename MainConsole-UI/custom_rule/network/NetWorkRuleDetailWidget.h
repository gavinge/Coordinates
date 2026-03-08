#ifndef NETWORKRULEDETAILWIDGET_H
#define NETWORKRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class NetWorkRuleDetailWidget;
}

class RuleNetworkProtect {
    public:
        int RID;
        int RuleGroupID;
        int OperationCode;
        int RuleType;
        std::string ProcessInfo;
        int ProcessInfoType;
        std::string IP;
        int InnerID;
        int InnerFlg;
        int Enabled;
        std::string Port;
        int Log;
        std::string Remark;
        int Options;
        int OsVersion;

        RuleNetworkProtect() {}
        ~RuleNetworkProtect() {}

        RuleNetworkProtect(int rid, int rule_group_id, int operation_code, int rule_type, const std::string& process_info, int process_info_type,
            const std::string& ip, int inner_ID, int inner_flg, int enabled, const std::string& port, int log, const std::string& remark,
            int options, int os_version)
            : RID(rid),
            RuleGroupID(rule_group_id),
            OperationCode(operation_code),
            RuleType(rule_type),
            ProcessInfo(process_info),
            ProcessInfoType(process_info_type),
            IP(ip),
            InnerID(inner_ID),
            InnerFlg(inner_flg),
            Enabled(enabled),
            Port(port),
            Log(log),
            Remark(remark),
            Options(options),
            OsVersion(os_version) {}

        RuleNetworkProtect(const RuleNetworkProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            OperationCode(other.OperationCode),
            RuleType(other.RuleType),
            ProcessInfo(other.ProcessInfo),
            ProcessInfoType(other.ProcessInfoType),
            IP(other.IP),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            Enabled(other.Enabled),
            Port(other.Port),
            Log(other.Log),
            Remark(other.Remark),
            Options(other.Options),
            OsVersion(other.OsVersion) {}

        RuleNetworkProtect& operator=(const RuleNetworkProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                OperationCode = other.OperationCode;
                RuleType = other.RuleType;
                ProcessInfo = other.ProcessInfo;
                ProcessInfoType = other.ProcessInfoType;
                IP = other.IP;
                InnerID = other.InnerID;
                InnerFlg = other.InnerFlg;
                Enabled = other.Enabled;
                Port = other.Port;
                Log = other.Log;
                Remark = other.Remark;
                Options = other.Options;
                OsVersion = other.OsVersion;
            }
            return *this;
        }
};

class NetWorkRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NetWorkRuleDetailWidget(QWidget *parent = nullptr);
    explicit NetWorkRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~NetWorkRuleDetailWidget();

private:
    Ui::NetWorkRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // NETWORKRULEDETAILWIDGET_H
