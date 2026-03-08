#include "AgentManAddGroupWidget.h"
#include "ui_AgentManAddGroupWidget.h"
#include <QPainter>
AgentManAddGroupWidget::AgentManAddGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManAddGroupWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
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
    emit confirmed();
    close();
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
