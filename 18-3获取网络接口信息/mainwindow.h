#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <QtNetwork/QtNetwork>
class QHostInfo;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

	 QHostAddress getLocalHostIP();

private:
	Ui::MainWindowClass ui;

private slots:
	void lookedUp(const QHostInfo &host);
};

#endif // MAINWINDOW_H
