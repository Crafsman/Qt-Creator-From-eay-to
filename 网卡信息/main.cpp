#include "adapterinfo.h"
#include <QtGui/QApplication>
#include <QTextCodec>


#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "QtNetworkd4.lib")
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	AdapterInfo w;
	w.GetAdaptInfo();
	w.show();
	return a.exec();
}
