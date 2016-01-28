#include "mainwindow.h"
#include <QtNetwork/QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//��ȡ�����������ƣ��Լ��ļ��������
	QString localHostName = QHostInfo::localHostName();
	//�����������ƻ�ȡ��Qhostinfo����
	QHostInfo info = QHostInfo::fromName(localHostName);
	
	//��һ����������ȡ��IP��ַ���ܲ�ֹһ�����������е�һ��һ���Ǳ����趨��IP��ַ
	qDebug()<<"localHostName:"<<localHostName<<endl
	<<"IP Address"<<info.addresses();//��ȡ����������ص�IP��ַ

	/*QList<QHostAddress> tlist = QHostInfo::localDomainName();*/

// 	foreach(QHostAddress address, QHostInfo::addresses())
// 	{
// 		if (address.protocol() == QAbstractSocket::IPv4Protocol)
// 		{
// 			qDebug()<<address.toString();
// 		}
// 	}
	qDebug()<<"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			qDebug()<<address.toString();
		}
	}

	//QHostInfo::lookupHost("www.baidu.com", this, SLOT(lookedUp(QHostInfo)));
	qDebug()<<"***************************************************************";
	//////////////////////////////////////////////////////////////////////////
	//��ȡ��������ӿڵ��б�
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

	int index = 0;
	//����ÿһ������ӿڵ��б�
	foreach(QNetworkInterface interface, list)
	{
		qDebug()<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
		//�ӿ�����
		qDebug()<<"Name:"<<interface.name();
		//Ӳ����ַ
		qDebug()<<"HardwareAddress:"<<interface.hardwareAddress()
			<<"human"<<interface.humanReadableName();
		
		//��ȡIP��ַ��Ŀ�б�ÿ����Ŀ����һ��IP��ַ��һ����������һ���㲥��ַ
		QList<QNetworkAddressEntry> entryList = interface.addressEntries();

		//����ÿһ��IP��ַ��Ŀ
		foreach(QNetworkAddressEntry entry, entryList)
		{
			qDebug()<<"))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))";
			qDebug()<<"IP address: "<<entry.ip().toString();
			if (entry.ip().protocol()  == QAbstractSocket::IPv4Protocol)
			{
				
				//qDebug()<<entry.ip().toString().f
				index++;
			}
			//��������
			qDebug()<<"Netmask:"<<entry.netmask().toString();
			
			//�㲥��ַ
			qDebug()<<"Brodcast: "<<entry.broadcast().toString();
		
			
		}

	}

	qDebug()<<"ipv4"<<index;
	qDebug()<<"00000000000000000000000000000000000000000000";
	getLocalHostIP();

}

MainWindow::~MainWindow()
{

}

void MainWindow::lookedUp(const QHostInfo &host)
{
	qDebug()<<"++++++++++++++++++++++++++++++"<<endl;
	if (host.error() != QHostInfo::NoError)
	{
		qDebug()<<"lookup failed:"<<host.errorString();
		return;
	}
	foreach(const QHostAddress& address, host.addresses())
		qDebug()<<"Found"<<address.toString();
}


QHostAddress MainWindow::getLocalHostIP()
{
	QList<QHostAddress> AddressList = QNetworkInterface::allAddresses();
	QHostAddress result;
	int index = 0;
	foreach(QHostAddress address, AddressList)
	{
		if(address.protocol() == QAbstractSocket::IPv4Protocol &&
			address != QHostAddress::Null &&
			address != QHostAddress::LocalHost
			)
		{
				
				if (address.toString().contains("192.168."))
				{
					//continue;
					index++;
					
				}
				qDebug()<<"getLocalHostIP"<<address.toString();
				result = address;
				//break;
		}

	}
	qDebug()<<"index = "<<index;
	return result;

}
