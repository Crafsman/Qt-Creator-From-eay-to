#include "mainwindow.h"

#include <QtNetwork/QtNetwork>
#include <QtNetwork/qnetworkinterface.h>
#include <QTextCodec>
#include <QList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//创建一个QNetworkAccessManager类的实例，用来发送网络请求和接受应答
	manager = new QNetworkAccessManager(this);

	ui.progressBar->hide();

}

MainWindow::~MainWindow()
{

}

void MainWindow::startRequest(QUrl url)
{
	//get函数来发送网络请求，
	reply = manager->get(QNetworkRequest(url));
	//readyRead()信号继承自QIODevice类，每当有新的数据可读取时，都会发射该信号
	connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));

	//每当网络请求的下载进度更新时，都会发射dounloadProgress信号用来更新进度条
	connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateDataReadProgress(qint64, qint64)));

	//每当应答处理结束时，都会发射finished()信号
	connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));

}

void MainWindow::httpReadyRead()
{
	//先判断是否创建了文件，若是则读取返回的所有数据
	if (file)
	{
		file->write(reply->readAll());
	}
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
	ui.progressBar->setMaximum(totalBytes);
	ui.progressBar->setValue(bytesRead);

}

void MainWindow::httpFinished()
{
	//当完成下载后，重新隐藏进度条，然后删除reply, and file
	ui.progressBar->hide();
	file->flush();
	file->close();
	reply->deleteLater();
	reply = 0;
	delete file;
	file = 0;
}

void MainWindow::on_pushButton_clicked()
{

	url = ui.lineEdit->text();
	QFileInfo info(url.path());
	QString fileName(info.fileName());
	if (fileName.isEmpty())
	{
		fileName = "index.html";
	}
	file = new QFile(fileName);
	if (!file->open(QIODevice::WriteOnly))
	{
		qDebug()<<"file open error";
		delete file;
		file = 0;
		return;
	}
	startRequest(url);
	ui.progressBar->setValue(0);
	ui.progressBar->show();
}

void MainWindow::on_pushButton_2_clicked()
{
	//获取所有网卡信息
//  	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
// 	QNetworkInterface::allAddresses().
//  	int index = 0;
//  	foreach(QNetworkInterface i, list)
//  	{
//  		index++;
//  		qDebug()<<i<<index;
//  	}

	//////////////////////////////////////////////////////////////////////////
// 	QList<QNetworkAddressEntry> list;  
// 	QHostAddress                addr;  
// 	QNetworkInterface   interface = QNetworkInterface::interfaceFromName("eth0");  
// 	list                          = interface.addressEntries();  
// 	if(!list.isEmpty())  
// 		addr = list.at(0).ip();  
	//////////////////////////////////////////////////////////////////////////
	QString allinfo = "";
	//1.获取登陆明
	QString name = qgetenv("USERNAME");
	qDebug()<<"User name:"<<name<<"\n";
	allinfo = tr("UserName用户:");
	allinfo += name +"\n";

	//ui.textBrowser->setText(name);

	//2.获取主机名，IP地址
	//QHostInfo类作用：获取主机名，也可以通过主机名来查找ip地址，//或者通过IP地址来反向查找主机名。
	QString localHostName = QHostInfo::localHostName();
	qDebug()<<"LocalHOstname:"<<localHostName<<"\n";
	allinfo += tr("LocalHostName计算机名:");
	allinfo += localHostName;
	allinfo +="\n";

	//获取IP地址
	QHostInfo info = QHostInfo::fromName(localHostName);
	qDebug()<<"IP Address:"<<info.addresses()<<"\n";
	allinfo += tr("IP Address:");
	allinfo +="\n";
	//allinfo +=info.addresses().;
	
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol);
		{
			allinfo +="IPv4 Address: ";
			allinfo += address.toString();
			allinfo +="\n";
			qDebug()<<"IPv4 Address:"<<address.toString();

		}
	}

	allinfo +="\n";

	foreach (QHostAddress address, QNetworkInterface::allAddresses())
	{
		allinfo +="Address: ";
		allinfo += address.toString();
		allinfo +="\n";
		qDebug() << "Address:" << address;
	} 
	allinfo +="\n";

	ui.textBrowser->setText(allinfo);

	//////////////////////////////////////////////////////////////////////////
	//c++获取网卡
	PIP_ADAPTER_INFO pIpAdapterInfo = new PIP_ADAPTER_INFO();

	
}


