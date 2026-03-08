#include "innerrulewidget.h"
#include "ui_innerrulewidget.h"

#include "common/ItemDelegate.h"
InnerRuleWidget::InnerRuleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InnerRuleWidget)
{
    ui->setupUi(this);
    initGroupInfo();
    InitTab();
    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}

InnerRuleWidget::~InnerRuleWidget()
{
    delete ui;
}

void InnerRuleWidget::initGroupInfo(){
    //AgentGroupInfo group_instance(1, "分组测试", 2, 1, "描述");
    std::string GroupName = "分组测试";
    for (int idx = 0; idx <10 ; idx++ ) {
        QListWidgetItem *item1 = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(GroupName.c_str())));
        ui->groupListWidget->addItem(item1);
    }
}

void InnerRuleWidget::getRuleSummaryInfo()
{
    ruleSummary.push_back({0, QString::fromLocal8Bit("所有类型"), InnerRuleClassify::All,199});
    ruleSummary.push_back({1, QString::fromLocal8Bit("计费类"), InnerRuleClassify::Accounting,11});
    ruleSummary.push_back({2, QString::fromLocal8Bit("无盘类"), InnerRuleClassify::DiskLess,11});
    ruleSummary.push_back({3, QString::fromLocal8Bit("营销类"), InnerRuleClassify::Marketing,11});
    ruleSummary.push_back({4, QString::fromLocal8Bit("文娱类"), InnerRuleClassify::Entertainment,12});
    ruleSummary.push_back({5, QString::fromLocal8Bit("安全类"), InnerRuleClassify::Security,111});
    ruleSummary.push_back({6, QString::fromLocal8Bit("综合类"), InnerRuleClassify::Comprehensive,222});
}
void InnerRuleWidget::InitTab()
{
    getRuleSummaryInfo();

    std::vector<TabClassifyInfo>::iterator it;
    for (it = ruleSummary.begin(); it != ruleSummary.end(); ++it) {
        const TabClassifyInfo& tab = *it;
        QWidget* tb = new QWidget(this);

        int idx = ui->tabWidget->addTab(tb, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
        ui->tabWidget->widget(idx)->hide();
    }
}

void InnerRuleWidget::initData(){
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选择
    ui->tableWidget->setShowGrid(false); //不显示表格线
    //ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //垂直滚动条
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setColumnCount(6);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//第一列固定宽度
    ui->tableWidget->setRowCount(10);
    // 设置表头
    QStringList headerLabels;
    //headerLabels << "Checkbox" << "Column 2" << "Column 3";

    headerLabels << QString::fromLocal8Bit("状态")
                 << QString::fromLocal8Bit("规则名称")
                 << QString::fromLocal8Bit("规则说明")
                 << QString::fromLocal8Bit("版本")
                 << QString::fromLocal8Bit("编号")
                 << QString::fromLocal8Bit(" ");

    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setColumnWidth(0, 70);  // 第一列的宽度
    ui->tableWidget->setColumnWidth(1, 220);
    ui->tableWidget->setColumnWidth(2, 440);
    ui->tableWidget->setColumnWidth(3, 120);
    ui->tableWidget->setColumnWidth(4, 120);

    //965  70,      660(220,440)          120,120
    //ui->tableWidget->setAlternatingRowColors(true);  //交替展示
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //去掉可编辑权限
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);//点击之后，header不高亮


    InnerRuleInfo rule_info(1, 23, "基础广告", 12, "拦截桌面广告图标、广告进程等", "23.12.11", "描述");

    // 增加10行数据
    for (int row = 0; row < 10; ++row) {
        //0.状态
        QTableWidgetItem* p_check = new QTableWidgetItem();
        p_check->setCheckState(1 ? Qt::Checked : Qt::Unchecked );
        ui->tableWidget->setItem(row,0,p_check);

        //1.规则名称
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
        ui->tableWidget->setItem(row, 5, textItem10);
    }
}
