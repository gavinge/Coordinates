#include "agentmanwidget.h"
#include "ui_agentmanwidget.h"
#include "agent_man_custom_listwidget_item.h"
#include <QContextMenuEvent>
#include "common/GlobalAgentGroupMenuItemEnum.h"

#include "AgentManAddGroupWidget.h"
#include "AgentManDelGroupWidget.h"
#include "AgentManRenameGroupWidget.h"
#include "AgentManDisableChargeWidget.h"
#include "common/MessageBoxWidget.h"

AgentManWidget::AgentManWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManWidget),
    menuAgentDetail(NULL),
    menuMoveGroup(NULL)
{
    ui->setupUi(this);

    initGroupInfo();

    initMachineList();

    initAgentGroupMenu();

    initAgentDetailMenu();

    initSearchEdit();
}

AgentManWidget::~AgentManWidget()
{
    delete ui;
}

QMenu* AgentManWidget::getAgentDetailMenu(){
    return menuAgentDetail;
}

void AgentManWidget::refreshMoveGrpupMenu(){

    if(!menuMoveGroup)
        return;

    menuMoveGroup->clear();
}

void AgentManWidget::initSearchEdit(){
    ui->researchLineEdit->setPlaceholderText(QString::fromLocal8Bit("搜索: 名称、IP、MAC"));
}

void AgentManWidget::initGroupInfo(){
    AgentGroupInfo group_instance(1, "分组测试", 2, 1, "描述");
    for (int idx = 0; idx <10 ; idx++ ) {
        QListWidgetItem *item1 = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(group_instance.GroupName.c_str())));
        ui->groupListWidget->addItem(item1);
    }
}


bool AgentManWidget::isMouseInWidget(const QWidget *widget,const QPoint &pos)  {
    return widget->rect().contains(widget->mapFromParent(pos));
}

void AgentManWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //判断鼠标是否在groupListWidget组件内
    if(!isMouseInWidget(ui->groupListWidget,event->pos()))
        return;

    QPoint pos = event->globalPos();
    QList<QAction*> listActions = menuAgentGroup->actions();


    if (ui->groupListWidget->indexAt(ui->groupListWidget->mapFromGlobal(pos)).isValid()){ //鼠标在item上
        for (int idx = 0; idx < listActions.size() ;idx++ ) {
            listActions[idx]->setVisible(true);
        }
    }else{ //鼠标在空白处
        for (int idx = 0; idx < listActions.size() ;idx++ ) {
            int idxMenuAction = static_cast<int>(listActions[idx]->data().toInt());
            if( idxMenuAction == (int)AgentGroupMenuItemEnum::RenameGroup ||
                    idxMenuAction == (int)AgentGroupMenuItemEnum::DelGroup)
            {
                listActions[idx]->setVisible(false);
            }else
            {
                listActions[idx]->setVisible(true);
            }
        }
    }
    menuAgentGroup->exec(event->globalPos());
}


void AgentManWidget::initMachineList(){
    AgentInfoTmp agentInfoInstance;
    agentInfoInstance.ID = 0;
    agentInfoInstance.Status = 1;
    agentInfoInstance.GroupID = 1;
    agentInfoInstance.Debug = 1;
    agentInfoInstance.DisableRule = 1;
    agentInfoInstance.DisableCharge = 1;
    agentInfoInstance.DisableGameMenu = 1;
    agentInfoInstance.IsSuper = 0;
    agentInfoInstance.PcName = "WIN-2GEB8B29VGO222222222222222222";
    agentInfoInstance.IP = "192.168.125.125";
    agentInfoInstance.Mac = "00-0C-29-93-FD-47";
    agentInfoInstance.VersionType = 1;
    agentInfoInstance.VersionName = 7601;
    agentInfoInstance.X64 = 1;
    agentInfoInstance.Cpu = "Intel(R) Core(TM) i7-9700K CPU @ 3.60GHz";
    agentInfoInstance.DisplayCard = "VMware SVGA 3D";
    agentInfoInstance.BaseBoard = "Intel Corporation 440BX Desktop Reference Platform";
    agentInfoInstance.MemorySize = "2047";
    agentInfoInstance.NetworkSpeed = 1000;
    agentInfoInstance.Logincs = 0;
    agentInfoInstance.Drvlog = 0;
    agentInfoInstance.BootTime = 410;
    agentInfoInstance.Token = "svYqy78p2r";
    agentInfoInstance.Ver = "Aug 17 2020 01:28:43";

    ui->customListWidget->clear();

    int ncount = 0;
    while (ncount++ < 50) {

        AgentManCustomListWidgetItem * widgetItem = new AgentManCustomListWidgetItem(this);
        widgetItem->setItemData(ncount,agentInfoInstance);
        widgetItem->show();

        QListWidgetItem* item = new QListWidgetItem;
        item->setSizeHint(QSize(840, 38));

        ui->customListWidget->addItem(item);
        ui->customListWidget->setItemWidget(item, widgetItem);
    }
}

