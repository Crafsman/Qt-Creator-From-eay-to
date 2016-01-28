#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <QUrl>
class QNetworkReply;
class QNetworkAccessManager;
class QFile;
class QUrl;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

	//网络请求函数
	void startRequest(QUrl url);
private:
	Ui::MainWindowClass ui;

	////
	QNetworkAccessManager *manager;
	QNetworkReply *reply;
	QUrl url;
	QFile *file;
private slots:
	
	void httpFinished();
	void httpReadyRead();
	void updateDataReadProgress(qint64, qint64);
	void on_pushButton_clicked();
	//获取本机网络信息
	void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
