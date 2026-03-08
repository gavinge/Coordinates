#include "ModuleRuleEditDetailWidget.h"
#include "ui_ModuleRuleEditDetailWidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QTextCodec>
#include "../common/RuleType.h"

ModuleRuleEditDetailWidget::ModuleRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::ModuleRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryModuleProtect(rid, rule_info);
	}

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	initUi();
	connect(ui->btnClose, &QPushButton::clicked, this, &ModuleRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &ModuleRuleEditDetailWidget::onConfirmBtnClicked);
}

ModuleRuleEditDetailWidget::ModuleRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModuleRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
	initUi();
    connect(ui->btnClose, &QPushButton::clicked, this, &ModuleRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &ModuleRuleEditDetailWidget::onConfirmBtnClicked);
}

ModuleRuleEditDetailWidget::~ModuleRuleEditDetailWidget()
{
    delete ui;
}

void ModuleRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void ModuleRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void ModuleRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void ModuleRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void ModuleRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel ModuleRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}

void ModuleRuleEditDetailWidget::initUi() {

	//源进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSourceProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtSourceProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//初始化子进程combox
	for (const auto &item : ModuleInfoTypeUtility::moduleInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxTargetModule->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtTargetModule->setPlaceholderText(QString::fromLocal8Bit("不能为空"));


	//初始化处理方式combox
	for (const auto &item : ModuleActionUtility::moduleActionItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxOperationCode->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}


	//初始化系统版本combox
	for (const auto &item : WindowsVersionUtility::windowsVersionItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSysVersion->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}


	//初始化优先级combox
	for (const auto &item : PriorityUtility::priorityItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxPriority->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}

	//初始化默认值
	if (ruleViewModel != RuleViewModel::AddModel)
	{
		//cmbxSourceProcess liedtSourceProcess
		//cmbxTargetModule  liedtTargetModule
		//cmbxOperationCode  cmbxPriority

		//进程
		QVariant data = static_cast<int>(rule_info.ProcessInfoType);
		int index = ui->cmbxSourceProcess->findData(data);
		if (index != -1) {
			ui->cmbxSourceProcess->setCurrentIndex(index);
		}
		ui->liedtSourceProcess->setText(QString::fromLocal8Bit(rule_info.ProcessInfo.c_str()));

		//模块
		data = static_cast<int>(rule_info.ModuleInfoType);
		index = ui->cmbxTargetModule->findData(data);
		if (index != -1) {
			ui->cmbxTargetModule->setCurrentIndex(index);
		}
		ui->liedtTargetModule->setText(QString::fromLocal8Bit(rule_info.ModuleInfo.c_str()));


		//初始化处理方式
		data = static_cast<int>(rule_info.OperationCode);
		index = ui->cmbxOperationCode->findData(data);
		if (index != -1) {
			ui->cmbxOperationCode->setCurrentIndex(index);
		}

		//callbacktype 还没处理

		//版本
		data = static_cast<int>(rule_info.OsVersion);
		index = ui->cmbxSysVersion->findData(data);
		if (index != -1) {
			ui->cmbxSysVersion->setCurrentIndex(index);
		}

		//优先级
		data = static_cast<int>(rule_info.Priority);
		index = ui->cmbxPriority->findData(data);
		if (index != -1) {
			ui->cmbxPriority->setCurrentIndex(index);
		}

		//备注
		ui->txtdtRemark->setText(QString::fromLocal8Bit(rule_info.Remark.c_str()));

		//日志上报标记
		ui->ckbxReportLog->setChecked(rule_info.Log);

		(ruleViewModel == RuleViewModel::DisplayModel) ? ui->btnComfirm->setText(QString::fromLocal8Bit("退出")) : ui->btnComfirm->setText(QString::fromLocal8Bit("确定"));
	}

	if (ruleViewModel == RuleViewModel::DisplayModel)
	{
		ui->cmbxSourceProcess->setEnabled(false);
		ui->liedtSourceProcess->setEnabled(false);

		ui->cmbxTargetModule->setEnabled(false);
		ui->liedtTargetModule->setEnabled(false);

		ui->cmbxOperationCode->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}
	ui->labError->hide();
}

void ModuleRuleEditDetailWidget::onConfirmBtnClicked() {

	if (ruleViewModel == RuleViewModel::DisplayModel) {
		close();
	}

	//1.check value
	QString qstrParent = ui->liedtSourceProcess->text();
	if (qstrParent.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:源进程不能为空."));
		ui->labError->show();
		return;
	}

	QString qstrModule = ui->liedtTargetModule->text();
	if (qstrModule.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:目标模块不能为空."));
		ui->labError->show();
		return;
	}


	RuleManagement::RuleModuleProtect rule(rule_info);


	//规则类型
	rule.RuleType = (int)RuleType::ModuleRuleType;
	//规则分组
	rule.RuleGroupID = 0;
	//生效标记
	rule.Enabled = 1;
	//是否为内部规则
	rule.InnerID = 0;
	rule.InnerFlg = 1;


	//创建时间
	long timeCurrent = (long)std::time(NULL);
	rule.CreateTime = timeCurrent;
	rule.UpdateTime = timeCurrent;

	//进程
	rule.ProcessInfoType = ui->cmbxSourceProcess->currentData().toInt();
	rule.ProcessInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrParent).toStdString();

	
	//模块
	rule.ModuleInfoType = ui->cmbxTargetModule->currentData().toInt();
	rule.ModuleInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrModule).toStdString();

	//处理方式
	rule.OperationCode = ui->cmbxOperationCode->currentData().toInt();

	//生效系统
	rule.OsVersion = ui->cmbxSysVersion->currentData().toInt();

	//优先级
	rule.Priority = ui->cmbxPriority->currentData().toInt();

	//备注
	rule.Remark = QTextCodec::codecForName("GBK")->fromUnicode(ui->txtdtRemark->toPlainText()).toStdString();

	//日志选择状态
	rule.Log = ui->ckbxReportLog->isChecked();


	//2.sava data
	if (ruleViewModel == RuleViewModel::UpdateModel || ruleViewModel == RuleViewModel::EditModel)
	{
		RULE_MAN_CONTROLLER->updateModuleProtect(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addModuleProtect(rule);
	}
	
	close();
}