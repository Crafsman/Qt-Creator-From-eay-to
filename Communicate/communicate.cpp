#include "communicate.h"
#include <QtNetwork/QtNetwork>

#include <QForeachContainer>

// #include <WinSock2.h>
// #include <IPHlpApi.h>
#include <QDebug>

Communicate::Communicate(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
	
	//��ȡ������Ϣ
	getNetCardInfoQt();

	udpSocket = new QUdpSocket(this);
		
	connect(ui.checkBox_receive, SIGNAL(clicked()), this, SLOT(ChoseClientOrServer()));
	connect(ui.checkBox_sender, SIGNAL(clicked()), this, SLOT(ChoseClientOrServer()));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int )), this, SLOT(setCurrentNetCard(int )));

	//��ȡ�ϴα������Ϣ
	readSettings();
}

Communicate::~Communicate()
{

}

void Communicate::ChoseClientOrServer()
{
	//ѡ���Ƿ��Ͷ�
	if (ui.checkBox_sender->isChecked ())			
	{
		setSender();		
		ui.checkBox_receive->setEnabled(false);
	}		
	if (ui.checkBox_receive->isChecked ())		
	{
		setReceiver();
		ui.checkBox_sender->setEnabled(false);
	}		
}

void Communicate::setSender()
{
	ui.pushButton->show();
	ui.receiveLabel->hide();
}

void Communicate::setReceiver()
{	
	ui.pushButton->hide();
	ui.receiveLabel->show();
 	int index = ui.comboBox->currentIndex();
	udpSocket->bind(m_addresss[index] , 45454, QUdpSocket::ShareAddress| QUdpSocket::ReuseAddressHint);
	//udpSocket->bind(45454, QUdpSocket::ShareAddress );
	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
	

}

void Communicate::processPendingDatagram()
{

	//ӵ�еȴ������ݱ�
	while(udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		//��datagram�Ĵ�СΪ�ȴ���������ݱ��Ĵ�С���������ܽ��ܵ�����������
		datagram.resize(udpSocket->pendingDatagramSize());

		//�������ݱ�������ŵ�datagram��
		udpSocket->readDatagram(datagram.data(), datagram.size());
		ui.receiveLabel->setText(datagram);
		ui.receiveLabel->show();

	}
}

void Communicate::on_pushButton_clicked()
{
	QByteArray datagram = "hello world!";
	//	�������ݱ�
	//udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
	udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
}

void Communicate::setCurrentNetCard(int index)
{
	//ѡ��״̬�Ƿ��Ͷˣ�������ѡ�����Σ�ֱ���˳�UDP���Ͳ�����������
// 	if (ui.checkBox->isChecked ())		
// 		setSender();			
// 	else		
// 		setReceiver();	
	
}

void Communicate::getNetCardInfo()
{

#if 0


	//PIP_ADAPTER_INFO�ṹ��ָ��洢����������Ϣ
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	//�õ��ṹ���С������GetAdaptersInfo����
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	//����GetAdaptersInfo���������pIpAdapterָ�����������stSize��������һ��������Ҳ��һ�������
	int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	//��¼��������
	int netCardNum = 0;
	//��¼ÿ�������ϵ�IP��ַ����

	if (ERROR_BUFFER_OVERFLOW == nRel)
	{
		//����������ص���ERROR_BUFFER_OVERFLOW
		//��˵��GetAdaptersInfo�������ݵ��ڴ�ռ䲻����ͬʱ�䴫��stSize,��ʾ��Ҫ�Ŀռ��С
		//��Ҳ��˵��ΪʲôstSize����һ��������Ҳ��һ�������
		//�ͷ�ԭ�����ڴ�ռ�
		delete pIpAdapterInfo;
		//���������ڴ�ռ������洢����������Ϣ
		pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
		//�ٴε���GetAdaptersInfo���������pIPAdapterInofָ�����
		nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	}
	if (ERROR_SUCCESS == nRel)
	{
		//���������Ϣ
		//�����ж��������ͨ��ѭ��ȥ�ж�
		while(pIpAdapterInfo)
		{
			qDebug()<<tr("�������ƣ�")<<pIpAdapterInfo->AdapterName<<endl;
			qDebug()<<tr("����������")<<pIpAdapterInfo->Description<<endl;
			qDebug()<<pIpAdapterInfo->CurrentIpAddress;
			qDebug()<<pIpAdapterInfo->Address;

			NetCardInfo net;
			net.name = pIpAdapterInfo->AdapterName;
			net.description = pIpAdapterInfo->Description;
			ui.comboBox->addItems(QStringList()<<(pIpAdapterInfo->Description));
			nets.push_back(net);

			qDebug()<<tr("����MAC��ַ��");
			for (DWORD i = 0; i < pIpAdapterInfo->AddressLength; i++)
			{
				if (i < pIpAdapterInfo->AddressLength -1)
				{
					printf("%02x-", pIpAdapterInfo->Address[i]);
					
				}
				else
				{
					printf("%02x\n", pIpAdapterInfo->Address[i]);
					

				}
			}

			qDebug()<<tr("����IP��ַ���£�")<<endl;
			//���������ж��IP��ѭ��ȥ�ж�
			int IPnumPerNetCard = 0;
			IP_ADDR_STRING *pIpAddrString =&(pIpAdapterInfo->IpAddressList);
			do 
			{
				qDebug()<<tr("�������ϵ�IP������ ")<<++IPnumPerNetCard<<endl;
				qDebug()<<tr("IP ��ַ�� ")<<pIpAddrString->IpAddress.String<<endl;
				
				pIpAddrString = pIpAddrString->Next;
			} while (pIpAddrString);
			pIpAdapterInfo = pIpAdapterInfo->Next;
			

		}

	}

	//�ͷ��ڴ�ռ�
	if (pIpAdapterInfo)
	{
		delete pIpAdapterInfo;
	}
#endif
}

void Communicate::getNetCardInfoQt()
{
	//��ȡ��������ӿڵ��б�
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

	int index = 0;

	//����ÿһ������ӿڵ��б�
	foreach(QNetworkInterface interface, list)
	{
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
			if (entry.ip().protocol()  == QAbstractSocket::IPv4Protocol 
				&& entry.ip() != QHostAddress::Null
				&&entry.ip() != QHostAddress::LocalHost)
			{
				qDebug()<<"IP: "<<entry.ip().toString();
				ui.comboBox->addItems(QStringList()<<(interface.humanReadableName()));
				m_addresss.push_back(entry.ip());

// 				if (entry.ip().toString().contains("192.168"))
// 				{
// 					//qDebug()<<"IP: "<<entry.ip().toString();
// 					//���뵽����combox��			
// 				}

				index++;
			}

			
		}

	}
	qDebug()<<index;
	qDebug()<<"0"<<m_addresss[0].toString();
	qDebug()<<"1"<<m_addresss[1].toString();

}


void Communicate::writeSettings()
{
	int index = ui.comboBox->currentIndex();
	QSettings settings("Yzs_think", "Application");
	settings.setValue("index", index);
 	
}

void Communicate::readSettings()
{
	QSettings settings("Yzs_think", "Application");
	int index = settings.value("index").toInt();
	ui.comboBox->setCurrentIndex(index);
}

//���˳���ʱ���¼combo��λ��
void Communicate::closeEvent(QCloseEvent *)
{
	writeSettings();
}
