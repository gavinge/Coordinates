#ifndef AGENTMANDISABLECHARGEWIDGET_H
#define AGENTMANDISABLECHARGEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

#include "Controller/AgentManController.h"

namespace Ui {
class AgentManDisableChargeWidget;
}

class AgentManDisableChargeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManDisableChargeWidget(QWidget *parent = nullptr);
    ~AgentManDisableChargeWidget();

	void SetAgentInfo(AgentManagement::AgentInfo& agentInfo);

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
private:
    Ui::AgentManDisableChargeWidget *ui;
	AgentManagement::AgentInfo m_agentInfo;
};

#endif // AGENTMANDISABLECHARGEWIDGET_H
