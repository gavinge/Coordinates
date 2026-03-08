#ifndef WINDOWRULEDETAILWIDGET_H
#define WINDOWRULEDETAILWIDGET_H

#include <QWidget>
#include "..\CustomRuleUtility.h"

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

private:
    Ui::WindowRuleDetailWidget *ui;

private:
    RuleViewModel ruleViewModel;
};

#endif // WINDOWRULEDETAILWIDGET_H
