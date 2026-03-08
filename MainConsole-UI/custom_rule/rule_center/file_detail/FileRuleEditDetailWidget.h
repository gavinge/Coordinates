#ifndef FILERULEEDITDETAILWIDGET_H
#define FILERULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"

namespace Ui {
class FileRuleEditDetailWidget;
}

class FileRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileRuleEditDetailWidget(QWidget *parent = nullptr);
    ~FileRuleEditDetailWidget();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    Ui::FileRuleEditDetailWidget *ui;
private:
    bool isMoving = false;
    QPoint startPos;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // FILERULEEDITDETAILWIDGET_H
