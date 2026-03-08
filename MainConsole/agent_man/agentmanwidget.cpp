#include "agentmanwidget.h"
#include "ui_agentmanwidget.h"
#include "agent_man_custom_listwidget_item.h"
#include <QContextMenuEvent>
#include <QMessageBox>
#include <QDebug>
#include "common/GlobalAgentGroupMenuItemEnum.h"

#include "AgentManAddGroupWidget.h"
#include "AgentManDelGroupWidget.h"
#include "AgentManRenameGroupWidget.h"
#include "AgentManDisableChargeWidget.h"
#include "common/MessageBoxWidget.h"
#include "global/global_define.h"
#include "Controller/AgentManController.h"
#include "mod_ext/agent_manager_ext.hpp"

AgentManWidget::AgentManWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManWidget),
    menuAgentDetail(NULL),
    menuMoveGroup(NULL)
{
    ui->setupUi(this);

	//初始化MVC框架.
	InitMVCFrameWork();

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


bool AgentManWidget::UpdateGroupInfo() {
	initGroupInfo();
	updateAgentDetailMoveGroupMenu();
	return true;
}

bool AgentManWidget::UpdateGroupInfo(long nGroupID, std::string strGroupName) {
	for (int idx = 0; idx < ui->groupListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->groupListWidget->item(idx);
		if (item->data(Qt::UserRole).toInt() == nGroupID) {
			item->setText(QString::fromLocal8Bit(("   " + strGroupName).c_str()));
			break;
		}
	}
	updateAgentDetailMoveGroupMenu();
	return true;
}

bool AgentManWidget::DeleteGroupInfo(long nGroupID) {

	for (int idx = 0; idx < ui->groupListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->groupListWidget->item(idx);
		if (item->data(Qt::UserRole).toInt() == nGroupID) {
			delete ui->groupListWidget->takeItem(idx);
			break; 
		}
	}
	updateAgentDetailMoveGroupMenu();
	return true;
}

bool AgentManWidget::DeleteAgentFromCurrentAgentList(int nAgentID) {

	AgentManagement::AgentInfo agentInfo;
	for (int idx = 0; idx < ui->customListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->customListWidget->item(idx);
		AgentManCustomListWidgetItem* selectedWidgetItem = qobject_cast<AgentManCustomListWidgetItem*>(ui->customListWidget->itemWidget(item));
		if (selectedWidgetItem) {
			selectedWidgetItem->getItemData(agentInfo);
			if (agentInfo.ID == nAgentID)
			{
				delete ui->customListWidget->takeItem(idx);
				break;
			}
		}
	}
	return true;
}

bool AgentManWidget::UpdateAgentFromCurrentAgentList(const AgentManagement::AgentInfo& agentInfo) {
	AgentManagement::AgentInfo agentInfoTmp;
	for (int idx = 0; idx < ui->customListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->customListWidget->item(idx);
		AgentManCustomListWidgetItem* selectedWidgetItem = qobject_cast<AgentManCustomListWidgetItem*>(ui->customListWidget->itemWidget(item));
		if (selectedWidgetItem) {
			selectedWidgetItem->getItemData(agentInfoTmp);
			if (agentInfo.ID == agentInfoTmp.ID)
			{
				selectedWidgetItem->setItemData(0, agentInfo);
				break;
			}
		}
	}
	return true;
}

bool AgentManWidget::OnLineNotifyView(long nGroupID) {
	return true;
}

bool AgentManWidget::UpdateAgentInfo(int nGroupID) {
	if (nGroupID == nCurrentGroupID) //只有当前页面和通知的页面一样才更新。
	{
		initMachineList(nCurrentGroupID);
	}
	return true;
}

//初始化MVC框架
bool AgentManWidget::InitMVCFrameWork() {

	CAgentManModel* pModel = new CAgentManModel();
	AGENT_MAN_CONTROLLER->BindModel(pModel);
	pModel->AttachView((CAgentManBaseView*)this);

	//启动网络服务
	int nret = AGENT_MAN_CONTROLLER->StartServer();
	LOGGER_INFO("init network...ret [%d] !" << nret);
	return true;
}


void AgentManWidget::onGroupListItemSelected(QListWidgetItem* item) {
	if (item) {
		
		int nSelectGroupID = item->data(Qt::UserRole).toInt();
		if (nSelectGroupID != nCurrentGroupID)
		{
			nCurrentGroupID = nSelectGroupID;
			initMachineList(nCurrentGroupID);
		}
	}
}

#include "../common/ToastBoxWidget .h"
void AgentManWidget::onShutDownPushButtonClicked() {

	Widget* mainWindow = FindMainWindow();
	if (mainWindow){
		Toast *toast = new Toast(mainWindow); //内存泄漏
		toast->showToast("Hello, this is a toast messagesdfsdfsadfasfsafasfsafsafsafsaf!", 3000);
	}
}

Widget* AgentManWidget::FindMainWindow() {
	QList<QWidget*> widgets = QApplication::topLevelWidgets();
	for (QList<QWidget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
		Widget* mainWindow = qobject_cast<Widget*>(*it);
		if (mainWindow) {
			return mainWindow;
		}
	}
	return NULL;
}
void AgentManWidget::onresearchPushButtonClicked() {
	
	std::string strQuerykey =  ui->researchLineEdit->text().toStdString();
	std::vector<AgentManagement::AgentInfo> queryAgentInfosResult;
	if (!strQuerykey.length())
	{
		AGENT_MAN_CONTROLLER->queryAgentInfoByGroupId(nCurrentGroupID, queryAgentInfosResult);
	}
	else
	{
		AGENT_MAN_CONTROLLER->queryAgentInfoByPattern(strQuerykey, nCurrentGroupID, queryAgentInfosResult);
	}
	
	initMachineList(queryAgentInfosResult);
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

	connect(ui->researchPushButton, &QPushButton::clicked, this, &AgentManWidget::onresearchPushButtonClicked);

	connect(ui->btnShutdown, &QPushButton::clicked, this, &AgentManWidget::onShutDownPushButtonClicked);
}

void AgentManWidget::RefreshAgentList() {
	//initMachineList(0); //测试先更新第一组吧
}

void AgentManWidget::initGroupInfo(){

	std::vector<AgentManagement::AgentGroupInfo> groups;
	
	AGENT_MAN_CONTROLLER->queryGroups(groups);

	ClearListWidget(ui->groupListWidget);

    for (int idx = 0; idx < groups.size() ; idx++ ) {
        QListWidgetItem *item = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(groups[idx].GroupName.c_str())));
		item->setData(Qt::UserRole, QVariant(groups[idx].GroupID));
        ui->groupListWidget->addItem(item);
    }

	//默认选择第一个。
	QListWidgetItem* firstItem = ui->groupListWidget->item(0);
	ui->groupListWidget->clearSelection();
	ui->groupListWidget->setCurrentItem(firstItem, QItemSelectionModel::Select);

	nCurrentGroupID = groups[0].GroupID;

	connect(ui->groupListWidget, &QListWidget::itemClicked, this, &AgentManWidget::onGroupListItemSelected);
}


