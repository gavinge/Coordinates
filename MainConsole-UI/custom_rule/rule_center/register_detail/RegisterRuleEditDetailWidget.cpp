#include "RegisterRuleEditDetailWidget.h"
#include "ui_RegisterRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>
RegisterRuleEditDetailWidget::RegisterRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &RegisterRuleEditDetailWidget::close);
}

RegisterRuleEditDetailWidget::~RegisterRuleEditDetailWidget()
{
    delete ui;
}


void RegisterRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void RegisterRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void RegisterRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void RegisterRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void RegisterRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel RegisterRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
