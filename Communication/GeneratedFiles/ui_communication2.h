/********************************************************************************
** Form generated from reading UI file 'communication2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATION2_H
#define UI_COMMUNICATION2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Communication2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Communication2Class)
    {
        if (Communication2Class->objectName().isEmpty())
            Communication2Class->setObjectName(QString::fromUtf8("Communication2Class"));
        Communication2Class->resize(600, 400);
        menuBar = new QMenuBar(Communication2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Communication2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Communication2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Communication2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Communication2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Communication2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Communication2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Communication2Class->setStatusBar(statusBar);

        retranslateUi(Communication2Class);

        QMetaObject::connectSlotsByName(Communication2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Communication2Class)
    {
        Communication2Class->setWindowTitle(QApplication::translate("Communication2Class", "Communication2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Communication2Class: public Ui_Communication2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATION2_H
