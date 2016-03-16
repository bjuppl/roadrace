/********************************************************************************
** Form generated from reading UI file 'title.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_H
#define UI_TITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_title
{
public:
    QPushButton *titleButton_2;

    void setupUi(QDialog *title)
    {
        if (title->objectName().isEmpty())
            title->setObjectName(QStringLiteral("title"));
        title->resize(569, 300);
        titleButton_2 = new QPushButton(title);
        titleButton_2->setObjectName(QStringLiteral("titleButton_2"));
        titleButton_2->setGeometry(QRect(290, 260, 85, 27));

        retranslateUi(title);

        QMetaObject::connectSlotsByName(title);
    } // setupUi

    void retranslateUi(QDialog *title)
    {
        title->setWindowTitle(QApplication::translate("title", "Dialog", 0));
        titleButton_2->setText(QApplication::translate("title", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class title: public Ui_title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_H
