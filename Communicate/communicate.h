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

	//设置为客户端
	void setSender();
	//设置为接收端
	void setReceiver();

	//获得网卡信息
	void getNetCardInfo();

	void getNetCardInfoQt();

	//记录信息
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
	//处理
   void processPendingDatagram();
   //测试发送
   void on_pushButton_clicked();

   //设置当前网卡
   void setCurrentNetCard(int index);

public:
	void closeEvent(QCloseEvent *);

};

#endif // COMMUNICATE_H
