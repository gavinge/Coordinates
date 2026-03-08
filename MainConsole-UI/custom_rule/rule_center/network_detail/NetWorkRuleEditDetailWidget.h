#ifndef NETWORKRULEEDITDETAILWIDGET_H
#define NETWORKRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class NetWorkRuleEditDetailWidget;
}

class NetWorkRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NetWorkRuleEditDetailWidget(QWidget *parent = nullptr);
    ~NetWorkRuleEditDetailWidget();

private:
    Ui::NetWorkRuleEditDetailWidget *ui;
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // NETWORKRULEEDITDETAILWIDGET_H
