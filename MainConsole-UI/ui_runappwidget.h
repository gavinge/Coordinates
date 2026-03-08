/********************************************************************************
** Form generated from reading UI file 'runappwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNAPPWIDGET_H
#define UI_RUNAPPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunAppWidget
{
public:
    QListWidget *groupListWidget;
    QFrame *groupTitleFrame;
    QLabel *label;
    QLabel *label_2;
    QFrame *toolbarFrame;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;

    void setupUi(QWidget *RunAppWidget)
    {
        if (RunAppWidget->objectName().isEmpty())
            RunAppWidget->setObjectName(QString::fromUtf8("RunAppWidget"));
        RunAppWidget->resize(1168, 585);
        groupListWidget = new QListWidget(RunAppWidget);
        groupListWidget->setObjectName(QString::fromUtf8("groupListWidget"));
        groupListWidget->setGeometry(QRect(0, 49, 170, 536));
        groupListWidget->setStyleSheet(QString::fromUtf8(""));
        groupTitleFrame = new QFrame(RunAppWidget);
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
        toolbarFrame = new QFrame(RunAppWidget);
        toolbarFrame->setObjectName(QString::fromUtf8("toolbarFrame"));
        toolbarFrame->setGeometry(QRect(180, 12, 961, 37));
        toolbarFrame->setFrameShape(QFrame::StyledPanel);
        toolbarFrame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(toolbarFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 112, 37));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_4 = new QPushButton(toolbarFrame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(850, 0, 112, 37));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        tableWidget = new QTableWidget(RunAppWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(180, 60, 965, 521));

        retranslateUi(RunAppWidget);

        QMetaObject::connectSlotsByName(RunAppWidget);
    } // setupUi

    void retranslateUi(QWidget *RunAppWidget)
    {
        RunAppWidget->setWindowTitle(QApplication::translate("RunAppWidget", "Form", nullptr));
        label->setText(QApplication::translate("RunAppWidget", "\346\234\272\345\231\250\345\210\206\347\273\204\347\256\241\347\220\206", nullptr));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("RunAppWidget", "\344\270\200\351\224\256\347\246\201\347\224\250", nullptr));
        pushButton_4->setText(QApplication::translate("RunAppWidget", "\344\273\273\345\212\241\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RunAppWidget: public Ui_RunAppWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNAPPWIDGET_H
