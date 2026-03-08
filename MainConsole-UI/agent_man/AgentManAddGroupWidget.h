#ifndef AGENTMANADDGROUPWIDGET_H
#define AGENTMANADDGROUPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class AgentManAddGroupWidget;
}

class AgentManAddGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManAddGroupWidget(QWidget *parent = nullptr);
    ~AgentManAddGroupWidget();

public:
    QString getLineEditContent() const;

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
    Ui::AgentManAddGroupWidget *ui;
};

#endif // AGENTMANADDGROUPWIDGET_H
