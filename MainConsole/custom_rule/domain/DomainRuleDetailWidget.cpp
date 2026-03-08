#include "DomainRuleDetailWidget.h"
#include "ui_DomainRuleDetailWidget.h"

#include "common/GlobalDefineUtility.h"
#include "common/ItemDelegate.h"

#include "../rule_center/domain_detail/DomainRuleEditDetailWidget.h"

DomainRuleDetailWidget::DomainRuleDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DomainRuleDetailWidget),
	parentPtr(NULL),
	nCurrentRuleID(0),
	nCurrentGroupID(1)
{
    ui->setupUi(this);
    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);

	//connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &DomainRuleDetailWidget::onTableItemDoubleClicked);
}

DomainRuleDetailWidget::DomainRuleDetailWidget(QWidget *parent,RuleViewModel model) :
    QWidget(parent),
    ui(new Ui::DomainRuleDetailWidget),
    ruleViewModel(model),
	parentPtr(NULL),
	nCurrentRuleID(0),
	nCurrentGroupID(1)
{
    ui->setupUi(this);
    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
	connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &DomainRuleDetailWidget::onTableItemDoubleClicked);
}

DomainRuleDetailWidget::~DomainRuleDetailWidget()
{
    delete ui;
}

#include <QTextStream>
void DomainRuleDetailWidget::onTableItemDoubleClicked(QTableWidgetItem *item)
{
	int selectedRow = item->row();
	QTableWidgetItem* pItem = ui->tableWidget->item(selectedRow, 0);
	if (pItem)
	{
		nCurrentRuleID = pItem->data(Qt::UserRole).toInt();

		/*DomainRuleEditDetailWidget detailWidget(this, RuleViewModel::DisplayModel, nCurrentRuleID);
		detailWidget.setWindowModality(Qt::WindowModal);
		QFile file(":/res/qss/style.qss");
		if (file.open(QFile::ReadOnly | QFile::Text)) {
			QTextStream stream(&file);
			QString styleSheet = stream.readAll();
			detailWidget.setStyleSheet(styleSheet);
			file.close();
		}
		detailWidget.show();
		QEventLoop loop;
		loop.exec();*/


		/*DomainRuleEditDetailWidget detailWidget(this, RuleViewModel::DisplayModel, nCurrentRuleID);
		detailWidget.setWindowModality(Qt::WindowModal);
		QEventLoop loop;
		detailWidget.show();
		loop.exec();*/


		/*DomainRuleEditDetailWidget detailWidget(this, RuleViewModel::DisplayModel, nCurrentRuleID);
		detailWidget.setWindowModality(Qt::ApplicationModal);
		QFile file(":/res/qss/style.qss");
		if (file.open(QFile::ReadOnly | QFile::Text)) {
			QTextStream stream(&file);
			QString styleSheet = stream.readAll();
			detailWidget.setStyleSheet(styleSheet);
			file.close();
		}
		detailWidget.show();
		QEventLoop loop;
		loop.exec();*/
	}
}
void DomainRuleDetailWidget::onItemChanged(QTableWidgetItem *item) {
	if (!parentPtr || !item) {
		return;
	}
	if (item->column() == 0) {
		QTableWidgetItem* pItem = ui->tableWidget->item(item->row(), 0);
		if (pItem)
		{
			nCurrentRuleID = pItem->data(Qt::UserRole).toInt();
			if (item->checkState() == Qt::Checked) {
				((CustomRuleWidget*)parentPtr)->EnableRuleInfo(true, RuleType::DomainRuleType, nCurrentRuleID);
			}
			else {
				((CustomRuleWidget*)parentPtr)->EnableRuleInfo(false, RuleType::DomainRuleType, nCurrentRuleID);
			}
		}
	}
}

void DomainRuleDetailWidget::contextMenuEvent(QContextMenuEvent *event)
{

	QPoint pos = event->pos();
	pos.setY(pos.y() - 40);
	if (!ui->tableWidget->rect().contains(ui->tableWidget->mapFromParent(pos))) {
		return;
	}

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

int DomainRuleDetailWidget::RefreshList() {
	return initData();
}

int DomainRuleDetailWidget::RefreshListByGourpID(int agentGroupID) {
	nCurrentGroupID = agentGroupID;
	return initData();
}
void DomainRuleDetailWidget::setCustomRuleWidgetPtr(void* parent) {
	parentPtr = parent;
}

long DomainRuleDetailWidget::getCurrentRuleID() {
	return nCurrentRuleID;
}
int DomainRuleDetailWidget::initData(){
	ClearTable(ui->tableWidget);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选择
    ui->tableWidget->setShowGrid(false); //不显示表格线
    //ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //垂直滚动条
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setColumnCount(10);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//第一列固定宽度
    ui->tableWidget->setRowCount(10);
    // 设置表头
    QStringList headerLabels;
    //headerLabels << "Checkbox" << "Column 2" << "Column 3";

    std::string colum1header = ruleViewModel == RuleViewModel::DisplayModel ? "状态" : "编号";
    headerLabels << QString::fromLocal8Bit(colum1header.c_str())
                 << QString::fromLocal8Bit("源进程类型")
                 << QString::fromLocal8Bit("源进程信息")
                 << QString::fromLocal8Bit("网站域名")
                 << QString::fromLocal8Bit("处理方式")
                 << QString::fromLocal8Bit("生效系统")
                 << QString::fromLocal8Bit("备注")
                 << QString::fromLocal8Bit("上报日志")
                 << QString::fromLocal8Bit("优先级别")
                 << QString::fromLocal8Bit(" ");


    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setColumnWidth(0, 70);  // 第一列的宽度为100像素
    for (int rowIdx = 1; rowIdx <=9 ; rowIdx++ ) {
        ui->tableWidget->setColumnWidth(rowIdx, 95);
    }
    //ui->tableWidget->setAlternatingRowColors(true);  //交替展示
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //去掉可编辑权限
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);//点击之后，header不高亮
	   
	return LoadRuleList();
}


