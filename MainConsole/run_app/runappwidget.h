#ifndef RUNAPPWIDGET_H
#define RUNAPPWIDGET_H

#include <QWidget>
#include <QListWidget>


#include "../agent_man/AgentManBaseView.h"
#include "../agent_man/Controller/AgentManController.h"
#include "../agent_man/Model/AgentManModel.h"

namespace Ui {
class RunAppWidget;
}

class RunAppWidget : 
	public QWidget,
	public CAgentManBaseView
{
    Q_OBJECT

public:
    explicit RunAppWidget(QWidget *parent = nullptr);
    ~RunAppWidget();
	//CAgentManBaseView
public:
	bool UpdateGroupInfo()override;
	bool UpdateGroupInfo(long nGroupID, std::string strGroupName) override;
	bool DeleteGroupInfo(long nGroupID) override;

public slots:
	void onGroupListItemSelected(QListWidgetItem* item);

private:
	bool InitAgentManMVCFW();
private:
    Ui::RunAppWidget *ui;

    void initData();
    void initGroupInfo();

	void ClearListWidget(QListWidget* listWidget);

	long nCurrentGroupID; //当前选择的分组。
};

#endif // RUNAPPWIDGET_H
