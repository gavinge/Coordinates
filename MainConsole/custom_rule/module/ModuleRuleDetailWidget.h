#ifndef MODULERULEDETAILWIDGET_H
#define MODULERULEDETAILWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "..\CustomRuleUtility.h"
#include "../Controller/RuleManController.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"

namespace Ui {
class ModuleRuleDetailWidget;
}



class ModuleRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModuleRuleDetailWidget(QWidget *parent = nullptr);
    explicit ModuleRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ModuleRuleDetailWidget();
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
    Ui::ModuleRuleDetailWidget *ui;
    int initData();

private:
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentRuleID;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // MODULERULEDETAILWIDGET_H
