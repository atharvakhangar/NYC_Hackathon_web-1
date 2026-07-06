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
#include <QDateEdit>
#include <QStackedWidget>
#include <QListWidget>
#include <QApplication>
#include <QClipboard>

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

    QWidget *pageDeadline = new QWidget;

    QVBoxLayout *deadlineLayout = new QVBoxLayout(pageDeadline);

    deadlineLayout->setContentsMargins(30,30,30,30);

    QLabel *deadlineTitle = new QLabel("Project Deadline");

    deadlineTitle->setStyleSheet(
        "font-size:28px;"
        "font-weight:bold;"
        );

    deadlineLayout->addWidget(deadlineTitle);

    deadlineLayout->addSpacing(20);

    QLabel *deadlineLabel = new QLabel("Submission Deadline");

    deadlineLabel->setStyleSheet(
        "font-size:15px;"
        );

    QDateEdit *deadlineInput = new QDateEdit;

    deadlineInput->setCalendarPopup(true);

    deadlineInput->setMinimumHeight(40);

    deadlineLayout->addWidget(deadlineLabel);

    deadlineLayout->addWidget(deadlineInput);

    deadlineLayout->addStretch();

    QHBoxLayout *deadlineNavigation = new QHBoxLayout;

    QPushButton *deadlineBack = new QPushButton("← Back");

    QPushButton *deadlineContinue = new QPushButton("Continue →");

    deadlineBack->setMinimumHeight(40);

    deadlineContinue->setMinimumHeight(40);

    deadlineNavigation->addWidget(deadlineBack);

    deadlineNavigation->addStretch();

    deadlineNavigation->addWidget(deadlineContinue);

    deadlineLayout->addLayout(deadlineNavigation);

    content->addWidget(pageDeadline);

    QWidget *pageCode = new QWidget;

    QVBoxLayout *codeLayout = new QVBoxLayout(pageCode);

    codeLayout->setContentsMargins(30,30,30,30);

    QLabel *codeTitle = new QLabel("Project Code");

    codeTitle->setStyleSheet(
        "font-size:28px;"
        "font-weight:bold;"
        );

    codeLayout->addWidget(codeTitle);

    codeLayout->addSpacing(20);

    QLabel *codeInfo = new QLabel(
        "Share this code with teammates so they can join your project."
        );

    codeInfo->setStyleSheet(
        "font-size:15px;"
        "color:gray;"
        );

    codeLayout->addWidget(codeInfo);

    codeLayout->addSpacing(20);

    QLabel *projectCodeLabel = new QLabel("PJ-4827");

    projectCodeLabel->setAlignment(Qt::AlignCenter);

    projectCodeLabel->setMinimumHeight(70);

    projectCodeLabel->setStyleSheet(
        "font-size:32px;"
        "font-weight:bold;"
        "border:2px solid #2563eb;"
        "border-radius:12px;"
        "background:white;"
        );

    codeLayout->addWidget(projectCodeLabel);

    QPushButton *copyButton = new QPushButton("Copy Code");

    copyButton->setMinimumHeight(40);

    copyButton->setStyleSheet(
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

    codeLayout->addSpacing(15);

    codeLayout->addWidget(copyButton, 0, Qt::AlignCenter);

    connect(copyButton, &QPushButton::clicked, this, [=]()
            {
                QApplication::clipboard()->setText(projectCodeLabel->text());
                copyButton->setText("Copied!");
            });

    codeLayout->addStretch();

    QHBoxLayout *codeNavigation = new QHBoxLayout;

    QPushButton *codeBack = new QPushButton("← Back");
    QPushButton *codeContinue = new QPushButton("Continue →");

    codeBack->setMinimumHeight(40);
    codeContinue->setMinimumHeight(40);

    codeNavigation->addWidget(codeBack);
    codeNavigation->addStretch();
    codeNavigation->addWidget(codeContinue);

    codeLayout->addLayout(codeNavigation);

    content->addWidget(pageCode);

    QWidget *pageOverview = new QWidget;

    QVBoxLayout *overviewLayout = new QVBoxLayout(pageOverview);

    overviewLayout->setContentsMargins(30,30,30,30);

    QLabel *overviewTitle = new QLabel("Overview");

    overviewTitle->setStyleSheet(
        "font-size:28px;"
        "font-weight:bold;"
        );

    overviewLayout->addWidget(overviewTitle);

    overviewLayout->addSpacing(20);

    QLabel *summaryTitle = new QLabel("Project Summary");

    summaryTitle->setStyleSheet(
        "font-size:18px;"
        "font-weight:bold;"
        );

    overviewLayout->addWidget(summaryTitle);

    overviewLayout->addSpacing(15);

    QLabel *summary = new QLabel(
        "Review your project before creating it.\n\n"
        "• Project Name\n"
        "• Selected Workflow\n"
        "• Deadline\n"
        "• Project Code\n\n"
        "Backend integration coming soon."
        );

    summary->setWordWrap(true);

    summary->setStyleSheet(
        "font-size:15px;"
        "border:1px solid lightgray;"
        "border-radius:10px;"
        "padding:15px;"
        "background:white;"
        );

    overviewLayout->addWidget(summary);

    overviewLayout->addStretch();

    QHBoxLayout *overviewNavigation = new QHBoxLayout;

    QPushButton *overviewBack = new QPushButton("← Back");

    QPushButton *finishButton = new QPushButton("Create Project");

    overviewBack->setMinimumHeight(40);
    finishButton->setMinimumHeight(40);

    finishButton->setStyleSheet(
        "QPushButton{"
        "background:#16a34a;"
        "color:white;"
        "border:none;"
        "border-radius:8px;"
        "font-size:15px;"
        "}"
        "QPushButton:hover{"
        "background:#15803d;"
        "}"
        );

    overviewNavigation->addWidget(overviewBack);

    overviewNavigation->addStretch();

    overviewNavigation->addWidget(finishButton);

    overviewLayout->addLayout(overviewNavigation);

    content->addWidget(pageOverview);

    connect(deadlineContinue, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(3);
            });

    connect(codeBack, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(2);
            });

    connect(workflowContinue, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(2);
            });

    connect(deadlineBack, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(1);
            });

    bodyLayout->addWidget(content);
    connect(nextButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(1);
            });

    connect(workflowBack, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(0);
            });

    connect(codeContinue, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(4);
            });

    connect(overviewBack, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(3);
            });

    connect(finishButton, &QPushButton::clicked, this, [=]()
            {
                finishButton->setText("Project Created");
            });

    connect(nameButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(0);
            });

    connect(eventButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(1);
            });

    connect(deadlineButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(2);
            });

    connect(codeButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(3);
            });

    connect(overviewButton, &QPushButton::clicked, this, [=]()
            {
                content->setCurrentIndex(4);
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