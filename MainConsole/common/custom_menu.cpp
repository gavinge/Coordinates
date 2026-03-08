#include "custom_menu.h"

CustomMenu::CustomMenu(QWidget *parent)
    : QMenu(parent)
{
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

CustomMenu::~CustomMenu()
{
}
//void CustomMenu::AddMenuItem(QString itemText,int data, Qt::ConnectionType atype){
//    QAction *action = new QAction(itemText, this);
//    action->setData(data);
//    this->addAction(action);
//    connect(action, &QAction::triggered, this, atype);
//}
