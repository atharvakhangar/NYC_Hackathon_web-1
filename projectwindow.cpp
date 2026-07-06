#include "projectwindow.h"
#include "dashboardwindow.h"

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

    QLabel *projectCode = new QLabel("Code : PJ-4827");

    headerLayout->addWidget(projectName);
    headerLayout->addStretch();
    headerLayout->addWidget(projectCode);

    mainLayout->addWidget(header);

    QHBoxLayout *bodyLayout = new QHBoxLayout;

    mainLayout->addLayout(bodyLayout);

    QFrame *sidebar = new QFrame;

    sidebar->setFixedWidth(230);

    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);

    sidebarLayout->setContentsMargins(15,15,15,15);

    sidebarLayout->setSpacing(12);

    QLabel *title = new QLabel("Project Setup");

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

        sidebarLayout->addWidget(button);
    }

    sidebarLayout->addStretch();

    bodyLayout->addWidget(sidebar);
    QStackedWidget *content = new QStackedWidget;

    QWidget *pageProjectName = new QWidget;

    QVBoxLayout *contentLayout = new QVBoxLayout(pageProjectName);

    contentLayout->setContentsMargins(30,30,30,30);

    QLabel *pageTitle = new QLabel("Project Name");

    contentLayout->addWidget(pageTitle);

    contentLayout->addSpacing(20);

    QLabel *nameLabel = new QLabel("Project Name");

    QLineEdit *projectNameInput = new QLineEdit;

    projectNameInput->setPlaceholderText("Enter project name");

    projectNameInput->setMinimumHeight(40);

    contentLayout->addWidget(nameLabel);

    contentLayout->addWidget(projectNameInput);

    contentLayout->addSpacing(25);

    QLabel *descriptionLabel = new QLabel("Project Description (Optional)");

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

    workflowLayout->addWidget(workflowTitle);

    workflowLayout->addSpacing(20);

    QLabel *workflowInfo = new QLabel(
        "Select the phases you want in your project."
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

    deadlineLayout->addWidget(deadlineTitle);

    deadlineLayout->addSpacing(20);

    QLabel *deadlineLabel = new QLabel("Submission Deadline");

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

    codeLayout->addWidget(codeTitle);

    codeLayout->addSpacing(20);

    QLabel *codeInfo = new QLabel(
        "Share this code with teammates so they can join your project."
        );

    codeLayout->addWidget(codeInfo);

    codeLayout->addSpacing(20);

    QLabel *projectCodeLabel = new QLabel("PJ-4827");

    projectCodeLabel->setAlignment(Qt::AlignCenter);

    projectCodeLabel->setMinimumHeight(70);

    codeLayout->addWidget(projectCodeLabel);

    QPushButton *copyButton = new QPushButton("Copy Code");

    copyButton->setMinimumHeight(40);

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

    overviewLayout->addWidget(overviewTitle);

    overviewLayout->addSpacing(20);

    QLabel *summaryTitle = new QLabel("Project Summary");

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

    overviewLayout->addWidget(summary);

    overviewLayout->addStretch();

    QHBoxLayout *overviewNavigation = new QHBoxLayout;

    QPushButton *overviewBack = new QPushButton("← Back");

    QPushButton *finishButton = new QPushButton("Create Project");

    overviewBack->setMinimumHeight(40);
    finishButton->setMinimumHeight(40);

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
                DashboardWindow *dashboard = new DashboardWindow;

                dashboard->show();

                this->close();
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
}

ProjectWindow::~ProjectWindow()
{
}