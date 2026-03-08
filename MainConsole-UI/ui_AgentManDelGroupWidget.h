/********************************************************************************
** Form generated from reading UI file 'AgentManDelGroupWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTMANDELGROUPWIDGET_H
#define UI_AGENTMANDELGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentManDelGroupWidget
{
public:
    QFrame *titleFrame;
    QPushButton *closeBtn;
    QLabel *labelCaption;
    QPushButton *pushCancleButton;
    QLabel *labelText;
    QPushButton *pushComfirmButton;

    void setupUi(QWidget *AgentManDelGroupWidget)
    {
        if (AgentManDelGroupWidget->objectName().isEmpty())
            AgentManDelGroupWidget->setObjectName(QString::fromUtf8("AgentManDelGroupWidget"));
        AgentManDelGroupWidget->resize(400, 200);
        AgentManDelGroupWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(AgentManDelGroupWidget);
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
        labelCaption = new QLabel(titleFrame);
        labelCaption->setObjectName(QString::fromUtf8("labelCaption"));
        labelCaption->setGeometry(QRect(10, 0, 91, 31));
        labelCaption->setStyleSheet(QString::fromUtf8("color:white;"));
        pushCancleButton = new QPushButton(AgentManDelGroupWidget);
        pushCancleButton->setObjectName(QString::fromUtf8("pushCancleButton"));
        pushCancleButton->setGeometry(QRect(230, 150, 110, 35));
        pushCancleButton->setStyleSheet(QString::fromUtf8(""));
        labelText = new QLabel(AgentManDelGroupWidget);
        labelText->setObjectName(QString::fromUtf8("labelText"));
        labelText->setGeometry(QRect(30, 80, 301, 31));
        labelText->setLayoutDirection(Qt::LeftToRight);
        pushComfirmButton = new QPushButton(AgentManDelGroupWidget);
        pushComfirmButton->setObjectName(QString::fromUtf8("pushComfirmButton"));
        pushComfirmButton->setGeometry(QRect(70, 150, 110, 35));
        pushComfirmButton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(AgentManDelGroupWidget);

        QMetaObject::connectSlotsByName(AgentManDelGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *AgentManDelGroupWidget)
    {
        AgentManDelGroupWidget->setWindowTitle(QApplication::translate("AgentManDelGroupWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("AgentManDelGroupWidget", "X", nullptr));
        labelCaption->setText(QApplication::translate("AgentManDelGroupWidget", "\350\255\246\345\221\212", nullptr));
        pushCancleButton->setText(QApplication::translate("AgentManDelGroupWidget", "\345\217\226\346\266\210", nullptr));
        labelText->setText(QApplication::translate("AgentManDelGroupWidget", "\346\226\260\345\242\236\345\210\206\347\273\204\345\220\215\347\247\260:", nullptr));
        pushComfirmButton->setText(QApplication::translate("AgentManDelGroupWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentManDelGroupWidget: public Ui_AgentManDelGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTMANDELGROUPWIDGET_H
