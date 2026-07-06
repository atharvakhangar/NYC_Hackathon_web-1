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

    mainLayout->addWidget(title);

    QFrame *topCard = new QFrame;

    QHBoxLayout *topLayout = new QHBoxLayout(topCard);

    QLabel *projectName = new QLabel("Hackathon Project");

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

    mainLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addStretch();

    buttonLayout->addWidget(newProject);

    mainLayout->addLayout(buttonLayout);

    QFrame *bottomBar = new QFrame;

    bottomBar->setFixedHeight(55);

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