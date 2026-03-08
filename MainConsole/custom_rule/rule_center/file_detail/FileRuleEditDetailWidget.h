#ifndef FILERULEEDITDETAILWIDGET_H
#define FILERULEEDITDETAILWIDGET_H

#include <QWidget>
#include "..\..\CustomRuleUtility.h"
#include "../../../common/GlobalDefineUtility.h"
#include "../../Controller/RuleManController.h"

namespace Ui {
class FileRuleEditDetailWidget;
}

class FileRuleEditDetailWidget : public QWidget
{
    Q_OBJECT

public:
	explicit FileRuleEditDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel, int rid = 0);
    explicit FileRuleEditDetailWidget(QWidget *parent = nullptr);
    ~FileRuleEditDetailWidget();

public slots:
	void onConfirmBtnClicked();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;
private:
    Ui::FileRuleEditDetailWidget *ui;
	void initUi();
private:
    bool isMoving = false;
    QPoint startPos;
	RuleManagement::RuleFileProtect ruel_info;
public:
    void SetViewModel(const RuleViewModel& model);
    RuleViewModel ViewModel();
private:
    RuleViewModel ruleViewModel;
};

#endif // FILERULEEDITDETAILWIDGET_H
