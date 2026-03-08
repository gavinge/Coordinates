#ifndef CUSTOMRULEWIDGET_H
#define CUSTOMRULEWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QMenu>
#include "rule_center/CustomRuleCenterWidget.h"

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
class CustomRuleWidget : public QWidget
{
    Q_OBJECT
public:


public:
    explicit CustomRuleWidget(QWidget *parent = nullptr);
    ~CustomRuleWidget();

public slots:
    void onRuleCenterBtnClicked();
    void onDisableBtnClicked();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    bool isMouseInWidget(const QWidget *widget,const QPoint &pos);
private:
    //先动态获取信息
    void getRuleSummaryInfo();
    std::vector<TabInfo> ruleSummary;

    void InitTab();
    void initGroupInfo();
    void initRuleDetailMenu();
    void onRuleDetailMenuItemClicked();
    void initSlots();
private:
    Ui::CustomRuleWidget *ui;

private:
    QStackedWidget *stackedWidget;
    QMenu* menuRuleDetailOper;
};

#endif // CUSTOMRULEWIDGET_H
