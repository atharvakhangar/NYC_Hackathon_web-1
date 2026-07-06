#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projectwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QSpacerItem>
#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1100, 700);
    setMinimumSize(900, 600);
    setWindowTitle("Project Manager");

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(30, 20, 30, 20);
    mainLayout->setSpacing(20);

    QHBoxLayout *topLayout = new QHBoxLayout();

    QVBoxLayout *leftLayout = new QVBoxLayout();

    QLabel *username = new QLabel("Username");
    QLabel *projects = new QLabel("Projects : 0");

    leftLayout->addWidget(username);
    leftLayout->addWidget(projects);

    QLabel *credits = new QLabel("Creators & Credits");

    credits->setFrameStyle(QFrame::Box);
    credits->setMinimumHeight(45);
    credits->setMinimumWidth(250);
    credits->setAlignment(Qt::AlignCenter);

    QLabel *profile = new QLabel();
    profile->setFrameStyle(QFrame::Box);
    profile->setFixedSize(55,55);

    profile->setAlignment(Qt::AlignCenter);
    profile->setAlignment(Qt::AlignCenter);

    topLayout->addLayout(leftLayout);
    topLayout->addStretch();
    topLayout->addWidget(credits);
    topLayout->addStretch();
    topLayout->addWidget(profile);

    QPushButton *createButton = new QPushButton("Create Your First Project");

    connect(createButton, &QPushButton::clicked, this, [=]()
            {
                ProjectWindow *window = new ProjectWindow();
                window->show();

                this->hide();
            });


    QPushButton *joinButton =
        new QPushButton("Join Your First Project");

    createButton->setMinimumSize(350,60);
    joinButton->setMinimumSize(350,60);
    connect(joinButton, &QPushButton::clicked, this, [=]()
            {
        {
            QDialog dialog(this);

            dialog.setWindowTitle("Join Project");

            dialog.resize(400,250);

            QVBoxLayout *layout = new QVBoxLayout(&dialog);

            QLabel *title = new QLabel("Prototype");

            QLineEdit *code = new QLineEdit();

            code->setPlaceholderText("Enter Project Code");

            QPushButton *join = new QPushButton("Join");

            QLabel *info =
                new QLabel("This is a prototype.\nFeature coming soon.");

            info->setAlignment(Qt::AlignCenter);

            layout->addWidget(title);

            layout->addWidget(code);

            layout->addWidget(join);

            layout->addStretch();

            layout->addWidget(info);

            dialog.exec();
        }
            });


    QLabel *helpTitle = new QLabel("How to use");

    QTextEdit *helpBox = new QTextEdit();

    helpBox->setReadOnly(true);

    helpBox->setText(
        "Welcome to Sync Forge\n\n"
        "Getting started is simple.\n\n"
        "• Create a project with the Add button.\n"
        "• Enter your project details.\n"
        "• Save your work.\n"
        "• Track your progress from the dashboard.\n\n"
        "Or join your team's project using a Team Code.\n\n"
        "Build smarter. Stay in sync."
        );                 //here need to set instructions

    mainLayout->addLayout(topLayout);

    mainLayout->addSpacing(25);

    mainLayout->addWidget(createButton);

    mainLayout->addSpacing(10);

    mainLayout->addWidget(joinButton);

    mainLayout->addSpacing(30);

    mainLayout->addWidget(helpTitle);

    mainLayout->addWidget(helpBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}