/********************************************************************************
** Form generated from reading UI file 'WindowRuleEditDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWRULEEDITDETAILWIDGET_H
#define UI_WINDOWRULEEDITDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowRuleEditDetailWidget
{
public:
    QFrame *titleFrame;
    QPushButton *closeBtn;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_4;
    QLabel *label_7;
    QComboBox *comboBox_5;
    QTextEdit *textEdit;
    QCheckBox *checkBox;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_10;

    void setupUi(QWidget *WindowRuleEditDetailWidget)
    {
        if (WindowRuleEditDetailWidget->objectName().isEmpty())
            WindowRuleEditDetailWidget->setObjectName(QString::fromUtf8("WindowRuleEditDetailWidget"));
        WindowRuleEditDetailWidget->resize(751, 338);
        WindowRuleEditDetailWidget->setStyleSheet(QString::fromUtf8(""));
        titleFrame = new QFrame(WindowRuleEditDetailWidget);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(1, 1, 751, 39));
        titleFrame->setStyleSheet(QString::fromUtf8(""));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        closeBtn = new QPushButton(titleFrame);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(710, 0, 40, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        closeBtn->setFont(font);
        closeBtn->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(titleFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton = new QPushButton(WindowRuleEditDetailWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(625, 290, 112, 37));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(WindowRuleEditDetailWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 47, 71, 31));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(WindowRuleEditDetailWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 77, 91, 31));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_4 = new QLabel(WindowRuleEditDetailWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 147, 91, 31));
        label_4->setLayoutDirection(Qt::LeftToRight);
        comboBox = new QComboBox(WindowRuleEditDetailWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 50, 105, 26));
        comboBox_3 = new QComboBox(WindowRuleEditDetailWidget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(110, 150, 105, 26));
        lineEdit = new QLineEdit(WindowRuleEditDetailWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 50, 511, 27));
        lineEdit_2 = new QLineEdit(WindowRuleEditDetailWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 80, 215, 27));
        label_5 = new QLabel(WindowRuleEditDetailWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(55, 177, 51, 31));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_6 = new QLabel(WindowRuleEditDetailWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(225, 150, 81, 31));
        comboBox_4 = new QComboBox(WindowRuleEditDetailWidget);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(305, 150, 110, 26));
        label_7 = new QLabel(WindowRuleEditDetailWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(435, 150, 81, 31));
        comboBox_5 = new QComboBox(WindowRuleEditDetailWidget);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(515, 150, 110, 26));
        textEdit = new QTextEdit(WindowRuleEditDetailWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(110, 180, 621, 85));
        checkBox = new QCheckBox(WindowRuleEditDetailWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(105, 290, 151, 24));
        label_8 = new QLabel(WindowRuleEditDetailWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(435, 80, 81, 31));
        lineEdit_3 = new QLineEdit(WindowRuleEditDetailWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(515, 80, 215, 27));
        label_9 = new QLabel(WindowRuleEditDetailWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(435, 113, 81, 31));
        lineEdit_4 = new QLineEdit(WindowRuleEditDetailWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(515, 113, 215, 27));
        lineEdit_5 = new QLineEdit(WindowRuleEditDetailWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 113, 215, 27));
        label_10 = new QLabel(WindowRuleEditDetailWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 110, 91, 31));
        label_10->setLayoutDirection(Qt::LeftToRight);

        retranslateUi(WindowRuleEditDetailWidget);

        QMetaObject::connectSlotsByName(WindowRuleEditDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *WindowRuleEditDetailWidget)
    {
        WindowRuleEditDetailWidget->setWindowTitle(QApplication::translate("WindowRuleEditDetailWidget", "Form", nullptr));
        closeBtn->setText(QApplication::translate("WindowRuleEditDetailWidget", "X", nullptr));
        label->setText(QApplication::translate("WindowRuleEditDetailWidget", "\347\252\227\345\217\243\350\247\204\345\210\231", nullptr));
        pushButton->setText(QApplication::translate("WindowRuleEditDetailWidget", "\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("WindowRuleEditDetailWidget", "\346\272\220\350\277\233\347\250\213", nullptr));
        label_3->setText(QApplication::translate("WindowRuleEditDetailWidget", "\347\252\227\345\217\243\346\240\207\351\242\230", nullptr));
        label_4->setText(QApplication::translate("WindowRuleEditDetailWidget", "\345\244\204\347\220\206\350\277\233\347\250\213", nullptr));
        label_5->setText(QApplication::translate("WindowRuleEditDetailWidget", "\345\244\207\346\263\250", nullptr));
        label_6->setText(QApplication::translate("WindowRuleEditDetailWidget", "\345\244\204\347\220\206\347\252\227\345\217\243", nullptr));
        label_7->setText(QApplication::translate("WindowRuleEditDetailWidget", "\344\274\230\345\205\210\347\272\247\345\210\253", nullptr));
        checkBox->setText(QApplication::translate("WindowRuleEditDetailWidget", "\344\270\212\346\212\245\346\227\245\345\277\227", nullptr));
        label_8->setText(QApplication::translate("WindowRuleEditDetailWidget", "\347\252\227\345\217\243\347\261\273\345\210\253", nullptr));
        label_9->setText(QApplication::translate("WindowRuleEditDetailWidget", "\347\252\227\345\217\243\345\256\275\345\272\246", nullptr));
        label_10->setText(QApplication::translate("WindowRuleEditDetailWidget", "\347\252\227\345\217\243\351\253\230\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowRuleEditDetailWidget: public Ui_WindowRuleEditDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWRULEEDITDETAILWIDGET_H
