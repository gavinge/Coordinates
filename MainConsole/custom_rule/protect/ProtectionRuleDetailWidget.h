#ifndef PROTECTIONRULEDETAILWIDGET_H
#define PROTECTIONRULEDETAILWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "..\CustomRuleUtility.h"
#include "../Controller/RuleManController.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"

namespace Ui {
class ProtectionRuleDetailWidget;
}


class ProtectionRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProtectionRuleDetailWidget(QWidget *parent = nullptr);
    explicit ProtectionRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ProtectionRuleDetailWidget();
	int RefreshList();
	int RefreshListByGourpID(int agentGroupID);

	void setCustomRuleWidgetPtr(void* parent);
	long getCurrentRuleID();

private slots:
	void onItemChanged(QTableWidgetItem *item);

protected:
	void contextMenuEvent(QContextMenuEvent *event) override;
private:
	bool ClearTable(QTableWidget* tableWidget);
	int LoadRuleList();
private:
    Ui::ProtectionRuleDetailWidget *ui;
    int initData();

private:
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentRuleID;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // PROTECTIONRULEDETAILWIDGET_H
