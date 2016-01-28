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
			//qDebug()<<"IP address: "<<entry.ip().toString();
			if (entry.ip().protocol()  == QAbstractSocket::IPv4Protocol 
				&& entry.ip() != QHostAddress::Null
				&&entry.ip() != QHostAddress::LocalHost)
			{

				if (entry.ip().toString().contains("192.168"))
				{
					qDebug()<<"IP: "<<entry.ip().toString();
					//���뵽����combox��
				}
				
				index++;
			}
			
			//�㲥��ַ
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
