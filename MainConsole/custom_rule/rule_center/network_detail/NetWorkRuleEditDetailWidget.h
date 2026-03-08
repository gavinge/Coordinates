#ifndef NETWORKRULEEDITDETAILWIDGET_H
#define NETWORKRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"

namespace Ui {
class NetWorkRuleEditDetailWidget;
}

class NetWorkRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit NetWorkRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit NetWorkRuleEditDetailWidget(QWidget *parent = nullptr);
    ~NetWorkRuleEditDetailWidget();
public slots:
	void onConfirmBtnClicked();
private:
    Ui::NetWorkRuleEditDetailWidget *ui;
	void initUi();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleNetworkProtect rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // NETWORKRULEEDITDETAILWIDGET_H
