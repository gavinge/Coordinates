#include "AgentManDisableChargeWidget.h"
#include "ui_AgentManDisableChargeWidget.h"
#include <QPainter>
AgentManDisableChargeWidget::AgentManDisableChargeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManDisableChargeWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &AgentManDisableChargeWidget::close);
}

AgentManDisableChargeWidget::~AgentManDisableChargeWidget()
{
    delete ui;
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