bool AgentManWidget::isMouseInWidget(const QWidget *widget,const QPoint &pos)  {
    return widget->rect().contains(widget->mapFromParent(pos));
}

void AgentManWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //判断鼠标是否在groupListWidget组件内
    /*if(!isMouseInWidget(ui->groupListWidget,event->pos()))
        return;*/

	//如果在GroupListWidget中
	if (isMouseInWidget(ui->groupListWidget, event->pos()))
	{
		QPoint pos = event->globalPos();
		QList<QAction*> listActions = menuAgentGroup->actions();


		if (ui->groupListWidget->indexAt(ui->groupListWidget->mapFromGlobal(pos)).isValid()) { //鼠标在item上
			for (int idx = 0; idx < listActions.size(); idx++) {
				//listActions[idx]->setVisible(true);
				listActions[idx]->setEnabled(true);
			}
		}
		else { //鼠标在空白处
			for (int idx = 0; idx < listActions.size(); idx++) {
				int idxMenuAction = static_cast<int>(listActions[idx]->data().toInt());
				if (idxMenuAction == (int)AgentGroupMenuItemEnum::RenameGroup ||
					idxMenuAction == (int)AgentGroupMenuItemEnum::DelGroup)
				{
					//listActions[idx]->setVisible(false);
					listActions[idx]->setEnabled(false);
				}
				else
				{
					//listActions[idx]->setVisible(true);
					listActions[idx]->setEnabled(true);
				}
			}
		}
		menuAgentGroup->exec(event->globalPos());
	} else if (isMouseInWidget(ui->customListWidget, event->pos())) { //如果在CustomListWidget中
		menuAgentDetailBground->exec(event->globalPos());
	}
    
}


