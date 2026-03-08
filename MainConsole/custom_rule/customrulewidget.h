#ifndef CUSTOMRULEWIDGET_H
#define CUSTOMRULEWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QMenu>
#include <QListWidget>
#include "rule_center/CustomRuleCenterWidget.h"
#include "../agent_man/AgentManBaseView.h"
#include "../agent_man/Controller/AgentManController.h"
#include "../agent_man/Model/AgentManModel.h"

#include "Controller/RuleManController.h"
namespace Ui {
class CustomRuleWidget;
}



///用户自定义规则菜单
enum class CustomRuleMenuItemEnum {
    Separator = 1000,             //分割线
    SubMenu   = 1001,             //子菜单
    CustomDefineBase = 1002, //自定义菜单基础
    EnabledAllGroup =  CustomDefineBase + 1,        //所有分组启用
    DisabledAllGroup = CustomDefineBase + 2,        //所有分组禁用
};

//
class CustomRuleWidget : 
	public QWidget,
	public CAgentManBaseView,
	public CRuleManBaseView
{
    Q_OBJECT
public:


public:
    explicit CustomRuleWidget(QWidget *parent = nullptr);
    ~CustomRuleWidget();

	
public:
	//CAgentManBaseView
	bool UpdateGroupInfo()override;
	bool UpdateGroupInfo(long nGroupID, std::string strGroupName) override;
	bool DeleteGroupInfo(long nGroupID) override;

	//CRuleManBaseView
	bool UpdateRuleList(int nRuleType);
	bool UpdateRule(int nRuleType, int nRuleID);

	QMenu* getRuleDetailMenu();

	//EnableInfo isEnable =ture, else disable = false
	int EnableRuleInfo(bool IsEnable,RuleType nRuleType, int nRuleID);
private:
	bool InitMVCFrameWork();

public slots:
    void onRuleCenterBtnClicked();
    void onDisableBtnClicked();
	void onGroupListItemSelected(QListWidgetItem* item);
	void onTabChanged(int index);

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    bool isMouseInWidget(const QWidget *widget,const QPoint &pos);
	void UpdateTabTitle(int idx, std::string strTitle);
	//当分组被切换之后，触发
	int  UpdateRuleListByGroupID();
private:
    void getRuleSummaryInfo();
    std::vector<TabInfo> ruleSummary;

    void InitTab();
    void initGroupInfo();
    void initRuleDetailMenu();
    void onRuleDetailMenuItemClicked();
    void initSlots();

	void ClearListWidget(QListWidget* listWidget);
	long GetCurrentSelectedRuleID(RuleType ruelType);
private:
    Ui::CustomRuleWidget *ui;
	long nCurrentGroupID; //当前选择的分组。
	bool bShowRuleCenter; //规则中心页面是否展示
	CustomRuleCenterWidget* ruleCenterWidget; //规则中心页面指针。
	RuleType eCurrentRuleTypeSelected; //当前选择展示的规则类型
private:
    QStackedWidget *stackedWidget;
    QMenu* menuRuleDetailOper;
};

#endif // CUSTOMRULEWIDGET_H
