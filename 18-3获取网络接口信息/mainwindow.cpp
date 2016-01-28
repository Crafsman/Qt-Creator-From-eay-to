#include "mainwindow.h"
#include <QtNetwork/QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//获取本地主机名称，自己的计算机名称
	QString localHostName = QHostInfo::localHostName();
	//根据主机名称获取了Qhostinfo对象
	QHostInfo info = QHostInfo::fromName(localHostName);
	
	//从一个主机名获取的IP地址可能不止一个，不过其中第一个一般是本机设定的IP地址
	qDebug()<<"localHostName:"<<localHostName<<endl
	<<"IP Address"<<info.addresses();//获取与主机名相关的IP地址

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
	//获取所有网络接口的列表
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

	int index = 0;
	//遍历每一个网络接口的列表
	foreach(QNetworkInterface interface, list)
	{
		qDebug()<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
		//接口名称
		qDebug()<<"Name:"<<interface.name();
		//硬件地址
		qDebug()<<"HardwareAddress:"<<interface.hardwareAddress()
			<<"human"<<interface.humanReadableName();
		
		//获取IP地址条目列表，每个条目包含一个IP地址，一个子网掩码一个广播地址
		QList<QNetworkAddressEntry> entryList = interface.addressEntries();

		//遍历每一个IP地址条目
		foreach(QNetworkAddressEntry entry, entryList)
		{
			qDebug()<<"))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))";
			qDebug()<<"IP address: "<<entry.ip().toString();
			if (entry.ip().protocol()  == QAbstractSocket::IPv4Protocol)
			{
				
				//qDebug()<<entry.ip().toString().f
				index++;
			}
			//子网掩码
			qDebug()<<"Netmask:"<<entry.netmask().toString();
			
			//广播地址
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
