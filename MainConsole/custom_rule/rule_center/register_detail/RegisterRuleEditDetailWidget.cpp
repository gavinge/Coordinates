#include "RegisterRuleEditDetailWidget.h"
#include "ui_RegisterRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTextCodec>
#include "../common/RuleType.h"

RegisterRuleEditDetailWidget::RegisterRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::RegisterRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryRegisterProtect(rid, rule_info);
	}
	initUi();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->btnClose, &QPushButton::clicked, this, &RegisterRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &RegisterRuleEditDetailWidget::onConfirmBtnClicked);
}

RegisterRuleEditDetailWidget::RegisterRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
	initUi();
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->btnClose, &QPushButton::clicked, this, &RegisterRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &RegisterRuleEditDetailWidget::onConfirmBtnClicked);
}

RegisterRuleEditDetailWidget::~RegisterRuleEditDetailWidget()
{
    delete ui;
}


void RegisterRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void RegisterRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void RegisterRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void RegisterRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void RegisterRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel RegisterRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}


void RegisterRuleEditDetailWidget::initUi() {

	//源进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSourceProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtSourceProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//初始化处理方式combox
	for (const auto &item : RegisterActionUtility::registerActionItems) {
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
		//liedtTargetRegisterPath
		//ckbxPrivilegeRead  ckbxPrivilegeWrite ckbxPrivilegeDelete
		//cmbxOperationCode  cmbxPriority

		//进程
		QVariant data = static_cast<int>(rule_info.ProcessInfoType);
		int index = ui->cmbxSourceProcess->findData(data);
		if (index != -1) {
			ui->cmbxSourceProcess->setCurrentIndex(index);
		}
		ui->liedtSourceProcess->setText(QString::fromLocal8Bit(rule_info.ProcessInfo.c_str()));

		//注册表路径
		ui->liedtTargetRegisterPath->setText(QString::fromLocal8Bit(rule_info.RegistryPath.c_str()));


		//权限
		if (rule_info.Options & (int)RegisterPrivilegetility::RegisterPrivilegeType::READ_REG)
		{
			ui->ckbxPrivilegeRead->setChecked(true);
		}
		if (rule_info.Options & (int)RegisterPrivilegetility::RegisterPrivilegeType::WRITE_REG)
		{
			ui->ckbxPrivilegeWrite->setChecked(true);
		}
		if (rule_info.Options & (int)RegisterPrivilegetility::RegisterPrivilegeType::DELETE_REG)
		{
			ui->ckbxPrivilegeDelete->setChecked(true);
		}

		//初始化处理方式
		data = static_cast<int>(rule_info.OperationCode);
		index = ui->cmbxOperationCode->findData(data);
		if (index != -1) {
			ui->cmbxOperationCode->setCurrentIndex(index);
		}


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

		ui->liedtTargetRegisterPath->setEnabled(false);

		ui->ckbxPrivilegeRead->setEnabled(false);
		ui->ckbxPrivilegeWrite->setEnabled(false);
		ui->ckbxPrivilegeDelete->setEnabled(false);

		ui->cmbxOperationCode->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}

	ui->labError->hide();
}

void RegisterRuleEditDetailWidget::onConfirmBtnClicked() {

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

	//liedtTargetRegisterPath 
	QString qstrRegisterPath = ui->liedtTargetRegisterPath->text();
	if (qstrRegisterPath.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:匹配路径不合法."));
		ui->labError->show();
		return;
	}


	int nPrivilegeOptions = 0;
	if (ui->ckbxPrivilegeRead->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)RegisterPrivilegetility::RegisterPrivilegeType::READ_REG;
	}
	if (ui->ckbxPrivilegeWrite->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)RegisterPrivilegetility::RegisterPrivilegeType::WRITE_REG;
	}
	if (ui->ckbxPrivilegeDelete->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)RegisterPrivilegetility::RegisterPrivilegeType::DELETE_REG;
	}
	

	if (nPrivilegeOptions == 0)
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:禁止权限必须选择一个."));
		ui->labError->show();
		return;
	}

	RuleManagement::RuleRegisterProtect rule(rule_info);


	//规则类型
	rule.RuleType = (int)RuleType::RegistryRuleType;
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

	//源进程
	rule.ProcessInfoType = ui->cmbxSourceProcess->currentData().toInt();
	rule.ProcessInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrParent).toStdString();

	//注册表路径
	rule.RegistryPath = QTextCodec::codecForName("GBK")->fromUnicode(qstrRegisterPath).toStdString();

	//处理方式这里有问题，暂没有实现
	rule.OperationCode = ui->cmbxOperationCode->currentData().toInt();

	//权限
	rule.Options = nPrivilegeOptions;

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
		RULE_MAN_CONTROLLER->updateRegisterProtect(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addRegisterProtect(rule);
	}
	close();
}