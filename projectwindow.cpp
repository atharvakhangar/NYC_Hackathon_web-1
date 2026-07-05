#include "projectwindow.h"

#include <QList>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include "QTextEdit.h"
#include "qlineedit.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QStackedWidget>
#include <QListWidget>

ProjectWindow::ProjectWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Project Dashboard");
    resize(1200, 700);

    QWidget *central = new QWidget;
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QFrame *header = new QFrame;
    header->setFixedHeight(70);

    QHBoxLayout *headerLayout = new QHBoxLayout(header);

    QLabel *projectName = new QLabel("Hackathon Project");

    projectName->setStyleSheet(
        "font-size:24px;"
        "font-weight:bold;"
        );

    QLabel *projectCode = new QLabel("Code : PJ-4827");

    projectCode->setStyleSheet(
        "font-size:16px;"
        "color:gray;"
        );

    headerLayout->addWidget(projectName);
    headerLayout->addStretch();
    headerLayout->addWidget(projectCode);

    mainLayout->addWidget(header);

    QHBoxLayout *bodyLayout = new QHBoxLayout;

    mainLayout->addLayout(bodyLayout);

    QFrame *sidebar = new QFrame;

    sidebar->setFixedWidth(230);

    sidebar->setStyleSheet(
        "QFrame{"
        "background:#f4f4f4;"
        "border-right:1px solid #d0d0d0;"
        "}"
        );

    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);

    sidebarLayout->setContentsMargins(15,15,15,15);

    sidebarLayout->setSpacing(12);

    QLabel *title = new QLabel("Project Setup");

    title->setStyleSheet(
        "font-size:20px;"
        "font-weight:bold;"
        );

    sidebarLayout->addWidget(title);

    sidebarLayout->addSpacing(15);

    QPushButton *nameButton = new QPushButton("Project Name");
    QPushButton *eventButton = new QPushButton("Event Setup");
    QPushButton *deadlineButton = new QPushButton("Deadline");
    QPushButton *codeButton = new QPushButton("Project Code");
    QPushButton *overviewButton = new QPushButton("Overview");

    QList<QPushButton*> pages =
        {
            nameButton,
            eventButton,
            deadlineButton,
            codeButton,
            overviewButton
        };

    for(QPushButton *button : pages)
    {
        button->setMinimumHeight(45);

        button->setStyleSheet(
            "QPushButton{"
            "background:white;"
            "border:none;"
            "border-radius:8px;"
            "text-align:left;"
            "padding-left:15px;"
            "font-size:15px;"
            "}"
            "QPushButton:hover{"
            "background:#dbeafe;"
            "}"
            );

        sidebarLayout->addWidget(button);
    }

    sidebarLayout->addStretch();

    bodyLayout->addWidget(sidebar);
    QStackedWidget *content = new QStackedWidget;

    QWidget *pageProjectName = new QWidget;

    QVBoxLayout *contentLayout = new QVBoxLayout(pageProjectName);

    contentLayout->setContentsMargins(30,30,30,30);

    QLabel *pageTitle = new QLabel("Project Name");

    pageTitle->setStyleSheet(
        "font-size:28px;"
        "font-weight:bold;"
        );

    contentLayout->addWidget(pageTitle);

    contentLayout->addSpacing(20);

    QLabel *nameLabel = new QLabel("Project Name");

    nameLabel->setStyleSheet(
        "font-size:15px;"
        );

    QLineEdit *projectNameInput = new QLineEdit;

    projectNameInput->setPlaceholderText("Enter project name");

    projectNameInput->setMinimumHeight(40);

    contentLayout->addWidget(nameLabel);

    contentLayout->addWidget(projectNameInput);

    contentLayout->addSpacing(25);

    QLabel *descriptionLabel = new QLabel("Project Description (Optional)");

    descriptionLabel->setStyleSheet(
        "font-size:15px;"
        );

    QTextEdit *descriptionInput = new QTextEdit;

    descriptionInput->setPlaceholderText(
        "Describe your project..."
        );

    descriptionInput->setMinimumHeight(180);

    contentLayout->addWidget(descriptionLabel);

    contentLayout->addWidget(descriptionInput);

    contentLayout->addStretch();

    QHBoxLayout *navigationLayout = new QHBoxLayout;

    QPushButton *backButton = new QPushButton("← Back");

    backButton->setMinimumHeight(40);

    backButton->setMinimumWidth(120);

    QPushButton *nextButton = new QPushButton("countinue →");

    nextButton->setMinimumHeight(40);

    nextButton->setMinimumWidth(120);

    navigationLayout->addWidget(backButton);

    navigationLayout->addStretch();

    navigationLayout->addWidget(nextButton);

    contentLayout->addLayout(navigationLayout);

    content->addWidget(pageProjectName);

    QWidget *pageWorkflow = new QWidget;

    QVBoxLayout *workflowLayout = new QVBoxLayout(pageWorkflow);

    workflowLayout->setContentsMargins(30,30,30,30);

    QLabel *workflowTitle = new QLabel("Workflow");

    workflowTitle->setStyleSheet(
        "font-size:28px;"
        "font-weight:bold;"
        );

    workflowLayout->addWidget(workflowTitle);

    workflowLayout->addSpacing(20);

    QLabel *workflowInfo = new QLabel(
        "Select the phases you want in your project."
        );

    workflowInfo->setStyleSheet(
        "font-size:15px;"
        "color:gray;"
        );

    workflowLayout->addWidget(workflowInfo);

    QCheckBox *selectionBox = new QCheckBox("Selection Phase");
    QCheckBox *votingBox = new QCheckBox("Voting Phase");
    QCheckBox *progressBox = new QCheckBox("Progress Update");
    QCheckBox *reviewBox = new QCheckBox("Review Phase");
    QCheckBox *todoBox = new QCheckBox("To-Do Tracker");

    selectionBox->setMinimumHeight(35);
    votingBox->setMinimumHeight(35);
    progressBox->setMinimumHeight(35);
    reviewBox->setMinimumHeight(35);
    todoBox->setMinimumHeight(35);

    workflowLayout->addWidget(selectionBox);
    workflowLayout->addWidget(votingBox);
    workflowLayout->addWidget(progressBox);
    workflowLayout->addWidget(reviewBox);
    workflowLayout->addWidget(todoBox);

    workflowLayout->addStretch();

    QHBoxLayout *workflowNavigation = new QHBoxLayout;

    QPushButton *workflowBack = new QPushButton("← Back");
    QPushButton *workflowContinue = new QPushButton("Continue →");

    workflowBack->setMinimumHeight(40);
    workflowContinue->setMinimumHeight(40);

    workflowNavigation->addWidget(workflowBack);
    workflowNavigation->addStretch();
    workflowNavigation->addWidget(workflowContinue);

    workflowLayout->addLayout(workflowNavigation);

    content->addWidget(pageWorkflow);

    bodyLayout->addWidget(content);
    connect(nextButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(1);
            });

    connect(workflowBack, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(0);
            });

    backButton->setStyleSheet(
        "QPushButton{"
        "background:white;"
        "border:1px solid lightgray;"
        "border-radius:8px;"
        "font-size:15px;"
        "padding:8px;"
        "}"
        "QPushButton:hover{"
        "background:#eeeeee;"
        "}"
        );

    nextButton->setStyleSheet(
        "QPushButton{"
        "background:#2563eb;"
        "color:white;"
        "border:none;"
        "border-radius:8px;"
        "font-size:15px;"
        "padding:8px;"
        "}"
        "QPushButton:hover{"
        "background:#1d4ed8;"
        "}"
        );
}

ProjectWindow::~ProjectWindow()
{
}