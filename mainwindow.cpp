#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    username->setStyleSheet(
        "font-size:20px;"
        "font-weight:bold;"
        );

    projects->setStyleSheet(
        "font-size:13px;"
        "color:gray;"
        );
    username->setStyleSheet(
        "font-size:18px;"
        "font-weight:bold;"
        );

    projects->setStyleSheet(
        "font-size:12px;"
        "color:gray;"
        );

    leftLayout->addWidget(username);
    leftLayout->addWidget(projects);

    QLabel *credits = new QLabel("Creators & Credits");
    credits->setStyleSheet(
        "font-size:12px;"
        "background:white;"
        "border:2px solid gray;"
        "border-radius:8px;"
        );
    credits->setFrameStyle(QFrame::Box);
    credits->setMinimumHeight(45);
    credits->setMinimumWidth(250);
    credits->setAlignment(Qt::AlignCenter);

    QLabel *profile = new QLabel();
    profile->setFrameStyle(QFrame::Box);
    profile->setFixedSize(55,55);
    profile->setStyleSheet(
        "background:#d9d9d9;"
        "border:2px solid gray;"
        "border-radius:30px;"
        );

    profile->setAlignment(Qt::AlignCenter);
    profile->setAlignment(Qt::AlignCenter);

    topLayout->addLayout(leftLayout);
    topLayout->addStretch();
    topLayout->addWidget(credits);
    topLayout->addStretch();
    topLayout->addWidget(profile);

    QPushButton *createButton =
        new QPushButton("Create Your First Project");


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
    helpTitle->setStyleSheet(
        "font-size:20px;"
        "font-weight:bold;"
        );

    QTextEdit *helpBox = new QTextEdit();

    helpBox->setReadOnly(true);

    helpBox->setPlaceholderText(
        "Instructions will appear here..."
        );                 //here need to set instructions
    setStyleSheet(R"(

QMainWindow{
    background:#f5f5f5;
}

QLabel{
    font-size:15px;
}

QPushButton{

    background:white;

    border:2px solid #2c2c2c;

    border-radius:5px;

    padding:12px;

    font-size:15px;

    font-weight:bold;
}

QPushButton:hover{

    background:#dfefff;

}

QPushButton:pressed{

    background:#b8d7ff;

}

QTextEdit{

    border:2px solid gray;

    border-radius:8px;

    background:white;

    padding:10px;

}

)");

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