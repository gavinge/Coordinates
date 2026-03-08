#include "NetWorkRuleEditDetailWidget.h"
#include "ui_NetWorkRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>
NetWorkRuleEditDetailWidget::NetWorkRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetWorkRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &NetWorkRuleEditDetailWidget::close);
}

NetWorkRuleEditDetailWidget::~NetWorkRuleEditDetailWidget()
{
    delete ui;
}

void NetWorkRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void NetWorkRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void NetWorkRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void NetWorkRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void NetWorkRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel NetWorkRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
