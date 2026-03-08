#ifndef AGENT_MAN_CUSTOM_LISTWIDGET_ITEM_H
#define AGENT_MAN_CUSTOM_LISTWIDGET_ITEM_H

#include <QWidget>
#include <QPainter>
#include <QMenu>
#include "agentmanwidget.h"

namespace Ui {
class AgentManCustomListWidgetItem;
}


//临时使用dll接口中的类，用做联调
class AgentInfoTmp {
    public:
        int ID;
        std::string Mid;
        int Status;
        int GroupID;
        int Debug;
        int DisableRule;
        int DisableCharge;
        int DisableGameMenu;
        int IsSuper;
        std::string PcName;
        std::string IP;
        std::string Mac;
        int VersionType;
        int VersionName;
        int X64;
        std::string Cpu;
        std::string DisplayCard;
        std::string BaseBoard;
        std::string MemorySize;
        int NetworkSpeed;
        int Logincs;
        int Drvlog;
        int BootTime;
        std::string Token;
        std::string Ver;

        AgentInfoTmp() {}

        ~AgentInfoTmp() {}

        AgentInfoTmp(int id,const std::string& mid, int status, int groupID, int debug, int disableRule, int disableCharge, int disableGameMenu,
            int isSuper, const std::string& pcName, const std::string& ip, const std::string& mac, int versionType,
            int versionName, int x64, const std::string& cpu, const std::string& displayCard,
            const std::string& baseBoard, const std::string& memorySize, int networkSpeed, int logincs, int drvlog,
            int bootTime, const std::string& token, const std::string& ver)
            : ID(id), Mid(mid), Status(status), GroupID(groupID), Debug(debug), DisableRule(disableRule), DisableCharge(disableCharge),
            DisableGameMenu(disableGameMenu), IsSuper(isSuper), PcName(pcName), IP(ip), Mac(mac),
            VersionType(versionType), VersionName(versionName), X64(x64), Cpu(cpu), DisplayCard(displayCard),
            BaseBoard(baseBoard), MemorySize(memorySize), NetworkSpeed(networkSpeed), Logincs(logincs),
            Drvlog(drvlog), BootTime(bootTime), Token(token), Ver(ver) {}

        AgentInfoTmp(const AgentInfoTmp& other)
            : ID(other.ID),Mid(other.Mid), Status(other.Status), GroupID(other.GroupID), Debug(other.Debug),
            DisableRule(other.DisableRule), DisableCharge(other.DisableCharge),
            DisableGameMenu(other.DisableGameMenu), IsSuper(other.IsSuper), PcName(other.PcName),
            IP(other.IP), Mac(other.Mac), VersionType(other.VersionType), VersionName(other.VersionName),
            X64(other.X64), Cpu(other.Cpu), DisplayCard(other.DisplayCard), BaseBoard(other.BaseBoard),
            MemorySize(other.MemorySize), NetworkSpeed(other.NetworkSpeed), Logincs(other.Logincs),
            Drvlog(other.Drvlog), BootTime(other.BootTime), Token(other.Token), Ver(other.Ver) {}

        AgentInfoTmp& operator=(const AgentInfoTmp& other) {
            if (this != &other) {
                ID = other.ID;
                Mid = other.Mid;
                Status = other.Status;
                GroupID = other.GroupID;
                Debug = other.Debug;
                DisableRule = other.DisableRule;
                DisableCharge = other.DisableCharge;
                DisableGameMenu = other.DisableGameMenu;
                IsSuper = other.IsSuper;
                PcName = other.PcName;
                IP = other.IP;
                Mac = other.Mac;
                VersionType = other.VersionType;
                VersionName = other.VersionName;
                X64 = other.X64;
                Cpu = other.Cpu;
                DisplayCard = other.DisplayCard;
                BaseBoard = other.BaseBoard;
                MemorySize = other.MemorySize;
                NetworkSpeed = other.NetworkSpeed;
                Logincs = other.Logincs;
                Drvlog = other.Drvlog;
                BootTime = other.BootTime;
                Token = other.Token;
                Ver = other.Ver;
            }
            return *this;
        }
};

class AgentManCustomListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit AgentManCustomListWidgetItem(QWidget *parent = nullptr);
    ~AgentManCustomListWidgetItem();

    //void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;



protected:
    void initMenu();
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void handleDelete();

public:
    void setItemData(int row,const AgentInfoTmp& agentInfo);
    void getItemData(AgentInfoTmp& agentInfo);
private:
    Ui::AgentManCustomListWidgetItem *ui;
     QMenu *menu;
    int m_nRow;
    AgentInfoTmp m_agentInfo;
    AgentManWidget* parentPtr;
};

#endif // AGENT_MAN_CUSTOM_LISTWIDGET_ITEM_H
