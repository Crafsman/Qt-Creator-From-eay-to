/********************************************************************************
** Form generated from reading UI file 'qtcreator从入门到精通.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCREATOR_4ECE__5165__95E8__5230__7CBE__901A__H
#define UI_QTCREATOR_4ECE__5165__95E8__5230__7CBE__901A__H

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

class Ui_QtCreator从入门到精通Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtCreator从入门到精通Class)
    {
        if (QtCreator从入门到精通Class->objectName().isEmpty())
            QtCreator从入门到精通Class->setObjectName(QString::fromUtf8("QtCreator\344\273\216\345\205\245\351\227\250\345\210\260\347\262\276\351\200\232Class"));
        QtCreator从入门到精通Class->resize(600, 400);
        menuBar = new QMenuBar(QtCreator从入门到精通Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtCreator从入门到精通Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtCreator从入门到精通Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtCreator从入门到精通Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtCreator从入门到精通Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtCreator从入门到精通Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtCreator从入门到精通Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtCreator从入门到精通Class->setStatusBar(statusBar);

        retranslateUi(QtCreator从入门到精通Class);

        QMetaObject::connectSlotsByName(QtCreator从入门到精通Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtCreator从入门到精通Class)
    {
        QtCreator从入门到精通Class->setWindowTitle(QApplication::translate("QtCreator从入门到精通Class", "QtCreator\344\273\216\345\205\245\351\227\250\345\210\260\347\262\276\351\200\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtCreator从入门到精通Class: public Ui_QtCreator从入门到精通Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCREATOR_4ECE__5165__95E8__5230__7CBE__901A__H
