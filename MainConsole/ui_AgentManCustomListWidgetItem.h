/********************************************************************************
** Form generated from reading UI file 'AgentManCustomListWidgetItem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTMANCUSTOMLISTWIDGETITEM_H
#define UI_AGENTMANCUSTOMLISTWIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentManCustomListWidgetItem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *machineCheckBox;
    QLabel *statusLabel;
    QLabel *ipLabel;
    QLabel *macLabel;
    QLabel *groupLabel;
    QRadioButton *superDiskRadioButton;
    QSpacerItem *horizontalSpacer1;
    QRadioButton *debugRadioButton;
    QSpacerItem *horizontalSpacer2;
    QRadioButton *disableRuleRadioButton;
    QSpacerItem *horizontalSpacer3;
    QRadioButton *disableJiFeiRadioButton;
    QSpacerItem *horizontalSpacer4;
    QRadioButton *disGameMenuRadioButton;
    QSpacerItem *horizontalSpacer5;

    void setupUi(QWidget *AgentManCustomListWidgetItem)
    {
        if (AgentManCustomListWidgetItem->objectName().isEmpty())
            AgentManCustomListWidgetItem->setObjectName(QString::fromUtf8("AgentManCustomListWidgetItem"));
        AgentManCustomListWidgetItem->resize(908, 38);
        AgentManCustomListWidgetItem->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(AgentManCustomListWidgetItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 10, 951, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        machineCheckBox = new QCheckBox(layoutWidget);
        machineCheckBox->setObjectName(QString::fromUtf8("machineCheckBox"));
        machineCheckBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(machineCheckBox->sizePolicy().hasHeightForWidth());
        machineCheckBox->setSizePolicy(sizePolicy);
        machineCheckBox->setMinimumSize(QSize(160, 0));
        machineCheckBox->setMaximumSize(QSize(160, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(8);
        machineCheckBox->setFont(font);
        machineCheckBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(machineCheckBox);

        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(20, 0));
        statusLabel->setMaximumSize(QSize(20, 16777215));
        statusLabel->setScaledContents(true);

        horizontalLayout->addWidget(statusLabel);

        ipLabel = new QLabel(layoutWidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ipLabel->sizePolicy().hasHeightForWidth());
        ipLabel->setSizePolicy(sizePolicy1);
        ipLabel->setMinimumSize(QSize(120, 0));
        ipLabel->setMaximumSize(QSize(120, 16777215));
        ipLabel->setFont(font);
        ipLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ipLabel);

        macLabel = new QLabel(layoutWidget);
        macLabel->setObjectName(QString::fromUtf8("macLabel"));
        sizePolicy1.setHeightForWidth(macLabel->sizePolicy().hasHeightForWidth());
        macLabel->setSizePolicy(sizePolicy1);
        macLabel->setMinimumSize(QSize(150, 0));
        macLabel->setMaximumSize(QSize(150, 16777215));
        macLabel->setFont(font);
        macLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(macLabel);

        groupLabel = new QLabel(layoutWidget);
        groupLabel->setObjectName(QString::fromUtf8("groupLabel"));
        sizePolicy1.setHeightForWidth(groupLabel->sizePolicy().hasHeightForWidth());
        groupLabel->setSizePolicy(sizePolicy1);
        groupLabel->setMinimumSize(QSize(120, 0));
        groupLabel->setMaximumSize(QSize(120, 16777215));
        groupLabel->setFont(font);
        groupLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(groupLabel);

        superDiskRadioButton = new QRadioButton(layoutWidget);
        superDiskRadioButton->setObjectName(QString::fromUtf8("superDiskRadioButton"));
        superDiskRadioButton->setMinimumSize(QSize(20, 20));
        superDiskRadioButton->setMaximumSize(QSize(20, 20));
        superDiskRadioButton->setAutoExclusive(false);

        horizontalLayout->addWidget(superDiskRadioButton);

        horizontalSpacer1 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer1);

        debugRadioButton = new QRadioButton(layoutWidget);
        debugRadioButton->setObjectName(QString::fromUtf8("debugRadioButton"));
        debugRadioButton->setMinimumSize(QSize(20, 20));
        debugRadioButton->setMaximumSize(QSize(20, 20));
        debugRadioButton->setAutoExclusive(false);

        horizontalLayout->addWidget(debugRadioButton);

        horizontalSpacer2 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer2);

        disableRuleRadioButton = new QRadioButton(layoutWidget);
        disableRuleRadioButton->setObjectName(QString::fromUtf8("disableRuleRadioButton"));
        disableRuleRadioButton->setMinimumSize(QSize(20, 20));
        disableRuleRadioButton->setMaximumSize(QSize(20, 20));
        disableRuleRadioButton->setAutoExclusive(false);

        horizontalLayout->addWidget(disableRuleRadioButton);

        horizontalSpacer3 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer3);

        disableJiFeiRadioButton = new QRadioButton(layoutWidget);
        disableJiFeiRadioButton->setObjectName(QString::fromUtf8("disableJiFeiRadioButton"));
        disableJiFeiRadioButton->setMinimumSize(QSize(20, 20));
        disableJiFeiRadioButton->setMaximumSize(QSize(20, 20));
        disableJiFeiRadioButton->setAutoExclusive(false);

        horizontalLayout->addWidget(disableJiFeiRadioButton);

        horizontalSpacer4 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer4);

        disGameMenuRadioButton = new QRadioButton(layoutWidget);
        disGameMenuRadioButton->setObjectName(QString::fromUtf8("disGameMenuRadioButton"));
        disGameMenuRadioButton->setMinimumSize(QSize(20, 20));
        disGameMenuRadioButton->setMaximumSize(QSize(20, 20));
        disGameMenuRadioButton->setAutoExclusive(false);

        horizontalLayout->addWidget(disGameMenuRadioButton);

        horizontalSpacer5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer5);


        retranslateUi(AgentManCustomListWidgetItem);

        QMetaObject::connectSlotsByName(AgentManCustomListWidgetItem);
    } // setupUi

    void retranslateUi(QWidget *AgentManCustomListWidgetItem)
    {
        AgentManCustomListWidgetItem->setWindowTitle(QString());
        machineCheckBox->setText(QApplication::translate("AgentManCustomListWidgetItem", "CheckBox", nullptr));
        ipLabel->setText(QApplication::translate("AgentManCustomListWidgetItem", "TextLabel", nullptr));
        macLabel->setText(QApplication::translate("AgentManCustomListWidgetItem", "TextLabel", nullptr));
        groupLabel->setText(QApplication::translate("AgentManCustomListWidgetItem", "TextLabel", nullptr));
        superDiskRadioButton->setText(QString());
        debugRadioButton->setText(QString());
        disableRuleRadioButton->setText(QString());
        disableJiFeiRadioButton->setText(QString());
        disGameMenuRadioButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AgentManCustomListWidgetItem: public Ui_AgentManCustomListWidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTMANCUSTOMLISTWIDGETITEM_H
