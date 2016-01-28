#include "adapterinfo.h"
#include <WinSock2.h>
#include <IPHlpApi.h>
#include <QDebug>
#include <stdio.h>

AdapterInfo::AdapterInfo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

AdapterInfo::~AdapterInfo()
{

}

void AdapterInfo::GetAdaptInfo()
{
	//PIP_ADAPTER_INFO�ṹ��ָ��洢����������Ϣ
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	//�õ��ṹ���С������GetAdaptersInfo����
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	//����GetAdaptersInfo���������pIpAdapterָ�����������stSize��������һ��������Ҳ��һ�������
	int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	//��¼��������
	int netCardNum = 0;
	//��¼ÿ�������ϵ�IP��ַ����
	int IPnumPerNetCard = 0;
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
			qDebug()<<tr("����������")<<++netCardNum<<endl;
			qDebug()<<tr("�������ƣ�")<<pIpAdapterInfo->AdapterName<<endl;
			qDebug()<<tr("����������")<<pIpAdapterInfo->Description<<endl;
			//ui.comboBox->insertItems(0, QStringList()
			//	<<QApplication::translate("AdapterinfoClass", pIpAdapterInfo->Description, 0, QApplication::UnicodeUTF8));
			ui.comboBox->addItems(QStringList()<<(pIpAdapterInfo->Description));
// 				comboBox->clear();
// 			comboBox->insertItems(0, QStringList()
// 				<< QApplication::translate("AdapterInfoClass", "1", 0, QApplication::UnicodeUTF8)
// 				<< QApplication::translate("AdapterInfoClass", "2", 0, QApplication::UnicodeUTF8)
// 				<< QApplication::translate("AdapterInfoClass", "3", 0, QApplication::UnicodeUTF8)

			switch(pIpAdapterInfo->Type)
			{
			case MIB_IF_TYPE_OTHER:
				qDebug()<<tr("�������ͣ�")<<"OTHER"<<endl;
				break;
			case MIB_IF_TYPE_ETHERNET:
				qDebug()<<tr("�������ͣ�")<<"ETHERNET"<<endl;
				break;
			case MIB_IF_TYPE_TOKENRING:
				qDebug()<<tr("�������ͣ�")<<"TOKENRING"<<endl;
				break;
			case MIB_IF_TYPE_FDDI:
				qDebug()<<tr("�������ͣ�")<<"FDDI"<<endl;
				break;
			case MIB_IF_TYPE_PPP:
				qDebug()<<tr("�������ͣ�")<<"PPP"<<endl;
				break;
			case MIB_IF_TYPE_LOOPBACK:
				qDebug()<<tr("�������ͣ�")<<"LOOPBACK"<<endl;
				break;
			case MIB_IF_TYPE_SLIP:
				qDebug()<<tr("�������ͣ�")<<"SLIP"<<endl;
				break;
			}

			qDebug()<<tr("����MAC��ַ��");
			for (DWORD i = 0; i < pIpAdapterInfo->AddressLength; i++)
			{
				if (i < pIpAdapterInfo->AddressLength -1)
				{
					printf("%02x-", pIpAdapterInfo->Address[i]);
					qDebug()<<pIpAdapterInfo->Address[i]<<endl;
				}
				else
				{
					printf("%02x\n", pIpAdapterInfo->Address[i]);
						qDebug()<<pIpAdapterInfo->Address[i]<<endl;
						//_itoa();
					
				}
			}

			qDebug()<<tr("����IP��ַ���£�")<<endl;
			//���������ж��IP��ѭ��ȥ�ж�
			IP_ADDR_STRING *pIpAddrString =&(pIpAdapterInfo->IpAddressList);
			do 
			{
				qDebug()<<tr("�������ϵ�IP������ ")<<++IPnumPerNetCard<<endl;
				qDebug()<<tr("IP ��ַ�� ")<<pIpAddrString->IpAddress.String<<endl;
				qDebug()<<tr("������ַ�� ")<<pIpAddrString->IpMask.String<<endl;
				qDebug()<<tr("���ص�ַ�� ")<<pIpAdapterInfo->GatewayList.IpAddress.String<<endl;
				pIpAddrString = pIpAddrString->Next;
			} while (pIpAddrString);
			pIpAdapterInfo = pIpAdapterInfo->Next;
			qDebug()<<"_________________________________________";

		}

	}

	//�ͷ��ڴ�ռ�
	if (pIpAdapterInfo)
	{
		delete pIpAdapterInfo;
	}

	
}

void AdapterInfo::on_pushButton_clicked()
{

}
