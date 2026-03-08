#include "widget.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

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

    QApplication a(argc, argv);

    qInstallMessageHandler(globalMessageHandler);
    qInfo() << "This is an informational message.";

    //设置皮肤
    QFile styleSheet(":/res/qss/style.qss");
    if (!styleSheet.open(QIODevice::ReadOnly)) {
        qWarning("Can't open the style sheet file.");
        return NULL;
    }
    qApp->setStyleSheet(styleSheet.readAll());
    styleSheet.close();

    Widget w;
    w.show();
    return a.exec();
}

