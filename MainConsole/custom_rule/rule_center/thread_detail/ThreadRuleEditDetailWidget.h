#ifndef THREADRULEEDITDETAILWIDGET_H
#define THREADRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"
namespace Ui {
class ThreadRuleEditDetailWidget;
}

class ThreadRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit ThreadRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit ThreadRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ThreadRuleEditDetailWidget();

public slots:
	void onConfirmBtnClicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;

private:
    Ui::ThreadRuleEditDetailWidget *ui;
	void initUi();
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleThreadCreation rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // THREADRULEEDITDETAILWIDGET_H
