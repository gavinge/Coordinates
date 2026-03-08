#include "customrulewidget.h"
#include "ui_customrulewidget.h"

#include <QVBoxLayout>
#include <QContextMenuEvent>
#include "process/ProcessRuleDetailWidget.h"
#include "domain/DomainRuleDetailWidget.h"
#include "file/FileRuleDetailWidget.h"
#include "kernel/KernelRuleDetailWidget.h"
#include "module/ModuleRuleDetailWidget.h"
#include "network/NetWorkRuleDetailWidget.h"
#include "protect/ProtectionRuleDetailWidget.h"
#include "register/RegisterRuleDetailWidget.h"
#include "thread/ThreadRuleDetailWidget.h"
#include "window/WindowRuleDetailWidget.h"

#include "rule_center/CustomRuleCenterWidget.h"
CustomRuleWidget::CustomRuleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomRuleWidget)
{
    ui->setupUi(this);
    initRuleDetailMenu();
    initGroupInfo();
    InitTab();
    initSlots();
}

CustomRuleWidget::~CustomRuleWidget()
{
    delete ui;
}
void CustomRuleWidget::initSlots(){
    connect(ui->ruleCenterPushButton, &QPushButton::clicked, this, &CustomRuleWidget::onRuleCenterBtnClicked);
    connect(ui->disablePushButton, &QPushButton::clicked, this, &CustomRuleWidget::onDisableBtnClicked);
}
void CustomRuleWidget::initRuleDetailMenu(){
    menuRuleDetailOper = new QMenu(this);

    QAction *actionEnabledAllGroup = new QAction(QString::fromLocal8Bit(" 所有分组启用"), this);
    actionEnabledAllGroup->setData(static_cast<int>(CustomRuleMenuItemEnum::EnabledAllGroup));
    menuRuleDetailOper->addAction(actionEnabledAllGroup);
    connect(actionEnabledAllGroup, &QAction::triggered, this, &CustomRuleWidget::onRuleDetailMenuItemClicked);

    QAction *actionDisabledAllGroup = new QAction(QString::fromLocal8Bit(" 所有分组禁用"), this);
    actionDisabledAllGroup->setData(static_cast<int>(CustomRuleMenuItemEnum::DisabledAllGroup));
    menuRuleDetailOper->addAction(actionDisabledAllGroup);
    connect(actionDisabledAllGroup, &QAction::triggered, this, &CustomRuleWidget::onRuleDetailMenuItemClicked);

}
void CustomRuleWidget::initGroupInfo(){
    //AgentGroupInfo group_instance(1, "分组测试", 2, 1, "描述");
    std::string GroupName = "分组测试";
    for (int idx = 0; idx <10 ; idx++ ) {
        QListWidgetItem *item1 = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(GroupName.c_str())));
        ui->groupListWidget->addItem(item1);
    }
}

bool CustomRuleWidget::isMouseInWidget(const QWidget *widget,const QPoint &pos)  {
    return widget->rect().contains(widget->mapFromParent(pos));
}

void CustomRuleWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //判断鼠标是否在groupListWidget组件内
    QPoint pos = event->pos();
    pos.setY(pos.y() - 80);
    if(!isMouseInWidget(ui->tabWidget,pos))
        return;

    menuRuleDetailOper->exec(event->globalPos());
}
void CustomRuleWidget::onRuleDetailMenuItemClicked()
{
    int idxMenuAction = 0;
    QAction *senderAction = qobject_cast<QAction *>(sender());
    if(senderAction){
        idxMenuAction = static_cast<int>(senderAction->data().toInt());
    }
    switch (idxMenuAction) {
    case (int)CustomRuleMenuItemEnum::EnabledAllGroup:
        break;
    case (int)CustomRuleMenuItemEnum::DisabledAllGroup:
        break;
    }
}

