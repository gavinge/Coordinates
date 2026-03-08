#ifndef AGENTMANWIDGET_H
#define AGENTMANWIDGET_H

#include <QWidget>
#include "common/custom_menu.h"

#include "Model/AgentManModel.h"
#include "AgentManBaseView.h"
#include <QListWidgetItem>

#include "../MainWidget.h"
namespace Ui {
class AgentManWidget;
}

///Agent详情菜单响应标记
enum class AgentDetailItemEnum {
    Separator = 1000,             //分割线
    SubMenu   = 1001,             //子菜单
    CustomDefineGroupBase = 1002, //自定义菜单基础
    RefreshList = 1,        //刷新列表
    EnableDebugMode = 2,    //开启调试模式
    RefreshDefenseRules = 3,//刷新防御规则
    ViewRuleLogs = 4,       //查看规则日志
    ViewProcessTree = 5,    //查看进程树
    DisableAllRules = 6,    //禁用全部规则
    DisableDebugRules = 7,  //禁用调试规则
    DisableDefenseRules = 8,//禁用防御规则
    DisableBilling = 9,     //禁用计费
    DisableGameMenu = 10,   //禁用游戏菜单
    DeleteAgent = 11,       //删除机器
};


class AgentManWidget : 
	public QWidget,
	public CAgentManBaseView
{
    Q_OBJECT

public:
    explicit AgentManWidget(QWidget *parent = nullptr);
    ~AgentManWidget();

	//CAgentManBaseView
public: 
	bool UpdateGroupInfo()override;
	bool UpdateAgentInfo(int nGroupID) override;
	bool UpdateGroupInfo(long nGroupID, std::string strGroupName) override;
	bool DeleteGroupInfo(long nGroupID) override;
	bool DeleteAgentFromCurrentAgentList(int nAgentID) override;
	bool UpdateAgentFromCurrentAgentList(const AgentManagement::AgentInfo& agentInfo) override;
	bool OnLineNotifyView(long nGroupID) override;
private:
	bool InitMVCFrameWork();

public slots:
	void onGroupListItemSelected(QListWidgetItem* item);
	void onresearchPushButtonClicked();

	void onShutDownPushButtonClicked();

	//
public:
    QMenu* getAgentDetailMenu();
    //void setAgentDetailMenuSelected();
    void refreshMoveGrpupMenu();

	void RefreshAgentList();
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    bool isMouseInWidget(const QWidget *widget,const QPoint &pos);

    void OnAddGroup(QString strGroupName);
    void OnDelGroup(QString strGroupName);
    void OnRenameGroup(QString strOldGroupName, QString strNewGroupName);

	Widget* FindMainWindow();
private:
    void initSearchEdit();
    void initGroupInfo();
    void initMachineList();
	void initMachineList(int nGroupID);
	void initMachineList(const std::vector<AgentManagement::AgentInfo>& agentList);
	void ClearListWidget(QListWidget* listWidget);

    //初始化主机详情操作菜单
    void initAgentDetailMenu();
	void updateAgentDetailMoveGroupMenu();
    void initAgentGroupMenu();
    void onAgentDetailMenuItemClicked();
	void onAgentDetailBgroundMenuItemClicked();
    void onAgentGroupMenuItemClicked();

	//分组移动
	void onMoveAgent2NewGroup(AgentManagement::AgentInfo& agentInfo,int nTargetGroupID);
private:
    Ui::AgentManWidget *ui;
    QMenu* menuAgentDetail; //Agent管理页面菜单
	QMenu* menuAgentDetailBground; //CustomListWidget空白处的菜单。
    QMenu* menuMoveGroup;   //Agent管理页面菜单，移动分组的子菜单
    QMenu* menuAgentGroup;  //主机组管理菜单

private:
	long nCurrentGroupID; //当前选择的分组。
	long nCurrentAgentID;
};

#endif // AGENTMANWIDGET_H
