#ifndef CUSTOMMENU_H
#define CUSTOMMENU_H

#include <QMenu>

class CustomMenu : public QMenu
{
    Q_OBJECT
public:
    explicit CustomMenu(QWidget *parent = nullptr);
    ~CustomMenu();
public:
    //void AddMenuItem(QString itemText,int data, Qt::ConnectionType atype);
};

#endif // CUSTOMMENU_H
