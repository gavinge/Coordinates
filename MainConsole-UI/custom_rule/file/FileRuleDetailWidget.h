#ifndef FILERULEDETAILWIDGET_H
#define FILERULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

namespace Ui {
class FileRuleDetailWidget;
}

class RuleFileProtect {
    public:
        int RID;                 //主键
        int RuleGroupID;         //规则分类ID，暂不用
        int OperationCode;       //处置码
        int RuleType;            //规则类，这个固定死。
        int ProcessInfoType;
        std::string ProcessInfo;
        int FileInfoType;
        std::string FileInfo;
        int Enabled;             //生效标记， ==1：表示生效
        int Log;
        std::string Remark;
        int Options;
        int OsVersion;
        int InnerID;             //内部ID(官方维护)
        int InnerFlg;            //内部标记(官方维护)  ==0：表示内部标记。 ==1：表示用户自定义标记。

        RuleFileProtect() {}
        ~RuleFileProtect() {}

        RuleFileProtect(int rid, int ruleGroupID, int operation_code, int rule_type, int process_info_type,
            const std::string& process_info, int file_info_type, const std::string& file_info,
            int enabled, int log, const std::string& remark, int options, int os_version, int innerID, int inner_flg)
            : RID(rid),
            RuleGroupID(ruleGroupID),
            OperationCode(operation_code),
            RuleType(rule_type),
            ProcessInfoType(process_info_type),
            ProcessInfo(process_info),
            FileInfoType(file_info_type),
            FileInfo(file_info),
            Enabled(enabled),
            Log(log),
            Remark(remark),
            Options(options),
            InnerID(innerID),
            InnerFlg(inner_flg),
            OsVersion(os_version) {}

        RuleFileProtect(const RuleFileProtect& other)
            : RID(other.RID),
            RuleGroupID(other.RuleGroupID),
            OperationCode(other.OperationCode),
            RuleType(other.RuleType),
            ProcessInfoType(other.ProcessInfoType),
            ProcessInfo(other.ProcessInfo),
            FileInfoType(other.FileInfoType),
            FileInfo(other.FileInfo),
            Enabled(other.Enabled),
            Log(other.Log),
            Remark(other.Remark),
            Options(other.Options),
            InnerID(other.InnerID),
            InnerFlg(other.InnerFlg),
            OsVersion(other.OsVersion) {}

        RuleFileProtect& operator=(const RuleFileProtect& other) {
            if (this != &other) {
                RID = other.RID;
                RuleGroupID = other.RuleGroupID;
                OperationCode = other.OperationCode;
                RuleType = other.RuleType;
                ProcessInfoType = other.ProcessInfoType;
                ProcessInfo = other.ProcessInfo;
                FileInfoType = other.FileInfoType;
                FileInfo = other.FileInfo;
                Enabled = other.Enabled;
                Log = other.Log;
                Remark = other.Remark;
                Options = other.Options;
                InnerID = other.InnerID;
                InnerFlg = other.InnerFlg;
                OsVersion = other.OsVersion;
            }
            return *this;
        }
};

class FileRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileRuleDetailWidget(QWidget *parent = nullptr);
    explicit FileRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~FileRuleDetailWidget();

private:
    Ui::FileRuleDetailWidget *ui;
    void initData();

private:
    RuleViewModel ruleViewModel;
};

#endif // FILERULEDETAILWIDGET_H
