#include "widget.h"
#include "ui_widget.h"
#include <QAction>
#include <QStyle>
#include <QtDebug>
#include <QMouseEvent>
#include <QPainter>

#include "home/homewidget.h"
#include "agent_man/agentmanwidget.h"
#include "inner_rule/innerrulewidget.h"
#include "custom_rule/customrulewidget.h"
#include "run_app/runappwidget.h"
#include "setting/settingwidget.h"
#include "about/aboutwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->titlelabel->setText(QString::fromLocal8Bit("XXXYYY"));
    this->setWindowFlags(Qt::FramelessWindowHint);

    initToolBar();

    initCaption();

    initStackedWidget();

    //initShadow();
}

void Widget::initToolBar(){
    optionToolButtons();
    setTabBarIndex (0) ;
}

void Widget::initCaption()
{
   connect(ui->minPushButton, &QPushButton::clicked, this, &Widget::showMinimized);
   connect(ui->closePushButton, &QPushButton::clicked, this, &Widget::closeMain);
   connect(ui->titleUpdate, &QPushButton::clicked, this, &Widget::updateVer);

   ui->titleWidget->installEventFilter(this);
}
void Widget::initShadow()
{
    /*QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(15);
    effect->setColor(Qt::black);
    effect->setOffset(0, 0);
    this->setGraphicsEffect(effect);*/
    //ui->topWidget->setGraphicsEffect(NULL);
}
void Widget::initStackedWidget(){

    //HomeWidget
    //AgentManWidget
    //InnerRuleWidget
    //CustomRuleWidget
    //RunAppWidget
    //SettingWidget
    //AboutWidget

    stackedWidget = new QStackedWidget;

    HomeWidget *homeWidget = new HomeWidget;
    stackedWidget->addWidget (homeWidget);

    AgentManWidget *agentManWidget = new AgentManWidget;
    stackedWidget->addWidget (agentManWidget);

    InnerRuleWidget *innerRuleWidget = new InnerRuleWidget;
    stackedWidget->addWidget (innerRuleWidget);

    CustomRuleWidget *customRuleWidget = new CustomRuleWidget;
    stackedWidget->addWidget (customRuleWidget);

    RunAppWidget *runAppWidget = new RunAppWidget;
    stackedWidget->addWidget (runAppWidget);

    SettingWidget *settingWidget = new SettingWidget;
    stackedWidget->addWidget (settingWidget);

    AboutWidget *aboutWidget = new AboutWidget;
    stackedWidget->addWidget (aboutWidget);
    ui->verticalLayout->addWidget (stackedWidget);
}
void Widget::optionToolButtons () {

    optionToolButton (0,ui->tbHome, QIcon(":/res/image/main/tab/toolbar_home.png"),QStringLiteral("当前状态"));
    optionToolButton (1,ui->tbAgentMan, QIcon(":/res/image/main/tab/toolbar_agent_man.png"), QStringLiteral("机器管理"));
    optionToolButton (2,ui->tbInnerRule, QIcon(":/res/image/main/tab/toolbar_inner_rule.png"), QStringLiteral("调试规则"));
    optionToolButton (3,ui->tbCustomRule, QIcon(":/res/image/main/tab/toolbar_custom_rule.png"), QStringLiteral("防御规则"));
    optionToolButton (4,ui->tbRunApp, QIcon(":/res/image/main/tab/toolbar_run_app.png"), QStringLiteral("开机任务"));
    optionToolButton (5,ui->tbSetting, QIcon(":/res/image/main/tab/toolbar_Setting.png"),QStringLiteral("基本设置"));
    optionToolButton (6,ui->tbAbout, QIcon(":/res/image/main/tab/toolbar_about.png"), QStringLiteral("关于软件"));
}

void Widget::updateStyle (QWidget * w) {
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update ();
}

void Widget::optionToolButton (unsigned idx,QToolButton * tb, QIcon icon, QString text) {
    QAction *pAction = new QAction(this);
    pAction->setText(text);
    pAction->setIcon(icon);
    tb->setIconSize(QSize(50, 50));
    tb->setDefaultAction(pAction);
    tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tb->setProperty ("mainwindow_toolbutton", true);
}

