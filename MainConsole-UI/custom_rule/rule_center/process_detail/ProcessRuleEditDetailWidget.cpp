#include "ProcessRuleEditDetailWidget.h"
#include "ui_ProcessRuleEditDetailWidget.h"
#include <QPainter>

ProcessRuleEditDetailWidget::ProcessRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &ProcessRuleEditDetailWidget::close);

}

ProcessRuleEditDetailWidget::~ProcessRuleEditDetailWidget()
{
    delete ui;
}


void ProcessRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void ProcessRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void ProcessRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void ProcessRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void ProcessRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel ProcessRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
