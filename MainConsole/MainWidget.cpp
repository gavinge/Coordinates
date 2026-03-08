#include "MainWidget.h"
#include "ui_widget.h"
#include <QAction>
#include <QStyle>
#include <QtDebug>
#include <QMouseEvent>
#include <QPainter>

#include <chrono>
#include <ctime>

#include "home/homewidget.h"
#include "agent_man/agentmanwidget.h"
#include "inner_rule/innerrulewidget.h"
#include "custom_rule/customrulewidget.h"
#include "run_app/runappwidget.h"
#include "setting/settingwidget.h"
#include "about/aboutwidget.h"

#include "cap_json\json_util.hpp"
//#include "mod_ext/agent_manager_ext.hpp"
#include "agent_man/Controller/AgentManController.h"
#include "global/global_define.h"

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
void Widget::initNetwork() {
	
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

    stackedWidget = new QStackedWidget;

    HomeWidget *homeWidget = new HomeWidget;
    stackedWidget->addWidget (homeWidget);
	
    AgentManWidget *agentManWidget = new AgentManWidget(this);
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

    optionToolButton ((int)PageIndex::tbHomePageIdx,ui->tbHome, QIcon(":/res/image/main/tab/toolbar_home.png"),QStringLiteral("当前状态"));
    optionToolButton ((int)PageIndex::tbAgentManPageIdx,ui->tbAgentMan, QIcon(":/res/image/main/tab/toolbar_agent_man.png"), QStringLiteral("机器管理"));
    optionToolButton ((int)PageIndex::tbInnerRulePageIdx,ui->tbInnerRule, QIcon(":/res/image/main/tab/toolbar_inner_rule.png"), QStringLiteral("调试规则"));
    optionToolButton ((int)PageIndex::tbCustomRulePageIdx,ui->tbCustomRule, QIcon(":/res/image/main/tab/toolbar_custom_rule.png"), QStringLiteral("防御规则"));
    optionToolButton ((int)PageIndex::tbRunAppPageIdx,ui->tbRunApp, QIcon(":/res/image/main/tab/toolbar_run_app.png"), QStringLiteral("开机任务"));
    optionToolButton ((int)PageIndex::tbSettingPageIdx,ui->tbSetting, QIcon(":/res/image/main/tab/toolbar_Setting.png"),QStringLiteral("基本设置"));
    optionToolButton ((int)PageIndex::tbAboutPageIdx,ui->tbAbout, QIcon(":/res/image/main/tab/toolbar_about.png"), QStringLiteral("关于软件"));
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

    ui->tbHome->setProperty (key, index== (int)PageIndex::tbHomePageIdx ?true:false);
    updateStyle (ui->tbHome) ;
    //connect(ui->tbHome, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbAgentMan->setProperty (key, index== (int)PageIndex::tbAgentManPageIdx ? true:false);
    updateStyle (ui->tbAgentMan) ;
    //connect(ui->tbAgentMan, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbInnerRule->setProperty (key, index== (int)PageIndex::tbInnerRulePageIdx ?true:false);
    updateStyle (ui->tbInnerRule) ;
    //connect(ui->tbInnerRule, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbCustomRule->setProperty (key, index== (int)PageIndex::tbCustomRulePageIdx ?true:false);
    updateStyle (ui->tbCustomRule) ;
    //connect(ui->tbCustomRule, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbRunApp->setProperty (key, index== (int)PageIndex::tbRunAppPageIdx ?true:false);
    updateStyle (ui->tbRunApp) ;
    //connect(ui->tbRunApp, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbSetting->setProperty (key, index== (int)PageIndex::tbSettingPageIdx ?true:false);
    updateStyle (ui->tbSetting) ;
    //connect(ui->tbSetting, SIGNAL(clicked()), this, SLOT(handleTabBarClicked()));

    ui->tbAbout->setProperty (key, index== (int)PageIndex::tbAboutPageIdx ?true:false);
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
        setTabBarIndex ((int)PageIndex::tbHomePageIdx);
    }else if(clickedButton->objectName() == "tbAgentMan"){
        setTabBarIndex ((int)PageIndex::tbAgentManPageIdx);
    }else if(clickedButton->objectName() == "tbInnerRule"){
        setTabBarIndex ((int)PageIndex::tbInnerRulePageIdx);
    }else if(clickedButton->objectName() == "tbCustomRule"){
        setTabBarIndex ((int)PageIndex::tbCustomRulePageIdx);
    }else if(clickedButton->objectName() == "tbRunApp"){
        setTabBarIndex ((int)PageIndex::tbRunAppPageIdx);
    }else if(clickedButton->objectName() == "tbSetting"){
        setTabBarIndex ((int)PageIndex::tbSettingPageIdx);
    }else if(clickedButton->objectName() == "tbAbout"){
        setTabBarIndex ((int)PageIndex::tbAboutPageIdx);
    }
}


void Widget::on_tbHome_clicked()
{
    setTabBarIndex ((int)PageIndex::tbHomePageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbHomePageIdx);
}

void Widget::on_tbAgentMan_clicked()
{
    setTabBarIndex ((int)PageIndex::tbAgentManPageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbAgentManPageIdx);
}
void Widget::on_tbInnerRule_clicked(){
    setTabBarIndex ((int)PageIndex::tbInnerRulePageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbInnerRulePageIdx);
}
void Widget::on_tbCustomRule_clicked(){
    setTabBarIndex ((int)PageIndex::tbCustomRulePageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbCustomRulePageIdx);
}
void Widget::on_tbRunApp_clicked(){
    setTabBarIndex ((int)PageIndex::tbRunAppPageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbRunAppPageIdx);
}
void Widget::on_tbSetting_clicked(){
    setTabBarIndex ((int)PageIndex::tbSettingPageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbSettingPageIdx);
}
void Widget::on_tbAbout_clicked(){
    setTabBarIndex ((int)PageIndex::tbAboutPageIdx);
    stackedWidget->setCurrentIndex ((int)PageIndex::tbAboutPageIdx);
}

void Widget::showMinimized(){
    QWidget::showMinimized();

	// 如果窗口当前是最大化的，则恢复到原始大小
	//if (isMaximized()) {
	//	showNormal();
	//}
	//else {
	//	// 否则最大化窗口
	//	showMaximized();
	//}
    //QWidget::showMaximized();
}
void Widget::closeMain(){
	int nret = AGENT_MAN_CONTROLLER->StopServer();
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
	QCoreApplication::exit(0);
    delete ui;
}




void Widget::paintEvent(QPaintEvent *event)  {

    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGray, 1)); // 设置黑色画笔，线宽为1像素
    painter.drawRect(rect().adjusted(0, 0, -1, -1)); // 绘制一个像素的边框线
}

