#ifndef MESSAGEBOXWIDGET_H
#define MESSAGEBOXWIDGET_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class MessageBoxWidget;
}

class MessageBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBoxWidget(QWidget *parent = nullptr);
    ~MessageBoxWidget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;

private:
    Ui::MessageBoxWidget *ui;
};

#endif // MESSAGEBOXWIDGET_H
