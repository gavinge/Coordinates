#ifndef REGISTERRULEEDITDETAILWIDGET_H
#define REGISTERRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class RegisterRuleEditDetailWidget;
}

class RegisterRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterRuleEditDetailWidget(QWidget *parent = nullptr);
    ~RegisterRuleEditDetailWidget();

private:
    Ui::RegisterRuleEditDetailWidget *ui;
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

#endif // REGISTERRULEEDITDETAILWIDGET_H
