#ifndef AGENTMANDELGROUPWIDGET_H
#define AGENTMANDELGROUPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "Controller/AgentManController.h"

namespace Ui {
class AgentManDelGroupWidget;
}

class AgentManDelGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManDelGroupWidget(QWidget *parent = nullptr);
    ~AgentManDelGroupWidget();

	void SetGroupID(long groupID);
	void SetCaptionText(std::string strCaption);
	void SetMsgText(std::string strMsgText);

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
    Ui::AgentManDelGroupWidget *ui;
};

#endif // AGENTMANDELGROUPWIDGET_H
