#ifndef PROCESSRULEDETAILWIDGET_H
#define PROCESSRULEDETAILWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "..\CustomRuleUtility.h"
#include "../Controller/RuleManController.h"
#include "../customrulewidget.h"
#include "../rule_center/CustomRuleCenterWidget.h"

namespace Ui {
class ProcessRuleDetailWidget;
}



class ProcessRuleDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessRuleDetailWidget(QWidget *parent = nullptr);
    explicit ProcessRuleDetailWidget(QWidget *parent = nullptr, RuleViewModel model = RuleViewModel::DisplayModel);
    ~ProcessRuleDetailWidget();

	int RefreshList();
	int RefreshListByGourpID(int agentGroupID);

	void setCustomRuleWidgetPtr(void* parent);
	long getCurrentRuleID();

private slots:
	void onItemChanged(QTableWidgetItem *item);

protected:
	void contextMenuEvent(QContextMenuEvent *event) override;
private:
	bool ClearTable(QTableWidget* tableWidget);
	int LoadRuleList();

    Ui::ProcessRuleDetailWidget *ui;
    int initData();
    int innerType;

private:
	long nCurrentRuleID;
    RuleViewModel ruleViewModel;
	void* parentPtr;
	long nCurrentGroupID; //当前选择的分组。
};

#endif // PROCESSRULEDETAILWIDGET_H


/*
ParentProcessInfoType 的取值 :
typedef enum _MATCH_TYPE
{
	MatchName,
	MatchPath,
	MatchCmd,
	MatchFileHeaderMd5 = 3,
	MatchFirstSectionMd5 = 4,
	MatchCompany,
	MatchVersion,
	MatchSignature,
	MatchProductName,
	MatchFileDescription,
	MatchSignatureSerialNumber = 10,
	MatchDomain = 10,
	MatchFileMd5,
	MatchOriginalFileName,
	MatchFileVersion,
	MatchMaximum
} MATCH_TYPE, *PMATCH_TYPE;

0:	进程名字匹配
1 : 进程路径匹配
2 : 进程命令行匹配
3 : 进程程序文件头MD5值匹配
4 : 进程程序第一段MD5值匹配
5 : 程序的公司名匹配
6 : 程序的版本匹配
7 : 程序的签名匹配
8 : 程序的产品名匹配
9 : 程序的文件描述匹配
10 : 程序的签名序列号匹配
11 : 程序的原始文件名匹配
12 : 程序的文件版本号匹配

OperationCode 是匹配到规则后采取的操作的类型，对于进程创建规则，它可有的取值是

0 : ActionDeny				拒绝进程创建

1 : ActionAllow				允许进程创建
2 : TerminateCreatedProcess	退出进程
3 : SuspendCreatedProcess		挂起进程
4 : TerminateParentProcess	终止父进程
5 : SuspendParentProcess		挂起父进程
6 : TerminateParentThread		终止父线程
7 : SuspendParentThread		挂起父线程

prority 这个应该是加入三个队列，prority为 - 1或大于100时 加入白名单或黑名单队列，其他 取值加入 以优先级排序的数组的队列中。
*/