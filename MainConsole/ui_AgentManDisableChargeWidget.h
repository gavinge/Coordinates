/********************************************************************************
** Form generated from reading UI file 'AgentManDisableChargeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTMANDISABLECHARGEWIDGET_H
#define UI_AGENTMANDISABLECHARGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentManDisableChargeWidget
{
public:
    QFrame *titleFrame;
    QPushButton *closeBtn;
    QLabel *label;
    QPushButton *pushComfirmButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *labelDes;
    QCheckBox *checkBox;
    QLabel *labelErr;

    void setupUi(QWidget *AgentManDisableChargeWidget)
    {
        if (AgentManDisableChargeWidget->objectName().isEmpty())
            AgentManDisableChargeWidget->setObjectName(QString::fromUtf8("AgentManDisableChargeWidget"));
        AgentManDisableChargeWidget->resize(400, 200);
        AgentManDisableChargeWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(AgentManDisableChargeWidget);
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
        pushComfirmButton = new QPushButton(AgentManDisableChargeWidget);
        pushComfirmButton->setObjectName(QString::fromUtf8("pushComfirmButton"));
        pushComfirmButton->setGeometry(QRect(280, 150, 110, 35));
        pushComfirmButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(AgentManDisableChargeWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 100, 91, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit = new QLineEdit(AgentManDisableChargeWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 100, 111, 27));
        labelDes = new QLabel(AgentManDisableChargeWidget);
        labelDes->setObjectName(QString::fromUtf8("labelDes"));
        labelDes->setGeometry(QRect(260, 100, 101, 31));
        labelDes->setLayoutDirection(Qt::LeftToRight);
        labelDes->setStyleSheet(QString::fromUtf8(""));
        checkBox = new QCheckBox(AgentManDisableChargeWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 70, 111, 18));
        labelErr = new QLabel(AgentManDisableChargeWidget);
        labelErr->setObjectName(QString::fromUtf8("labelErr"));
        labelErr->setGeometry(QRect(140, 130, 131, 31));
        labelErr->setLayoutDirection(Qt::LeftToRight);
        labelErr->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));

        retranslateUi(AgentManDisableChargeWidget);

        QMetaObject::connectSlotsByName(AgentManDisableChargeWidget);
    } // setupUi

    void retranslateUi(QWidget *AgentManDisableChargeWidget)
    {
        AgentManDisableChargeWidget->setWindowTitle(QApplication::translate("AgentManDisableChargeWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("AgentManDisableChargeWidget", "X", nullptr));
        label->setText(QApplication::translate("AgentManDisableChargeWidget", "\350\207\252\345\256\232\344\271\211\346\227\266\351\225\277", nullptr));
        pushComfirmButton->setText(QApplication::translate("AgentManDisableChargeWidget", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("AgentManDisableChargeWidget", "\347\246\201\347\224\250\346\227\266\351\225\277:", nullptr));
        labelDes->setText(QApplication::translate("AgentManDisableChargeWidget", "\345\210\206\351\222\237(1-180)", nullptr));
        checkBox->setText(QApplication::translate("AgentManDisableChargeWidget", "\344\270\200\347\233\264\347\246\201\347\224\250", nullptr));
        labelErr->setText(QApplication::translate("AgentManDisableChargeWidget", "\345\220\215\347\247\260\345\267\262\347\273\217\345\255\230\345\234\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentManDisableChargeWidget: public Ui_AgentManDisableChargeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTMANDISABLECHARGEWIDGET_H
