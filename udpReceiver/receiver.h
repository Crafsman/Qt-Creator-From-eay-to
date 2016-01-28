#ifndef RECEIVER_H
#define RECEIVER_H

#include <QtGui/QDialog>
#include "ui_receiver.h"

class QUdpSocket;

class Receiver : public QDialog
{
	Q_OBJECT

public:
	Receiver(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Receiver();

private:
	Ui::ReceiverClass ui;

	QUdpSocket *receiver;
	//
private slots:
	void processPendingDatagram();
};

#endif // RECEIVER_H
