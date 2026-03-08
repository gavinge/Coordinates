#include "runappwidget.h"
#include "ui_runappwidget.h"
#include "common/ItemDelegate.h"
RunAppWidget::RunAppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunAppWidget)
{
    ui->setupUi(this);
    initData();
    initGroupInfo();
    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}

RunAppWidget::~RunAppWidget()
{
    delete ui;
}

void RunAppWidget::initGroupInfo(){
    //AgentGroupInfo group_instance(1, "分组1", 2, 1, "描述");
    std::string GroupName = "分组测试";
    for (int idx = 0; idx <10 ; idx++ ) {
        QListWidgetItem *item1 = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(GroupName.c_str())));
        ui->groupListWidget->addItem(item1);
    }
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
