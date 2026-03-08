#ifndef MODULERULEEDITDETAILWIDGET_H
#define MODULERULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"
namespace Ui {
class ModuleRuleEditDetailWidget;
}

class ModuleRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit ModuleRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit ModuleRuleEditDetailWidget(QWidget *parent = nullptr);
    ~ModuleRuleEditDetailWidget();

public slots:
	void onConfirmBtnClicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;

private:
    Ui::ModuleRuleEditDetailWidget *ui;
	void initUi();
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleModuleProtect rule_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // MODULERULEEDITDETAILWIDGET_H
