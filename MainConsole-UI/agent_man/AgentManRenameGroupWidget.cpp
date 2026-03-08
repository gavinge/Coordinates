#include "AgentManRenameGroupWidget.h"
#include "ui_AgentManRenameGroupWidget.h"
#include <QPainter>
AgentManRenameGroupWidget::AgentManRenameGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManRenameGroupWidget)
{
    ui->setupUi(this);
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

void AgentManRenameGroupWidget::onConfirmBtnClicked(){
    emit confirmed();
            close();
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
