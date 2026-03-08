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
}

AgentManDelGroupWidget::~AgentManDelGroupWidget()
{
    delete ui;
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
