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
#include <QtDebug>
CustomRuleWidget::CustomRuleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomRuleWidget),
	bShowRuleCenter(false),
	ruleCenterWidget(NULL)
{
    ui->setupUi(this);

	InitMVCFrameWork();

    initRuleDetailMenu();
    initGroupInfo();
    InitTab();
    initSlots();
}


bool CustomRuleWidget::UpdateGroupInfo() {
	initGroupInfo();
	return true;
}

bool CustomRuleWidget::UpdateGroupInfo(long nGroupID, std::string strGroupName) {
	for (int idx = 0; idx < ui->groupListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->groupListWidget->item(idx);
		if (item->data(Qt::UserRole).toInt() == nGroupID) {
			item->setText(QString::fromLocal8Bit(("   " + strGroupName).c_str()));
			break;
		}
	}
	return true;
}

bool CustomRuleWidget::DeleteGroupInfo(long nGroupID) {

	for (int idx = 0; idx < ui->groupListWidget->count(); ++idx) {
		QListWidgetItem* item = ui->groupListWidget->item(idx);
		if (item->data(Qt::UserRole).toInt() == nGroupID) {
			delete ui->groupListWidget->takeItem(idx);
			break;
		}
	}
	return true;
}


int CustomRuleWidget::UpdateRuleListByGroupID() {
	/*switch ((RuleType)eCurrentRuleTypeSelected) {
	case RuleType::ProcessRuleType:*/
	{
		ProcessRuleDetailWidget *tabWidget = qobject_cast<ProcessRuleDetailWidget *>(ui->tabWidget->widget(0));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(0, "进程(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::FileRuleType:*/
	{
		FileRuleDetailWidget *tabWidget = qobject_cast<FileRuleDetailWidget *>(ui->tabWidget->widget(2));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(2, "文件(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::ModuleRuleType:*/
	{
		ModuleRuleDetailWidget *tabWidget = qobject_cast<ModuleRuleDetailWidget *>(ui->tabWidget->widget(3));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(3, "模块(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::KernelRuleType:*/
	{
		KernelRuleDetailWidget *tabWidget = qobject_cast<KernelRuleDetailWidget *>(ui->tabWidget->widget(4));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(4, "驱动(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::NetworkRuleType:*/
	{
		NetWorkRuleDetailWidget *tabWidget = qobject_cast<NetWorkRuleDetailWidget *>(ui->tabWidget->widget(5));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(5, "网络(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::DomainRuleType:*/
	{
		DomainRuleDetailWidget *tabWidget = qobject_cast<DomainRuleDetailWidget *>(ui->tabWidget->widget(6));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(6, "域名(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::WindowRuleType:*/
	{
		WindowRuleDetailWidget *tabWidget = qobject_cast<WindowRuleDetailWidget *>(ui->tabWidget->widget(7));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(7, "窗口(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::RegistryRuleType:*/
	{
		RegisterRuleDetailWidget *tabWidget = qobject_cast<RegisterRuleDetailWidget *>(ui->tabWidget->widget(8));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(8, "注册表(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::ProtectionRuleType:*/
	{
		ProtectionRuleDetailWidget *tabWidget = qobject_cast<ProtectionRuleDetailWidget *>(ui->tabWidget->widget(9));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(9, "保护(" + std::to_string(count) + ")");
		}
	}
	/*break;
	case RuleType::ThreadRuleType:*/
	{
		ThreadRuleDetailWidget *tabWidget = qobject_cast<ThreadRuleDetailWidget *>(ui->tabWidget->widget(1));
		if (tabWidget)
		{
			int count = tabWidget->RefreshListByGourpID(nCurrentGroupID);
			UpdateTabTitle(1, "线程(" + std::to_string(count) + ")");
		}
	}
	//break;
	//// 添加其他 case 分支，确保覆盖所有枚举值
	//default:
	//	// 处理其他规则类型
	//	break;
	//}
	return 0;
}
bool CustomRuleWidget::UpdateRuleList(int nRuleType) {

	switch ((RuleType)nRuleType) {
	case RuleType::ProcessRuleType:
	{
		ProcessRuleDetailWidget *tabWidget = qobject_cast<ProcessRuleDetailWidget *>(ui->tabWidget->widget(0));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(0, "进程(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::FileRuleType:
	{
		FileRuleDetailWidget *tabWidget = qobject_cast<FileRuleDetailWidget *>(ui->tabWidget->widget(2));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(2, "文件(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::ModuleRuleType:
	{
		ModuleRuleDetailWidget *tabWidget = qobject_cast<ModuleRuleDetailWidget *>(ui->tabWidget->widget(3));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(3, "模块(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::KernelRuleType:
	{
		KernelRuleDetailWidget *tabWidget = qobject_cast<KernelRuleDetailWidget *>(ui->tabWidget->widget(4));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(4, "驱动(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::NetworkRuleType:
	{
		NetWorkRuleDetailWidget *tabWidget = qobject_cast<NetWorkRuleDetailWidget *>(ui->tabWidget->widget(5));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(5, "网络(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::DomainRuleType:
	{
		DomainRuleDetailWidget *tabWidget = qobject_cast<DomainRuleDetailWidget *>(ui->tabWidget->widget(6));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(6, "域名(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::WindowRuleType:
	{
		WindowRuleDetailWidget *tabWidget = qobject_cast<WindowRuleDetailWidget *>(ui->tabWidget->widget(7));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(7, "窗口(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::RegistryRuleType:
	{
		RegisterRuleDetailWidget *tabWidget = qobject_cast<RegisterRuleDetailWidget *>(ui->tabWidget->widget(8));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(8, "注册表(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::ProtectionRuleType:
	{
		ProtectionRuleDetailWidget *tabWidget = qobject_cast<ProtectionRuleDetailWidget *>(ui->tabWidget->widget(9));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(9, "保护(" + std::to_string(count) + ")");
		}
	}
	break;
	case RuleType::ThreadRuleType:
	{
		ThreadRuleDetailWidget *tabWidget = qobject_cast<ThreadRuleDetailWidget *>(ui->tabWidget->widget(1));
		if (tabWidget)
		{
			int count = tabWidget->RefreshList();
			UpdateTabTitle(1, "线程(" + std::to_string(count) + ")");
		}
	}
	break;
	// 添加其他 case 分支，确保覆盖所有枚举值
	default:
		// 处理其他规则类型
		break;
	}

	if (bShowRuleCenter)
	{
		ruleCenterWidget->UpdateRuleList(nRuleType);
	}
	return true;
}
bool CustomRuleWidget::UpdateRule(int nRuleType, int nRuleID) {
	return true;
}

bool CustomRuleWidget::InitMVCFrameWork() {

	CAgentManModel* pAgentManModel = (CAgentManModel*)AGENT_MAN_CONTROLLER->GetBindModel();
	if (pAgentManModel)
	{
		pAgentManModel->AttachView((CAgentManBaseView*)this);
	}

	CRuleManModel* pRuleManModel = new CRuleManModel();
	RULE_MAN_CONTROLLER->BindModel(pRuleManModel);
	pRuleManModel->AttachView((CRuleManBaseView*)this);

	AGENT_MAN_CONTROLLER->BindCustomRuleModel(pRuleManModel);
	return true;
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
    /*std::string GroupName = "分组测试";
    for (int idx = 0; idx <10 ; idx++ ) {
        QListWidgetItem *item1 = new QListWidgetItem(QString("   %1").arg(QString::fromLocal8Bit(GroupName.c_str())));
        ui->groupListWidget->addItem(item1);
    }*/

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

	connect(ui->groupListWidget, &QListWidget::itemClicked, this, &CustomRuleWidget::onGroupListItemSelected);
}

void CustomRuleWidget::onGroupListItemSelected(QListWidgetItem* item) {
	if (item) {

		int nSelectGroupID = item->data(Qt::UserRole).toInt();
		if (nSelectGroupID != nCurrentGroupID)
		{
			nCurrentGroupID = nSelectGroupID;
			UpdateRuleListByGroupID();
		}
	}
}

void CustomRuleWidget::onTabChanged(int index) {
	eCurrentRuleTypeSelected = (RuleType)ui->tabWidget->tabBar()->tabData(index).toInt();
}

void CustomRuleWidget::ClearListWidget(QListWidget* listWidget) {
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

void CustomRuleWidget::UpdateTabTitle(int idx, std::string strTitle) {
	if (idx >= 0 && idx < ui->tabWidget->count()) {
		ui->tabWidget->setTabText(idx, QString::fromLocal8Bit(strTitle.c_str()));
	}
}

bool CustomRuleWidget::isMouseInWidget(const QWidget *widget,const QPoint &pos)  {
    return widget->rect().contains(widget->mapFromParent(pos));
}


QMenu* CustomRuleWidget::getRuleDetailMenu() {
	return menuRuleDetailOper;
}

int CustomRuleWidget::EnableRuleInfo(bool IsEnable, RuleType nRuleType, int nRuleID) {

	//创建时间
	long timeCurrent = (long)std::time(NULL);
	RuleManagement::AgentEnabledRuleInfo enableInfo;
	enableInfo.AgentGroupID = nCurrentGroupID;
	enableInfo.RuleType = (int)nRuleType;
	enableInfo.RuleID = nRuleID;
	enableInfo.EnabledType = 2; //自定义规则

	if (IsEnable)
	{
		enableInfo.CreateTime = timeCurrent;
		enableInfo.UpdateTime = timeCurrent;
		return RULE_MAN_CONTROLLER->customEnabledInfo(enableInfo);
	}
	else
	{
		enableInfo.UpdateTime = timeCurrent;
		return RULE_MAN_CONTROLLER->customDisableInfo(enableInfo);
	}
	return 0;
}
void CustomRuleWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //判断鼠标是否在groupListWidget组件内
    QPoint pos = event->pos();
    if(!isMouseInWidget(ui->tabWidget,pos))
        return;
	
    //menuRuleDetailOper->exec(event->globalPos());
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
		//1.类型
		//2.ID
		{
			long nRuleID = GetCurrentSelectedRuleID(eCurrentRuleTypeSelected);

			//把规则给所有的组。
			std::vector<AgentManagement::AgentGroupInfo> queryResult;
			AGENT_MAN_CONTROLLER->queryGroups(queryResult);

			long timeCurrent = (long)std::time(NULL);
			RuleManagement::AgentEnabledRuleInfo enableInfo;
			enableInfo.RuleType = (int)eCurrentRuleTypeSelected;
			enableInfo.RuleID = nRuleID;
			enableInfo.EnabledType = 2; 
			enableInfo.CreateTime = timeCurrent;
			enableInfo.UpdateTime = timeCurrent;
			for (auto item: queryResult)
			{
				enableInfo.AgentGroupID = item.GroupID;
				RULE_MAN_CONTROLLER->customEnabledInfo(enableInfo);
			}
			UpdateRuleList((int)eCurrentRuleTypeSelected);
		}
        break;
    case (int)CustomRuleMenuItemEnum::DisabledAllGroup:        
		{
			long nRuleID = GetCurrentSelectedRuleID(eCurrentRuleTypeSelected);
			//把规则给所有的组。
			std::vector<AgentManagement::AgentGroupInfo> queryResult;
			AGENT_MAN_CONTROLLER->queryGroups(queryResult);

			long timeCurrent = (long)std::time(NULL);
			RuleManagement::AgentEnabledRuleInfo enableInfo;
			enableInfo.RuleType = (int)eCurrentRuleTypeSelected;
			enableInfo.RuleID = nRuleID;
			enableInfo.EnabledType = 2;
			enableInfo.CreateTime = timeCurrent;
			enableInfo.UpdateTime = timeCurrent;
			for (auto item : queryResult)
			{
				enableInfo.AgentGroupID = item.GroupID;
				RULE_MAN_CONTROLLER->customDisableInfo(enableInfo);
			}
			UpdateRuleList((int)eCurrentRuleTypeSelected);
		}
		break;
    }
}

void CustomRuleWidget::getRuleSummaryInfo()
{
    ruleSummary.push_back({0, QString::fromLocal8Bit("进程"), RuleType::ProcessRuleType,(unsigned)RULE_MAN_CONTROLLER->queryProcessCreationCount()});
    ruleSummary.push_back({1, QString::fromLocal8Bit("线程"), RuleType::ThreadRuleType,(unsigned)RULE_MAN_CONTROLLER->queryThreadCreationCount() });
    ruleSummary.push_back({2, QString::fromLocal8Bit("文件"), RuleType::FileRuleType,(unsigned)RULE_MAN_CONTROLLER->queryFileProtectCount() });
    ruleSummary.push_back({3, QString::fromLocal8Bit("模块"), RuleType::ModuleRuleType,(unsigned)RULE_MAN_CONTROLLER->queryModuleProtectCount() });
    ruleSummary.push_back({4, QString::fromLocal8Bit("驱动"), RuleType::KernelRuleType,(unsigned)RULE_MAN_CONTROLLER->queryKernelProtectCount() });
    ruleSummary.push_back({5, QString::fromLocal8Bit("网络"), RuleType::NetworkRuleType,(unsigned)RULE_MAN_CONTROLLER->queryNetworkProtectCount() });
    ruleSummary.push_back({6, QString::fromLocal8Bit("域名"), RuleType::DomainRuleType,(unsigned)RULE_MAN_CONTROLLER->queryDomainProtectCount() });
    ruleSummary.push_back({7, QString::fromLocal8Bit("窗口"), RuleType::WindowRuleType,0});
    ruleSummary.push_back({8, QString::fromLocal8Bit("注册表"), RuleType::RegistryRuleType,(unsigned)RULE_MAN_CONTROLLER->queryRegisterProtectCount() });
    ruleSummary.push_back({9, QString::fromLocal8Bit("保护"), RuleType::ProtectionRuleType,(unsigned)RULE_MAN_CONTROLLER->queryProcProtectCount() });
}

void CustomRuleWidget::InitTab()
{
	getRuleSummaryInfo();


	{
		ProcessRuleDetailWidget *tabWidgetDetail = new ProcessRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[0];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidgetDetail, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidgetDetail->setCustomRuleWidgetPtr(this);
		}
	}
	{
		ThreadRuleDetailWidget *tabWidget = new ThreadRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[1];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		FileRuleDetailWidget *tabWidget = new FileRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[2];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		ModuleRuleDetailWidget *tabWidget = new ModuleRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[3];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		KernelRuleDetailWidget *tabWidget = new KernelRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[4];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		NetWorkRuleDetailWidget *tabWidget = new NetWorkRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[5];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		DomainRuleDetailWidget *tabWidget = new DomainRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[6];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		WindowRuleDetailWidget *tabWidget = new WindowRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[7];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		RegisterRuleDetailWidget *tabWidget = new RegisterRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[8];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		ProtectionRuleDetailWidget *tabWidget = new ProtectionRuleDetailWidget(this, RuleViewModel::DisplayModel);
		TabInfo tab = ruleSummary[9];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}

	eCurrentRuleTypeSelected = (RuleType)ui->tabWidget->tabBar()->tabData(0).toInt();
	connect(ui->tabWidget, &QTabWidget::currentChanged, this, &CustomRuleWidget::onTabChanged);
}

//void CustomRuleWidget::InitTab()
//{
//    getRuleSummaryInfo();
//
//    std::vector<TabInfo>::iterator it;
//    for (it = ruleSummary.begin(); it != ruleSummary.end(); ++it) {
//        const TabInfo& tab = *it;
//
//        //tabWidget->setObjectName(QString("ruletab_%1").arg(tab.idx));
//
//        switch (tab.ruleType) {
//        case RuleType::ProcessRuleType:
//        {
//            ProcessRuleDetailWidget *tabWidgetDetail = new ProcessRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            //QVBoxLayout *layout = new QVBoxLayout(tabWidgetDetail);
//            //layout->addWidget(tabWidgetDetail);
//            if (ui->tabWidget) {
//                int idx = ui->tabWidget->addTab(tabWidgetDetail, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::FileRuleType:
//        {
//            FileRuleDetailWidget *tabWidget = new FileRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::ModuleRuleType:
//        {
//            ModuleRuleDetailWidget *tabWidget = new ModuleRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::KernelRuleType:
//        {
//            KernelRuleDetailWidget *tabWidget = new KernelRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::NetworkRuleType:
//        {
//            NetWorkRuleDetailWidget *tabWidget = new NetWorkRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::DomainRuleType:
//        {
//            DomainRuleDetailWidget *tabWidget = new DomainRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::WindowRuleType:
//        {
//            WindowRuleDetailWidget *tabWidget = new WindowRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::RegistryRuleType:
//        {
//            RegisterRuleDetailWidget *tabWidget = new RegisterRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::ProtectionRuleType:
//        {
//            ProtectionRuleDetailWidget *tabWidget = new ProtectionRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//        case RuleType::ThreadRuleType:
//        {
//            ThreadRuleDetailWidget *tabWidget = new ThreadRuleDetailWidget(this,RuleViewModel::DisplayModel);
//            if (ui->tabWidget) {
//				int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//				ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
//            }
//        }
//            break;
//            // 添加其他 case 分支，确保覆盖所有枚举值
//        default:
//            // 处理其他规则类型
//            break;
//        }
//
//
//
//        /*switch (tab.ruleType) {
//        case RuleType::ProcessRuleType:
//            ProcessRuleDetailWidget * tabWidget = new ProcessRuleDetailWidget(this);
//            //ui->ProcessRuleDetailWidget
//            ui->tabWidget->addTab(tabWidget,QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//            break;
//        case RuleType::FileRuleType:
//            QWidget * tabWidget2 = new QWidget(this);
//            ui->tabWidget->addTab(tabWidget2,QString("%1(%2)").arg(tab.tabText).arg(tab.count));
//            break;
//        case RuleType::ModuleRuleType:
//            break;
//        case RuleType::KernelRuleType:
//            break;
//        case RuleType::NetworkRuleType:
//            break;
//        case RuleType::DomainRuleType:
//            break;
//        case RuleType::WindowRuleType:
//            break;
//        case RuleType::RegistryRuleType:
//            break;
//        case RuleType::ProtectionRuleType:
//            break;
//        case RuleType::ThreadRuleType:
//            break;
//        default:
//            break;
//        }*/
//    }
//	//UpdateTabTitle(0, "你好这是测试222");
//	eCurrentRuleTypeSelected = (RuleType)ui->tabWidget->tabBar()->tabData(0).toInt(); 
//	connect(ui->tabWidget, &QTabWidget::currentChanged, this, &CustomRuleWidget::onTabChanged);
//}


void CustomRuleWidget::onRuleCenterBtnClicked(){
	

    CustomRuleCenterWidget customRuleCenterWidget(this);
	ruleCenterWidget = &customRuleCenterWidget;
	bShowRuleCenter = true;

    customRuleCenterWidget.setWindowModality(Qt::ApplicationModal);
    customRuleCenterWidget.num = 10000;
    // 连接子窗口的关闭信号到处理函数
    connect(&customRuleCenterWidget, &CustomRuleCenterWidget::closed, this, [=](int num) {
		bShowRuleCenter = false;
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



long CustomRuleWidget::GetCurrentSelectedRuleID(RuleType ruelType) {

	switch ((RuleType)ruelType) {
	case RuleType::ProcessRuleType:
	{
		ProcessRuleDetailWidget *tabWidget = qobject_cast<ProcessRuleDetailWidget *>(ui->tabWidget->widget(0));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::FileRuleType:
	{
		FileRuleDetailWidget *tabWidget = qobject_cast<FileRuleDetailWidget *>(ui->tabWidget->widget(2));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::ModuleRuleType:
	{
		ModuleRuleDetailWidget *tabWidget = qobject_cast<ModuleRuleDetailWidget *>(ui->tabWidget->widget(3));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::KernelRuleType:
	{
		KernelRuleDetailWidget *tabWidget = qobject_cast<KernelRuleDetailWidget *>(ui->tabWidget->widget(4));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::NetworkRuleType:
	{
		NetWorkRuleDetailWidget *tabWidget = qobject_cast<NetWorkRuleDetailWidget *>(ui->tabWidget->widget(5));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::DomainRuleType:
	{
		DomainRuleDetailWidget *tabWidget = qobject_cast<DomainRuleDetailWidget *>(ui->tabWidget->widget(6));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::WindowRuleType:
	{
		WindowRuleDetailWidget *tabWidget = qobject_cast<WindowRuleDetailWidget *>(ui->tabWidget->widget(7));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::RegistryRuleType:
	{
		RegisterRuleDetailWidget *tabWidget = qobject_cast<RegisterRuleDetailWidget *>(ui->tabWidget->widget(8));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::ProtectionRuleType:
	{
		ProtectionRuleDetailWidget *tabWidget = qobject_cast<ProtectionRuleDetailWidget *>(ui->tabWidget->widget(9));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	case RuleType::ThreadRuleType:
	{
		ThreadRuleDetailWidget *tabWidget = qobject_cast<ThreadRuleDetailWidget *>(ui->tabWidget->widget(1));
		if (tabWidget)
		{
			return tabWidget->getCurrentRuleID();
		}
	}
	break;
	// 添加其他 case 分支，确保覆盖所有枚举值
	default:
		// 处理其他规则类型
		break;
	}

	return 0;
}