void AgentManWidget::initAgentGroupMenu(){
    menuAgentGroup = new QMenu(this);

    QAction *actionAddGroup = new QAction(QIcon(":/res/image/agentMan/menu_addgroup.png"),QString::fromLocal8Bit("添加分组"), this);
    actionAddGroup->setData(static_cast<int>(AgentGroupMenuItemEnum::AddGroup));
    menuAgentGroup->addAction(actionAddGroup);
    connect(actionAddGroup, &QAction::triggered, this, &AgentManWidget::onAgentGroupMenuItemClicked);

    QAction *actionDelGroup = new QAction(QIcon(":/res/image/agentMan/menu_delgroup.png"),QString::fromLocal8Bit("删除分组"), this);
    actionDelGroup->setData(static_cast<int>(AgentGroupMenuItemEnum::DelGroup));
    menuAgentGroup->addAction(actionDelGroup);
    connect(actionDelGroup, &QAction::triggered, this, &AgentManWidget::onAgentGroupMenuItemClicked);

    QAction *actionRenameGroup = new QAction(QIcon(":/res/image/agentMan/menu_renamegroup.png"),QString::fromLocal8Bit("重命名"), this);
    actionRenameGroup->setData(static_cast<int>(AgentGroupMenuItemEnum::RenameGroup));
    menuAgentGroup->addAction(actionRenameGroup);
    connect(actionRenameGroup, &QAction::triggered, this, &AgentManWidget::onAgentGroupMenuItemClicked);

}
void AgentManWidget::initAgentDetailMenu(){

    menuAgentDetail = new QMenu(this);

    /*const std::vector<std::pair<AgentDetailItemEnum, std::string>> enumItems = {
        {AgentDetailItemEnum::RefreshList, "刷新列表"},
        {AgentDetailItemEnum::Separator, ""},

        {AgentDetailItemEnum::EnableDebugMode, "开启调试模式"},
        {AgentDetailItemEnum::RefreshDefenseRules, "刷新防御规则"},
        {AgentDetailItemEnum::ViewRuleLogs, "查看规则日志"},
        {AgentDetailItemEnum::ViewProcessTree, "查看进程树"},

        {AgentDetailItemEnum::SubMenu, "禁用规则"},
        {AgentDetailItemEnum::DisableAllRules, "禁用全部规则"},
        {AgentDetailItemEnum::DisableDebugRules, "禁用调试规则"},
        {AgentDetailItemEnum::DisableDefenseRules, "禁用防御规则"},
        {AgentDetailItemEnum::Separator, ""},

        {AgentDetailItemEnum::DisableBilling, "禁用计费"},
        {AgentDetailItemEnum::DisableGameMenu, "禁用游戏菜单"},
        {AgentDetailItemEnum::Separator, ""},
        {AgentDetailItemEnum::SubMenu, "移动分组"},
        {AgentDetailItemEnum::DeleteAgent, "删除机器"},
    };*/


    QAction *actionRefreshList = new QAction(QString::fromLocal8Bit(" 刷新列表"), this);
    actionRefreshList->setData(static_cast<int>(AgentDetailItemEnum::RefreshList));
    menuAgentDetail->addAction(actionRefreshList);
    connect(actionRefreshList, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    menuAgentDetail->addSeparator(); //分割

    QAction *actionEnableDebugMode = new QAction(QString::fromLocal8Bit(" 开启调试模式"), this);
    actionEnableDebugMode->setData(static_cast<int>(AgentDetailItemEnum::EnableDebugMode));
    menuAgentDetail->addAction(actionEnableDebugMode);
    connect(actionEnableDebugMode, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QAction *actionRefreshDefenseRules = new QAction(QString::fromLocal8Bit(" 刷新防御规则"), this);
    actionRefreshDefenseRules->setData(static_cast<int>(AgentDetailItemEnum::RefreshDefenseRules));
    menuAgentDetail->addAction(actionRefreshDefenseRules);
    connect(actionRefreshDefenseRules, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QAction *actionViewRuleLogs = new QAction(QString::fromLocal8Bit(" 查看规则日志"), this);
    actionViewRuleLogs->setData(static_cast<int>(AgentDetailItemEnum::ViewRuleLogs));
    menuAgentDetail->addAction(actionViewRuleLogs);
    connect(actionViewRuleLogs, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QAction *actionViewProcessTree = new QAction(QString::fromLocal8Bit(" 查看进程树"), this);
    actionViewProcessTree->setData(static_cast<int>(AgentDetailItemEnum::ViewProcessTree));
    menuAgentDetail->addAction(actionViewProcessTree);
    connect(actionViewProcessTree, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QMenu *menuDisableRule = menuAgentDetail->addMenu(QString::fromLocal8Bit(" 禁用规则"));//子菜单

    QAction *actionDisableAllRules = new QAction(QString::fromLocal8Bit(" 禁用全部规则"), this);
    actionDisableAllRules->setData(static_cast<int>(AgentDetailItemEnum::DisableAllRules));
    menuDisableRule->addAction(actionDisableAllRules);
    connect(actionDisableAllRules, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QAction *actionDisableDebugRules = new QAction(QString::fromLocal8Bit(" 禁用调试规则"), this);
    actionDisableDebugRules->setData(static_cast<int>(AgentDetailItemEnum::DisableDebugRules));
    menuDisableRule->addAction(actionDisableDebugRules);
    connect(actionDisableDebugRules, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QAction *actionDisableDefenseRules = new QAction(QString::fromLocal8Bit(" 禁用防御规则"), this);
    actionDisableDefenseRules->setData(static_cast<int>(AgentDetailItemEnum::DisableDefenseRules));
    menuDisableRule->addAction(actionDisableDefenseRules);
    connect(actionDisableDefenseRules, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    menuAgentDetail->addSeparator(); //分割

    QAction *actionDisableBilling = new QAction(QString::fromLocal8Bit(" 禁用计费"), this);
    actionDisableBilling->setData(static_cast<int>(AgentDetailItemEnum::DisableBilling));
    menuAgentDetail->addAction(actionDisableBilling);
    connect(actionDisableBilling, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    QAction *actionDisableGameMenu = new QAction(QString::fromLocal8Bit(" 禁用游戏菜单"), this);
    actionDisableGameMenu->setData(static_cast<int>(AgentDetailItemEnum::DisableGameMenu));
    menuAgentDetail->addAction(actionDisableGameMenu);
    connect(actionDisableGameMenu, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);

    menuMoveGroup = menuAgentDetail->addMenu(QString::fromLocal8Bit(" 移动分组")); //子菜单

    QAction *actionDeleteAgent = new QAction(QString::fromLocal8Bit(" 删除机器"), this);
    actionDeleteAgent->setData(static_cast<int>(AgentDetailItemEnum::DeleteAgent));
    menuAgentDetail->addAction(actionDeleteAgent);
    connect(actionDeleteAgent, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);
}

#include <QMessageBox>
#include <QDebug>

void AgentManWidget::onAgentGroupMenuItemClicked()
{
    int idxMenuAction = 0;
    QAction *senderAction = qobject_cast<QAction *>(sender());
    if(senderAction){
        idxMenuAction = static_cast<int>(senderAction->data().toInt());
    }
    QListWidgetItem *item = ui->groupListWidget->currentItem();
    switch (idxMenuAction) {
    case (int)AgentGroupMenuItemEnum::AddGroup:
        // Handle AddGroup
        {
            //AgentManAddGroupWidget
            AgentManAddGroupWidget addGroupWidget(this);
            addGroupWidget.setWindowModality(Qt::WindowModal);

            QEventLoop loop;
            QObject::connect(&addGroupWidget, &AgentManAddGroupWidget::confirmed, [&]() {
                    QString content = addGroupWidget.getLineEditContent();
                    //qDebug() << "LineEdit content:" << content;
                    //OnAddGroup(content);
                    loop.quit();
                });

            addGroupWidget.show();

            loop.exec();

            /*QListWidgetItem *item1 = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit("新增加")));
            ui->groupListWidget->addItem(item1);*/
        }
        break;
    case (int)AgentGroupMenuItemEnum::DelGroup:

        /*if(item){
            delete ui->groupListWidget->takeItem(ui->groupListWidget->row(item));
        }*/
        {
            AgentManDelGroupWidget delGroupWidget(this);
            delGroupWidget.setWindowModality(Qt::WindowModal);
            QEventLoop loop;
            delGroupWidget.show();
            loop.exec();
        }
        break;
    case (int)AgentGroupMenuItemEnum::RenameGroup:
        // Handle RenameGroup
        {
            AgentManRenameGroupWidget renameGroupWidget(this);
            renameGroupWidget.setWindowModality(Qt::WindowModal);

            QEventLoop loop;
            QObject::connect(&renameGroupWidget, &AgentManRenameGroupWidget::confirmed, [&]() {
                    QString content = renameGroupWidget.getLineEditContent();
                    //qDebug() << "LineEdit content:" << content;
                    //OnRenameGroup("",content);
                    loop.quit();
                });
            renameGroupWidget.show();
            loop.exec();
        }
        /*if (item) {
            item->setText("   xxxxx");
        }*/
        break;
    }
}
void AgentManWidget::onAgentDetailMenuItemClicked()
{
    QAction *senderAction = qobject_cast<QAction *>(sender());

    int idxMenuAction = 0;
    AgentInfoTmp agentInfo;
    AgentManCustomListWidgetItem* selectedWidgetItem = NULL;
    if (senderAction)
    {
        QListWidgetItem* selectedItem = ui->customListWidget->currentItem();
        if (selectedItem) {
            selectedWidgetItem = qobject_cast<AgentManCustomListWidgetItem*>(ui->customListWidget->itemWidget(selectedItem));
            if (!selectedWidgetItem) {
                return;
            }
            selectedWidgetItem->getItemData(agentInfo);
            idxMenuAction = static_cast<int>(senderAction->data().toInt());
        }else{
            return;
        }

        //qInfo() << "This is an informational message." << QString::number(static_cast<int>(senderAction->data().toInt()));
        //QString item = QString::number(static_cast<int>(senderAction->data().toInt()));
        //QMessageBox::information(this,item,"");
    }


    //移动组的菜单
    if((int)AgentDetailItemEnum::CustomDefineGroupBase <= idxMenuAction ){

        //开始移动吧,更新数据库 ！！！！注意：这里要判断一下agentInfo本身有没有问题先
        selectedWidgetItem->setItemData(0,agentInfo);
        return;
    }

    //固定的菜单
    switch (idxMenuAction) {
    case (int)AgentDetailItemEnum::RefreshList:
        // Handle RefreshList
        break;
    case (int)AgentDetailItemEnum::EnableDebugMode:
        // Handle EnableDebugMode
        break;
    case (int)AgentDetailItemEnum::RefreshDefenseRules:
        // Handle RefreshDefenseRules
        break;
    case (int)AgentDetailItemEnum::ViewRuleLogs:
        // Handle ViewRuleLogs
        break;
    case (int)AgentDetailItemEnum::ViewProcessTree:
        // Handle ViewProcessTree
        break;
    case (int)AgentDetailItemEnum::DisableAllRules:
        // Handle DisableAllRules
        break;
    case (int)AgentDetailItemEnum::DisableDebugRules:
        // Handle DisableDebugRules
        break;
    case (int)AgentDetailItemEnum::DisableDefenseRules:
        // Handle DisableDefenseRules
        break;
    case (int)AgentDetailItemEnum::DisableBilling:
        // Handle DisableBilling
        {
            AgentManDisableChargeWidget disableChargeWidget(this);
            disableChargeWidget.setWindowModality(Qt::WindowModal);
            QEventLoop loop;
            disableChargeWidget.show();
            loop.exec();
        }
        break;
    case (int)AgentDetailItemEnum::DisableGameMenu:
        // Handle DisableGameMenu
        break;
    case (int)AgentDetailItemEnum::DeleteAgent:
        // Handle DeleteAgent
        break;
    default:
        // Handle unknown option
        break;
    }
}


