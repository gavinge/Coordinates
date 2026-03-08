/********************************************************************************
** Form generated from reading UI file 'AgentManAddGroupWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTMANADDGROUPWIDGET_H
#define UI_AGENTMANADDGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentManAddGroupWidget
{
public:
    QFrame *titleFrame;
    QPushButton *closeBtn;
    QLabel *label;
    QPushButton *pushComfirmButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *labelErr;

    void setupUi(QWidget *AgentManAddGroupWidget)
    {
        if (AgentManAddGroupWidget->objectName().isEmpty())
            AgentManAddGroupWidget->setObjectName(QString::fromUtf8("AgentManAddGroupWidget"));
        AgentManAddGroupWidget->resize(400, 200);
        AgentManAddGroupWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(AgentManAddGroupWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 398, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        closeBtn = new QPushButton(titleFrame);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(358, 0, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        closeBtn->setFont(font);
        closeBtn->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        pushComfirmButton = new QPushButton(AgentManAddGroupWidget);
        pushComfirmButton->setObjectName(QString::fromUtf8("pushComfirmButton"));
        pushComfirmButton->setGeometry(QRect(280, 150, 110, 35));
        pushComfirmButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(AgentManAddGroupWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 115, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit = new QLineEdit(AgentManAddGroupWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 231, 27));
        labelErr = new QLabel(AgentManAddGroupWidget);
        labelErr->setObjectName(QString::fromUtf8("labelErr"));
        labelErr->setGeometry(QRect(130, 110, 231, 31));
        labelErr->setLayoutDirection(Qt::LeftToRight);
        labelErr->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(AgentManAddGroupWidget);

        QMetaObject::connectSlotsByName(AgentManAddGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *AgentManAddGroupWidget)
    {
        AgentManAddGroupWidget->setWindowTitle(QApplication::translate("AgentManAddGroupWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("AgentManAddGroupWidget", "X", nullptr));
        label->setText(QApplication::translate("AgentManAddGroupWidget", "\346\267\273\345\212\240\345\210\206\347\273\204", nullptr));
        pushComfirmButton->setText(QApplication::translate("AgentManAddGroupWidget", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("AgentManAddGroupWidget", "\346\226\260\345\242\236\345\210\206\347\273\204\345\220\215\347\247\260:", nullptr));
        labelErr->setText(QApplication::translate("AgentManAddGroupWidget", "\345\220\215\347\247\260\345\267\262\347\273\217\345\255\230\345\234\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentManAddGroupWidget: public Ui_AgentManAddGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTMANADDGROUPWIDGET_H
