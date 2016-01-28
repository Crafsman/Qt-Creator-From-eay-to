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
	
	//获取网卡信息
	getNetCardInfoQt();

	udpSocket = new QUdpSocket(this);
		
	connect(ui.checkBox_receive, SIGNAL(clicked()), this, SLOT(ChoseClientOrServer()));
	connect(ui.checkBox_sender, SIGNAL(clicked()), this, SLOT(ChoseClientOrServer()));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int )), this, SLOT(setCurrentNetCard(int )));

	//读取上次保存的信息
	readSettings();
}

Communicate::~Communicate()
{

}

void Communicate::ChoseClientOrServer()
{
	//选中是发送端
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

	//拥有等待的数据报
	while(udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		//让datagram的大小为等待处理的数据报的大小，这样才能接受到完整的数据
		datagram.resize(udpSocket->pendingDatagramSize());

		//接受数据报，将其放到datagram中
		udpSocket->readDatagram(datagram.data(), datagram.size());
		ui.receiveLabel->setText(datagram);
		ui.receiveLabel->show();

	}
}

void Communicate::on_pushButton_clicked()
{
	QByteArray datagram = "hello world!";
	//	发送数据报
	//udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
	udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
}

void Communicate::setCurrentNetCard(int index)
{
	//选中状态是发送端，把网卡选项屏蔽，直接退出UDP发送不用设置网卡
// 	if (ui.checkBox->isChecked ())		
// 		setSender();			
// 	else		
// 		setReceiver();	
	
}

void Communicate::getNetCardInfo()
{

#if 0


	//PIP_ADAPTER_INFO结构体指针存储本机网卡信息
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	//得到结构体大小，用于GetAdaptersInfo参数
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	//调用GetAdaptersInfo函数，填充pIpAdapter指针变量，其中stSize参数既是一个输入量也是一个输出量
	int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	//记录网卡数量
	int netCardNum = 0;
	//记录每张网卡上的IP地址数量

	if (ERROR_BUFFER_OVERFLOW == nRel)
	{
		//如果函数返回的是ERROR_BUFFER_OVERFLOW
		//则说明GetAdaptersInfo参数传递的内存空间不够，同时其传出stSize,表示需要的空间大小
		//这也是说明为什么stSize既是一个输入量也是一个输出量
		//释放原来的内存空间
		delete pIpAdapterInfo;
		//重新申请内存空间用来存储所有网卡信息
		pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
		//再次调用GetAdaptersInfo函数，填充pIPAdapterInof指针变量
		nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	}
	if (ERROR_SUCCESS == nRel)
	{
		//输出网卡信息
		//可能有多个网卡，通过循环去判断
		while(pIpAdapterInfo)
		{
			qDebug()<<tr("网卡名称：")<<pIpAdapterInfo->AdapterName<<endl;
			qDebug()<<tr("网卡描述：")<<pIpAdapterInfo->Description<<endl;
			qDebug()<<pIpAdapterInfo->CurrentIpAddress;
			qDebug()<<pIpAdapterInfo->Address;

			NetCardInfo net;
			net.name = pIpAdapterInfo->AdapterName;
			net.description = pIpAdapterInfo->Description;
			ui.comboBox->addItems(QStringList()<<(pIpAdapterInfo->Description));
			nets.push_back(net);

			qDebug()<<tr("网卡MAC地址：");
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

			qDebug()<<tr("网卡IP地址如下：")<<endl;
			//可能网卡有多个IP，循环去判断
			int IPnumPerNetCard = 0;
			IP_ADDR_STRING *pIpAddrString =&(pIpAdapterInfo->IpAddressList);
			do 
			{
				qDebug()<<tr("该网卡上的IP数量： ")<<++IPnumPerNetCard<<endl;
				qDebug()<<tr("IP 地址： ")<<pIpAddrString->IpAddress.String<<endl;
				
				pIpAddrString = pIpAddrString->Next;
			} while (pIpAddrString);
			pIpAdapterInfo = pIpAdapterInfo->Next;
			

		}

	}

	//释放内存空间
	if (pIpAdapterInfo)
	{
		delete pIpAdapterInfo;
	}
#endif
}

void Communicate::getNetCardInfoQt()
{
	//获取所有网络接口的列表
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

	int index = 0;

	//遍历每一个网络接口的列表
	foreach(QNetworkInterface interface, list)
	{
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
// 					//加入到网卡combox中			
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

//在退出的时候记录combo的位置
void Communicate::closeEvent(QCloseEvent *)
{
	writeSettings();
}
