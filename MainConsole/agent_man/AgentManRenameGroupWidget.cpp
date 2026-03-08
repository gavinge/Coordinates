#include "AgentManRenameGroupWidget.h"
#include "ui_AgentManRenameGroupWidget.h"
#include <QPainter>
#include "string/stringhelper.hpp"
#include <QTextCodec>

AgentManRenameGroupWidget::AgentManRenameGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManRenameGroupWidget)
{
    ui->setupUi(this);
	ui->labelErr->hide();
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &AgentManRenameGroupWidget::close);
    connect(ui->pushComfirmButton, &QPushButton::clicked, this, &AgentManRenameGroupWidget::onConfirmBtnClicked);
}

AgentManRenameGroupWidget::~AgentManRenameGroupWidget()
{
    delete ui;
}

QString AgentManRenameGroupWidget::getLineEditContent() const{
    return ui->lineEdit->text();
}

void AgentManRenameGroupWidget::SetGroupID(long groupID) {

	if (!AGENT_MAN_CONTROLLER->queryGroupInfoByGroupId(groupID, m_groupInfo)) {

	}

	std::stringstream strStream;

	//std::vector<AgentManagement::AgentInfo> queryResult;

	/*std::stringstream strStream2;
	AGENT_MAN_CONTROLLER->queryAgentInfoByGroupId(groupID, queryResult);
	if (groupID == 1) {
		ui->labelText->setStyleSheet("QLabel { color: red; }");
		strStream2 << "默认分组不能删除!";
		ui->pushComfirmButton->hide();
	}
	else if (queryResult.size() > 0) {
		ui->labelText->setStyleSheet("QLabel { color: red; }");
		strStream2 << "当前分组下管理着" << queryResult.size() << "台终端，无法删除！";
		ui->pushComfirmButton->hide();
	}
	else {
		strStream2 << "确定删除 " << m_groupInfo.GroupName << " 分组吗?";
	}
	SetMsgText(strStream2.str());*/
}

void AgentManRenameGroupWidget::onConfirmBtnClicked(){

	QString qstr = ui->lineEdit->text();
	std::string strGroupName = QTextCodec::codecForName("GBK")->fromUnicode(qstr).toStdString();
	std::string::iterator end_pos = std::remove(strGroupName.begin(), strGroupName.end(), ' ');
	strGroupName.erase(end_pos, strGroupName.end());
	//int ncount = JwUtility::CStringHelper::calChineseLength(strGroupName);
	//int ncount2 = strGroupName.length();

	if (m_groupInfo.GroupID == 1)
	{
		ui->labelErr->setText(QString::fromLocal8Bit("默认分组不能修改名称。"));
		ui->labelErr->show();
		return;
	}
	if (strGroupName == "默认分组") {
		ui->labelErr->setText(QString::fromLocal8Bit("分组名称已存在。"));
		ui->labelErr->show();
		return;
	}

	if (JwUtility::CStringHelper::calChineseLength(strGroupName) < 6) {
		ui->labelErr->setText(QString::fromLocal8Bit("分组名称小于6个字符。"));
		ui->labelErr->show();
		return;
	}

	ui->labelErr->hide();
	long time = (long)std::time(NULL);

	m_groupInfo.GroupName = strGroupName;

	int nret = AGENT_MAN_CONTROLLER->renameGroupName(m_groupInfo);

	if (nret > 0) {
		emit confirmed();
		close();
	}
	else if (nret == -1) {
		ui->labelErr->setText(QString::fromLocal8Bit("分组名称已存在。"));
		ui->labelErr->show();
	}
}

void AgentManRenameGroupWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void AgentManRenameGroupWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void AgentManRenameGroupWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void AgentManRenameGroupWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}
