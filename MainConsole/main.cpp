#include "MainWidget.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

#include "global/global_define.h"
#include "mod_ext/communication_server_ext.hpp"
#include <iostream>
void globalMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QFile file("global.log");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << qPrintable(qFormatLogMessage(type, context, msg)) << endl;
        if (type == QtFatalMsg)
            abort();
        file.close();
    }
}


int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
    //QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);

    QApplication app(argc, argv);
	//app.setQuitOnLastWindowClosed(true);
	//a.setQuitOnLastWindowClosed(true);
    //qInstallMessageHandler(globalMessageHandler);
    //qInfo() << "This is an informational message.";


	REGISTER_CUSTOM_LOGGER(global_path->GetCurrentExePath(), "info.log");

	LOGGER_INFO("beginning.............................");

    //设置皮肤
    QFile styleSheet(":/res/qss/style.qss");
    if (!styleSheet.open(QIODevice::ReadOnly)) {
        qWarning("Can't open the style sheet file.");
        return NULL;
    }
    app.setStyleSheet(styleSheet.readAll());
    styleSheet.close();

    Widget mainWidge;

	mainWidge.show();
    return app.exec();
}

