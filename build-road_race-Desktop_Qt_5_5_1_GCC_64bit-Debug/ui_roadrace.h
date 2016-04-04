/********************************************************************************
** Form generated from reading UI file 'roadrace.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QLabel *Go1;
    QLabel *Sto1;
    QLabel *Wa1;
    QLabel *name1;
    QPushButton *helpBtn;
    QRadioButton *EsyBtn;
    QRadioButton *MedBtn;
    QRadioButton *HardBtn;
    QPushButton *cheatBtn;
    QPushButton *SaveBtn;
    QPushButton *tst2Btn;
    QLabel *label_2;
    QLabel *lblTime;
    QPushButton *RanBtn;
    QPushButton *btnSendToServer;
    QTextEdit *txtServerOutput;
    QLineEdit *iptServerName;
    QPushButton *btnConnect;
    QPushButton *testBtn;
    QPushButton *joinBtn;
    QTextEdit *iptServerMsg;
    QLabel *label_3;
    QSlider *volumeSlider;
    QLabel *label_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RoadRace)
    {
        if (RoadRace->objectName().isEmpty())
            RoadRace->setObjectName(QStringLiteral("RoadRace"));
        RoadRace->resize(1004, 722);
        actionFrom_file = new QAction(RoadRace);
        actionFrom_file->setObjectName(QStringLiteral("actionFrom_file"));
        centralWidget = new QWidget(RoadRace);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnStuff = new QPushButton(centralWidget);
        btnStuff->setObjectName(QStringLiteral("btnStuff"));
        btnStuff->setGeometry(QRect(220, 0, 115, 41));
        btnOpenGame = new QToolButton(centralWidget);
        btnOpenGame->setObjectName(QStringLiteral("btnOpenGame"));
        btnOpenGame->setGeometry(QRect(780, 0, 121, 41));
        iptGameFileName = new QLineEdit(centralWidget);
        iptGameFileName->setObjectName(QStringLiteral("iptGameFileName"));
        iptGameFileName->setGeometry(QRect(460, 0, 311, 41));
        playerName = new QLabel(centralWidget);
        playerName->setObjectName(QStringLiteral("playerName"));
        playerName->setGeometry(QRect(20, 30, 111, 71));
        playerName->setStyleSheet(QLatin1String("color:green;\n"
"font-size:30px;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 90, 81, 17));
        label->setStyleSheet(QStringLiteral("font-weight:bold;"));
        lblWood = new QLabel(centralWidget);
        lblWood->setObjectName(QStringLiteral("lblWood"));
        lblWood->setGeometry(QRect(20, 110, 41, 17));
        lblSto = new QLabel(centralWidget);
        lblSto->setObjectName(QStringLiteral("lblSto"));
        lblSto->setGeometry(QRect(20, 170, 41, 20));
        lblWa = new QLabel(centralWidget);
        lblWa->setObjectName(QStringLiteral("lblWa"));
        lblWa->setGeometry(QRect(20, 130, 41, 16));
        lblGo = new QLabel(centralWidget);
        lblGo->setObjectName(QStringLiteral("lblGo"));
        lblGo->setGeometry(QRect(20, 150, 31, 20));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(210, 50, 781, 621));
        gameLayout = new QGridLayout(gridLayoutWidget);
        gameLayout->setSpacing(6);
        gameLayout->setContentsMargins(11, 11, 11, 11);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));
        gameLayout->setContentsMargins(0, 0, 0, 0);
        wo1 = new QLabel(centralWidget);
        wo1->setObjectName(QStringLiteral("wo1"));
        wo1->setGeometry(QRect(70, 110, 101, 17));
        Go1 = new QLabel(centralWidget);
        Go1->setObjectName(QStringLiteral("Go1"));
        Go1->setGeometry(QRect(70, 150, 91, 17));
        Sto1 = new QLabel(centralWidget);
        Sto1->setObjectName(QStringLiteral("Sto1"));
        Sto1->setGeometry(QRect(70, 170, 91, 17));
        Wa1 = new QLabel(centralWidget);
        Wa1->setObjectName(QStringLiteral("Wa1"));
        Wa1->setGeometry(QRect(70, 130, 91, 17));
        name1 = new QLabel(centralWidget);
        name1->setObjectName(QStringLiteral("name1"));
        name1->setGeometry(QRect(149, 40, 20, 20));
        helpBtn = new QPushButton(centralWidget);
        helpBtn->setObjectName(QStringLiteral("helpBtn"));
        helpBtn->setGeometry(QRect(910, 0, 85, 41));
        EsyBtn = new QRadioButton(centralWidget);
        EsyBtn->setObjectName(QStringLiteral("EsyBtn"));
        EsyBtn->setGeometry(QRect(20, 290, 102, 22));
        MedBtn = new QRadioButton(centralWidget);
        MedBtn->setObjectName(QStringLiteral("MedBtn"));
        MedBtn->setGeometry(QRect(20, 310, 121, 22));
        HardBtn = new QRadioButton(centralWidget);
        HardBtn->setObjectName(QStringLiteral("HardBtn"));
        HardBtn->setGeometry(QRect(20, 330, 111, 22));
        cheatBtn = new QPushButton(centralWidget);
        cheatBtn->setObjectName(QStringLiteral("cheatBtn"));
        cheatBtn->setGeometry(QRect(20, 220, 71, 31));
        QFont font;
        font.setPointSize(8);
        cheatBtn->setFont(font);
        SaveBtn = new QPushButton(centralWidget);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));
        SaveBtn->setGeometry(QRect(10, 360, 191, 31));
        tst2Btn = new QPushButton(centralWidget);
        tst2Btn->setObjectName(QStringLiteral("tst2Btn"));
        tst2Btn->setGeometry(QRect(340, 0, 111, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 190, 121, 16));
        label_2->setStyleSheet(QStringLiteral("font-weight:bold;"));
        lblTime = new QLabel(centralWidget);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        lblTime->setGeometry(QRect(130, 190, 59, 16));
        RanBtn = new QPushButton(centralWidget);
        RanBtn->setObjectName(QStringLiteral("RanBtn"));
        RanBtn->setGeometry(QRect(10, 610, 191, 61));
        btnSendToServer = new QPushButton(centralWidget);
        btnSendToServer->setObjectName(QStringLiteral("btnSendToServer"));
        btnSendToServer->setGeometry(QRect(10, 460, 191, 32));
        txtServerOutput = new QTextEdit(centralWidget);
        txtServerOutput->setObjectName(QStringLiteral("txtServerOutput"));
        txtServerOutput->setGeometry(QRect(10, 500, 191, 51));
        iptServerName = new QLineEdit(centralWidget);
        iptServerName->setObjectName(QStringLiteral("iptServerName"));
        iptServerName->setGeometry(QRect(10, 560, 91, 41));
        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(110, 560, 91, 41));
        testBtn = new QPushButton(centralWidget);
        testBtn->setObjectName(QStringLiteral("testBtn"));
        testBtn->setGeometry(QRect(10, 0, 101, 41));
        joinBtn = new QPushButton(centralWidget);
        joinBtn->setObjectName(QStringLiteral("joinBtn"));
        joinBtn->setGeometry(QRect(120, 0, 91, 41));
        iptServerMsg = new QTextEdit(centralWidget);
        iptServerMsg->setObjectName(QStringLiteral("iptServerMsg"));
        iptServerMsg->setGeometry(QRect(10, 400, 191, 51));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 270, 91, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(100, 240, 91, 21));
        volumeSlider->setMaximum(100);
        volumeSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 220, 81, 20));
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
        Go1->setText(QString());
        Sto1->setText(QString());
        Wa1->setText(QString());
        name1->setText(QString());
        helpBtn->setText(QApplication::translate("RoadRace", "Help!", 0));
        EsyBtn->setText(QApplication::translate("RoadRace", "Easy Mode", 0));
        MedBtn->setText(QApplication::translate("RoadRace", "Normal Mode", 0));
        HardBtn->setText(QApplication::translate("RoadRace", "Hard Mode", 0));
        cheatBtn->setText(QApplication::translate("RoadRace", "Cheater...", 0));
        SaveBtn->setText(QApplication::translate("RoadRace", "Save the Game", 0));
        tst2Btn->setText(QApplication::translate("RoadRace", "Use 7X7 test", 0));
        label_2->setText(QApplication::translate("RoadRace", "Time (sec)", 0));
        lblTime->setText(QApplication::translate("RoadRace", "0", 0));
        RanBtn->setText(QApplication::translate("RoadRace", "Generate a random World! ", 0));
        btnSendToServer->setText(QApplication::translate("RoadRace", "Send to Server", 0));
        iptServerName->setText(QApplication::translate("RoadRace", "localhost", 0));
        btnConnect->setText(QApplication::translate("RoadRace", "Connect", 0));
        testBtn->setText(QApplication::translate("RoadRace", "Launch Game", 0));
        joinBtn->setText(QApplication::translate("RoadRace", "Join Game", 0));
        label_3->setText(QApplication::translate("RoadRace", "Difficulty", 0));
        label_4->setText(QApplication::translate("RoadRace", " - Volume +", 0));
    } // retranslateUi

};

namespace Ui {
    class RoadRace: public Ui_RoadRace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROADRACE_H
