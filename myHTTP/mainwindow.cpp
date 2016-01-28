#include "mainwindow.h"

#include <QtNetwork/QtNetwork>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//����һ��QNetworkAccessManager���ʵ��������������������ͽ���Ӧ��
	manager = new QNetworkAccessManager(this);
	//ÿ������Ӧ��������ᷢ������ź�
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
	//get��������һ��QNetworkReplly����
	manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));
}

MainWindow::~MainWindow()
{

}

void MainWindow::replyFinished(QNetworkReply *reply)
{
	//ת������
	QTextCodec *codec = QTextCodec::codecForLocale();
	QString all = codec->toUnicode(reply->readAll());
	ui.textBrowser->setText(all);
	reply->deleteLater();
}
