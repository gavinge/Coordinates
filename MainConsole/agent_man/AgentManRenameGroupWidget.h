#ifndef AGENTMANRENAMEGROUPWIDGET_H
#define AGENTMANRENAMEGROUPWIDGET_H

#include "Controller/AgentManController.h"

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class AgentManRenameGroupWidget;
}

class AgentManRenameGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManRenameGroupWidget(QWidget *parent = nullptr);
    ~AgentManRenameGroupWidget();

public:
    QString getLineEditContent() const;
	void SetGroupID(long groupID);
signals:
    void confirmed();
public slots:
    void onConfirmBtnClicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
	AgentManagement::AgentGroupInfo m_groupInfo;
private:
    Ui::AgentManRenameGroupWidget *ui;
};

#endif // AGENTMANRENAMEGROUPWIDGET_H
