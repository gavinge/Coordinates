#ifndef PROTECTIONRULEEDITDETAILWIDGET_H
#define PROTECTIONRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"

namespace Ui {
class ProtectionRuleEditDetailWidget;
}

class ProtectionRuleEditDetailWidget : public QWidget
{
    Q_OBJECT	

public:
	explicit ProtectionRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit ProtectionRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ProtectionRuleEditDetailWidget();
public slots:
	void onConfirmBtnClicked();
private:
    Ui::ProtectionRuleEditDetailWidget *ui;
	void initUi();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleProcProtect rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // PROTECTIONRULEEDITDETAILWIDGET_H
