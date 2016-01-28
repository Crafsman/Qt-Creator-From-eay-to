/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SenderClass
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *SenderClass)
    {
        if (SenderClass->objectName().isEmpty())
            SenderClass->setObjectName(QString::fromUtf8("SenderClass"));
        SenderClass->resize(600, 400);
        pushButton = new QPushButton(SenderClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 180, 112, 34));

        retranslateUi(SenderClass);

        QMetaObject::connectSlotsByName(SenderClass);
    } // setupUi

    void retranslateUi(QDialog *SenderClass)
    {
        SenderClass->setWindowTitle(QApplication::translate("SenderClass", "Sender", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SenderClass", "\350\277\233\350\241\214\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SenderClass: public Ui_SenderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
