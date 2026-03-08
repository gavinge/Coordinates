#ifndef KERNELRULEEDITDETAILWIDGET_H
#define KERNELRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class KernelRuleEditDetailWidget;
}

class KernelRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KernelRuleEditDetailWidget(QWidget *parent = nullptr);
    ~KernelRuleEditDetailWidget();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    Ui::KernelRuleEditDetailWidget *ui;
private:
    bool isMoving = false;
    QPoint startPos;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // KERNELRULEEDITDETAILWIDGET_H
