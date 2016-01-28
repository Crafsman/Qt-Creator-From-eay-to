/********************************************************************************
** Form generated from reading UI file 'adapterinfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADAPTERINFO_H
#define UI_ADAPTERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdapterInfoClass
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdapterInfoClass)
    {
        if (AdapterInfoClass->objectName().isEmpty())
            AdapterInfoClass->setObjectName(QString::fromUtf8("AdapterInfoClass"));
        AdapterInfoClass->resize(714, 520);
        centralWidget = new QWidget(AdapterInfoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 411, 31));
        comboBox->setInsertPolicy(QComboBox::InsertAtTop);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 210, 112, 34));
        AdapterInfoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdapterInfoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 714, 30));
        AdapterInfoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdapterInfoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AdapterInfoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdapterInfoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AdapterInfoClass->setStatusBar(statusBar);

        retranslateUi(AdapterInfoClass);

        QMetaObject::connectSlotsByName(AdapterInfoClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdapterInfoClass)
    {
        AdapterInfoClass->setWindowTitle(QApplication::translate("AdapterInfoClass", "AdapterInfo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AdapterInfoClass", "\345\217\221\351\200\201\345\271\277\346\222\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdapterInfoClass: public Ui_AdapterInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADAPTERINFO_H
