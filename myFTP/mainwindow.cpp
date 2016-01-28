#include "mainwindow.h"
#include <QtNetwork/QFtp>

#pragma comment(lib, "QtNetworkd4.lib")

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ftp = new QFtp(this);
	//使用指定的端口号连接到FTP服务器主机，默认端口号是21
	ftp->connectToHost("ftp.qt.nokia.com");
	//使用指定的用户名和密码登陆到FTP服务器，
	ftp->login();
	//cd改变服务器中的工作目录到指定的目录
	ftp->cd("qt");

	//get从服务器下载指定的文件
	ftp->get("INSTALL");
	//关闭到FTP服务器的连接
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
		ui.label->setText(tr("正在连接到服务器...."));
		break;
	case QFtp::Login:
		ui.label->setText(tr("正在登陆...."));
		break;
	case QFtp::Get:
		ui.label->setText(tr("正在下载...."));
		break;
	case QFtp::Close:
		ui.label->setText(tr("正在关闭连接...."));
	
	}
}

void MainWindow::ftpCommandFinished(int, bool error)
{
	if (ftp->currentCommand() == QFtp::ConnectToHost)
	{
		if (error)
		{
			ui.label->setText(tr("连接服务器出现错误：%1").arg(ftp->errorString()));
			
		}
		else
		{
			ui.label->setText(tr("连接到服务费成功"));
		}
	}
	else if (ftp->currentCommand() == QFtp::Login)
	{
		if (error)
			ui.label->setText(tr("登陆出现错误：%1").arg(ftp->errorString()));
		else
			ui.label->setText(tr("登陆成功"));
		
	}
	else if (ftp->currentCommand() == QFtp::Get)
	{
		if (error)
			ui.label->setText(tr("下载出现错误：%1").arg(ftp->errorString()));
		else
		{
			ui.label->setText(tr("已经完成下载"));
			ui.textBrowser->setText(ftp->readAll());
		}
			
	}else if (ftp->currentCommand() == QFtp::Close)
	{
		ui.label->setText(tr("已经关闭连接"));
	}

}
