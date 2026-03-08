#include "agent_man_custom_listwidget_item.h"
#include "ui_AgentManCustomListWidgetItem.h"

#include <QtDebug>
#include <QMouseEvent>
#include <QContextMenuEvent>



AgentManCustomListWidgetItem::AgentManCustomListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgentManCustomListWidgetItem)
{
    ui->setupUi(this);
    parentPtr = (AgentManWidget*)parent;
    //setAttribute(Qt::WA_TransparentForMouseEvents);
    initMenu();
}


AgentManCustomListWidgetItem::~AgentManCustomListWidgetItem()
{
    delete ui;
}

/*
void AgentManCustomListWidgetItem::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    // 根据行数设置不同的背景颜色
    QColor backgroundColor = (m_nRow % 2 == 0) ? QColor("#E0E0E0") : QColor("#D7E9F3");

    QPainter painter(this);
    //painter.fillRect(rect(), backgroundColor);
}*/

void AgentManCustomListWidgetItem::getItemData(AgentInfoTmp& agentInfo){
    agentInfo = m_agentInfo;
}
void AgentManCustomListWidgetItem::setItemData(int row,const AgentInfoTmp& agentInfo){

    m_nRow = row;
    m_agentInfo = agentInfo;

    //机器名称
    ui->machineCheckBox->setChecked(false);
    ui->machineCheckBox->setText(agentInfo.PcName.c_str());

    //机器状态
    QPixmap pixmap(agentInfo.Status == 1 ?  ":/res/image/agentMan/oneline.png" : ":/res/image/agentMan/offline.png");
    ui->statusLabel->setPixmap(pixmap);

    //IP地址
    ui->ipLabel->setText(agentInfo.IP.c_str());

    //MAC地址
    ui->macLabel->setText(agentInfo.Mac.c_str());

    //所属分组
    ui->groupLabel->setText(QString::fromLocal8Bit("默认机器分组"));

    //无盘超级
    ui->superDiskRadioButton->setChecked(agentInfo.IsSuper>=1);

    //调试模式
    ui->debugRadioButton->setChecked(agentInfo.Debug);

    //禁止计费
    ui->disableJiFeiRadioButton->setChecked(agentInfo.DisableCharge);

    //禁止游戏菜单
    ui->disGameMenuRadioButton->setChecked(agentInfo.DisableGameMenu);

    this->paintEvent(NULL);
}


void AgentManCustomListWidgetItem::mousePressEvent(QMouseEvent *event){

    //qInfo() << ">>>>>AgentManCustomListWidgetItem::mousePressEvent";
    if (event->button() == Qt::RightButton) {
        //qDebug() << "Right mouse button clicked!";
    }else if(event->button() == Qt::LeftButton) {
        //qDebug() << "Left mouse button clicked!";
    }
    QWidget::mousePressEvent(event);
}
void AgentManCustomListWidgetItem::mouseReleaseEvent(QMouseEvent *event) {
    //qInfo() << "*****AgentManCustomListWidgetItem::mouseReleaseEvent";
    QWidget::mouseReleaseEvent(event);
}
void AgentManCustomListWidgetItem::mouseDoubleClickEvent(QMouseEvent *event) {
    //qInfo() << "-----AgentManCustomListWidgetItem::mouseDoubleClickEvent";
    QWidget::mouseDoubleClickEvent(event);
}
void AgentManCustomListWidgetItem::mouseMoveEvent(QMouseEvent *event) {
    //qInfo() << "~~~~~AgentManCustomListWidgetItem::mouseMoveEvent";
    QWidget::mouseMoveEvent(event);
}

void AgentManCustomListWidgetItem::initMenu(){
    menu = new QMenu(this);

    QAction *deleteAction = menu->addAction(QString::fromLocal8Bit("刷新列表"));
    menu->addSeparator();

    //用一个key、vaule的map表达一个数组，
    menu->addAction(QString::fromLocal8Bit("开启调试模式"));
    menu->addAction(QString::fromLocal8Bit("刷新防御规则"));
    menu->addAction(QString::fromLocal8Bit("查看规则日志"));
    menu->addAction(QString::fromLocal8Bit("查看进程数"));
    //menu.addAction(QString::fromLocal8Bit("禁用规则"));
    QMenu *menuDisableRule = menu->addMenu(QString::fromLocal8Bit("禁用规则"));
    menuDisableRule->addAction(QString::fromLocal8Bit("禁用全部规则"));
    menuDisableRule->addAction(QString::fromLocal8Bit("禁用调试规则"));
    menuDisableRule->addAction(QString::fromLocal8Bit("禁用防御规则"));

    menu->addSeparator();
    menu->addAction(QString::fromLocal8Bit("禁用计费"));
    menu->addAction(QString::fromLocal8Bit("禁用游戏菜单"));
    menu->addSeparator();
    //menu.addAction(QString::fromLocal8Bit("移动分组"));
    QMenu *menuMoveGroup = menu->addMenu(QString::fromLocal8Bit("移动分组"));
    menuMoveGroup->addAction(QString::fromLocal8Bit("默认分组"));
    menuMoveGroup->addAction(QString::fromLocal8Bit("分组1"));

    menu->addAction(QString::fromLocal8Bit("删除机器"));
    connect(deleteAction, &QAction::triggered, this, &AgentManCustomListWidgetItem::handleDelete);

}
void AgentManCustomListWidgetItem::contextMenuEvent(QContextMenuEvent *event)
{
    //menu->exec(event->globalPos());
    parentPtr->getAgentDetailMenu()->exec(event->globalPos());
}

void AgentManCustomListWidgetItem::handleDelete()
{
    // 处理删除按钮点击事件的逻辑
}



