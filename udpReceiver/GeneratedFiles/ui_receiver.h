/********************************************************************************
** Form generated from reading UI file 'receiver.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_H
#define UI_RECEIVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ReceiverClass
{
public:
    QLabel *label;

    void setupUi(QDialog *ReceiverClass)
    {
        if (ReceiverClass->objectName().isEmpty())
            ReceiverClass->setObjectName(QString::fromUtf8("ReceiverClass"));
        ReceiverClass->resize(600, 400);
        label = new QLabel(ReceiverClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 110, 181, 41));

        retranslateUi(ReceiverClass);

        QMetaObject::connectSlotsByName(ReceiverClass);
    } // setupUi

    void retranslateUi(QDialog *ReceiverClass)
    {
        ReceiverClass->setWindowTitle(QApplication::translate("ReceiverClass", "Receiver", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ReceiverClass", "waiting...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReceiverClass: public Ui_ReceiverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_H
