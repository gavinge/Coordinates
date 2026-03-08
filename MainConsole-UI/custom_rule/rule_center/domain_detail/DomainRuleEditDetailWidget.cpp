#include "DomainRuleEditDetailWidget.h"
#include "ui_DomainRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>
DomainRuleEditDetailWidget::DomainRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DomainRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &DomainRuleEditDetailWidget::close);
}

DomainRuleEditDetailWidget::~DomainRuleEditDetailWidget()
{
    delete ui;
}

void DomainRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void DomainRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void DomainRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void DomainRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void DomainRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel DomainRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}

