/********************************************************************************
** Form generated from reading UI file 'joiner.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINER_H
#define UI_JOINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_joiner
{
public:
    QPushButton *killBtn;
    QPushButton *joinBtn;
    QLineEdit *gameBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *passBox;
    QLineEdit *nameBox;
    QLabel *label_4;
    QLabel *statLbl;

    void setupUi(QDialog *joiner)
    {
        if (joiner->objectName().isEmpty())
            joiner->setObjectName(QStringLiteral("joiner"));
        joiner->resize(400, 300);
        killBtn = new QPushButton(joiner);
        killBtn->setObjectName(QStringLiteral("killBtn"));
        killBtn->setGeometry(QRect(310, 260, 85, 27));
        joinBtn = new QPushButton(joiner);
        joinBtn->setObjectName(QStringLiteral("joinBtn"));
        joinBtn->setGeometry(QRect(210, 260, 85, 27));
        gameBox = new QLineEdit(joiner);
        gameBox->setObjectName(QStringLiteral("gameBox"));
        gameBox->setGeometry(QRect(130, 50, 113, 27));
        label = new QLabel(joiner);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 111, 17));
        label_2 = new QLabel(joiner);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 131, 17));
        label_3 = new QLabel(joiner);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 130, 111, 17));
        passBox = new QLineEdit(joiner);
        passBox->setObjectName(QStringLiteral("passBox"));
        passBox->setGeometry(QRect(160, 80, 113, 27));
        nameBox = new QLineEdit(joiner);
        nameBox->setObjectName(QStringLiteral("nameBox"));
        nameBox->setGeometry(QRect(130, 120, 113, 27));
        label_4 = new QLabel(joiner);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 55, 17));
        statLbl = new QLabel(joiner);
        statLbl->setObjectName(QStringLiteral("statLbl"));
        statLbl->setGeometry(QRect(90, 170, 141, 31));

        retranslateUi(joiner);

        QMetaObject::connectSlotsByName(joiner);
    } // setupUi

    void retranslateUi(QDialog *joiner)
    {
        joiner->setWindowTitle(QApplication::translate("joiner", "Dialog", 0));
        killBtn->setText(QApplication::translate("joiner", "Cancel", 0));
        joinBtn->setText(QApplication::translate("joiner", "Join Game", 0));
        label->setText(QApplication::translate("joiner", "Enter Game name", 0));
        label_2->setText(QApplication::translate("joiner", "Enter Game Password", 0));
        label_3->setText(QApplication::translate("joiner", "Enter your name", 0));
        label_4->setText(QApplication::translate("joiner", "Status", 0));
        statLbl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class joiner: public Ui_joiner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINER_H
