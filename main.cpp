#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

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