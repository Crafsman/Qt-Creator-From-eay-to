#include "sender.h"
#include <QtNetwork/QtNetwork>

Sender::Sender(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	sender = new QUdpSocket(this);

}

Sender::~Sender()
{

}

void Sender::on_pushButton_clicked()
{
	QByteArray datagram = "hello world!";
    //	发送数据报
	sender->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
}
