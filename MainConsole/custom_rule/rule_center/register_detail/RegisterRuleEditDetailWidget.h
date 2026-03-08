#ifndef REGISTERRULEEDITDETAILWIDGET_H
#define REGISTERRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"

namespace Ui {
class RegisterRuleEditDetailWidget;
}

class RegisterRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit RegisterRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit RegisterRuleEditDetailWidget(QWidget *parent = nullptr);
    ~RegisterRuleEditDetailWidget();
public slots:
	void onConfirmBtnClicked();
private:
    Ui::RegisterRuleEditDetailWidget *ui;
	void initUi();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleRegisterProtect rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // REGISTERRULEEDITDETAILWIDGET_H
