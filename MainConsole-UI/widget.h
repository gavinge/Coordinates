#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QToolButton>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QButtonGroup *buttonGroup;
private:
    void initToolBar();

    void initCaption();

    void initStackedWidget();

    void initShadow();

    bool eventFilter(QObject *obj, QEvent *event) override;

    void setupToolButton(QToolButton *button);
    void optionToolButton (unsigned idx,QToolButton * tb, QIcon icon, QString text);
    void optionToolButtons();
    void updateStyle (QWidget * w);
    void setTabBarIndex (int index) ;

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void handleTabBarClicked();
    void on_tbHome_clicked();
    void on_tbAgentMan_clicked();
    void on_tbInnerRule_clicked();
    void on_tbCustomRule_clicked();
    void on_tbRunApp_clicked();
    void on_tbSetting_clicked();
    void on_tbAbout_clicked();

public slots:
    void showMinimized();
    void closeMain();
    void updateVer();

private:
    bool isDragging;
    QPoint dragStartPosition;
    QStackedWidget *stackedWidget;
};
#endif // WIDGET_H