void AgentManWidget::initMachineList(){
	initMachineList(nCurrentGroupID);  
}
void AgentManWidget::initMachineList(int nGroupID) {

	std::vector<AgentManagement::AgentInfo> queryAgentInfosResult;
	AGENT_MAN_CONTROLLER->queryAgentInfoByGroupId(nGroupID, queryAgentInfosResult);

	initMachineList(queryAgentInfosResult);
}

void AgentManWidget::initMachineList(const std::vector<AgentManagement::AgentInfo>& agentList) {
	ClearListWidget(ui->customListWidget);

	int ncount = 0;
	for (int idx = 0; idx < agentList.size(); idx++) {

		AgentManCustomListWidgetItem * widgetItem = new AgentManCustomListWidgetItem();
		widgetItem->setItemData(ncount, agentList[idx]);
		widgetItem->setAgentManPtr(this);

		QListWidgetItem* item = new QListWidgetItem(ui->customListWidget);
		//item->setSizeHint(QSize(840, 38));

		ui->customListWidget->addItem(item);
		ui->customListWidget->setItemWidget(item, widgetItem);
	}
}


void AgentManWidget::ClearListWidget(QListWidget* listWidget) {
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

	updateAgentDetailMoveGroupMenu();


	//空白处菜单
	menuAgentDetailBground = new QMenu(this);
	QAction *actionBGRefreshList = new QAction(QString::fromLocal8Bit(" 刷新列表"), this);
	actionBGRefreshList->setData(static_cast<int>(AgentDetailItemEnum::RefreshList));
	menuAgentDetailBground->addAction(actionBGRefreshList);
	connect(actionBGRefreshList, &QAction::triggered, this, &AgentManWidget::onAgentDetailBgroundMenuItemClicked);

	menuAgentDetailBground->addSeparator(); //分割
}

