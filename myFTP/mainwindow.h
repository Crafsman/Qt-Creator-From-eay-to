#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"

class QFtp;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	QFtp *ftp;

private slots:
	void ftpCommandStarted(int);
	void ftpCommandFinished(int, bool);

};

#endif // MAINWINDOW_H
