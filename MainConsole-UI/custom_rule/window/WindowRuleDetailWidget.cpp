#include "WindowRuleDetailWidget.h"
#include "ui_WindowRuleDetailWidget.h"

WindowRuleDetailWidget::WindowRuleDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowRuleDetailWidget)
{
    ui->setupUi(this);
}

WindowRuleDetailWidget::WindowRuleDetailWidget(QWidget *parent,RuleViewModel model) :
    QWidget(parent),
    ui(new Ui::WindowRuleDetailWidget),
    ruleViewModel(model)
{
    ui->setupUi(this);
}

WindowRuleDetailWidget::~WindowRuleDetailWidget()
{
    delete ui;
}
