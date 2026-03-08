#include "homewidget.h"
#include "ui_homewidget.h"

HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWidget)
{
    ui->setupUi(this);
    ui->welcomeLabel->setText(QString::fromLocal8Bit("欢迎使用主动防御系统"));
}

HomeWidget::~HomeWidget()
{
    delete ui;
}
