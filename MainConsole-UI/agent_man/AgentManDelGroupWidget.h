#ifndef AGENTMANDELGROUPWIDGET_H
#define AGENTMANDELGROUPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class AgentManDelGroupWidget;
}

class AgentManDelGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManDelGroupWidget(QWidget *parent = nullptr);
    ~AgentManDelGroupWidget();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
private:
    Ui::AgentManDelGroupWidget *ui;
};

#endif // AGENTMANDELGROUPWIDGET_H
