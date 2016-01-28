#include "receiver.h"
#include <QtNetwork/QtNetwork>

Receiver::Receiver(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	receiver = new QUdpSocket(this);
	receiver->bind(45454, QUdpSocket::ShareAddress);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
}

Receiver::~Receiver()
{

}

void Receiver::processPendingDatagram()
{
	//ӵ�еȴ������ݱ�
	while(receiver->hasPendingDatagrams())
	{
		QByteArray datagram;
		//��datagram�Ĵ�СΪ�ȴ���������ݱ��Ĵ�С���������ܽ��ܵ�����������
		datagram.resize(receiver->pendingDatagramSize());

		//�������ݱ�������ŵ�datagram��
		receiver->readDatagram(datagram.data(), datagram.size());
		ui.label->setText(datagram);

	}
}