void AgentManWidget::updateAgentDetailMoveGroupMenu()
{
	menuMoveGroup->clear();
	std::vector<AgentManagement::AgentGroupInfo> queryGroupInfoResult; //从缓存中取出来
	AGENT_MAN_CONTROLLER->queryGroups(queryGroupInfoResult);
	if (queryGroupInfoResult.size() > 1)
	{
		for (size_t idx = 0; idx < queryGroupInfoResult.size(); idx++)
		{
			QAction * actionGroup = new QAction(QString::fromLocal8Bit((" " + queryGroupInfoResult[idx].GroupName).c_str()), menuMoveGroup);
			actionGroup->setData(static_cast<int>(AgentDetailItemEnum::CustomDefineGroupBase) + queryGroupInfoResult[idx].GroupID);
			menuMoveGroup->addAction(actionGroup);
			connect(actionGroup, &QAction::triggered, this, &AgentManWidget::onAgentDetailMenuItemClicked);
		}
	}
}

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

        }
        break;
    case (int)AgentGroupMenuItemEnum::DelGroup:

        /*if(item){
            delete ui->groupListWidget->takeItem(ui->groupListWidget->row(item));
        }*/
		if(item)
        {
            AgentManDelGroupWidget delGroupWidget(this);
            delGroupWidget.setWindowModality(Qt::WindowModal);
			delGroupWidget.SetGroupID(item->data(Qt::UserRole).toInt());
			
            QEventLoop loop;
            delGroupWidget.show();
            loop.exec();
        }
        break;
    case (int)AgentGroupMenuItemEnum::RenameGroup:
        // Handle RenameGroup
		if(item)
        {
            AgentManRenameGroupWidget renameGroupWidget(this);
            renameGroupWidget.setWindowModality(Qt::WindowModal);
			renameGroupWidget.SetGroupID(item->data(Qt::UserRole).toInt());
            QEventLoop loop;
            QObject::connect(&renameGroupWidget, &AgentManRenameGroupWidget::confirmed, [&]() {
                    QString content = renameGroupWidget.getLineEditContent();
                    loop.quit();
                });
            renameGroupWidget.show();
            loop.exec();
        }
        break;
    }
}
void AgentManWidget::onAgentDetailBgroundMenuItemClicked() {
	QAction *senderAction = qobject_cast<QAction *>(sender());
	if (senderAction) {
		int idxMenuAction = static_cast<int>(senderAction->data().toInt());

		if (idxMenuAction == (int)AgentDetailItemEnum::RefreshList) {
			initMachineList(nCurrentGroupID);
		}
	}
}
void AgentManWidget::onAgentDetailMenuItemClicked()
{
    QAction *senderAction = qobject_cast<QAction *>(sender());

    int idxMenuAction = 0;
	AgentManagement::AgentInfo agentInfo;
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
		int nTargetGroupID = idxMenuAction - (int)AgentDetailItemEnum::CustomDefineGroupBase; //目标分组id
		onMoveAgent2NewGroup(agentInfo, nTargetGroupID);
        return;
    }

    //固定的菜单
    switch (idxMenuAction) {
    case (int)AgentDetailItemEnum::RefreshList:
        // Handle RefreshList
		initMachineList(nCurrentGroupID);
        break;
    case (int)AgentDetailItemEnum::EnableDebugMode:  //开启调试模式
		agentInfo.Debug = !agentInfo.Debug;
		AGENT_MAN_CONTROLLER->disableAgentInfo(agentInfo);
        // Handle EnableDebugMode
        break;
    case (int)AgentDetailItemEnum::RefreshDefenseRules:
        // Handle RefreshDefenseRules
        break;
    case (int)AgentDetailItemEnum::ViewRuleLogs:
        // Handle ViewRuleLogs
		{
			std::string strRule = "\"50\"";
			AGENT_MAN_CONTROLLER->SendDataToClient(CommandProcRuleCreationListLog, agentInfo.Mac.c_str(), strRule);
		}
        break;
    case (int)AgentDetailItemEnum::ViewProcessTree:
        // Handle ViewProcessTree
        break;
    case (int)AgentDetailItemEnum::DisableAllRules:   //禁用全部规则
		agentInfo.DisableRule = !agentInfo.DisableRule;
		AGENT_MAN_CONTROLLER->disableAgentInfo(agentInfo);
        // Handle DisableAllRules
        break;
    case (int)AgentDetailItemEnum::DisableDebugRules: //禁用调试规则
        // Handle DisableDebugRules
		agentInfo.DisableInnerRule = !agentInfo.DisableInnerRule;
		AGENT_MAN_CONTROLLER->disableAgentInfo(agentInfo);
        break;
    case (int)AgentDetailItemEnum::DisableDefenseRules:
        // Handle DisableDefenseRules
		agentInfo.DisableCustomRule = !agentInfo.DisableCustomRule;
		AGENT_MAN_CONTROLLER->disableAgentInfo(agentInfo);
        break;
    case (int)AgentDetailItemEnum::DisableBilling:
        // Handle DisableBilling
        {
			if (agentInfo.DisableCharge > 0)
			{
				agentInfo.DisableCharge = !agentInfo.DisableCharge;
				AGENT_MAN_CONTROLLER->disableAgentInfo(agentInfo);
			}else{
				AgentManDisableChargeWidget disableChargeWidget(this);
				disableChargeWidget.setWindowModality(Qt::WindowModal);
				disableChargeWidget.SetAgentInfo(agentInfo);
				QEventLoop loop;
				disableChargeWidget.show();
				loop.exec();
			}
        }
        break;
    case (int)AgentDetailItemEnum::DisableGameMenu:
		agentInfo.DisableGameMenu = !agentInfo.DisableGameMenu;
		AGENT_MAN_CONTROLLER->disableAgentInfo(agentInfo);
        // Handle DisableGameMenu
        break;
    case (int)AgentDetailItemEnum::DeleteAgent:
        // Handle DeleteAgent
		{
			MessageBoxWidget msgWidget(this,"删除警告", "确定要删除此机器吗？");
			msgWidget.setWindowModality(Qt::WindowModal);
			QEventLoop loop;
			QObject::connect(&msgWidget, &MessageBoxWidget::confirmed, [&]() {
				AGENT_MAN_CONTROLLER->delAgentInfo(agentInfo);
				loop.quit();
			});
			msgWidget.show();
			loop.exec();
		}
        break;
    default:
        // Handle unknown option
        break;
    }
}

void AgentManWidget::onMoveAgent2NewGroup(AgentManagement::AgentInfo& agentInfo, int nTargetGroupID) {

	if (agentInfo.GroupID == nTargetGroupID) //目标分组id和本身一样，啥也不做了。
	{
		return;
	}
	
	agentInfo.GroupID = nTargetGroupID;

	AGENT_MAN_CONTROLLER->moveAgent2NewGroup(agentInfo);
}


