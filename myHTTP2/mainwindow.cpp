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
	//����һ��QNetworkAccessManager���ʵ��������������������ͽ���Ӧ��
	manager = new QNetworkAccessManager(this);

	ui.progressBar->hide();

}

MainWindow::~MainWindow()
{

}

void MainWindow::startRequest(QUrl url)
{
	//get������������������
	reply = manager->get(QNetworkRequest(url));
	//readyRead()�źż̳���QIODevice�࣬ÿ�����µ����ݿɶ�ȡʱ�����ᷢ����ź�
	connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));

	//ÿ��������������ؽ��ȸ���ʱ�����ᷢ��dounloadProgress�ź��������½�����
	connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateDataReadProgress(qint64, qint64)));

	//ÿ��Ӧ�������ʱ�����ᷢ��finished()�ź�
	connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));

}

void MainWindow::httpReadyRead()
{
	//���ж��Ƿ񴴽����ļ����������ȡ���ص���������
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
	//��������غ��������ؽ�������Ȼ��ɾ��reply, and file
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
	//��ȡ����������Ϣ
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
	//1.��ȡ��½��
	QString name = qgetenv("USERNAME");
	qDebug()<<"User name:"<<name<<"\n";
	allinfo = tr("UserName�û�:");
	allinfo += name +"\n";

	//ui.textBrowser->setText(name);

	//2.��ȡ��������IP��ַ
	//QHostInfo�����ã���ȡ��������Ҳ����ͨ��������������ip��ַ��//����ͨ��IP��ַ�����������������
	QString localHostName = QHostInfo::localHostName();
	qDebug()<<"LocalHOstname:"<<localHostName<<"\n";
	allinfo += tr("LocalHostName�������:");
	allinfo += localHostName;
	allinfo +="\n";

	//��ȡIP��ַ
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
	//c++��ȡ����
	PIP_ADAPTER_INFO pIpAdapterInfo = new PIP_ADAPTER_INFO();

	
}


