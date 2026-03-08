#ifndef KERNELRULEEDITDETAILWIDGET_H
#define KERNELRULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"

namespace Ui {
class KernelRuleEditDetailWidget;
}

class KernelRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit KernelRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit KernelRuleEditDetailWidget(QWidget *parent = nullptr);
    ~KernelRuleEditDetailWidget();
public slots:
	void onConfirmBtnClicked();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    Ui::KernelRuleEditDetailWidget *ui;
	void initUi();
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleKernelProtect ruel_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // KERNELRULEEDITDETAILWIDGET_H
