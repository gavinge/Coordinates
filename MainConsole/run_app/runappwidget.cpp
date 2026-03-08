#include "runappwidget.h"
#include "ui_runappwidget.h"
#include "common/ItemDelegate.h"
RunAppWidget::RunAppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunAppWidget)
{
    ui->setupUi(this);

	InitAgentManMVCFW();

    initData();

    initGroupInfo();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}

RunAppWidget::~RunAppWidget()
{
    delete ui;
}

void RunAppWidget::initGroupInfo() {

	std::vector<AgentManagement::AgentGroupInfo> groups;

	AGENT_MAN_CONTROLLER->queryGroups(groups);

	ClearListWidget(ui->groupListWidget);

	for (int idx = 0; idx < groups.size(); idx++) {
		QListWidgetItem *item = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(groups[idx].GroupName.c_str())));
		item->setData(Qt::UserRole, QVariant(groups[idx].GroupID));
		ui->groupListWidget->addItem(item);
	}

	//默认选择第一个。
	QListWidgetItem* firstItem = ui->groupListWidget->item(0);
	ui->groupListWidget->clearSelection();
	ui->groupListWidget->setCurrentItem(firstItem, QItemSelectionModel::Select);

	nCurrentGroupID = groups[0].GroupID;

	connect(ui->groupListWidget, &QListWidget::itemClicked, this, &RunAppWidget::onGroupListItemSelected);
}


void RunAppWidget::onGroupListItemSelected(QListWidgetItem* item) {
	if (item) {

		int nSelectGroupID = item->data(Qt::UserRole).toInt();
		if (nSelectGroupID != nCurrentGroupID)
		{
			nCurrentGroupID = nSelectGroupID;
			//initMachineList(nCurrentGroupID);
		}
	}
}

bool RunAppWidget::InitAgentManMVCFW() {

	CAgentManModel* pModel = (CAgentManModel*)AGENT_MAN_CONTROLLER->GetBindModel();
	if (pModel)
	{
		pModel->AttachView((CAgentManBaseView*)this);
	}
	return true;
}

bool RunAppWidget::UpdateGroupInfo() {
	initGroupInfo();
	return true;
}

bool RunAppWidget::UpdateGroupInfo(long nGroupID, std::string strGroupName) {
	for (int idx = 0; idx < ui->groupListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->groupListWidget->item(idx);
		if (item->data(Qt::UserRole).toInt() == nGroupID) {
			item->setText(QString::fromLocal8Bit(("   " + strGroupName).c_str()));
			break;
		}
	}
	return true;
}

bool RunAppWidget::DeleteGroupInfo(long nGroupID) {

	for (int idx = 0; idx < ui->groupListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->groupListWidget->item(idx);
		if (item->data(Qt::UserRole).toInt() == nGroupID) {
			delete ui->groupListWidget->takeItem(idx);
			break;
		}
	}
	return true;
}

void RunAppWidget::ClearListWidget(QListWidget* listWidget) {
	if (!listWidget) return;
	for (int idx = 0; idx < listWidget->count(); ++idx) {
		QListWidgetItem* item = listWidget->item(idx);
		QWidget* widget = listWidget->itemWidget(item);
		if (widget) {
			delete widget;
		}
		delete item;
	}
	listWidget->clear();
}
void RunAppWidget::initData(){
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选择
    ui->tableWidget->setShowGrid(false); //不显示表格线
    //ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //垂直滚动条
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setColumnCount(8);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//第一列固定宽度
    //ui->tableWidget->setRowCount(10);
    // 设置表头
    QStringList headerLabels;
    //headerLabels << "Checkbox" << "Column 2" << "Column 3";

    headerLabels << QString::fromLocal8Bit("状态")
                 << QString::fromLocal8Bit("任务名称")
                 << QString::fromLocal8Bit("执行文件")
                 << QString::fromLocal8Bit("启动参数")
                 << QString::fromLocal8Bit("延时")
                 << QString::fromLocal8Bit("生效IP")
                 << QString::fromLocal8Bit("生效系统")
                 << QString::fromLocal8Bit(" ");

    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setColumnWidth(0, 70);  // 第一列的宽度
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setColumnWidth(2, 220);
    ui->tableWidget->setColumnWidth(3, 170);
    ui->tableWidget->setColumnWidth(4, 100);
    ui->tableWidget->setColumnWidth(5, 120);
    ui->tableWidget->setColumnWidth(6, 120);

    //965  70,      660(220,440)          120,120
    //ui->tableWidget->setAlternatingRowColors(true);  //交替展示
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //去掉可编辑权限
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);//点击之后，header不高亮


    //InnerRuleInfo rule_info(1, 23, "基础广告", 12, "拦截桌面广告图标、广告进程等", "23.12.11", "描述");

    // 增加10行数据
    for (int row = 0; row < 10; ++row) {
        //0.状态
        /*QTableWidgetItem* p_check = new QTableWidgetItem();
        p_check->setCheckState(1 ? Qt::Checked : Qt::Unchecked );
        ui->tableWidget->setItem(row,0,p_check);

        //1.任务名称
        QTableWidgetItem *textItem1 = new QTableWidgetItem(QString::fromLocal8Bit(rule_info.Name.c_str()));
        textItem1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 1, textItem1);

        //2.规则说明
        QString strParentDetail(QString::fromLocal8Bit(rule_info.Des.c_str()));
        QTableWidgetItem *textItem2 = new QTableWidgetItem(strParentDetail);
        textItem2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 2, textItem2);

        //3.版本
        QTableWidgetItem *textItem3 = new QTableWidgetItem(QString::fromLocal8Bit(rule_info.Ver.c_str()));
        textItem3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 3, textItem3);


        //4.编号
        QTableWidgetItem *textItem4 = new QTableWidgetItem(QString("%1").arg(rule_info.DefaultID));
        textItem4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 4, textItem4);


        //5.一列空的
        QTableWidgetItem *textItem10 = new QTableWidgetItem("");
        textItem1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 5, textItem10);*/
    }
}
