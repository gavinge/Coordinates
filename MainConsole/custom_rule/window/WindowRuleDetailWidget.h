#ifndef WINDOWRULEDETAILWIDGET_H
#define WINDOWRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"

namespace Ui {
class WindowRuleDetailWidget;
}

class WindowRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WindowRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    explicit WindowRuleDetailWidget(QWidget *parent = nullptr);
    ~WindowRuleDetailWidget();
	bool RefreshList();
	int RefreshListByGourpID(int agentGroupID);

	void setCustomRuleWidgetPtr(void* parent);
	long getCurrentRuleID();
protected:
	void contextMenuEvent(QContextMenuEvent *event) override;
private:
    Ui::WindowRuleDetailWidget *ui;

private:
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentRuleID;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // WINDOWRULEDETAILWIDGET_H
