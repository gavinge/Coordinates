#ifndef MODULERULEEDITDETAILWIDGET_H
#define MODULERULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class ModuleRuleEditDetailWidget;
}

class ModuleRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModuleRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ModuleRuleEditDetailWidget();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;

private:
    Ui::ModuleRuleEditDetailWidget *ui;
private:
    bool isMoving = false;
    QPoint startPos;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // MODULERULEEDITDETAILWIDGET_H
