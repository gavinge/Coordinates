#include "WindowRuleEditDetailWidget.h"
#include "ui_WindowRuleEditDetailWidget.h"
#include <QPainter>
#include <QMouseEvent>


WindowRuleEditDetailWidget::WindowRuleEditDetailWidget(QWidget *parent, RuleViewModel model, int rid) :
	QWidget(parent),
	ui(new Ui::WindowRuleEditDetailWidget),
	ruleViewModel(model)
{
	ui->setupUi(this);

	/*if (model == RuleViewModel::UpdateModel && rid > 0)
	{
		RULE_MAN_CONTROLLER->queryThreadCreation(rid, rule_info);
	}*/
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->closeBtn, &QPushButton::clicked, this, &WindowRuleEditDetailWidget::close);
}

WindowRuleEditDetailWidget::WindowRuleEditDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowRuleEditDetailWidget),
    ruleViewModel(RuleViewModel::AddModel)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &WindowRuleEditDetailWidget::close);
}

WindowRuleEditDetailWidget::~WindowRuleEditDetailWidget()
{
    delete ui;
}


void WindowRuleEditDetailWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void WindowRuleEditDetailWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void WindowRuleEditDetailWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void WindowRuleEditDetailWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}

void WindowRuleEditDetailWidget::SetViewModel(const RuleViewModel& model){
    ruleViewModel = model;
}
RuleViewModel WindowRuleEditDetailWidget::ViewModel(){
    return ruleViewModel;
}
