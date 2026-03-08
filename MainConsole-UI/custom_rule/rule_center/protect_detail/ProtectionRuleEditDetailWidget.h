#ifndef PROTECTIONRULEEDITDETAILWIDGET_H
#define PROTECTIONRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class ProtectionRuleEditDetailWidget;
}

class ProtectionRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProtectionRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ProtectionRuleEditDetailWidget();

private:
    Ui::ProtectionRuleEditDetailWidget *ui;
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

#endif // PROTECTIONRULEEDITDETAILWIDGET_H
