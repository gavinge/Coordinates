#include "DomainRuleEditDetailWidget.h"
#include "ui_DomainRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTextCodec>
#include "../common/RuleType.h"

DomainRuleEditDetailWidget::DomainRuleEditDetailWidget(QWidget *parent, RuleViewModel model , int rid):
	QWidget(parent),
	ui(new Ui::DomainRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0 )
	{
		RULE_MAN_CONTROLLER->queryDomainProtect(rid, ruel_info);
	}	
	initUi();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->btnClose, &QPushButton::clicked, this, &DomainRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &DomainRuleEditDetailWidget::onConfirmBtnClicked);
}
DomainRuleEditDetailWidget::DomainRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DomainRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
	initUi();
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->btnClose, &QPushButton::clicked, this, &DomainRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &DomainRuleEditDetailWidget::onConfirmBtnClicked);
}

DomainRuleEditDetailWidget::~DomainRuleEditDetailWidget()
{
    delete ui;
}

void DomainRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void DomainRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void DomainRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void DomainRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void DomainRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel DomainRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}


void DomainRuleEditDetailWidget::initUi() {

	//源进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSourceProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}

	ui->liedtSourceProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//和网络的一样
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
		//源进程combox
		QVariant data = static_cast<int>(ruel_info.ProcessInfoType);
		int index = ui->cmbxSourceProcess->findData(data);
		if (index != -1) {
			ui->cmbxSourceProcess->setCurrentIndex(index);
		}
		ui->liedtSourceProcess->setText(QString::fromLocal8Bit(ruel_info.ProcessInfo.c_str()));

		//域名
		ui->liedtTargetDomain->setText(QString::fromLocal8Bit(ruel_info.DomainName.c_str()));

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
		ui->cmbxSourceProcess->setEnabled(false);
		ui->liedtSourceProcess->setEnabled(false);

		ui->liedtTargetDomain->setEnabled(false);

		ui->cmbxOperationCode->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}

	ui->labError->hide();
}

void DomainRuleEditDetailWidget::onConfirmBtnClicked() {

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

	//liedtTargetDomain 
	QString qstrDomain = ui->liedtTargetDomain->text();
	if (qstrDomain.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:网站域名不能为空."));
		ui->labError->show();
		return;
	}


	RuleManagement::RuleDomainProtect rule(ruel_info);


	//规则类型
	rule.RuleType = (int)RuleType::DomainRuleType;
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

	//域名
	rule.DomainName = QTextCodec::codecForName("GBK")->fromUnicode(qstrDomain).toStdString();

	//处理方式这里有问题，暂没有实现
	//rule.OperationCode = ui->cmbxOperationCode->currentData().toInt();

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
		RULE_MAN_CONTROLLER->updateDomainProtect(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addDomainProtect(rule);
	}
	
	close();
}