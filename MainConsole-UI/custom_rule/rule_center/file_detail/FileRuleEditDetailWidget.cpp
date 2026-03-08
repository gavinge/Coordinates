#include "FileRuleEditDetailWidget.h"
#include "ui_FileRuleEditDetailWidget.h"
#include <QMouseEvent>
#include <QPainter>

FileRuleEditDetailWidget::FileRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &FileRuleEditDetailWidget::close);
}

FileRuleEditDetailWidget::~FileRuleEditDetailWidget()
{
    delete ui;
}


void FileRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void FileRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void FileRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void FileRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void FileRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel FileRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
