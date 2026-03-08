#include "FileRuleEditDetailWidget.h"
#include "ui_FileRuleEditDetailWidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QTextCodec>
#include "../common/RuleType.h"


FileRuleEditDetailWidget::FileRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::FileRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	if (model != RuleViewModel::AddModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryFileProtect(rid, ruel_info);
	}

	initUi();

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->btnClose, &QPushButton::clicked, this, &FileRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &FileRuleEditDetailWidget::onConfirmBtnClicked);
}


FileRuleEditDetailWidget::FileRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);

	initUi();

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->btnClose, &QPushButton::clicked, this, &FileRuleEditDetailWidget::close);
	connect(ui->btnComfirm, &QPushButton::clicked, this, &FileRuleEditDetailWidget::onConfirmBtnClicked);
}

FileRuleEditDetailWidget::~FileRuleEditDetailWidget()
{
    delete ui;
}


void FileRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void FileRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void FileRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void FileRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void FileRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel FileRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}


void FileRuleEditDetailWidget::initUi() {

	//源进程combox
	for (const auto &item : ProcessInfoTypeUtility::processInfoTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxSourceProcess->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtSourceProcess->setPlaceholderText(QString::fromLocal8Bit("不能为空"));

	//初始化文件combox
	for (const auto &item : FileCheckTypeUtility::fileCheckTypeItems) {
		QVariant data = static_cast<int>(item.first);
		ui->cmbxTargetFile->addItem(QString::fromLocal8Bit(item.second.c_str()), data);
	}
	ui->liedtTargetFile->setPlaceholderText(QString::fromLocal8Bit("不能为空"));


	//初始化处理方式combox
	for (const auto &item : FileActionUtility::fileActionItems) {
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


		//初始化文件combox
		data = static_cast<int>(ruel_info.FileInfoType);
		index = ui->cmbxTargetFile->findData(data);
		if (index != -1) {
			ui->cmbxTargetFile->setCurrentIndex(index);
		}
		ui->liedtTargetFile->setText(QString::fromLocal8Bit(ruel_info.FileInfo.c_str()));

		//初始化处理方式
		data = static_cast<int>(ruel_info.OperationCode);
		index = ui->cmbxOperationCode->findData(data);
		if (index != -1) {
			ui->cmbxOperationCode->setCurrentIndex(index);
		}

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

		//禁止权限
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::READ_FILE)
		{
			ui->ckbxPrivilegeRead->setChecked(true);
		}
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::WRITE_FILE)
		{
			ui->ckbxPrivilegeWrite->setChecked(true);
		}
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::CREATE_FILE)
		{
			ui->ckbxPrivilegeCreate->setChecked(true);
		}
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::OPEN_FILE)
		{
			ui->ckbxPrivilegeOpen->setChecked(true);
		}
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::DELETE_FILE)
		{
			ui->ckbxPrivilegeDelete->setChecked(true);
		}
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::QUERY_FILE_INFO)
		{
			ui->ckbxPrivilegeQuery->setChecked(true);
		}
		if (ruel_info.Options & (int)FilePrivilegetility::FilePrivilegeType::RENAME_FILE)
		{
			ui->ckbxPrivilegeRename->setChecked(true);
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

		ui->cmbxTargetFile->setEnabled(false);
		ui->liedtTargetFile->setEnabled(false);

		ui->ckbxPrivilegeRead->setEnabled(false);
		ui->ckbxPrivilegeWrite->setEnabled(false);
		ui->ckbxPrivilegeCreate->setEnabled(false);
		ui->ckbxPrivilegeOpen->setEnabled(false);
		ui->ckbxPrivilegeDelete->setEnabled(false);
		ui->ckbxPrivilegeQuery->setEnabled(false);
		ui->ckbxPrivilegeRename->setEnabled(false);


		ui->cmbxOperationCode->setEnabled(false);
		ui->cmbxSysVersion->setEnabled(false);
		ui->cmbxPriority->setEnabled(false);
		ui->txtdtRemark->setEnabled(false);
		ui->ckbxReportLog->setEnabled(false);
	}

	ui->labError->hide();
}

void FileRuleEditDetailWidget::onConfirmBtnClicked() {

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

	QString qstrfile = ui->liedtTargetFile->text();
	if (qstrfile.isEmpty())
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:目标文件不能为空."));
		ui->labError->show();
		return;
	}

	//权限
	int nPrivilegeOptions = 0;
	if (ui->ckbxPrivilegeRead->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::READ_FILE;
	}
	if (ui->ckbxPrivilegeWrite->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::WRITE_FILE;
	}
	if (ui->ckbxPrivilegeCreate->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::CREATE_FILE;
	}
	if (ui->ckbxPrivilegeOpen->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::OPEN_FILE;
	}
	if (ui->ckbxPrivilegeDelete->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::DELETE_FILE;
	}
	if (ui->ckbxPrivilegeQuery->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::QUERY_FILE_INFO;
	}
	if (ui->ckbxPrivilegeRename->isChecked())
	{
		nPrivilegeOptions = nPrivilegeOptions | (int)FilePrivilegetility::FilePrivilegeType::RENAME_FILE;
	}

	if (nPrivilegeOptions == 0)
	{
		ui->labError->setText(QString::fromLocal8Bit("错误提示:禁止权限必须选择一个."));
		ui->labError->show();
		return;
	}


	RuleManagement::RuleFileProtect rule(ruel_info);;


	//规则类型
	rule.RuleType = (int)RuleType::FileRuleType;
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

	//文件属性
	rule.FileInfoType = ui->cmbxTargetFile->currentData().toInt();
	rule.FileInfo = QTextCodec::codecForName("GBK")->fromUnicode(qstrfile).toStdString();

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

	//禁止权限
	rule.Options = nPrivilegeOptions;
	

	if (ruleViewModel == RuleViewModel::UpdateModel || ruleViewModel == RuleViewModel::EditModel)
	{
		RULE_MAN_CONTROLLER->updateFileProtect(rule);
	}
	else if (ruleViewModel == RuleViewModel::AddModel) {
		RULE_MAN_CONTROLLER->addFileProtect(rule);
	}

	close();
}