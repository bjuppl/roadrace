/********************************************************************************
** Form generated from reading UI file 'roadrace.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROADRACE_H
#define UI_ROADRACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoadRace
{
public:
    QAction *actionFrom_file;
    QWidget *centralWidget;
    QPushButton *btnStuff;
    QToolButton *btnOpenGame;
    QLineEdit *iptGameFileName;
    QLabel *player1;
    QLabel *name1;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_20;
    QWidget *gridLayoutWidget;
    QGridLayout *gameLayout;
    QLabel *wo1;
    QLabel *Sto1;
    QLabel *Go1;
    QLabel *Wa1;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RoadRace)
    {
        if (RoadRace->objectName().isEmpty())
            RoadRace->setObjectName(QStringLiteral("RoadRace"));
        RoadRace->resize(922, 709);
        actionFrom_file = new QAction(RoadRace);
        actionFrom_file->setObjectName(QStringLiteral("actionFrom_file"));
        centralWidget = new QWidget(RoadRace);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnStuff = new QPushButton(centralWidget);
        btnStuff->setObjectName(QStringLiteral("btnStuff"));
        btnStuff->setGeometry(QRect(710, 10, 115, 32));
        btnOpenGame = new QToolButton(centralWidget);
        btnOpenGame->setObjectName(QStringLiteral("btnOpenGame"));
        btnOpenGame->setGeometry(QRect(350, 10, 101, 41));
        iptGameFileName = new QLineEdit(centralWidget);
        iptGameFileName->setObjectName(QStringLiteral("iptGameFileName"));
        iptGameFileName->setGeometry(QRect(32, 10, 311, 41));
        player1 = new QLabel(centralWidget);
        player1->setObjectName(QStringLiteral("player1"));
        player1->setGeometry(QRect(20, 60, 55, 17));
        name1 = new QLabel(centralWidget);
        name1->setObjectName(QStringLiteral("name1"));
        name1->setGeometry(QRect(80, 60, 81, 17));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 81, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 100, 21, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(70, 100, 21, 17));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 120, 21, 16));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(70, 120, 21, 17));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(170, 60, 731, 601));
        gameLayout = new QGridLayout(gridLayoutWidget);
        gameLayout->setSpacing(6);
        gameLayout->setContentsMargins(11, 11, 11, 11);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));
        gameLayout->setContentsMargins(0, 0, 0, 0);
        wo1 = new QLabel(centralWidget);
        wo1->setObjectName(QStringLiteral("wo1"));
        wo1->setGeometry(QRect(40, 100, 21, 17));
        Sto1 = new QLabel(centralWidget);
        Sto1->setObjectName(QStringLiteral("Sto1"));
        Sto1->setGeometry(QRect(90, 100, 21, 17));
        Go1 = new QLabel(centralWidget);
        Go1->setObjectName(QStringLiteral("Go1"));
        Go1->setGeometry(QRect(90, 120, 21, 17));
        Wa1 = new QLabel(centralWidget);
        Wa1->setObjectName(QStringLiteral("Wa1"));
        Wa1->setGeometry(QRect(40, 120, 21, 17));
        RoadRace->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(RoadRace);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RoadRace->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RoadRace);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RoadRace->setStatusBar(statusBar);

        retranslateUi(RoadRace);

        QMetaObject::connectSlotsByName(RoadRace);
    } // setupUi

    void retranslateUi(QMainWindow *RoadRace)
    {
        RoadRace->setWindowTitle(QApplication::translate("RoadRace", "RoadRace", 0));
        actionFrom_file->setText(QApplication::translate("RoadRace", "From file...", 0));
        btnStuff->setText(QApplication::translate("RoadRace", "Use Test Case", 0));
        btnOpenGame->setText(QApplication::translate("RoadRace", "&Open Game...", 0));
        iptGameFileName->setText(QString());
        player1->setText(QApplication::translate("RoadRace", "Player 1", 0));
        name1->setText(QApplication::translate("RoadRace", "*placeholder*", 0));
        label->setText(QApplication::translate("RoadRace", "Resources", 0));
        label_5->setText(QApplication::translate("RoadRace", "Wo", 0));
        label_9->setText(QApplication::translate("RoadRace", "Sto", 0));
        label_10->setText(QApplication::translate("RoadRace", "Wa", 0));
        label_20->setText(QApplication::translate("RoadRace", "Go", 0));
        wo1->setText(QString());
        Sto1->setText(QString());
        Go1->setText(QString());
        Wa1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RoadRace: public Ui_RoadRace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROADRACE_H
