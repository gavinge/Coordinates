#include "ThreadRuleEditDetailWidget.h"
#include "ui_ThreadRuleEditDetailWidget.h"
#include <QMouseEvent>
#include <QPainter>

ThreadRuleEditDetailWidget::ThreadRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreadRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &ThreadRuleEditDetailWidget::close);
}

ThreadRuleEditDetailWidget::~ThreadRuleEditDetailWidget()
{
    delete ui;
}

void ThreadRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void ThreadRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void ThreadRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void ThreadRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void ThreadRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel ThreadRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
