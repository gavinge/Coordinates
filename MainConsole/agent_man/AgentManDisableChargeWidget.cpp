#include "AgentManDisableChargeWidget.h"
#include "ui_AgentManDisableChargeWidget.h"
#include <QPainter>
AgentManDisableChargeWidget::AgentManDisableChargeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManDisableChargeWidget)
{
    ui->setupUi(this);
	ui->labelErr->hide();
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &AgentManDisableChargeWidget::close);
	connect(ui->pushComfirmButton, &QPushButton::clicked, this, &AgentManDisableChargeWidget::onConfirmBtnClicked);
}

AgentManDisableChargeWidget::~AgentManDisableChargeWidget()
{
    delete ui;
}

void AgentManDisableChargeWidget::onConfirmBtnClicked() {
	long nDisableChargeTime = 0;
	
	if (ui->checkBox->isChecked())
	{
		nDisableChargeTime = 1000000;
	}
	else 
	{
		std::string strEditTime = ui->lineEdit->text().toStdString();
		nDisableChargeTime = atol(strEditTime.c_str());
		if (nDisableChargeTime < 1 || nDisableChargeTime > 180)
		{
			ui->labelErr->setText(QString::fromLocal8Bit("时间不符合规范。"));
			ui->labelErr->show();
			return;
		}
	}
	m_agentInfo.DisableCharge = nDisableChargeTime;

	AGENT_MAN_CONTROLLER->disableAgentInfo(m_agentInfo);

	close();
}
void AgentManDisableChargeWidget::SetAgentInfo(AgentManagement::AgentInfo& agentInfo) {
	m_agentInfo = agentInfo;
}
void AgentManDisableChargeWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void AgentManDisableChargeWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void AgentManDisableChargeWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void AgentManDisableChargeWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}
