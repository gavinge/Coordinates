/********************************************************************************
** Form generated from reading UI file 'agentmanwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTMANWIDGET_H
#define UI_AGENTMANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentManWidget
{
public:
    QListWidget *customListWidget;
    QListWidget *groupListWidget;
    QFrame *groupTitleFrame;
    QLabel *label;
    QLabel *label_2;
    QFrame *toolbarFrame;
    QPushButton *btnShutdown;
    QPushButton *btnReboot;
    QPushButton *btnResume;
    QPushButton *btnRemoteControl;
    QFrame *frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer1;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer6;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer8;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer9;
    QLabel *label_11;
    QFrame *SearchFrame;
    QLineEdit *researchLineEdit;
    QPushButton *researchPushButton;

    void setupUi(QWidget *AgentManWidget)
    {
        if (AgentManWidget->objectName().isEmpty())
            AgentManWidget->setObjectName(QString::fromUtf8("AgentManWidget"));
        AgentManWidget->resize(1150, 585);
        customListWidget = new QListWidget(AgentManWidget);
        customListWidget->setObjectName(QString::fromUtf8("customListWidget"));
        customListWidget->setGeometry(QRect(180, 100, 965, 481));
        customListWidget->setStyleSheet(QString::fromUtf8("border: none;"));
        groupListWidget = new QListWidget(AgentManWidget);
        groupListWidget->setObjectName(QString::fromUtf8("groupListWidget"));
        groupListWidget->setGeometry(QRect(0, 49, 170, 536));
        groupListWidget->setStyleSheet(QString::fromUtf8(""));
        groupTitleFrame = new QFrame(AgentManWidget);
        groupTitleFrame->setObjectName(QString::fromUtf8("groupTitleFrame"));
        groupTitleFrame->setGeometry(QRect(0, 12, 170, 37));
        groupTitleFrame->setStyleSheet(QString::fromUtf8("background-color: #66895D;"));
        groupTitleFrame->setFrameShape(QFrame::StyledPanel);
        groupTitleFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(groupTitleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(45, 9, 101, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(8);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        label_2 = new QLabel(groupTitleFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 19, 19));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/res/image/agentMan/group_icon.png")));
        toolbarFrame = new QFrame(AgentManWidget);
        toolbarFrame->setObjectName(QString::fromUtf8("toolbarFrame"));
        toolbarFrame->setGeometry(QRect(180, 12, 511, 37));
        toolbarFrame->setFrameShape(QFrame::StyledPanel);
        toolbarFrame->setFrameShadow(QFrame::Raised);
        btnShutdown = new QPushButton(toolbarFrame);
        btnShutdown->setObjectName(QString::fromUtf8("btnShutdown"));
        btnShutdown->setGeometry(QRect(0, 0, 112, 37));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        btnShutdown->setFont(font1);
        btnShutdown->setStyleSheet(QString::fromUtf8(""));
        btnReboot = new QPushButton(toolbarFrame);
        btnReboot->setObjectName(QString::fromUtf8("btnReboot"));
        btnReboot->setGeometry(QRect(124, 0, 112, 37));
        btnReboot->setFont(font1);
        btnReboot->setStyleSheet(QString::fromUtf8(""));
        btnResume = new QPushButton(toolbarFrame);
        btnResume->setObjectName(QString::fromUtf8("btnResume"));
        btnResume->setGeometry(QRect(248, 0, 112, 37));
        btnResume->setFont(font1);
        btnResume->setStyleSheet(QString::fromUtf8(""));
        btnRemoteControl = new QPushButton(toolbarFrame);
        btnRemoteControl->setObjectName(QString::fromUtf8("btnRemoteControl"));
        btnRemoteControl->setGeometry(QRect(372, 0, 112, 37));
        btnRemoteControl->setFont(font1);
        btnRemoteControl->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(AgentManWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(180, 60, 965, 40));
        frame->setStyleSheet(QString::fromUtf8("background-color: #F6FDED;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, 10, 951, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        checkBox->setFont(font2);

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer1 = new QSpacerItem(90, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout->addWidget(label_4);

        horizontalSpacer3 = new QSpacerItem(90, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        horizontalLayout->addWidget(label_5);

        horizontalSpacer4 = new QSpacerItem(100, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        horizontalSpacer5 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer5);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer6 = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer6);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        horizontalLayout->addWidget(label_8);

        horizontalSpacer7 = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer7);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        horizontalLayout->addWidget(label_9);

        horizontalSpacer8 = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer8);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        horizontalLayout->addWidget(label_10);

        horizontalSpacer9 = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer9);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        horizontalLayout->addWidget(label_11);

        SearchFrame = new QFrame(AgentManWidget);
        SearchFrame->setObjectName(QString::fromUtf8("SearchFrame"));
        SearchFrame->setGeometry(QRect(900, 12, 241, 37));
        SearchFrame->setStyleSheet(QString::fromUtf8("background-color: #EBF9FF;\n"
"border-radius: 18px;\n"
""));
        SearchFrame->setFrameShape(QFrame::StyledPanel);
        SearchFrame->setFrameShadow(QFrame::Raised);
        researchLineEdit = new QLineEdit(SearchFrame);
        researchLineEdit->setObjectName(QString::fromUtf8("researchLineEdit"));
        researchLineEdit->setGeometry(QRect(20, 5, 181, 27));
        researchPushButton = new QPushButton(SearchFrame);
        researchPushButton->setObjectName(QString::fromUtf8("researchPushButton"));
        researchPushButton->setGeometry(QRect(192, 10, 31, 20));

        retranslateUi(AgentManWidget);

        QMetaObject::connectSlotsByName(AgentManWidget);
    } // setupUi

    void retranslateUi(QWidget *AgentManWidget)
    {
        AgentManWidget->setWindowTitle(QApplication::translate("AgentManWidget", "Form", nullptr));
        label->setText(QApplication::translate("AgentManWidget", "\346\234\272\345\231\250\345\210\206\347\273\204\347\256\241\347\220\206", nullptr));
        label_2->setText(QString());
        btnShutdown->setText(QApplication::translate("AgentManWidget", "\345\205\263\351\227\255\346\234\272\345\231\250", nullptr));
        btnReboot->setText(QApplication::translate("AgentManWidget", "\351\207\215\345\220\257\346\234\272\345\231\250", nullptr));
        btnResume->setText(QApplication::translate("AgentManWidget", "\345\224\244\351\206\222\346\234\272\345\231\250", nullptr));
        btnRemoteControl->setText(QApplication::translate("AgentManWidget", "\350\277\234\347\250\213\346\216\247\345\210\266", nullptr));
        checkBox->setText(QApplication::translate("AgentManWidget", "\345\220\215\347\247\260", nullptr));
        label_3->setText(QApplication::translate("AgentManWidget", "\346\234\272\345\231\250\347\212\266\346\200\201", nullptr));
        label_4->setText(QApplication::translate("AgentManWidget", "IP\345\234\260\345\235\200", nullptr));
        label_5->setText(QApplication::translate("AgentManWidget", "MAC\345\234\260\345\235\200", nullptr));
        label_6->setText(QApplication::translate("AgentManWidget", "\346\211\200\345\261\236\345\210\206\347\273\204", nullptr));
        label_7->setText(QApplication::translate("AgentManWidget", "\346\227\240\347\233\230\350\266\205\347\272\247", nullptr));
        label_8->setText(QApplication::translate("AgentManWidget", "\350\260\203\350\257\225\346\250\241\345\274\217", nullptr));
        label_9->setText(QApplication::translate("AgentManWidget", "\347\246\201\350\247\204\345\210\231", nullptr));
        label_10->setText(QApplication::translate("AgentManWidget", "\347\246\201\350\256\241\350\264\271", nullptr));
        label_11->setText(QApplication::translate("AgentManWidget", "\347\246\201\346\270\270\346\210\217\350\217\234\345\215\225", nullptr));
        researchPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AgentManWidget: public Ui_AgentManWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTMANWIDGET_H
