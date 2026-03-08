#ifndef DOMAINRULEDETAILWIDGET_H
#define DOMAINRULEDETAILWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "..\CustomRuleUtility.h"
#include "../Controller/RuleManController.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"


namespace Ui {
class DomainRuleDetailWidget;
}


class DomainRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DomainRuleDetailWidget(QWidget *parent = nullptr);
    explicit DomainRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~DomainRuleDetailWidget();
	int RefreshList();
	int RefreshListByGourpID(int agentGroupID);

	void setCustomRuleWidgetPtr(void* parent);
	long getCurrentRuleID();
private slots:
	void onTableItemDoubleClicked(QTableWidgetItem *item);
private slots:
	void onItemChanged(QTableWidgetItem *item);
protected:
	void contextMenuEvent(QContextMenuEvent *event) override;
private:
	bool ClearTable(QTableWidget* tableWidget);
	int LoadRuleList();
private:
    Ui::DomainRuleDetailWidget *ui;
    int initData();
private:
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentRuleID;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // DOMAINRULEDETAILWIDGET_H
