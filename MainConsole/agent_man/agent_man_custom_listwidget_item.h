#ifndef AGENT_MAN_CUSTOM_LISTWIDGET_ITEM_H
#define AGENT_MAN_CUSTOM_LISTWIDGET_ITEM_H

#include <QWidget>
#include <QPainter>
#include <QMenu>
#include "agentmanwidget.h"

namespace Ui {
class AgentManCustomListWidgetItem;
}


class AgentManCustomListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManCustomListWidgetItem(QWidget *parent = nullptr);
    ~AgentManCustomListWidgetItem();

    //void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


	void setAgentManPtr(AgentManWidget* parent);

protected:
    void initMenu();
    void contextMenuEvent(QContextMenuEvent *event) override;
	void reSetMenuDisplay(QMenu* menuAgentDetail);
	void GetAllActions(QMenu *menu, QList<QAction *> &actionsList);
private slots:
    void handleDelete();

public:
    void setItemData(int row,const AgentManagement::AgentInfo& agentInfo);
    void getItemData(AgentManagement::AgentInfo& agentInfo);
private:
    Ui::AgentManCustomListWidgetItem *ui;
     QMenu *menu;
    int m_nRow;
	AgentManagement::AgentInfo m_agentInfo;
    AgentManWidget* parentPtr;
};

#endif // AGENT_MAN_CUSTOM_LISTWIDGET_ITEM_H
