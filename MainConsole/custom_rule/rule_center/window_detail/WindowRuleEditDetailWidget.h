#ifndef WINDOWRULEEDITDETAILWIDGET_H
#define WINDOWRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class WindowRuleEditDetailWidget;
}

class WindowRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit WindowRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit WindowRuleEditDetailWidget(QWidget *parent = nullptr);
    ~WindowRuleEditDetailWidget();

private:
    Ui::WindowRuleEditDetailWidget *ui;
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
	//RuleManagement::RuleThreadCreation rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // WINDOWRULEEDITDETAILWIDGET_H
