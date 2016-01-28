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
	//拥有等待的数据报
	while(receiver->hasPendingDatagrams())
	{
		QByteArray datagram;
		//让datagram的大小为等待处理的数据报的大小，这样才能接受到完整的数据
		datagram.resize(receiver->pendingDatagramSize());

		//接受数据报，将其放到datagram中
		receiver->readDatagram(datagram.data(), datagram.size());
		ui.label->setText(datagram);

	}
}
