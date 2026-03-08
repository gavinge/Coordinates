#include "ProtectionRuleEditDetailWidget.h"
#include "ui_ProtectionRuleEditDetailWidget.h"

#include <QPainter>
#include <QMouseEvent>

ProtectionRuleEditDetailWidget::ProtectionRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProtectionRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &ProtectionRuleEditDetailWidget::close);
}

ProtectionRuleEditDetailWidget::~ProtectionRuleEditDetailWidget()
{
    delete ui;
}

void ProtectionRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void ProtectionRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void ProtectionRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void ProtectionRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void ProtectionRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel ProtectionRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
