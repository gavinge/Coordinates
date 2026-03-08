#ifndef CUSTOMRULECENTERWIDGET_H
#define CUSTOMRULECENTERWIDGET_H

#include <QWidget>
#include <QMouseEvent>
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

class CustomRuleCenterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomRuleCenterWidget(QWidget *parent = nullptr);
    ~CustomRuleCenterWidget();

    int getNum() const;

signals:
    void closed(int num);

public slots:
    void onAddRuleBtnClicked();

public:
    int num;
private:
    Ui::CustomRuleCenterWidget *ui;
    bool isDragging;
    QPoint dragStartPosition;
protected:
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
    void closeEvent(QCloseEvent *event) override ;
    void paintEvent(QPaintEvent *event) override;
private:
    //先动态获取信息
    void getRuleSummaryInfo();
    std::vector<TabInfo> ruleSummary;

    void InitTab();
private:
    bool isMoving = false;
    QPoint startPos;
};

#endif // CUSTOMRULECENTERWIDGET_H
