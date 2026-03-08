#include "KernelRuleEditDetailWidget.h"
#include "ui_KernelRuleEditDetailWidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QTextCodec>
#include "../common/RuleType.h"


KernelRuleEditDetailWidget::KernelRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::KernelRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryKernelProtect(rid, ruel_info);
	}

	initUi();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->btnClose, &QPushButton::clicked, this, &KernelRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &KernelRuleEditDetailWidget::onConfirmBtnClicked);
}


KernelRuleEditDetailWidget::KernelRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KernelRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
	initUi();
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->btnClose, &QPushButton::clicked, this, &KernelRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &KernelRuleEditDetailWidget::onConfirmBtnClicked);
}

KernelRuleEditDetailWidget::~KernelRuleEditDetailWidget()
{
    delete ui;
}


void KernelRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void KernelRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void KernelRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void KernelRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void KernelRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel KernelRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}


void KernelRuleEditDetailWidget::onConfirmBtnClicked() {
	
	if (ruleViewModel == RuleViewModel::DisplayModel) {
		close();
	}
	//1.check value
	QString qstrKernelInfo = ui->liedtKernelInfo->text();
	if (qstrKernelInfo.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:驱动信息不能为空."));
		ui->labError->show();
		return;
	}

	RuleManagement::RuleKernelProtect rule(ruel_info);


	//规则类型
	rule.RuleType = (int)RuleType::KernelRuleType;
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
	rule.DriverInfoType = ui->cmbxKerneInfo->currentData().toInt();
	rule.DriverInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrKernelInfo).toStdString();

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
		RULE_MAN_CONTROLLER->updateKernelProtect(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addKernelProtect(rule);
	}

	close();
}

void KernelRuleEditDetailWidget::initUi() {

	//内核模块信息
	for (const auto &item : KernelInfoTypeUtility::kernelInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxKerneInfo->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtKernelInfo->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//初始化处理方式combox
	for (const auto &item : KernelInfoTypeUtility::kernelInfoTypeItems) {
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
		//cmbxKerneInfo liedtKernelInfo
		//cmbxOperationCode  cmbxCallBackType
		//cmbxSysVersion  cmbxPriority

		//驱动combox
		QVariant data = static_cast<int>(ruel_info.DriverInfoType);
		int index = ui->cmbxKerneInfo->findData(data);
		if (index != -1) {
			ui->cmbxKerneInfo->setCurrentIndex(index);
		}
		ui->liedtKernelInfo->setText(QString::fromLocal8Bit(ruel_info.DriverInfo.c_str()));


		//初始化处理方式
		data = static_cast<int>(ruel_info.OperationCode);
		index = ui->cmbxOperationCode->findData(data);
		if (index != -1) {
			ui->cmbxOperationCode->setCurrentIndex(index);
		}

		//callbacktype 还没处理

		//版本
		data = static_cast<int>(ruel_info.OsVersion);
		index = ui->cmbxSysVersion->findData(data);
		if (index != -1) {
			ui->cmbxSysVersion->setCurrentIndex(index);
		}

		//优先级
		data = static_cast<int>(ruel_info.Priority);
		index = ui->cmbxPriority->findData(data);
		if (index != -1) {
			ui->cmbxPriority->setCurrentIndex(index);
		}

		//备注
		ui->txtdtRemark->setText(QString::fromLocal8Bit(ruel_info.Remark.c_str()));

		//日志上报标记
		ui->ckbxReportLog->setChecked(ruel_info.Log);

		(ruleViewModel == RuleViewModel::DisplayModel) ? ui->btnComfirm->setText(QString::fromLocal8Bit("退出")) : ui->btnComfirm->setText(QString::fromLocal8Bit("确定"));
	}

	if (ruleViewModel == RuleViewModel::DisplayModel)
	{
		ui->cmbxKerneInfo->setEnabled(false);
		ui->liedtKernelInfo->setEnabled(false);

		ui->cmbxCallBackType->setEnabled(false);

		ui->cmbxOperationCode->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}

	ui->labError->hide();
}