#ifndef INNERRULEWIDGET_H
#define INNERRULEWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include "common/RuleType.h"

#include "../agent_man/AgentManBaseView.h"
#include "../agent_man/Controller/AgentManController.h"
#include "../agent_man/Model/AgentManModel.h"

namespace Ui {
class InnerRuleWidget;
}

class InnerRuleInfo {
    public:
        int ID;
        int DefaultID;      //默认规则ID(官方维护)
        int DefaultType;    //自定义规则类型(官方维护)
        std::string Name;   //自定义规则名称
        std::string Des;    //描述
        std::string Ver;    //版本
        std::string Remark; //标记

        InnerRuleInfo() {}
        ~InnerRuleInfo() {}

        InnerRuleInfo(int id, int defaultID, const std::string& name, int defaultType,
            const std::string& des, const std::string& ver, const std::string& remark)
            : ID(id),
            DefaultID(defaultID),
            Name(name),
            DefaultType(defaultType),
            Des(des),
            Ver(ver),
            Remark(remark) {}

        InnerRuleInfo(const InnerRuleInfo& other)
            : ID(other.ID),
            DefaultID(other.DefaultID),
            Name(other.Name),
            DefaultType(other.DefaultType),
            Des(other.Des),
            Ver(other.Ver),
            Remark(other.Remark) {}

        InnerRuleInfo& operator=(const InnerRuleInfo& other) {
            if (this != &other) {
                ID = other.ID;
                DefaultID = other.DefaultID;
                Name = other.Name;
                DefaultType = other.DefaultType;
                Des = other.Des;
                Ver = other.Ver;
                Remark = other.Remark;
            }
            return *this;
        }
};

class InnerRuleWidget : 
	public QWidget,
	public CAgentManBaseView
{
    Q_OBJECT

public:
    ///规则tab信息
    class TabClassifyInfo {
    public:
        unsigned idx;     //tab的idx
        QString  tabText; //text显示名字
        InnerRuleClassify ruleType;//规则类型
        unsigned count;   //规则总数
    };

public:
    explicit InnerRuleWidget(QWidget *parent = nullptr);
    ~InnerRuleWidget();

	//CAgentManBaseView
public:
	bool UpdateGroupInfo()override;
	bool UpdateGroupInfo(long nGroupID, std::string strGroupName) override;
	bool DeleteGroupInfo(long nGroupID) override;

public slots:
	void onGroupListItemSelected(QListWidgetItem* item);

private:
	bool InitAgentManMVCFW();
private:
    void getRuleSummaryInfo();
    std::vector<TabClassifyInfo> ruleSummary;

    void InitTab();
    void initData();
    void initGroupInfo();

	void ClearListWidget(QListWidget* listWidget);
private:
    Ui::InnerRuleWidget *ui;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // INNERRULEWIDGET_H