void CustomRuleWidget::getRuleSummaryInfo()
{
    ruleSummary.push_back({0, QString::fromLocal8Bit("进程"), RuleType::ProcessRuleType,20});
    ruleSummary.push_back({1, QString::fromLocal8Bit("线程"), RuleType::ThreadRuleType,11});
    ruleSummary.push_back({2, QString::fromLocal8Bit("文件"), RuleType::FileRuleType,11});
    ruleSummary.push_back({3, QString::fromLocal8Bit("模块"), RuleType::ModuleRuleType,11});
    ruleSummary.push_back({4, QString::fromLocal8Bit("驱动"), RuleType::KernelRuleType,12});
    ruleSummary.push_back({5, QString::fromLocal8Bit("网络"), RuleType::NetworkRuleType,111});
    ruleSummary.push_back({6, QString::fromLocal8Bit("域名"), RuleType::DomainRuleType,222});
    ruleSummary.push_back({7, QString::fromLocal8Bit("窗口"), RuleType::WindowRuleType,141});
    ruleSummary.push_back({8, QString::fromLocal8Bit("注册表"), RuleType::RegistryRuleType,119});
    ruleSummary.push_back({9, QString::fromLocal8Bit("保护"), RuleType::ProtectionRuleType,224});
}
void CustomRuleWidget::InitTab()
{
    getRuleSummaryInfo();

    std::vector<TabInfo>::iterator it;
    for (it = ruleSummary.begin(); it != ruleSummary.end(); ++it) {
        const TabInfo& tab = *it;

        //tabWidget->setObjectName(QString("ruletab_%1").arg(tab.idx));

        switch (tab.ruleType) {
        case RuleType::ProcessRuleType:
        {
            ProcessRuleDetailWidget *tabWidgetDetail = new ProcessRuleDetailWidget(this,RuleViewModel::DisplayModel);
            //QVBoxLayout *layout = new QVBoxLayout(tabWidgetDetail);
            //layout->addWidget(tabWidgetDetail);
            if (ui->tabWidget) {
                //tabWidgetDetail->setLayout(layout);
                ui->tabWidget->addTab(tabWidgetDetail, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                //tabWidgetDetail->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            }
        }
            break;
        case RuleType::FileRuleType:
        {
            FileRuleDetailWidget *tabWidget = new FileRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::ModuleRuleType:
        {
            ModuleRuleDetailWidget *tabWidget = new ModuleRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::KernelRuleType:
        {
            KernelRuleDetailWidget *tabWidget = new KernelRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::NetworkRuleType:
        {
            NetWorkRuleDetailWidget *tabWidget = new NetWorkRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::DomainRuleType:
        {
            DomainRuleDetailWidget *tabWidget = new DomainRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::WindowRuleType:
        {
            WindowRuleDetailWidget *tabWidget = new WindowRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::RegistryRuleType:
        {
            RegisterRuleDetailWidget *tabWidget = new RegisterRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::ProtectionRuleType:
        {
            ProtectionRuleDetailWidget *tabWidget = new ProtectionRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
        case RuleType::ThreadRuleType:
        {
            ThreadRuleDetailWidget *tabWidget = new ThreadRuleDetailWidget(this,RuleViewModel::DisplayModel);
            if (ui->tabWidget) {
                ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            }
        }
            break;
            // 添加其他 case 分支，确保覆盖所有枚举值
        default:
            // 处理其他规则类型
            break;
        }



        /*switch (tab.ruleType) {
        case RuleType::ProcessRuleType:
            ProcessRuleDetailWidget * tabWidget = new ProcessRuleDetailWidget(this);
            //ui->ProcessRuleDetailWidget
            ui->tabWidget->addTab(tabWidget,QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            break;
        case RuleType::FileRuleType:
            QWidget * tabWidget2 = new QWidget(this);
            ui->tabWidget->addTab(tabWidget2,QString("%1(%2)").arg(tab.tabText).arg(tab.count));
            break;
        case RuleType::ModuleRuleType:
            break;
        case RuleType::KernelRuleType:
            break;
        case RuleType::NetworkRuleType:
            break;
        case RuleType::DomainRuleType:
            break;
        case RuleType::WindowRuleType:
            break;
        case RuleType::RegistryRuleType:
            break;
        case RuleType::ProtectionRuleType:
            break;
        case RuleType::ThreadRuleType:
            break;
        default:
            break;
        }*/
    }
}

#include <QtDebug>
void CustomRuleWidget::onRuleCenterBtnClicked(){
    CustomRuleCenterWidget customRuleCenterWidget(this);
    customRuleCenterWidget.setWindowModality(Qt::ApplicationModal);
    customRuleCenterWidget.num = 10000;
    // 连接子窗口的关闭信号到处理函数
    connect(&customRuleCenterWidget, &CustomRuleCenterWidget::closed, this, [=](int num) {
        qDebug() << "~~~~~SubWidget num value:" << num;
        qDebug() << "~~~~~SubWidget closed";
    });

    //重新加载一下
    QFile file(":/res/qss/style.qss");
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream stream(&file);
            QString styleSheet = stream.readAll();
            customRuleCenterWidget.setStyleSheet(styleSheet);
            file.close();
        }

    customRuleCenterWidget.show();
    QEventLoop loop;
    loop.exec();
}

/*CustomRuleCenterWidget *customRuleCenterWidget;
void CustomRuleWidget::onRuleCenterBtnClicked(){
    //CustomRuleCenterWidget customRuleCenterWidget;
    customRuleCenterWidget = new CustomRuleCenterWidget();
    //customRuleCenterWidget->setWindowModality(Qt::WindowModal);
    customRuleCenterWidget->setWindowModality(Qt::ApplicationModal);
    //customRuleCenterWidget->setWindowFlags(Qt::Window);
    customRuleCenterWidget->num = 10000;

    // 连接子窗口的关闭信号到处理函数
    connect(customRuleCenterWidget, &CustomRuleCenterWidget::closed, this, [=](int num) {
        qDebug() << "---------SubWidget num value:" << num;
        qDebug() << "---------SubWidget closed";
    });

    customRuleCenterWidget->show();
}*/


void CustomRuleWidget::onDisableBtnClicked(){

}
