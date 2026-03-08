#ifndef NETWORKRULEDETAILWIDGET_H
#define NETWORKRULEDETAILWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "..\CustomRuleUtility.h"
#include "../Controller/RuleManController.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"

namespace Ui {
class NetWorkRuleDetailWidget;
}



class NetWorkRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NetWorkRuleDetailWidget(QWidget *parent = nullptr);
    explicit NetWorkRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~NetWorkRuleDetailWidget();
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
    Ui::NetWorkRuleDetailWidget *ui;
    int initData();

private:
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentRuleID;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // NETWORKRULEDETAILWIDGET_H
