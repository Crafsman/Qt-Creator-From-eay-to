#ifndef SENDER_H
#define SENDER_H

#include <QtGui/QDialog>
#include "ui_sender.h"
class QUdpSocket;

class Sender : public QDialog
{
	Q_OBJECT

public:
	Sender(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Sender();

private:
	Ui::SenderClass ui;
	QUdpSocket *sender;

private slots:
	void on_pushButton_clicked();
};

#endif // SENDER_H
