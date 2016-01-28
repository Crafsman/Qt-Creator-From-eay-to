#include "communicate.h"
#include <QtGui/QApplication>
#include <QTextCodec>

#pragma comment(lib, "Iphlpapi.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	Communicate w;
	w.show();
	return a.exec();
}
