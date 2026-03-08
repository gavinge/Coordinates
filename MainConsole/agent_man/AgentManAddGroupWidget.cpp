#include "AgentManAddGroupWidget.h"
#include "ui_AgentManAddGroupWidget.h"
#include <QPainter>
#include "Controller/AgentManController.h"
#include <QTextCodec>
#include "string/stringhelper.hpp"
AgentManAddGroupWidget::AgentManAddGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManAddGroupWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
	ui->labelErr->hide();
    connect(ui->closeBtn, &QPushButton::clicked, this, &AgentManAddGroupWidget::close);
    connect(ui->pushComfirmButton, &QPushButton::clicked, this, &AgentManAddGroupWidget::onConfirmBtnClicked);
}

AgentManAddGroupWidget::~AgentManAddGroupWidget()
{
    delete ui;
}

QString AgentManAddGroupWidget::getLineEditContent() const{
    return ui->lineEdit->text();
}


void AgentManAddGroupWidget::onConfirmBtnClicked(){

	QString qstr = ui->lineEdit->text();
	std::string strGroupName = QTextCodec::codecForName("GBK")->fromUnicode(qstr).toStdString();
	std::string::iterator end_pos = std::remove(strGroupName.begin(), strGroupName.end(), ' ');
	strGroupName.erase(end_pos, strGroupName.end());
	//int ncount = JwUtility::CStringHelper::calChineseLength(strGroupName);
	//int ncount2 = strGroupName.length();
	if (strGroupName == "默认分组") {
		ui->labelErr->setText(QString::fromLocal8Bit("分组名称已存在。"));
		ui->labelErr->show();
		return;
	}

	if (JwUtility::CStringHelper::calChineseLength(strGroupName) < 6){
		ui->labelErr->setText(QString::fromLocal8Bit("分组名称小于6个字符。"));
		ui->labelErr->show();
		return;
	}

	ui->labelErr->hide();
	long time = (long)std::time(NULL);
	AgentManagement::AgentGroupInfo groupInfo(0, strGroupName,0,0,"",time,time,0,0,0,"","","");

	int nret = AGENT_MAN_CONTROLLER->addGroup(groupInfo);

	if(nret > 0) {
		emit confirmed();
		close();
	}else if (nret == -1) {
		ui->labelErr->setText(QString::fromLocal8Bit("分组名称已存在。"));
		ui->labelErr->show();
	}
}
void AgentManAddGroupWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void AgentManAddGroupWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void AgentManAddGroupWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void AgentManAddGroupWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}
