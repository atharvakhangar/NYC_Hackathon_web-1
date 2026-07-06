#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleFile(":/style.qss");

    qDebug() << "Exists:" << styleFile.exists();

    if(styleFile.open(QFile::ReadOnly))
    {
        qDebug() << "Loaded";
        app.setStyleSheet(styleFile.readAll());
    }
    else
    {
        qDebug() << "Not Loaded";
    }
    app.setApplicationName("Sync Forge");
    app.setApplicationDisplayName("Sync Forge");

    QIcon icon(":/logo.png");

    qDebug() << "Icon loaded:" << !icon.isNull();

    app.setWindowIcon(icon);

    MainWindow w;

    w.setWindowTitle("Sync Forge");

    w.show();

    return app.exec();
}