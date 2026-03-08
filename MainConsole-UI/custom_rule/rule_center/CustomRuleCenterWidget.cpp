#include "CustomRuleCenterWidget.h"
#include "ui_CustomRuleCenterWidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QTabBar>

#include "../process/ProcessRuleDetailWidget.h"
#include "../domain/DomainRuleDetailWidget.h"
#include "../file/FileRuleDetailWidget.h"
#include "../kernel/KernelRuleDetailWidget.h"
#include "../module/ModuleRuleDetailWidget.h"
#include "../network/NetWorkRuleDetailWidget.h"
#include "../protect/ProtectionRuleDetailWidget.h"
#include "../register/RegisterRuleDetailWidget.h"
#include "../thread/ThreadRuleDetailWidget.h"
#include "../window/WindowRuleDetailWidget.h"

#include "process_detail/ProcessRuleEditDetailWidget.h"
#include "thread_detail/ThreadRuleEditDetailWidget.h"
#include "file_detail/FileRuleEditDetailWidget.h"
#include "module_detail/ModuleRuleEditDetailWidget.h"
#include "kernel_detail/KernelRuleEditDetailWidget.h"
#include "network_detail/NetWorkRuleEditDetailWidget.h"
#include "domain_detail/DomainRuleEditDetailWidget.h"
#include "window_detail/WindowRuleEditDetailWidget.h"
#include "register_detail/RegisterRuleEditDetailWidget.h"
#include "protect_detail/ProtectionRuleEditDetailWidget.h"

CustomRuleCenterWidget::CustomRuleCenterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomRuleCenterWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->ruleCenterCloseBtn, &QPushButton::clicked, this, &CustomRuleCenterWidget::close);
    connect(ui->addRulePushButton, &QPushButton::clicked, this, &CustomRuleCenterWidget::onAddRuleBtnClicked);

    InitTab();
}

int CustomRuleCenterWidget::getNum() const{
    return num;
}

CustomRuleCenterWidget::~CustomRuleCenterWidget()
{
    delete ui;
}
void CustomRuleCenterWidget::onAddRuleBtnClicked(){
    //ProcessRuleEditDetailWidget processRuleEditDetailWidget(this);
    //ThreadRuleEditDetailWidget processRuleEditDetailWidget(this);
    //FileRuleEditDetailWidget processRuleEditDetailWidget(this);
    //ModuleRuleEditDetailWidget processRuleEditDetailWidget(this);
    //KernelRuleEditDetailWidget processRuleEditDetailWidget(this);
    //NetWorkRuleEditDetailWidget processRuleEditDetailWidget(this);
    ////DomainRuleEditDetailWidget  processRuleEditDetailWidget(this);
    //WindowRuleEditDetailWidget  processRuleEditDetailWidget(this);
    //RegisterRuleEditDetailWidget   processRuleEditDetailWidget(this);
    //ProtectionRuleEditDetailWidget processRuleEditDetailWidget(this);
    ////processRuleEditDetailWidget.setWindowModality(Qt::WindowModal);
    //processRuleEditDetailWidget.setWindowModality(Qt::ApplicationModal);
    //customRuleCenterWidget.num = 10000;
    // 连接子窗口的关闭信号到处理函数
    /*connect(&processRuleEditDetailWidget, &ProcessRuleEditDetailWidget::closed, this, [=](int num) {
        qDebug() << "~~~~~SubWidget num value:" << num;
        qDebug() << "~~~~~SubWidget closed";
    });*/

    //重新加载一下
    /*QFile file(":/res/qss/style.qss");
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream stream(&file);
            QString styleSheet = stream.readAll();
            processRuleEditDetailWidget.setStyleSheet(styleSheet);
            file.close();
        }*/

    ////processRuleEditDetailWidget.show();

    /*ProcessRuleEditDetailWidget detailWidget(this);
    detailWidget.setWindowModality(Qt::WindowModal);
    detailWidget.show();
    QEventLoop loop;
    loop.exec();*/

    //return;
    int currentIndex = ui->tabWidget->currentIndex();
    QVariant dataVariant = ui->tabWidget->tabBar()->tabData(currentIndex);
    if(dataVariant.toInt()< (int)RuleType::ProcessRuleType || dataVariant.toInt() > (int)RuleType::ThreadRuleType){
        return;
    }

    switch ((RuleType)dataVariant.toInt()) {
    case RuleType::ProcessRuleType:
        {
            ProcessRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::FileRuleType:
        {
            FileRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::ModuleRuleType:
        {
            ModuleRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::KernelRuleType:
        {
            KernelRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::NetworkRuleType:
        {
            NetWorkRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::DomainRuleType:
        {
            DomainRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::WindowRuleType:
        {
            WindowRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::RegistryRuleType:
        {
            RegisterRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::ProtectionRuleType:
        {
            ProtectionRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::ThreadRuleType:
        {
            ThreadRuleEditDetailWidget detailWidget(this);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    default:
        break;
    }


}

void CustomRuleCenterWidget::getRuleSummaryInfo()
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
void CustomRuleCenterWidget::InitTab()
{
    getRuleSummaryInfo();

    std::vector<TabInfo>::iterator it;
    for (it = ruleSummary.begin(); it != ruleSummary.end(); ++it) {
        const TabInfo& tab = *it;

        //tabWidget->setObjectName(QString("ruletab_%1").arg(tab.idx));

        switch (tab.ruleType) {
        case RuleType::ProcessRuleType:
        {
            ProcessRuleDetailWidget *tabWidgetDetail = new ProcessRuleDetailWidget(this,RuleViewModel::EditModel);
            //QVBoxLayout *layout = new QVBoxLayout(tabWidgetDetail);
            //layout->addWidget(tabWidgetDetail);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidgetDetail, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::FileRuleType:
        {
            FileRuleDetailWidget *tabWidget = new FileRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::ModuleRuleType:
        {
            ModuleRuleDetailWidget *tabWidget = new ModuleRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::KernelRuleType:
        {
            KernelRuleDetailWidget *tabWidget = new KernelRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::NetworkRuleType:
        {
            NetWorkRuleDetailWidget *tabWidget = new NetWorkRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::DomainRuleType:
        {
            DomainRuleDetailWidget *tabWidget = new DomainRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::WindowRuleType:
        {
            WindowRuleDetailWidget *tabWidget = new WindowRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::RegistryRuleType:
        {
            RegisterRuleDetailWidget *tabWidget = new RegisterRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::ProtectionRuleType:
        {
            ProtectionRuleDetailWidget *tabWidget = new ProtectionRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
            }
        }
            break;
        case RuleType::ThreadRuleType:
        {
            ThreadRuleDetailWidget *tabWidget = new ThreadRuleDetailWidget(this,RuleViewModel::EditModel);
            if (ui->tabWidget) {
                int tabIndex = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
                ui->tabWidget->tabBar()->setTabData(tabIndex,QVariant((int)tab.ruleType));
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

void CustomRuleCenterWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void CustomRuleCenterWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void CustomRuleCenterWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void CustomRuleCenterWidget::closeEvent(QCloseEvent *event)  {
    emit closed(num);
    QWidget::closeEvent(event);
}
void CustomRuleCenterWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}
