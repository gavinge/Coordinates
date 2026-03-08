#include "ProcessRuleEditDetailWidget.h"
#include "ui_ProcessRuleEditDetailWidget.h"
#include <QPainter>
#include <QMessageBox>
#include <QTextCodec>

#include "../common/RuleType.h"


ProcessRuleEditDetailWidget::ProcessRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::ProcessRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryProcessCreation(rid, rule_info);
	}
	initUi();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->btnClose, &QPushButton::clicked, this, &ProcessRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &ProcessRuleEditDetailWidget::onConfirmBtnClicked);
}

ProcessRuleEditDetailWidget::ProcessRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
	
	initUi();

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->btnClose, &QPushButton::clicked, this, &ProcessRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &ProcessRuleEditDetailWidget::onConfirmBtnClicked);
}


ProcessRuleEditDetailWidget::~ProcessRuleEditDetailWidget()
{
    delete ui;
}

void ProcessRuleEditDetailWidget::onConfirmBtnClicked() {

	if (ruleViewModel == RuleViewModel::DisplayModel) {
		close();
	}
	//1.check value
	QString qstrParent = ui->liedtParentProcess->text();
	if (qstrParent.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:父进程不能为空."));
		ui->labError->show();
		return;
	}

	QString qstrSon = ui->liedtSonProcess->text();
	if (qstrSon.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:子进程不能为空."));
		ui->labError->show();
		return;
	}

	RuleManagement::RuleProcessCreation rule(rule_info);

	//规则类型
	rule.RuleType = (int)RuleType::ProcessRuleType;
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
	rule.ParentProcessInfoType = ui->cmbxParentProcess->currentData().toInt();
	rule.ParentProcessInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrParent).toStdString();

	//子进程
	rule.ChildProcessInfoType = ui->cmbxSonProcess->currentData().toInt();
	rule.ChildProcessInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrSon).toStdString();

	//处理方式
	rule.OperationCode = ui->cmbxTreatMod->currentData().toInt();

	//生效系统
	rule.OsVersion = ui->cmbxSysVersion->currentData().toInt();
	
	//优先级
	rule.Priority  = ui->cmbxPriority->currentData().toInt();

	//备注
	rule.Remark = QTextCodec::codecForName("GBK")->fromUnicode(ui->txtdtRemark->toPlainText()).toStdString();

	//日志选择状态
	rule.Log = ui->ckbxReportLog->isChecked();


	//2.sava data
	if (ruleViewModel == RuleViewModel::UpdateModel || ruleViewModel == RuleViewModel::EditModel)
	{
		RULE_MAN_CONTROLLER->updateProcessCreation(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addProcessCreation(rule);
	}
	close();
}
void ProcessRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void ProcessRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void ProcessRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void ProcessRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void ProcessRuleEditDetailWidget::initUi() {

	//初始化父进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxParentProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtParentProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//初始化子进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSonProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtSonProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));


	//初始化处理方式combox
	for (const auto &item : ProcessActionUtility::processActionItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxTreatMod->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
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
		//cmbxParentProcess liedtParentProcess
		//cmbxSonProcess  liedtSonProcess
		//cmbxOperationCode  cmbxPriority

		//父进程
		QVariant data = static_cast<int>(rule_info.ParentProcessInfoType);
		int index = ui->cmbxParentProcess->findData(data);
		if (index != -1) {
			ui->cmbxParentProcess->setCurrentIndex(index);
		}
		ui->liedtParentProcess->setText(QString::fromLocal8Bit(rule_info.ParentProcessInfo.c_str()));


		//子进程
		data = static_cast<int>(rule_info.ChildProcessInfoType);
		index = ui->cmbxSonProcess->findData(data);
		if (index != -1) {
			ui->cmbxSonProcess->setCurrentIndex(index);
		}
		ui->liedtSonProcess->setText(QString::fromLocal8Bit(rule_info.ChildProcessInfo.c_str()));


		//初始化处理方式
		data = static_cast<int>(rule_info.OperationCode);
		index = ui->cmbxTreatMod->findData(data);
		if (index != -1) {
			ui->cmbxTreatMod->setCurrentIndex(index);
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
		ui->cmbxParentProcess->setEnabled(false);
		ui->liedtParentProcess->setEnabled(false);

		ui->cmbxSonProcess->setEnabled(false);
		ui->liedtSonProcess->setEnabled(false);

		ui->cmbxTreatMod->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}

	ui->labError->hide();
}


void ProcessRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel ProcessRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
