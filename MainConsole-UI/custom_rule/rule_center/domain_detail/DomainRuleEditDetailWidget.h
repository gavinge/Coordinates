#ifndef DOMAINRULEEDITDETAILWIDGET_H
#define DOMAINRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class DomainRuleEditDetailWidget;
}

class DomainRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DomainRuleEditDetailWidget(QWidget *parent = nullptr);
    ~DomainRuleEditDetailWidget();

private:
    Ui::DomainRuleEditDetailWidget *ui;
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

#endif // DOMAINRULEEDITDETAILWIDGET_H
