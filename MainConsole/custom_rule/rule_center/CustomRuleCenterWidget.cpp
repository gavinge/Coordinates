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

#include "../../common/MessageBoxWidget.h"
CustomRuleCenterWidget::CustomRuleCenterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomRuleCenterWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->ruleCenterCloseBtn, &QPushButton::clicked, this, &CustomRuleCenterWidget::close);
    connect(ui->addRulePushButton, &QPushButton::clicked, this, &CustomRuleCenterWidget::onAddRuleBtnClicked);

    InitTab();
	initRuleDetailMenu();
}

int CustomRuleCenterWidget::getNum() const{
    return num;
}

CustomRuleCenterWidget::~CustomRuleCenterWidget()
{
    delete ui;
}
void CustomRuleCenterWidget::onAddRuleBtnClicked(){
   


    int currentIndex = ui->tabWidget->currentIndex();
    QVariant dataVariant = ui->tabWidget->tabBar()->tabData(currentIndex);
    if(dataVariant.toInt()< (int)RuleType::ProcessRuleType || dataVariant.toInt() > (int)RuleType::ThreadRuleType){
        return;
    }

    switch ((RuleType)dataVariant.toInt()) {
    case RuleType::ProcessRuleType:
        {
            ProcessRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::FileRuleType:
        {
		FileRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::ModuleRuleType:
        {
            ModuleRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::KernelRuleType:
        {
            KernelRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::NetworkRuleType:
        {
            NetWorkRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::DomainRuleType:
        {
            DomainRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel,0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::WindowRuleType:
        {
            WindowRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::RegistryRuleType:
        {
            RegisterRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::ProtectionRuleType:
        {
            ProtectionRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
            detailWidget.setWindowModality(Qt::WindowModal);
            detailWidget.show();
            QEventLoop loop;
            loop.exec();
        }
        break;
    case RuleType::ThreadRuleType:
        {
            ThreadRuleEditDetailWidget detailWidget(this, RuleViewModel::AddModel, 0);
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
void CustomRuleCenterWidget::onTabChanged(int index) {
	eCurrentRuleTypeSelected = (RuleType)ui->tabWidget->tabBar()->tabData(index).toInt();
}

void CustomRuleCenterWidget::initRuleDetailMenu() {
	menuRuleDetailOper = new QMenu(this);

	QAction *actionDetailRule = new QAction(QString::fromLocal8Bit(" 详情"), this);
	actionDetailRule->setData(static_cast<int>(CustomRuleCenterMenuItemEnum::DetailRule));
	menuRuleDetailOper->addAction(actionDetailRule);
	connect(actionDetailRule, &QAction::triggered, this, &CustomRuleCenterWidget::onRuleDetailMenuItemClicked);

	QAction *actionUpdateRule = new QAction(QString::fromLocal8Bit(" 修改"), this);
	actionUpdateRule->setData(static_cast<int>(CustomRuleCenterMenuItemEnum::UpdateRule));
	menuRuleDetailOper->addAction(actionUpdateRule);
	connect(actionUpdateRule, &QAction::triggered, this, &CustomRuleCenterWidget::onRuleDetailMenuItemClicked);

	QAction *actionDeleteRule = new QAction(QString::fromLocal8Bit(" 删除"), this);
	actionDeleteRule->setData(static_cast<int>(CustomRuleCenterMenuItemEnum::DeleteRule));
	menuRuleDetailOper->addAction(actionDeleteRule);
	connect(actionDeleteRule, &QAction::triggered, this, &CustomRuleCenterWidget::onRuleDetailMenuItemClicked);
}

void CustomRuleCenterWidget::onRuleDetailMenuItemClicked()
{
	int idxMenuAction = 0;
	QAction *senderAction = qobject_cast<QAction *>(sender());
	if (senderAction) {
		idxMenuAction = static_cast<int>(senderAction->data().toInt());
	}
	//CustomRuleCenterMenuItemEnum::DetailRule
	switch (idxMenuAction) {
	case (int)CustomRuleCenterMenuItemEnum::DetailRule:
	{
		long nRuleID = GetCurrentSelectedRuleID(eCurrentRuleTypeSelected);
		OnMenuActionUpdateRule(eCurrentRuleTypeSelected, nRuleID, RuleViewModel::DisplayModel);
	}
	break;
	case (int)CustomRuleCenterMenuItemEnum::UpdateRule:
	{
		long nRuleID = GetCurrentSelectedRuleID(eCurrentRuleTypeSelected);
		OnMenuActionUpdateRule(eCurrentRuleTypeSelected, nRuleID, RuleViewModel::UpdateModel);
	}
	break;
	case (int)CustomRuleCenterMenuItemEnum::DeleteRule:
	{
		long nRuleID = GetCurrentSelectedRuleID(eCurrentRuleTypeSelected);

		MessageBoxWidget msgWidget(this, "删除警告", "确定要删除这条规则吗？");
		msgWidget.setWindowModality(Qt::WindowModal);
		QEventLoop loop;
		QObject::connect(&msgWidget, &MessageBoxWidget::confirmed, [&]() {
			RULE_MAN_CONTROLLER->deleteRule((int)eCurrentRuleTypeSelected, nRuleID);
			loop.quit();
		});
		msgWidget.show();
		loop.exec();
	}
	break;
	}
}

void CustomRuleCenterWidget::getRuleSummaryInfo()
{
	ruleSummary.push_back({ 0, QString::fromLocal8Bit("进程"), RuleType::ProcessRuleType,(unsigned)RULE_MAN_CONTROLLER->queryProcessCreationCount() });
	ruleSummary.push_back({ 1, QString::fromLocal8Bit("线程"), RuleType::ThreadRuleType,(unsigned)RULE_MAN_CONTROLLER->queryThreadCreationCount() });
	ruleSummary.push_back({ 2, QString::fromLocal8Bit("文件"), RuleType::FileRuleType,(unsigned)RULE_MAN_CONTROLLER->queryFileProtectCount() });
	ruleSummary.push_back({ 3, QString::fromLocal8Bit("模块"), RuleType::ModuleRuleType,(unsigned)RULE_MAN_CONTROLLER->queryModuleProtectCount() });
	ruleSummary.push_back({ 4, QString::fromLocal8Bit("驱动"), RuleType::KernelRuleType,(unsigned)RULE_MAN_CONTROLLER->queryKernelProtectCount() });
	ruleSummary.push_back({ 5, QString::fromLocal8Bit("网络"), RuleType::NetworkRuleType,(unsigned)RULE_MAN_CONTROLLER->queryNetworkProtectCount() });
	ruleSummary.push_back({ 6, QString::fromLocal8Bit("域名"), RuleType::DomainRuleType,(unsigned)RULE_MAN_CONTROLLER->queryDomainProtectCount() });
	ruleSummary.push_back({ 7, QString::fromLocal8Bit("窗口"), RuleType::WindowRuleType,0 });
	ruleSummary.push_back({ 8, QString::fromLocal8Bit("注册表"), RuleType::RegistryRuleType,(unsigned)RULE_MAN_CONTROLLER->queryRegisterProtectCount() });
	ruleSummary.push_back({ 9, QString::fromLocal8Bit("保护"), RuleType::ProtectionRuleType,(unsigned)RULE_MAN_CONTROLLER->queryProcProtectCount() });
}
void CustomRuleCenterWidget::InitTab()
{
	getRuleSummaryInfo();
	{
		ProcessRuleDetailWidget *tabWidgetDetail = new ProcessRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[0];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidgetDetail, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidgetDetail->setCustomRuleWidgetPtr(this);
		}
	}
	{
		ThreadRuleDetailWidget *tabWidget = new ThreadRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[1];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		FileRuleDetailWidget *tabWidget = new FileRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[2];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		ModuleRuleDetailWidget *tabWidget = new ModuleRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[3];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		KernelRuleDetailWidget *tabWidget = new KernelRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[4];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		NetWorkRuleDetailWidget *tabWidget = new NetWorkRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[5];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		DomainRuleDetailWidget *tabWidget = new DomainRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[6];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		WindowRuleDetailWidget *tabWidget = new WindowRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[7];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		RegisterRuleDetailWidget *tabWidget = new RegisterRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[8];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	{
		ProtectionRuleDetailWidget *tabWidget = new ProtectionRuleDetailWidget(this, RuleViewModel::EditModel);
		TabInfo tab = ruleSummary[9];
		if (ui->tabWidget) {
			int idx = ui->tabWidget->addTab(tabWidget, QString("%1(%2)").arg(tab.tabText).arg(tab.count));
			ui->tabWidget->tabBar()->setTabData(idx, QVariant((int)tab.ruleType));
			tabWidget->setCustomRuleWidgetPtr(this);
		}
	}
	

	eCurrentRuleTypeSelected = (RuleType)ui->tabWidget->tabBar()->tabData(0).toInt();
	connect(ui->tabWidget, &QTabWidget::currentChanged, this, &CustomRuleCenterWidget::onTabChanged);
}
void CustomRuleCenterWidget::UpdateTabTitle(int idx, std::string strTitle) {
	if (idx >= 0 && idx < ui->tabWidget->count()) {
		ui->tabWidget->setTabText(idx, QString::fromLocal8Bit(strTitle.c_str()));
	}
}
QMenu* CustomRuleCenterWidget::getRuleDetailMenu() {
	return menuRuleDetailOper;
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

bool CustomRuleCenterWidget::UpdateRuleList(int nRuleType) {
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
	return true;
}
bool CustomRuleCenterWidget::UpdateRule(int nRuleType, int nRuleID) {
	return true;
}

void CustomRuleCenterWidget::OnMenuActionUpdateRule(RuleType ruelType, int rid, RuleViewModel mode) {

	switch (ruelType) {
	case RuleType::ProcessRuleType:
	{
		ProcessRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::FileRuleType:
	{
		FileRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::ModuleRuleType:
	{
		ModuleRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::KernelRuleType:
	{
		KernelRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::NetworkRuleType:
	{
		NetWorkRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::DomainRuleType:
	{
		DomainRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::WindowRuleType:
	{
		WindowRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::RegistryRuleType:
	{
		RegisterRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::ProtectionRuleType:
	{
		ProtectionRuleEditDetailWidget detailWidget(this, mode, rid);
		detailWidget.setWindowModality(Qt::WindowModal);
		detailWidget.show();
		QEventLoop loop;
		loop.exec();
	}
	break;
	case RuleType::ThreadRuleType:
	{
		ThreadRuleEditDetailWidget detailWidget(this, mode, rid);
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

long CustomRuleCenterWidget::GetCurrentSelectedRuleID(RuleType ruelType) {

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