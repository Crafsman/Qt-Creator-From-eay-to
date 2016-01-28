/********************************************************************************
** Form generated from reading UI file 'communicate.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATE_H
#define UI_COMMUNICATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicateClass
{
public:
    QCheckBox *checkBox_sender;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *receiveLabel;
    QPushButton *pushButton;
    QCheckBox *checkBox_receive;
    QLabel *label_2;
    QComboBox *comboBox_IP;

    void setupUi(QWidget *CommunicateClass)
    {
        if (CommunicateClass->objectName().isEmpty())
            CommunicateClass->setObjectName(QString::fromUtf8("CommunicateClass"));
        CommunicateClass->resize(448, 157);
        CommunicateClass->setAutoFillBackground(true);
        checkBox_sender = new QCheckBox(CommunicateClass);
        checkBox_sender->setObjectName(QString::fromUtf8("checkBox_sender"));
        checkBox_sender->setGeometry(QRect(10, 9, 91, 20));
        checkBox_sender->setChecked(false);
        comboBox = new QComboBox(CommunicateClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 99, 101, 21));
        label = new QLabel(CommunicateClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 51, 16));
        receiveLabel = new QLabel(CommunicateClass);
        receiveLabel->setObjectName(QString::fromUtf8("receiveLabel"));
        receiveLabel->setGeometry(QRect(220, 10, 81, 21));
        pushButton = new QPushButton(CommunicateClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 10, 75, 23));
        checkBox_receive = new QCheckBox(CommunicateClass);
        checkBox_receive->setObjectName(QString::fromUtf8("checkBox_receive"));
        checkBox_receive->setGeometry(QRect(10, 50, 105, 22));
        label_2 = new QLabel(CommunicateClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 100, 41, 18));
        comboBox_IP = new QComboBox(CommunicateClass);
        comboBox_IP->setObjectName(QString::fromUtf8("comboBox_IP"));
        comboBox_IP->setGeometry(QRect(240, 100, 181, 24));

        retranslateUi(CommunicateClass);

        QMetaObject::connectSlotsByName(CommunicateClass);
    } // setupUi

    void retranslateUi(QWidget *CommunicateClass)
    {
        CommunicateClass->setWindowTitle(QApplication::translate("CommunicateClass", "Communicate", 0, QApplication::UnicodeUTF8));
        checkBox_sender->setText(QApplication::translate("CommunicateClass", "\345\217\221\351\200\201\347\253\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CommunicateClass", "\347\275\221\345\215\241\357\274\232", 0, QApplication::UnicodeUTF8));
        receiveLabel->setText(QString());
        pushButton->setText(QApplication::translate("CommunicateClass", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        checkBox_receive->setText(QApplication::translate("CommunicateClass", "\346\216\245\346\224\266\347\253\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CommunicateClass", "IP:", 0, QApplication::UnicodeUTF8));
        comboBox_IP->clear();
        comboBox_IP->insertItems(0, QStringList()
         << QApplication::translate("CommunicateClass", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CommunicateClass", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CommunicateClass", "3", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CommunicateClass: public Ui_CommunicateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATE_H
