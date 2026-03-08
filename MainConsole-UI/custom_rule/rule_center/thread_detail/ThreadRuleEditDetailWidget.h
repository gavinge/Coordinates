#ifndef THREADRULEEDITDETAILWIDGET_H
#define THREADRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class ThreadRuleEditDetailWidget;
}

class ThreadRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ThreadRuleEditDetailWidget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;

private:
    Ui::ThreadRuleEditDetailWidget *ui;
private:
    bool isMoving = false;
    QPoint startPos;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // THREADRULEEDITDETAILWIDGET_H
