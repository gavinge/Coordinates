#ifndef CUSTOMRULECENTERWIDGET_H
#define CUSTOMRULECENTERWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include "common/RuleType.h"
#include "..\CustomRuleUtility.h"

namespace Ui {
class CustomRuleCenterWidget;
}

///规则tab信息
class TabInfo {
public:
    unsigned idx;     //tab的idx
    QString  tabText; //text显示名字
    RuleType ruleType;//规则类型
    unsigned count;   //规则总数
};

///用户自定义规则菜单
enum class CustomRuleCenterMenuItemEnum {
	Separator = 1000,                 //分割线
	SubMenu = 1001,                   //子菜单
	CustomDefineBase = 1002,          //自定义菜单基础
	DetailRule = CustomDefineBase + 1,//规则详情
	UpdateRule = CustomDefineBase + 2,//更新规则
	DeleteRule = CustomDefineBase + 3,//删除规则
};

class CustomRuleCenterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomRuleCenterWidget(QWidget *parent = nullptr);
    ~CustomRuleCenterWidget();

    int getNum() const;

	QMenu* getRuleDetailMenu();
signals:
    void closed(int num);

public slots:
    void onAddRuleBtnClicked();
	void onTabChanged(int index);
public:
    int num;

	bool UpdateRuleList(int nRuleType);
	bool UpdateRule(int nRuleType, int nRuleID);
private:
    Ui::CustomRuleCenterWidget *ui;
    bool isDragging;
    QPoint dragStartPosition;
	void UpdateTabTitle(int idx, std::string strTitle);
protected:
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
    void closeEvent(QCloseEvent *event) override ;
    void paintEvent(QPaintEvent *event) override;

	void OnMenuActionUpdateRule(RuleType ruelType, int rid, RuleViewModel mode);
private:
    //先动态获取信息
    void getRuleSummaryInfo();
    std::vector<TabInfo> ruleSummary;

    void InitTab();
	void initRuleDetailMenu();
	void onRuleDetailMenuItemClicked();
	long GetCurrentSelectedRuleID(RuleType ruelType);
private:
	QMenu* menuRuleDetailOper;
    bool isMoving = false;
    QPoint startPos;
	RuleType eCurrentRuleTypeSelected; //当前选择展示的规则类型
};

#endif // CUSTOMRULECENTERWIDGET_H
