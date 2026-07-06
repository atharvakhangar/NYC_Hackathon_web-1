#include "dashboardwindow.h"
#include "mainwindow.h"

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>

#include <QVBoxLayout>
#include <QHBoxLayout>

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("TaskFlow");
    resize(1200,700);

    QWidget *central = new QWidget;
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(40,30,40,30);
    mainLayout->setSpacing(25);

    QLabel *title = new QLabel("TaskFlow");

    title->setStyleSheet(
        "font-size:30px;"
        "font-weight:bold;"
        );

    mainLayout->addWidget(title);

    QFrame *topCard = new QFrame;

    topCard->setStyleSheet(
        "QFrame{"
        "background:white;"
        "border:1px solid #dcdcdc;"
        "border-radius:12px;"
        "}"
        );

    QHBoxLayout *topLayout = new QHBoxLayout(topCard);

    QLabel *projectName = new QLabel("Hackathon Project");

    projectName->setStyleSheet(
        "font-size:22px;"
        "font-weight:bold;"
        );

    QProgressBar *progress = new QProgressBar;

    progress->setValue(45);
    progress->setFixedWidth(220);

    topLayout->addWidget(projectName);
    topLayout->addStretch();
    topLayout->addWidget(progress);

    mainLayout->addWidget(topCard);

    mainLayout->addStretch();

    QPushButton *newProject = new QPushButton("+ Add");

    connect(newProject, &QPushButton::clicked, this, [=]()
            {
                MainWindow *home = new MainWindow;

                home->show();
            });

    newProject->setMinimumSize(180,50);

    newProject->setStyleSheet(
        "QPushButton{"
        "background:#2563eb;"
        "color:white;"
        "font-size:18px;"
        "font-weight:bold;"
        "border:none;"
        "border-radius:10px;"
        "}"
        "QPushButton:hover{"
        "background:#1d4ed8;"
        "}"
        );

    mainLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addStretch();

    buttonLayout->addWidget(newProject);

    mainLayout->addLayout(buttonLayout);

    QFrame *bottomBar = new QFrame;

    bottomBar->setFixedHeight(55);

    bottomBar->setStyleSheet(
        "QFrame{"
        "border-top:1px solid #dcdcdc;"
        "}"
        );

    QHBoxLayout *bottomLayout = new QHBoxLayout(bottomBar);

    QPushButton *projects = new QPushButton("Projects");
    QPushButton *help = new QPushButton("Help");
    QPushButton *settings = new QPushButton("Settings");

    projects->setFlat(true);
    help->setFlat(true);
    settings->setFlat(true);

    bottomLayout->addStretch();
    bottomLayout->addWidget(projects);
    bottomLayout->addSpacing(40);
    bottomLayout->addWidget(help);
    bottomLayout->addSpacing(40);
    bottomLayout->addWidget(settings);
    bottomLayout->addStretch();

    mainLayout->addWidget(bottomBar);
}

DashboardWindow::~DashboardWindow()
{
}