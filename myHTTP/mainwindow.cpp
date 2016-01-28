#include "mainwindow.h"

#include <QtNetwork/QtNetwork>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//创建一个QNetworkAccessManager类的实例，用来发送网络请求和接受应答
	manager = new QNetworkAccessManager(this);
	//每当网络应答结束都会发射这个信号
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
	//get函数返回一个QNetworkReplly对象
	manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));
}

MainWindow::~MainWindow()
{

}

void MainWindow::replyFinished(QNetworkReply *reply)
{
	//转换编码
	QTextCodec *codec = QTextCodec::codecForLocale();
	QString all = codec->toUnicode(reply->readAll());
	ui.textBrowser->setText(all);
	reply->deleteLater();
}
