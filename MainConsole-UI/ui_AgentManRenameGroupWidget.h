/********************************************************************************
** Form generated from reading UI file 'AgentManRenameGroupWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTMANRENAMEGROUPWIDGET_H
#define UI_AGENTMANRENAMEGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentManRenameGroupWidget
{
public:
    QFrame *titleFrame;
    QPushButton *closeBtn;
    QLabel *label;
    QPushButton *pushComfirmButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *labelErr;

    void setupUi(QWidget *AgentManRenameGroupWidget)
    {
        if (AgentManRenameGroupWidget->objectName().isEmpty())
            AgentManRenameGroupWidget->setObjectName(QString::fromUtf8("AgentManRenameGroupWidget"));
        AgentManRenameGroupWidget->resize(400, 200);
        AgentManRenameGroupWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(AgentManRenameGroupWidget);
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
        pushComfirmButton = new QPushButton(AgentManRenameGroupWidget);
        pushComfirmButton->setObjectName(QString::fromUtf8("pushComfirmButton"));
        pushComfirmButton->setGeometry(QRect(280, 150, 110, 35));
        pushComfirmButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(AgentManRenameGroupWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 115, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit = new QLineEdit(AgentManRenameGroupWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 231, 27));
        labelErr = new QLabel(AgentManRenameGroupWidget);
        labelErr->setObjectName(QString::fromUtf8("labelErr"));
        labelErr->setGeometry(QRect(130, 110, 231, 31));
        labelErr->setLayoutDirection(Qt::LeftToRight);
        labelErr->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(AgentManRenameGroupWidget);

        QMetaObject::connectSlotsByName(AgentManRenameGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *AgentManRenameGroupWidget)
    {
        AgentManRenameGroupWidget->setWindowTitle(QApplication::translate("AgentManRenameGroupWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("AgentManRenameGroupWidget", "X", nullptr));
        label->setText(QApplication::translate("AgentManRenameGroupWidget", "\351\207\215\345\221\275\345\220\215\345\210\206\347\273\204", nullptr));
        pushComfirmButton->setText(QApplication::translate("AgentManRenameGroupWidget", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("AgentManRenameGroupWidget", "\345\210\206\347\273\204\346\226\260\345\220\215\347\247\260:", nullptr));
        labelErr->setText(QApplication::translate("AgentManRenameGroupWidget", "\345\220\215\347\247\260\345\267\262\347\273\217\345\255\230\345\234\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentManRenameGroupWidget: public Ui_AgentManRenameGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTMANRENAMEGROUPWIDGET_H
