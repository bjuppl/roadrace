/********************************************************************************
** Form generated from reading UI file 'cheater.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEATER_H
#define UI_CHEATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_cheater
{
public:
    QTextEdit *woodBox;
    QTextEdit *goBox;
    QTextEdit *waBOx;
    QTextEdit *stoBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *yesBtn;
    QPushButton *canBtn;
    QCheckBox *RndBox;

    void setupUi(QDialog *cheater)
    {
        if (cheater->objectName().isEmpty())
            cheater->setObjectName(QStringLiteral("cheater"));
        cheater->resize(400, 370);
        woodBox = new QTextEdit(cheater);
        woodBox->setObjectName(QStringLiteral("woodBox"));
        woodBox->setGeometry(QRect(20, 70, 104, 21));
        goBox = new QTextEdit(cheater);
        goBox->setObjectName(QStringLiteral("goBox"));
        goBox->setGeometry(QRect(20, 200, 104, 21));
        waBOx = new QTextEdit(cheater);
        waBOx->setObjectName(QStringLiteral("waBOx"));
        waBOx->setGeometry(QRect(20, 260, 104, 21));
        stoBox = new QTextEdit(cheater);
        stoBox->setObjectName(QStringLiteral("stoBox"));
        stoBox->setGeometry(QRect(20, 130, 104, 21));
        label = new QLabel(cheater);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 101, 17));
        label_2 = new QLabel(cheater);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 131, 17));
        label_3 = new QLabel(cheater);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 180, 101, 17));
        label_4 = new QLabel(cheater);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 240, 121, 17));
        label_5 = new QLabel(cheater);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 20, 91, 17));
        yesBtn = new QPushButton(cheater);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));
        yesBtn->setGeometry(QRect(150, 320, 85, 27));
        canBtn = new QPushButton(cheater);
        canBtn->setObjectName(QStringLiteral("canBtn"));
        canBtn->setGeometry(QRect(280, 320, 85, 27));
        RndBox = new QCheckBox(cheater);
        RndBox->setObjectName(QStringLiteral("RndBox"));
        RndBox->setGeometry(QRect(180, 70, 191, 22));

        retranslateUi(cheater);

        QMetaObject::connectSlotsByName(cheater);
    } // setupUi

    void retranslateUi(QDialog *cheater)
    {
        cheater->setWindowTitle(QApplication::translate("cheater", "Dialog", 0));
        label->setText(QApplication::translate("cheater", "Set wood amount", 0));
        label_2->setText(QApplication::translate("cheater", "Set stone amount", 0));
        label_3->setText(QApplication::translate("cheater", "Set gold amount", 0));
        label_4->setText(QApplication::translate("cheater", "Set water amount", 0));
        label_5->setText(QApplication::translate("cheater", "HAAAAXXXX!", 0));
        yesBtn->setText(QApplication::translate("cheater", "Accept", 0));
        canBtn->setText(QApplication::translate("cheater", "Cancel", 0));
        RndBox->setText(QApplication::translate("cheater", "Shut off Random events", 0));
    } // retranslateUi

};

namespace Ui {
    class cheater: public Ui_cheater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEATER_H
