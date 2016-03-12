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
    QLabel *player2;
    QLabel *name2;
    QLabel *name3;
    QLabel *name4;
    QLabel *player3;
    QLabel *player4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RoadRace)
    {
        if (RoadRace->objectName().isEmpty())
            RoadRace->setObjectName(QStringLiteral("RoadRace"));
        RoadRace->resize(834, 704);
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
        player1->setGeometry(QRect(20, 100, 55, 17));
        name1 = new QLabel(centralWidget);
        name1->setObjectName(QStringLiteral("name1"));
        name1->setGeometry(QRect(100, 100, 81, 17));
        player2 = new QLabel(centralWidget);
        player2->setObjectName(QStringLiteral("player2"));
        player2->setGeometry(QRect(20, 140, 55, 17));
        name2 = new QLabel(centralWidget);
        name2->setObjectName(QStringLiteral("name2"));
        name2->setGeometry(QRect(110, 140, 55, 17));
        name3 = new QLabel(centralWidget);
        name3->setObjectName(QStringLiteral("name3"));
        name3->setGeometry(QRect(110, 180, 55, 17));
        name4 = new QLabel(centralWidget);
        name4->setObjectName(QStringLiteral("name4"));
        name4->setGeometry(QRect(110, 220, 55, 17));
        player3 = new QLabel(centralWidget);
        player3->setObjectName(QStringLiteral("player3"));
        player3->setGeometry(QRect(20, 180, 55, 17));
        player4 = new QLabel(centralWidget);
        player4->setObjectName(QStringLiteral("player4"));
        player4->setGeometry(QRect(20, 220, 55, 17));
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
        btnStuff->setText(QApplication::translate("RoadRace", "Do Stuff", 0));
        btnOpenGame->setText(QApplication::translate("RoadRace", "&Open Game...", 0));
        iptGameFileName->setText(QString());
        player1->setText(QApplication::translate("RoadRace", "Player 1", 0));
        name1->setText(QApplication::translate("RoadRace", "*placeholder*", 0));
        player2->setText(QApplication::translate("RoadRace", "*placeholder*", 0));
        name2->setText(QApplication::translate("RoadRace", "*placeholder\"", 0));
        name3->setText(QApplication::translate("RoadRace", "*placeholder\"", 0));
        name4->setText(QApplication::translate("RoadRace", "*placeholder\"", 0));
        player3->setText(QApplication::translate("RoadRace", "*placeholder\"", 0));
        player4->setText(QApplication::translate("RoadRace", "*placeholder\"", 0));
    } // retranslateUi

};

namespace Ui {
    class RoadRace: public Ui_RoadRace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROADRACE_H