bool DomainRuleDetailWidget::ClearTable(QTableWidget* tableWidget) {

	if (!tableWidget)
		return false;

	tableWidget->setUpdatesEnabled(false);

	for (int row = 0; row < tableWidget->rowCount(); ++row) {
		for (int col = 0; col < tableWidget->columnCount(); ++col) {
			QTableWidgetItem *item = tableWidget->takeItem(row, col);
			if (item)
			{
				delete item;
			}
		}
	}

	tableWidget->setRowCount(0);

	tableWidget->setColumnCount(0);

	tableWidget->setUpdatesEnabled(true);
	return true;
}

int DomainRuleDetailWidget::LoadRuleList() {

	std::vector<RuleManagement::RuleDomainProtect> domainProtectRules;
	RULE_MAN_CONTROLLER->queryDomainProtect(nCurrentGroupID, domainProtectRules);

	ui->tableWidget->setRowCount(domainProtectRules.size());

	ui->tableWidget->blockSignals(true);

	for (int row = 0; row < domainProtectRules.size(); ++row) {

		RuleManagement::RuleDomainProtect rule_info(domainProtectRules[row]);
		//0.状态或者编号
		QTableWidgetItem* pItem = NULL;
		if (ruleViewModel == RuleViewModel::DisplayModel) {
			pItem = new QTableWidgetItem();
			pItem->setCheckState(rule_info.Enabled >= 1 ? Qt::Checked : Qt::Unchecked);
		}
		else {
			pItem = new QTableWidgetItem(QString("%1").arg(row));
			pItem->setTextAlignment(Qt::AlignCenter);
		}
		if (pItem)
		{
			pItem->setData(Qt::UserRole, QVariant(rule_info.RID));
		}
		ui->tableWidget->setItem(row, 0, pItem);

		//1.源进程类型
		QTableWidgetItem *textItem1 = new QTableWidgetItem(QString::fromLocal8Bit(ProcessInfoTypeUtility::K2V(rule_info.ProcessInfoType).c_str()));
		textItem1->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 1, textItem1);

		//2.源进程信息
		QString strParentDetail(QString::fromLocal8Bit(rule_info.ProcessInfo.c_str()));
		QTableWidgetItem *textItem2 = new QTableWidgetItem(strParentDetail);
		textItem2->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 2, textItem2);

		//3.网站域名
		QTableWidgetItem *textItem3 = new QTableWidgetItem(QString::fromLocal8Bit(rule_info.DomainName.c_str()));
		textItem3->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 3, textItem3);


		//4.处理方式
		QTableWidgetItem *textItem5 = new QTableWidgetItem(QString::fromLocal8Bit(""));
		textItem5->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 4, textItem5);


		//5.生效系统
		QTableWidgetItem *textItem6 = new QTableWidgetItem(QString::fromLocal8Bit((WindowsVersionUtility::K2V(rule_info.OsVersion).c_str())));
		textItem6->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 5, textItem6);

		//6.备注
		QString strMark(QString::fromLocal8Bit(rule_info.Remark.c_str()));
		QTableWidgetItem *textItem7 = new QTableWidgetItem(strMark);
		textItem7->setTextAlignment(Qt::AlignCenter);
		//textItem7->setToolTip(strMark);
		ui->tableWidget->setItem(row, 6, textItem7);


		//7.日志
		QTableWidgetItem *textItem8 = new QTableWidgetItem(QString::fromLocal8Bit((LogStateUtility::K2V(rule_info.Log).c_str())));
		textItem8->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 7, textItem8);

		//8.优先级
		QTableWidgetItem *textItem9 = new QTableWidgetItem(QString("%1").arg(rule_info.Priority));
		textItem9->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 8, textItem9);

		//9.一列空的
		QTableWidgetItem *textItem10 = new QTableWidgetItem("");
		textItem1->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(row, 9, textItem10);
	}

	ui->tableWidget->blockSignals(false);
	connect(ui->tableWidget, &QTableWidget::itemChanged, this, &DomainRuleDetailWidget::onItemChanged);
	return domainProtectRules.size();
}