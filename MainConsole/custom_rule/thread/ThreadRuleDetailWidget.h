#ifndef THREADRULEDETAILWIDGET_H
#define THREADRULEDETAILWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "..\CustomRuleUtility.h"
#include "../Controller/RuleManController.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"

namespace Ui {
class ThreadRuleDetailWidget;
}

class ThreadRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadRuleDetailWidget(QWidget *parent = nullptr);
    explicit ThreadRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ThreadRuleDetailWidget();
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
    Ui::ThreadRuleDetailWidget *ui;
    int initData();

private:
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentRuleID;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // THREADRULEDETAILWIDGET_H
