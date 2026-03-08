#ifndef PROCESSRULEEDITDETAILWIDGET_H
#define PROCESSRULEEDITDETAILWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class ProcessRuleEditDetailWidget;
}

class ProcessRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ProcessRuleEditDetailWidget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    Ui::ProcessRuleEditDetailWidget *ui;

private:
    bool isMoving = false;
    QPoint startPos;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // PROCESSRULEEDITDETAILWIDGET_H