void Widget::setTabBarIndex (int index) {
    const char * key = "mainwindow_toolbutton_selected";

    ui->tbHome->setProperty (key, index==0?true:false);
    updateStyle (ui->tbHome) ;
    //connect(ui->tbHome, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbAgentMan->setProperty (key, index==1?true:false);
    updateStyle (ui->tbAgentMan) ;
    //connect(ui->tbAgentMan, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbInnerRule->setProperty (key, index==2?true:false);
    updateStyle (ui->tbInnerRule) ;
    //connect(ui->tbInnerRule, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbCustomRule->setProperty (key, index==3?true:false);
    updateStyle (ui->tbCustomRule) ;
    //connect(ui->tbCustomRule, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbRunApp->setProperty (key, index==4?true:false);
    updateStyle (ui->tbRunApp) ;
    //connect(ui->tbRunApp, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbSetting->setProperty (key, index==5?true:false);
    updateStyle (ui->tbSetting) ;
    //connect(ui->tbSetting, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbAbout->setProperty (key, index==6?true:false);
    updateStyle (ui->tbAbout) ;
    //connect(ui->tbAbout, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));
}




void Widget::setupToolButton(QToolButton *button) {
    button->setCheckable(true);
    buttonGroup->addButton(button);
    connect(button, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));
}

void Widget::handleTabBarClicked() {
    QToolButton *clickedButton = qobject_cast<QToolButton*>(sender());

    if(!clickedButton)
        return;

    if(clickedButton->objectName() == "tbHome"){
        setTabBarIndex (0);
    }else if(clickedButton->objectName() == "tbAgentMan"){
        setTabBarIndex (1);
    }else if(clickedButton->objectName() == "tbInnerRule"){
        setTabBarIndex (2);
    }else if(clickedButton->objectName() == "tbCustomRule"){
        setTabBarIndex (3);
    }else if(clickedButton->objectName() == "tbRunApp"){
        setTabBarIndex (4);
    }else if(clickedButton->objectName() == "tbSetting"){
        setTabBarIndex (5);
    }else if(clickedButton->objectName() == "tbAbout"){
        setTabBarIndex (6);
    }
}


void Widget::on_tbHome_clicked()
{
    setTabBarIndex (0);
    stackedWidget->setCurrentIndex (0);
}

void Widget::on_tbAgentMan_clicked()
{
    setTabBarIndex (1);
    stackedWidget->setCurrentIndex (1);
}
void Widget::on_tbInnerRule_clicked(){
    setTabBarIndex (2);
    stackedWidget->setCurrentIndex (2);
}
void Widget::on_tbCustomRule_clicked(){
    setTabBarIndex (3);
    stackedWidget->setCurrentIndex (3);
}
void Widget::on_tbRunApp_clicked(){
    setTabBarIndex (4);
    stackedWidget->setCurrentIndex (4);
}
void Widget::on_tbSetting_clicked(){
    setTabBarIndex (5);
    stackedWidget->setCurrentIndex (5);
}
void Widget::on_tbAbout_clicked(){
    setTabBarIndex (6);
    stackedWidget->setCurrentIndex (6);
}

void Widget::showMinimized(){
    QWidget::showMinimized();
    //QWidget::showMaximized();
}
void Widget::closeMain(){
    QWidget::close();
}

void Widget::updateVer(){

}

bool Widget::eventFilter(QObject *obj, QEvent *event)  {
        if (obj == ui->titleWidget) {
            if (event->type() == QEvent::MouseButtonPress) {
                // 处理鼠标按下事件，记录鼠标点击位置和窗口位置
                QMouseEvent *mouseEvent = reinterpret_cast<QMouseEvent*>(event);
                if (mouseEvent->button() == Qt::LeftButton) {
                    isDragging = true;
                    dragStartPosition = mouseEvent->globalPos() - frameGeometry().topLeft();
                }
                return true;
            } else if (event->type() == QEvent::MouseMove) {
                // 处理鼠标移动事件，拖动窗口
                QMouseEvent *mouseEvent = reinterpret_cast<QMouseEvent*>(event);
                if (isDragging) {
                    move(mouseEvent->globalPos() - dragStartPosition);
                    return true;
                }
            } else if (event->type() == QEvent::MouseButtonRelease) {
                // 处理鼠标释放事件，停止拖动
                QMouseEvent *mouseEvent = reinterpret_cast<QMouseEvent*>(event);
                if (mouseEvent->button() == Qt::LeftButton) {
                    isDragging = false;
                    return true;
                }
            }
        }

        return QWidget::eventFilter(obj, event);
    }

Widget::~Widget()
{
    delete ui;
}



void Widget::paintEvent(QPaintEvent *event)  {

    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1)); // 设置黑色画笔，线宽为1像素
    painter.drawRect(rect().adjusted(0, 0, -1, -1)); // 绘制一个像素的边框线
}

