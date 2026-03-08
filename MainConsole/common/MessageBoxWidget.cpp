#include "MessageBoxWidget.h"
#include "ui_MessageBoxWidget.h"
#include <QPainter>
/*MessageBoxWidget::MessageBoxWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageBoxWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window|Qt::WindowStaysOnTopHint);
    connect(ui->closeBtn, &QPushButton::clicked, this, &MessageBoxWidget::close);
    connect(ui->pushCancleButton, &QPushButton::clicked, this, &MessageBoxWidget::close);
}*/

MessageBoxWidget::MessageBoxWidget(QWidget *parent, std::string strCaption, std::string strMsg) :
	QWidget(parent),
	ui(new Ui::MessageBoxWidget),
	Caption(strCaption),
	Msg(strMsg)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
	connect(ui->closeBtn, &QPushButton::clicked, this, &MessageBoxWidget::close);
	connect(ui->pushCancleButton, &QPushButton::clicked, this, &MessageBoxWidget::close);
	connect(ui->pushComfirmButton, &QPushButton::clicked, this, &MessageBoxWidget::onConfirmBtnClicked);
	ui->labelCaption->setText(QString::fromLocal8Bit(Caption.c_str()));
	ui->labelMsg->setText(QString::fromLocal8Bit(Msg.c_str()));
}



MessageBoxWidget::~MessageBoxWidget()
{
    delete ui;
}

void MessageBoxWidget::onConfirmBtnClicked() {
	emit confirmed();
	close();
}
void MessageBoxWidget::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void MessageBoxWidget::mousePressEvent(QMouseEvent *event)  {
    if (event->buttons() == Qt::LeftButton && event->pos().y() < 32) {
        isMoving = true;
        startPos = event->globalPos() - pos();
    }
}

void MessageBoxWidget::mouseMoveEvent(QMouseEvent *event)  {
    if (isMoving) {
        move(event->globalPos() - startPos);
    }
}

void MessageBoxWidget::mouseReleaseEvent(QMouseEvent *event)  {
    Q_UNUSED(event);
    isMoving = false;
}
