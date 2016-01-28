#include "communication2.h"
#include <QtNetwork/QtNetwork>

Communication2::Communication2(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	getNetCardInfoQt();
}

Communication2::~Communication2()
{

}

void Communication2::getNetCardInfoQt()
{
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
			//qDebug()<<"IP address: "<<entry.ip().toString();
			if (entry.ip().protocol()  == QAbstractSocket::IPv4Protocol 
				&& entry.ip() != QHostAddress::Null
				&&entry.ip() != QHostAddress::LocalHost)
			{

				if (entry.ip().toString().contains("192.168"))
				{
					qDebug()<<"IP: "<<entry.ip().toString();
					//加入到网卡combox中
				}
				
				index++;
			}
			
			//广播地址
			//qDebug()<<"Brodcast: "<<entry.broadcast().toString();


		}

	}
// 
// 	//////////////////////////////////////////////////////////////////////////
// 	QList<QHostAddress> AddressList = QNetworkInterface::allAddresses();
// 	QHostAddress result;
// 	int index = 0;
// 	foreach(QHostAddress address, AddressList)
// 	{
// 		if(address.protocol() == QAbstractSocket::IPv4Protocol &&
// 			address != QHostAddress::Null &&
// 			address != QHostAddress::LocalHost
// 			)
// 		{
// 
// 			if (address.toString().contains("192.168."))
// 			{
// 				//continue;
// 				index++;
// 				qDebug()<<"getLocalHostIP"<<address.toString();
// 
// 			}
// 			result = address;
// 			//break;
// 		}
// 
// 	}
	qDebug()<<"index = "<<index;
}
