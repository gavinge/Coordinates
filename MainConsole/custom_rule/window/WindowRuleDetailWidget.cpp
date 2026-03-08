#include "WindowRuleDetailWidget.h"
#include "ui_WindowRuleDetailWidget.h"

WindowRuleDetailWidget::WindowRuleDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowRuleDetailWidget),
	parentPtr(NULL),
	nCurrentRuleID(0),
	nCurrentGroupID(1)
{
    ui->setupUi(this);
}

WindowRuleDetailWidget::WindowRuleDetailWidget(QWidget *parent,RuleViewModel model) :
    QWidget(parent),
    ui(new Ui::WindowRuleDetailWidget),
    ruleViewModel(model),
	parentPtr(NULL),
	nCurrentRuleID(0),
	nCurrentGroupID(1)
{
    ui->setupUi(this);
}

WindowRuleDetailWidget::~WindowRuleDetailWidget()
{
    delete ui;
}

void WindowRuleDetailWidget::contextMenuEvent(QContextMenuEvent *event)
{
	if (!parentPtr) {
		return;
	}
	QMenu* menuRuleDetailOper = NULL;
	if (ruleViewModel == RuleViewModel::DisplayModel)
	{
		menuRuleDetailOper = ((CustomRuleWidget*)parentPtr)->getRuleDetailMenu();
	}
	else
	{
		menuRuleDetailOper = ((CustomRuleCenterWidget*)parentPtr)->getRuleDetailMenu();
	}

	if (!menuRuleDetailOper) {
		return;
	}
	QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
	if (!selectedRows.isEmpty()) {
		int selectedRow = selectedRow = selectedRows.first().row();
		QTableWidgetItem* pItem = ui->tableWidget->item(selectedRow, 0);
		if (pItem)
		{
			nCurrentRuleID = pItem->data(Qt::UserRole).toInt();

			menuRuleDetailOper->exec(event->globalPos());
		}
	}
}

bool WindowRuleDetailWidget::RefreshList() {
	return true;
}
int WindowRuleDetailWidget::RefreshListByGourpID(int agentGroupID) {
	nCurrentGroupID = agentGroupID;
	return 1;// initData();
}

void WindowRuleDetailWidget::setCustomRuleWidgetPtr(void* parent) {
	parentPtr = parent;
}

long WindowRuleDetailWidget::getCurrentRuleID() {
	return nCurrentRuleID;
}