/********************************************************************************
** Form generated from reading UI file 'homewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWIDGET_H
#define UI_HOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWidget
{
public:
    QLabel *imageLabel;
    QLabel *welcomeLabel;
    QFrame *separatorLine;
    QFrame *runningRectangle;
    QLabel *runningImageLabel;
    QLabel *serverStatusLabel;
    QLabel *runningImageStatus;
    QLabel *runningTextLabel;
    QFrame *protectRectangle;
    QLabel *protectImageLabel;
    QLabel *protectionLabel;
    QLabel *protectCountLabel;
    QFrame *clientRectangle;
    QLabel *clientImageLabel;
    QLabel *clientDesLabel;
    QLabel *clientCountLabel;
    QFrame *verRectangle;
    QLabel *verImageLabel;
    QLabel *verDesLabel;
    QLabel *verLabel;
    QPushButton *verButton;
    QWidget *logWidget;
    QLabel *logImageLabel;
    QPushButton *logDetailButton;

    void setupUi(QWidget *HomeWidget)
    {
        if (HomeWidget->objectName().isEmpty())
            HomeWidget->setObjectName(QString::fromUtf8("HomeWidget"));
        HomeWidget->resize(1152, 585);
        imageLabel = new QLabel(HomeWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(165, 60, 228, 228));
        welcomeLabel = new QLabel(HomeWidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(390, 150, 591, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(19);
        font.setBold(false);
        font.setWeight(50);
        welcomeLabel->setFont(font);
        welcomeLabel->setStyleSheet(QString::fromUtf8("margin-left: 20px; color: #333333;"));
        separatorLine = new QFrame(HomeWidget);
        separatorLine->setObjectName(QString::fromUtf8("separatorLine"));
        separatorLine->setGeometry(QRect(1, 340, 1149, 2));
        separatorLine->setStyleSheet(QString::fromUtf8("background-color: #C9D8E0;"));
        separatorLine->setFrameShape(QFrame::HLine);
        separatorLine->setFrameShadow(QFrame::Sunken);
        separatorLine->setLineWidth(1);
        separatorLine->setMidLineWidth(0);
        runningRectangle = new QFrame(HomeWidget);
        runningRectangle->setObjectName(QString::fromUtf8("runningRectangle"));
        runningRectangle->setGeometry(QRect(43, 365, 197, 195));
        runningRectangle->setStyleSheet(QString::fromUtf8("background-color: #F6F6FB;border-radius: 4px;"));
        runningRectangle->setFrameShape(QFrame::Box);
        runningRectangle->setFrameShadow(QFrame::Plain);
        runningRectangle->setLineWidth(0);
        runningRectangle->setMidLineWidth(0);
        runningImageLabel = new QLabel(runningRectangle);
        runningImageLabel->setObjectName(QString::fromUtf8("runningImageLabel"));
        runningImageLabel->setGeometry(QRect(78, 34, 41, 57));
        serverStatusLabel = new QLabel(runningRectangle);
        serverStatusLabel->setObjectName(QString::fromUtf8("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(56, 100, 111, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        serverStatusLabel->setFont(font1);
        serverStatusLabel->setStyleSheet(QString::fromUtf8("color: #66757D;"));
        runningImageStatus = new QLabel(runningRectangle);
        runningImageStatus->setObjectName(QString::fromUtf8("runningImageStatus"));
        runningImageStatus->setGeometry(QRect(60, 139, 21, 21));
        runningTextLabel = new QLabel(runningRectangle);
        runningTextLabel->setObjectName(QString::fromUtf8("runningTextLabel"));
        runningTextLabel->setGeometry(QRect(80, 139, 81, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(10);
        runningTextLabel->setFont(font2);
        runningTextLabel->setStyleSheet(QString::fromUtf8("color: #649B17;"));
        protectRectangle = new QFrame(HomeWidget);
        protectRectangle->setObjectName(QString::fromUtf8("protectRectangle"));
        protectRectangle->setGeometry(QRect(259, 365, 197, 195));
        protectRectangle->setStyleSheet(QString::fromUtf8("background-color: #F6F6FB;border-radius: 4px;"));
        protectRectangle->setFrameShape(QFrame::Box);
        protectRectangle->setFrameShadow(QFrame::Plain);
        protectRectangle->setLineWidth(0);
        protectRectangle->setMidLineWidth(0);
        protectImageLabel = new QLabel(protectRectangle);
        protectImageLabel->setObjectName(QString::fromUtf8("protectImageLabel"));
        protectImageLabel->setGeometry(QRect(76, 34, 47, 57));
        protectionLabel = new QLabel(protectRectangle);
        protectionLabel->setObjectName(QString::fromUtf8("protectionLabel"));
        protectionLabel->setGeometry(QRect(56, 100, 121, 21));
        protectionLabel->setFont(font1);
        protectionLabel->setStyleSheet(QString::fromUtf8("color: #66757D;"));
        protectCountLabel = new QLabel(protectRectangle);
        protectCountLabel->setObjectName(QString::fromUtf8("protectCountLabel"));
        protectCountLabel->setGeometry(QRect(80, 139, 91, 21));
        protectCountLabel->setFont(font2);
        protectCountLabel->setStyleSheet(QString::fromUtf8("color: #000000;"));
        clientRectangle = new QFrame(HomeWidget);
        clientRectangle->setObjectName(QString::fromUtf8("clientRectangle"));
        clientRectangle->setGeometry(QRect(475, 365, 197, 195));
        clientRectangle->setStyleSheet(QString::fromUtf8("background-color: #F6F6FB;border-radius: 4px;"));
        clientImageLabel = new QLabel(clientRectangle);
        clientImageLabel->setObjectName(QString::fromUtf8("clientImageLabel"));
        clientImageLabel->setGeometry(QRect(69, 34, 60, 50));
        clientDesLabel = new QLabel(clientRectangle);
        clientDesLabel->setObjectName(QString::fromUtf8("clientDesLabel"));
        clientDesLabel->setGeometry(QRect(56, 100, 121, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        clientDesLabel->setFont(font3);
        clientDesLabel->setStyleSheet(QString::fromUtf8("color: #66757D;"));
        clientCountLabel = new QLabel(clientRectangle);
        clientCountLabel->setObjectName(QString::fromUtf8("clientCountLabel"));
        clientCountLabel->setGeometry(QRect(80, 139, 81, 21));
        clientCountLabel->setFont(font3);
        clientCountLabel->setStyleSheet(QString::fromUtf8("color: #000000;"));
        verRectangle = new QFrame(HomeWidget);
        verRectangle->setObjectName(QString::fromUtf8("verRectangle"));
        verRectangle->setGeometry(QRect(691, 365, 197, 195));
        verRectangle->setStyleSheet(QString::fromUtf8("background-color: #F6F6FB;border-radius: 4px;"));
        verImageLabel = new QLabel(verRectangle);
        verImageLabel->setObjectName(QString::fromUtf8("verImageLabel"));
        verImageLabel->setGeometry(QRect(73, 34, 56, 43));
        verDesLabel = new QLabel(verRectangle);
        verDesLabel->setObjectName(QString::fromUtf8("verDesLabel"));
        verDesLabel->setGeometry(QRect(56, 100, 121, 21));
        verDesLabel->setFont(font3);
        verDesLabel->setStyleSheet(QString::fromUtf8("color: #66757D;"));
        verLabel = new QLabel(verRectangle);
        verLabel->setObjectName(QString::fromUtf8("verLabel"));
        verLabel->setGeometry(QRect(60, 139, 81, 21));
        verLabel->setFont(font3);
        verLabel->setStyleSheet(QString::fromUtf8("color: #000000;"));
        verButton = new QPushButton(verRectangle);
        verButton->setObjectName(QString::fromUtf8("verButton"));
        verButton->setGeometry(QRect(130, 145, 16, 16));
        verButton->setStyleSheet(QString::fromUtf8(""));
        logWidget = new QWidget(HomeWidget);
        logWidget->setObjectName(QString::fromUtf8("logWidget"));
        logWidget->setGeometry(QRect(907, 365, 197, 195));
        logWidget->setStyleSheet(QString::fromUtf8("background-color: #F6F6FB;border-radius: 4px;"));
        logImageLabel = new QLabel(logWidget);
        logImageLabel->setObjectName(QString::fromUtf8("logImageLabel"));
        logImageLabel->setGeometry(QRect(73, 34, 64, 47));
        logDetailButton = new QPushButton(logWidget);
        logDetailButton->setObjectName(QString::fromUtf8("logDetailButton"));
        logDetailButton->setGeometry(QRect(50, 110, 101, 31));
        logDetailButton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(HomeWidget);

        QMetaObject::connectSlotsByName(HomeWidget);
    } // setupUi

    void retranslateUi(QWidget *HomeWidget)
    {
        imageLabel->setText(QString());
        welcomeLabel->setText(QApplication::translate("HomeWidget", "\346\254\242\350\277\216\344\275\277\347\224\250\345\256\211\345\205\250\350\261\271\344\270\273\345\212\250\351\230\262\345\276\241\347\263\273\347\273\237", nullptr));
        runningImageLabel->setText(QString());
        serverStatusLabel->setText(QApplication::translate("HomeWidget", "\346\234\215\345\212\241\347\253\257\347\212\266\346\200\201", nullptr));
        runningTextLabel->setText(QApplication::translate("HomeWidget", "\350\277\220\350\241\214\344\270\255", nullptr));
        protectImageLabel->setText(QString());
        protectionLabel->setText(QApplication::translate("HomeWidget", "\345\256\242\346\210\267\346\234\272\344\277\235\346\212\244", nullptr));
        protectCountLabel->setText(QApplication::translate("HomeWidget", "23\346\254\241", nullptr));
        clientImageLabel->setText(QString());
        clientDesLabel->setText(QApplication::translate("HomeWidget", "\345\256\242\346\210\267\346\234\272\344\277\235\346\212\244", nullptr));
        clientCountLabel->setText(QApplication::translate("HomeWidget", "50\345\217\260", nullptr));
        verImageLabel->setText(QString());
        verDesLabel->setText(QApplication::translate("HomeWidget", "\345\256\242\346\210\267\346\234\272\347\211\210\346\234\254", nullptr));
        verLabel->setText(QApplication::translate("HomeWidget", "23.11.09", nullptr));
        logImageLabel->setText(QString());
        logDetailButton->setText(QApplication::translate("HomeWidget", "\346\237\245\347\234\213\346\227\245\345\277\227", nullptr));
        Q_UNUSED(HomeWidget);
    } // retranslateUi

};

namespace Ui {
    class HomeWidget: public Ui_HomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWIDGET_H
