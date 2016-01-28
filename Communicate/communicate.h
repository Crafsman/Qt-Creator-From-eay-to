#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include "ui_communicate.h"
#include <QtGui/QWidget>
#include <QtNetwork/QtNetwork>

class QUdpSocket;

class Communicate : public QWidget
{
	Q_OBJECT

public:
	Communicate(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Communicate();

private:
	Ui::CommunicateClass ui;

	QUdpSocket *udpSocket;

	//����Ϊ�ͻ���
	void setSender();
	//����Ϊ���ն�
	void setReceiver();

	//���������Ϣ
	void getNetCardInfo();

	void getNetCardInfoQt();

	//��¼��Ϣ
	void writeSettings();
	void readSettings();

	struct NetCardInfo
	{
		QString name;
		QString description;
		QString IP;
	};
	std::vector<NetCardInfo> nets;

	std::vector<QHostAddress> m_addresss;


private slots:

	void ChoseClientOrServer();
	//����
   void processPendingDatagram();
   //���Է���
   void on_pushButton_clicked();

   //���õ�ǰ����
   void setCurrentNetCard(int index);

public:
	void closeEvent(QCloseEvent *);

};

#endif // COMMUNICATE_H
