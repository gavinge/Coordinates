#include "ModuleRuleEditDetailWidget.h"
#include "ui_ModuleRuleEditDetailWidget.h"

#include <QPainter>
#include <QMouseEvent>
ModuleRuleEditDetailWidget::ModuleRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModuleRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &ModuleRuleEditDetailWidget::close);
}

ModuleRuleEditDetailWidget::~ModuleRuleEditDetailWidget()
{
    delete ui;
}

void ModuleRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void ModuleRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void ModuleRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void ModuleRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void ModuleRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel ModuleRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
