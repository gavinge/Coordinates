#include "AgentManDelGroupWidget.h"
#include "ui_AgentManDelGroupWidget.h"

#include <QPainter>
AgentManDelGroupWidget::AgentManDelGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManDelGroupWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
	
    connect(ui->closeBtn, &QPushButton::clicked, this, &AgentManDelGroupWidget::close);
    connect(ui->pushCancleButton, &QPushButton::clicked, this, &AgentManDelGroupWidget::close);
	connect(ui->pushComfirmButton, &QPushButton::clicked, this, &AgentManDelGroupWidget::onConfirmBtnClicked);
}

AgentManDelGroupWidget::~AgentManDelGroupWidget()
{
    delete ui;
}

void AgentManDelGroupWidget::onConfirmBtnClicked() {
	AGENT_MAN_CONTROLLER->deleteGroup(m_groupInfo);
	emit confirmed();
	close();
}
void AgentManDelGroupWidget::SetGroupID(long groupID) {

	
	if (!AGENT_MAN_CONTROLLER->queryGroupInfoByGroupId(groupID, m_groupInfo)) {

	}

	std::stringstream strStream;
	strStream << "删除分组提示";
	SetCaptionText(strStream.str());

	std::vector<AgentManagement::AgentInfo> queryResult;

	std::stringstream strStream2;
	AGENT_MAN_CONTROLLER->queryAgentInfoByGroupId(groupID, queryResult);
	if (groupID == 1) {
		ui->labelText->setStyleSheet("QLabel { color: red; }");
		strStream2 << "默认分组不能删除!";
		ui->pushComfirmButton->hide();
	}else if (queryResult.size() > 0) {
		ui->labelText->setStyleSheet("QLabel { color: red; }");
		strStream2 << "当前分组下管理着" << queryResult.size() << "台终端，无法删除！";
		ui->pushComfirmButton->hide();
	}else {
		strStream2 << "确定删除 " << m_groupInfo.GroupName << " 分组吗?";
	}
	SetMsgText(strStream2.str());
}

void AgentManDelGroupWidget::SetCaptionText(std::string strCaption) {
	ui->labelCaption->setText(QString::fromLocal8Bit(strCaption.c_str()));
}
void AgentManDelGroupWidget::SetMsgText(std::string strMsgText) {
	ui->labelText->setText(QString::fromLocal8Bit(strMsgText.c_str()));
}

void AgentManDelGroupWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void AgentManDelGroupWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void AgentManDelGroupWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void AgentManDelGroupWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}
