#ifndef PROCESSRULEEDITDETAILWIDGET_H
#define PROCESSRULEEDITDETAILWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"
namespace Ui {
class ProcessRuleEditDetailWidget;
}

class ProcessRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit ProcessRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit ProcessRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ProcessRuleEditDetailWidget();

public slots:
	void onConfirmBtnClicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    Ui::ProcessRuleEditDetailWidget *ui;
	void initUi();
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleProcessCreation rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // PROCESSRULEEDITDETAILWIDGET_H
