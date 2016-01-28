#include "mainwindow.h"
#include <QtNetwork/QFtp>

#pragma comment(lib, "QtNetworkd4.lib")

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ftp = new QFtp(this);
	//ʹ��ָ���Ķ˿ں����ӵ�FTP������������Ĭ�϶˿ں���21
	ftp->connectToHost("ftp.qt.nokia.com");
	//ʹ��ָ�����û����������½��FTP��������
	ftp->login();
	//cd�ı�������еĹ���Ŀ¼��ָ����Ŀ¼
	ftp->cd("qt");

	//get�ӷ���������ָ�����ļ�
	ftp->get("INSTALL");
	//�رյ�FTP������������
	ftp->close();
	connect(ftp, SIGNAL(commandStarted(int)), this, SLOT(ftpCommandStarted(int)));
	connect(ftp, SIGNAL(commandFinished(int)), this, SLOT(ftpCommandFinished(int)));
	
}

MainWindow::~MainWindow()
{

}

void MainWindow::ftpCommandStarted(int)
{
	int id = ftp->currentCommand();
	switch(id)
	{
	case QFtp::ConnectToHost:
		ui.label->setText(tr("�������ӵ�������...."));
		break;
	case QFtp::Login:
		ui.label->setText(tr("���ڵ�½...."));
		break;
	case QFtp::Get:
		ui.label->setText(tr("��������...."));
		break;
	case QFtp::Close:
		ui.label->setText(tr("���ڹر�����...."));
	
	}
}

void MainWindow::ftpCommandFinished(int, bool error)
{
	if (ftp->currentCommand() == QFtp::ConnectToHost)
	{
		if (error)
		{
			ui.label->setText(tr("���ӷ��������ִ���%1").arg(ftp->errorString()));
			
		}
		else
		{
			ui.label->setText(tr("���ӵ�����ѳɹ�"));
		}
	}
	else if (ftp->currentCommand() == QFtp::Login)
	{
		if (error)
			ui.label->setText(tr("��½���ִ���%1").arg(ftp->errorString()));
		else
			ui.label->setText(tr("��½�ɹ�"));
		
	}
	else if (ftp->currentCommand() == QFtp::Get)
	{
		if (error)
			ui.label->setText(tr("���س��ִ���%1").arg(ftp->errorString()));
		else
		{
			ui.label->setText(tr("�Ѿ��������"));
			ui.textBrowser->setText(ftp->readAll());
		}
			
	}else if (ftp->currentCommand() == QFtp::Close)
	{
		ui.label->setText(tr("�Ѿ��ر�����"));
	}

}
