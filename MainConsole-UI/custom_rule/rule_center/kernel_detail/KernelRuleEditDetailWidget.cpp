#include "KernelRuleEditDetailWidget.h"
#include "ui_KernelRuleEditDetailWidget.h"

#include <QPainter>
#include <QMouseEvent>

KernelRuleEditDetailWidget::KernelRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KernelRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &KernelRuleEditDetailWidget::close);
}

KernelRuleEditDetailWidget::~KernelRuleEditDetailWidget()
{
    delete ui;
}


void KernelRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void KernelRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void KernelRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void KernelRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void KernelRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel KernelRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
