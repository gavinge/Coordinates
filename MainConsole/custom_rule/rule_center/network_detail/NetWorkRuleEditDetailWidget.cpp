#include "NetWorkRuleEditDetailWidget.h"
#include "ui_NetWorkRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTextCodec>
#include "../common/RuleType.h"

NetWorkRuleEditDetailWidget::NetWorkRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::NetWorkRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryNetworkProtect(rid, rule_info);
	}
	initUi();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->btnClose, &QPushButton::clicked, this, &NetWorkRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &NetWorkRuleEditDetailWidget::onConfirmBtnClicked);
}


NetWorkRuleEditDetailWidget::NetWorkRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetWorkRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
	initUi();

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->btnClose, &QPushButton::clicked, this, &NetWorkRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &NetWorkRuleEditDetailWidget::onConfirmBtnClicked);
}

NetWorkRuleEditDetailWidget::~NetWorkRuleEditDetailWidget()
{
    delete ui;
}

void NetWorkRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void NetWorkRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void NetWorkRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void NetWorkRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void NetWorkRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel NetWorkRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}


void NetWorkRuleEditDetailWidget::initUi() {

	//源进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSourceProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtSourceProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//初始化处理方式combox
	for (const auto &item : NetWorkActionUtility::netWorkActionItems) {
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
		//liedtTargetIP  liedtTargetPort
		//cmbxOperationCode  cmbxPriority

		//进程
		QVariant data = static_cast<int>(rule_info.ProcessInfoType);
		int index = ui->cmbxSourceProcess->findData(data);
		if (index != -1) {
			ui->cmbxSourceProcess->setCurrentIndex(index);
		}
		ui->liedtSourceProcess->setText(QString::fromLocal8Bit(rule_info.ProcessInfo.c_str()));

		//IP
		ui->liedtTargetIP->setText(QString::fromLocal8Bit(rule_info.IP.c_str()));

		//Port
		ui->liedtTargetPort->setText(QString::fromLocal8Bit(rule_info.Port.c_str()));

	
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

		ui->liedtTargetIP->setEnabled(false);
		ui->liedtTargetPort->setEnabled(false);

		ui->cmbxOperationCode->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}

	ui->labError->hide();
}


void NetWorkRuleEditDetailWidget::onConfirmBtnClicked() {

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

	//liedtTargetIP 
	QString qstrIP = ui->liedtTargetIP->text();
	if (qstrIP.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:IP不能为空."));
		ui->labError->show();
		return;
	}

	QString qstrPort = ui->liedtTargetPort->text();
	if (qstrPort.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:端口不能为空."));
		ui->labError->show();
		return;
	}

	RuleManagement::RuleNetworkProtect rule(rule_info);


	//规则类型
	rule.RuleType = (int)RuleType::NetworkRuleType;
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

	//父进程
	rule.ProcessInfoType = ui->cmbxSourceProcess->currentData().toInt();
	rule.ProcessInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrParent).toStdString();

	//IP + Port
	rule.IP = qstrIP.toStdString();
	rule.Port = qstrPort.toStdString();

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
		RULE_MAN_CONTROLLER->updateNetworkProtect(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addNetworkProtect(rule);
	}

	close();
}