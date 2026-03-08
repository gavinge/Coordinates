#ifndef AGENTMANDISABLECHARGEWIDGET_H
#define AGENTMANDISABLECHARGEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class AgentManDisableChargeWidget;
}

class AgentManDisableChargeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManDisableChargeWidget(QWidget *parent = nullptr);
    ~AgentManDisableChargeWidget();
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
};

#endif // AGENTMANDISABLECHARGEWIDGET_H
