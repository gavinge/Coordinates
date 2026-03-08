#ifndef AGENTMANWIDGET_H
#define AGENTMANWIDGET_H

#include <QWidget>
#include "common/custom_menu.h"
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


class AgentGroupInfo {
    public:
        int GroupID;
        std::string GroupName;
        int GroupParentID;
        int Disable;
        std::string Remark;

        AgentGroupInfo() {}

        AgentGroupInfo(int groupID, const std::string& groupName, int groupParentID, int disable, const std::string& remark)
            : GroupID(groupID), GroupName(groupName), GroupParentID(groupParentID), Disable(disable), Remark(remark) {}

        AgentGroupInfo(const AgentGroupInfo& other)
            : GroupID(other.GroupID), GroupName(other.GroupName), GroupParentID(other.GroupParentID), Disable(other.Disable), Remark(other.Remark) {}

        AgentGroupInfo& operator=(const AgentGroupInfo& other) {
            if (this != &other) {
                GroupID = other.GroupID;
                GroupName = other.GroupName;
                GroupParentID = other.GroupParentID;
                Disable = other.Disable;
                Remark = other.Remark;
            }
            return *this;
        }
};
class AgentManWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManWidget(QWidget *parent = nullptr);
    ~AgentManWidget();

public:
    QMenu* getAgentDetailMenu();
    //void setAgentDetailMenuSelected();
    void refreshMoveGrpupMenu();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    bool isMouseInWidget(const QWidget *widget,const QPoint &pos);

    void OnAddGroup(QString strGroupName);
    void OnDelGroup(QString strGroupName);
    void OnRenameGroup(QString strOldGroupName, QString strNewGroupName);
private:
    void initSearchEdit();
    void initGroupInfo();
    void initMachineList();

    //初始化主机详情操作菜单
    void initAgentDetailMenu();
    void initAgentGroupMenu();
    void onAgentDetailMenuItemClicked();
    void onAgentGroupMenuItemClicked();

private:
    Ui::AgentManWidget *ui;
    QMenu* menuAgentDetail; //Agent管理页面菜单
    QMenu* menuMoveGroup;   //Agent管理页面菜单，移动分组的子菜单
    QMenu* menuAgentGroup;  //主机组管理菜单
};

#endif // AGENTMANWIDGET_H
