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
#include <QtWidgets/QTextBrowser>
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
    QLabel *playerName;
    QLabel *label;
    QLabel *lblWood;
    QLabel *lblSto;
    QLabel *lblWa;
    QLabel *lblGo;
    QWidget *gridLayoutWidget;
    QGridLayout *gameLayout;
    QLabel *wo1;
    QLabel *Sto1;
    QLabel *Go1;
    QLabel *Wa1;
    QLabel *name1;
    QTextBrowser *textBrowser;
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
        playerName = new QLabel(centralWidget);
        playerName->setObjectName(QStringLiteral("playerName"));
        playerName->setGeometry(QRect(20, 60, 111, 71));
        playerName->setStyleSheet(QLatin1String("color:green;\n"
"font-size:30px;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 81, 17));
        label->setStyleSheet(QStringLiteral("font-weight:bold;"));
        lblWood = new QLabel(centralWidget);
        lblWood->setObjectName(QStringLiteral("lblWood"));
        lblWood->setGeometry(QRect(20, 140, 41, 17));
        lblSto = new QLabel(centralWidget);
        lblSto->setObjectName(QStringLiteral("lblSto"));
        lblSto->setGeometry(QRect(20, 200, 41, 20));
        lblWa = new QLabel(centralWidget);
        lblWa->setObjectName(QStringLiteral("lblWa"));
        lblWa->setGeometry(QRect(20, 160, 41, 16));
        lblGo = new QLabel(centralWidget);
        lblGo->setObjectName(QStringLiteral("lblGo"));
        lblGo->setGeometry(QRect(20, 180, 31, 20));
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
        wo1->setGeometry(QRect(70, 140, 21, 17));
        Sto1 = new QLabel(centralWidget);
        Sto1->setObjectName(QStringLiteral("Sto1"));
        Sto1->setGeometry(QRect(70, 180, 21, 17));
        Go1 = new QLabel(centralWidget);
        Go1->setObjectName(QStringLiteral("Go1"));
        Go1->setGeometry(QRect(70, 200, 21, 17));
        Wa1 = new QLabel(centralWidget);
        Wa1->setObjectName(QStringLiteral("Wa1"));
        Wa1->setGeometry(QRect(70, 160, 21, 17));
        name1 = new QLabel(centralWidget);
        name1->setObjectName(QStringLiteral("name1"));
        name1->setGeometry(QRect(149, 70, 20, 20));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 241, 111, 181));
        textBrowser->setStyleSheet(QStringLiteral("background:transparent;"));
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
        playerName->setText(QApplication::translate("RoadRace", "Status", 0));
        label->setText(QApplication::translate("RoadRace", "Resources", 0));
        lblWood->setText(QApplication::translate("RoadRace", "Wood", 0));
        lblSto->setText(QApplication::translate("RoadRace", "Stone", 0));
        lblWa->setText(QApplication::translate("RoadRace", "Water", 0));
        lblGo->setText(QApplication::translate("RoadRace", "Gold", 0));
        wo1->setText(QString());
        Sto1->setText(QString());
        Go1->setText(QString());
        Wa1->setText(QString());
        name1->setText(QString());
        textBrowser->setHtml(QApplication::translate("RoadRace", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Currently in single-player mode. Upgrade for more options.</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class RoadRace: public Ui_RoadRace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROADRACE_H
