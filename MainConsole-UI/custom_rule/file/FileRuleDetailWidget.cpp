#include "FileRuleDetailWidget.h"
#include "ui_FileRuleDetailWidget.h"

#include "common/GlobalDefineUtility.h"
#include "common/ItemDelegate.h"

FileRuleDetailWidget::FileRuleDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileRuleDetailWidget)
{
    ui->setupUi(this);
    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}
FileRuleDetailWidget::FileRuleDetailWidget(QWidget *parent,RuleViewModel model) :
    QWidget(parent),
    ui(new Ui::FileRuleDetailWidget),
    ruleViewModel(model)
{
    ui->setupUi(this);
    initData();

    CustomItemDelegate *delegate = new CustomItemDelegate(ui->tableWidget);
    ui->tableWidget->setItemDelegate(delegate);
}

FileRuleDetailWidget::~FileRuleDetailWidget()
{
    delete ui;
}


void FileRuleDetailWidget::initData(){
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选择
    ui->tableWidget->setShowGrid(false); //不显示表格线
    //ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //垂直滚动条
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setColumnCount(13);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//第一列固定宽度
    ui->tableWidget->setRowCount(10);
    // 设置表头
    QStringList headerLabels;
    //headerLabels << "Checkbox" << "Column 2" << "Column 3";

    std::string colum1header = ruleViewModel == RuleViewModel::DisplayModel ? "状态" : "编号";
    headerLabels << QString::fromLocal8Bit(colum1header.c_str())
                 << QString::fromLocal8Bit("源进程类型")
                 << QString::fromLocal8Bit("源进程信息")
                 << QString::fromLocal8Bit("目标文件类型")
                 << QString::fromLocal8Bit("目标文件信息")
                 << QString::fromLocal8Bit("处理方式")
                 << QString::fromLocal8Bit("禁止权限")
                 << QString::fromLocal8Bit("文件转向")
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



    RuleFileProtect rule_info(1,21, 0, 2, 0, "*cmd.exe", 0, "*123.txt", 1, 1, "123123123123123123123123123123123123123123", 222, 3,28,1);


    // 增加10行数据
    for (int row = 0; row < 10; ++row) {
        //0.状态或者编号
        QTableWidgetItem* pItem = NULL;
        if(ruleViewModel == RuleViewModel::DisplayModel){
            pItem = new QTableWidgetItem();
            pItem->setCheckState(rule_info.Enabled >= 1 ? Qt::Checked : Qt::Unchecked );
        }
        else{
            pItem = new QTableWidgetItem(QString("%1").arg(row));
            pItem->setTextAlignment(Qt::AlignCenter);
        }
        ui->tableWidget->setItem(row,0,pItem);

        //1.源进程类型
        QTableWidgetItem *textItem1 = new QTableWidgetItem(QString::fromLocal8Bit(ProcessInfoTypeUtility::K2V(rule_info.ProcessInfoType).c_str()));
        textItem1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 1, textItem1);

        //2.源进程信息
        QString strParentDetail(QString::fromLocal8Bit(rule_info.ProcessInfo.c_str()));
        QTableWidgetItem *textItem2 = new QTableWidgetItem(strParentDetail);
        textItem2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 2, textItem2);

        //3.目标文件类型
        QTableWidgetItem *textItem3 = new QTableWidgetItem(QString::fromLocal8Bit((FileCheckTypeUtility::K2V(rule_info.FileInfoType).c_str())));
        textItem3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 3, textItem3);


        //4.目标文件信息
        QTableWidgetItem *textItem4 = new QTableWidgetItem(QString::fromLocal8Bit(rule_info.FileInfo.c_str()));
        textItem4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 4, textItem4);

        //5.处理方式
        QTableWidgetItem *textItem5 = new QTableWidgetItem(QString::fromLocal8Bit((FileActionUtility::K2V(rule_info.OperationCode).c_str())));
        textItem5->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 5, textItem5);

        //6.禁止权限
        QTableWidgetItem *textItem6 = new QTableWidgetItem(QString::fromLocal8Bit("写入|创建"));//Options
        textItem6->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 6, textItem6);


        //7.文件转向
        QTableWidgetItem *textItem7 = new QTableWidgetItem(QString::fromLocal8Bit(""));
        textItem7->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 7, textItem7);

        //8.生效系统
        QTableWidgetItem *textItem8 = new QTableWidgetItem(QString::fromLocal8Bit((WindowsVersionUtility::K2V(rule_info.OsVersion).c_str())));
        textItem8->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 8, textItem8);

        //9.备注
        QString strMark(QString::fromLocal8Bit(rule_info.Remark.c_str()));
        QTableWidgetItem *textItem9 = new QTableWidgetItem(strMark);
        textItem9->setTextAlignment(Qt::AlignCenter);
        //textItem7->setToolTip(strMark);
        ui->tableWidget->setItem(row, 9, textItem9);


        //10.日志
        QTableWidgetItem *textItem10 = new QTableWidgetItem(QString::fromLocal8Bit((LogStateUtility::K2V(rule_info.Log).c_str())));
        textItem10->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 10, textItem10);

        //11.优先级
        QTableWidgetItem *textItem11 = new QTableWidgetItem(QString::fromLocal8Bit("30"));
        textItem11->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 11, textItem11);

        //12.一列空的
        QTableWidgetItem *textItem12 = new QTableWidgetItem("");
        textItem12->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 12, textItem12);
    }
}
