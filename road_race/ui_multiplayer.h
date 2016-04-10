/********************************************************************************
** Form generated from reading UI file 'multiplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAYER_H
#define UI_MULTIPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_multiplayer
{
public:
    QPushButton *okBtn;
    QPushButton *voidBtn;
    QLineEdit *nameBox;
    QLineEdit *passBox;
    QLineEdit *numBox;
    QRadioButton *fiveBtn;
    QRadioButton *sevBtn;
    QRadioButton *randBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *playerBox;

    void setupUi(QDialog *multiplayer)
    {
        if (multiplayer->objectName().isEmpty())
            multiplayer->setObjectName(QStringLiteral("multiplayer"));
        multiplayer->resize(400, 372);
        okBtn = new QPushButton(multiplayer);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(240, 330, 61, 27));
        voidBtn = new QPushButton(multiplayer);
        voidBtn->setObjectName(QStringLiteral("voidBtn"));
        voidBtn->setGeometry(QRect(320, 330, 51, 27));
        nameBox = new QLineEdit(multiplayer);
        nameBox->setObjectName(QStringLiteral("nameBox"));
        nameBox->setGeometry(QRect(110, 50, 113, 27));
        passBox = new QLineEdit(multiplayer);
        passBox->setObjectName(QStringLiteral("passBox"));
        passBox->setGeometry(QRect(110, 90, 113, 27));
        numBox = new QLineEdit(multiplayer);
        numBox->setObjectName(QStringLiteral("numBox"));
        numBox->setGeometry(QRect(110, 130, 113, 27));
        fiveBtn = new QRadioButton(multiplayer);
        fiveBtn->setObjectName(QStringLiteral("fiveBtn"));
        fiveBtn->setGeometry(QRect(100, 220, 102, 22));
        sevBtn = new QRadioButton(multiplayer);
        sevBtn->setObjectName(QStringLiteral("sevBtn"));
        sevBtn->setGeometry(QRect(100, 260, 102, 22));
        randBtn = new QRadioButton(multiplayer);
        randBtn->setObjectName(QStringLiteral("randBtn"));
        randBtn->setGeometry(QRect(100, 300, 102, 22));
        label = new QLabel(multiplayer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 180, 91, 17));
        label_2 = new QLabel(multiplayer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 71, 17));
        label_3 = new QLabel(multiplayer);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 90, 55, 17));
        label_4 = new QLabel(multiplayer);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 130, 91, 17));
        playerBox = new QLineEdit(multiplayer);
        playerBox->setObjectName(QStringLiteral("playerBox"));
        playerBox->setGeometry(QRect(110, 170, 113, 27));

        retranslateUi(multiplayer);

        QMetaObject::connectSlotsByName(multiplayer);
    } // setupUi

    void retranslateUi(QDialog *multiplayer)
    {
        multiplayer->setWindowTitle(QApplication::translate("multiplayer", "Dialog", 0));
        okBtn->setText(QApplication::translate("multiplayer", "Launch", 0));
        voidBtn->setText(QApplication::translate("multiplayer", "Cancel", 0));
        fiveBtn->setText(QApplication::translate("multiplayer", "TestSet1", 0));
        sevBtn->setText(QApplication::translate("multiplayer", "TestSet2", 0));
        randBtn->setText(QApplication::translate("multiplayer", "TestSet3", 0));
        label->setText(QApplication::translate("multiplayer", "Player 1 name", 0));
        label_2->setText(QApplication::translate("multiplayer", "Game Name", 0));
        label_3->setText(QApplication::translate("multiplayer", "Password", 0));
        label_4->setText(QApplication::translate("multiplayer", "Player number", 0));
    } // retranslateUi

};

namespace Ui {
    class multiplayer: public Ui_multiplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYER_H
