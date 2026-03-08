#ifndef RUNAPPWIDGET_H
#define RUNAPPWIDGET_H

#include <QWidget>

namespace Ui {
class RunAppWidget;
}

class RunAppWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RunAppWidget(QWidget *parent = nullptr);
    ~RunAppWidget();

private:
    Ui::RunAppWidget *ui;

    void initData();
    void initGroupInfo();
};

#endif // RUNAPPWIDGET_H
