#include "ProcessRuleDetailWidget.h"
#include "ui_ProcessRuleDetailWidget.h"

#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

#include "common/GlobalDefineUtility.h"
#include "common/ItemDelegate.h"


ProcessRuleDetailWidget::ProcessRuleDetailWidget(QWidget *parent,RuleViewModel model) :
    QWidget(parent),
    ui(new Ui::ProcessRuleDetailWidget),
    ruleViewModel(model)
{
    ui->setupUi(this);
    //QMessageBox::information(this,"ProcessRuleDetailWidget","ProcessRuleDetailWidget");

    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}

ProcessRuleDetailWidget::ProcessRuleDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessRuleDetailWidget)
{
    ui->setupUi(this);
    //QMessageBox::information(this,"ProcessRuleDetailWidget","ProcessRuleDetailWidget");

    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}

ProcessRuleDetailWidget::~ProcessRuleDetailWidget()
{
    delete ui;
}

void ProcessRuleDetailWidget::initData(){
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选择
    ui->tableWidget->setShowGrid(false); //不显示表格线
    //ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //垂直滚动条
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setColumnCount(11);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//第一列固定宽度
    ui->tableWidget->setRowCount(10);
    // 设置表头
    QStringList headerLabels;
    //headerLabels << "Checkbox" << "Column 2" << "Column 3";

    std::string colum1header = ruleViewModel == RuleViewModel::DisplayModel ? "状态" : "编号";
    headerLabels << QString::fromLocal8Bit(colum1header.c_str())
                 << QString::fromLocal8Bit("父进程类型")
                 << QString::fromLocal8Bit("父进程信息")
                 << QString::fromLocal8Bit("子进程类型")
                 << QString::fromLocal8Bit("子进程信息")
                 << QString::fromLocal8Bit("处理方式")
                 << QString::fromLocal8Bit("生效系统")
                 << QString::fromLocal8Bit("备注")
                 << QString::fromLocal8Bit("上报日志")
                 << QString::fromLocal8Bit("优先级别")
                 << QString::fromLocal8Bit(" ");

    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setColumnWidth(0, 70);  // 第一列的宽度为100像素
    for (int rowIdx = 1; rowIdx <=11 ; rowIdx++ ) {
        ui->tableWidget->setColumnWidth(rowIdx, 95);
    }
    //ui->tableWidget->setAlternatingRowColors(true);  //交替展示
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //去掉可编辑权限
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);//点击之后，header不高亮

    /*
    int RID;
    int RuleGroupID;
    int OperationCode; //6
    int RuleType;
    int ChildProcessInfoType; //4
    std::string ChildProcessInfo; //5
    int ParentProcessInfoType;  //2
    std::string ParentProcessInfo;//3
    int InnerID;
    int InnerFlg;
    int Enabled; // 1
    int Log; //9
    std::string Remark; //8
    int OsVersion; //7
    */
    RuleProcessCreation process_rule_info(1,28, 0, 1, 0, "*calc.exe", 0, "*", 28,1, 1, 1, "123123123123123123123123", 3);

    // 增加10行数据
    for (int row = 0; row < 10; ++row) {
        //0.状态或者编号
        QTableWidgetItem* pItem = NULL;
        if(ruleViewModel == RuleViewModel::DisplayModel){
            pItem = new QTableWidgetItem();
            pItem->setCheckState(process_rule_info.Enabled >= 1 ? Qt::Checked : Qt::Unchecked );
        }
        else{
            pItem = new QTableWidgetItem(QString("%1").arg(row));
            pItem->setTextAlignment(Qt::AlignCenter);
        }
        ui->tableWidget->setItem(row,0,pItem);

        //1.父进程类型
        QTableWidgetItem *textItem1 = new QTableWidgetItem(QString::fromLocal8Bit(ProcessInfoTypeUtility::K2V(process_rule_info.ParentProcessInfoType).c_str()));
        textItem1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 1, textItem1);

        //2.父进程详情
        QString strParentDetail(QString::fromLocal8Bit(process_rule_info.ParentProcessInfo.c_str()));
        QTableWidgetItem *textItem2 = new QTableWidgetItem(strParentDetail);
        //textItem2->setToolTip(strParentDetail);
        textItem2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 2, textItem2);

        //3.子进程类型
        QTableWidgetItem *textItem3 = new QTableWidgetItem(QString::fromLocal8Bit((ProcessInfoTypeUtility::K2V(process_rule_info.ChildProcessInfoType).c_str())));
        textItem3->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(row, 3, textItem3);


        //4.子进程详情
        QTableWidgetItem *textItem4 = new QTableWidgetItem(QString::fromLocal8Bit(process_rule_info.ChildProcessInfo.c_str()));
        textItem4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 4, textItem4);

        //5.处理方式
        QTableWidgetItem *textItem5 = new QTableWidgetItem(QString::fromLocal8Bit((ProcessActionUtility::K2V(process_rule_info.OperationCode).c_str())));
        textItem5->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 5, textItem5);


        //6.生效系统
        QTableWidgetItem *textItem6 = new QTableWidgetItem(QString::fromLocal8Bit((WindowsVersionUtility::K2V(process_rule_info.OsVersion).c_str())));
        textItem6->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 6, textItem6);

        //7.备注
        QString strMark(QString::fromLocal8Bit(process_rule_info.Remark.c_str()));
        QTableWidgetItem *textItem7 = new QTableWidgetItem(strMark);
        textItem7->setTextAlignment(Qt::AlignCenter);
        //textItem7->setToolTip(strMark);
        ui->tableWidget->setItem(row, 7, textItem7);


        //8.日志
        QTableWidgetItem *textItem8 = new QTableWidgetItem(QString::fromLocal8Bit((LogStateUtility::K2V(process_rule_info.Log).c_str())));
        textItem8->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 8, textItem8);

        //9.优先级
        QTableWidgetItem *textItem9 = new QTableWidgetItem(QString::fromLocal8Bit("30"));
        textItem9->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 9, textItem9);

        //10.一列空的
        QTableWidgetItem *textItem10 = new QTableWidgetItem("");
        textItem1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 10, textItem10);
    }
}

