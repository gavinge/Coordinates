#ifndef DOMAINRULEEDITDETAILWIDGET_H
#define DOMAINRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"

namespace Ui {
class DomainRuleEditDetailWidget;
}

class DomainRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DomainRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::UpdateModel, int rid = 0);
	explicit DomainRuleEditDetailWidget(QWidget *parent = nullptr);
    ~DomainRuleEditDetailWidget();

public slots:
	void onConfirmBtnClicked();

private:
    Ui::DomainRuleEditDetailWidget *ui;
	void initUi();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleDomainProtect ruel_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // DOMAINRULEEDITDETAILWIDGET_H
