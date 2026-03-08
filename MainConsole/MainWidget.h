#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QToolButton>
#include <QStackedWidget>

#include "mod_ext/communication_server_ext.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


enum class PageIndex {
	tbHomePageIdx = 0,       //首页
	tbAgentManPageIdx = 1,   //机器管理
	tbInnerRulePageIdx = 2,  //调试规则
	tbCustomRulePageIdx = 3, //防御规则
	tbRunAppPageIdx = 4,     //开机任务 
	tbSettingPageIdx = 5,    //基本设置
	tbAboutPageIdx = 6       //关于软件
};

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
	void initNetwork();

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
	//void closeEvent(QCloseEvent *event) override;

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
