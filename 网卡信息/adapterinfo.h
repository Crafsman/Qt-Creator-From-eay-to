#ifndef ADAPTERINFO_H
#define ADAPTERINFO_H

#include <QtGui/QMainWindow>
#include "ui_adapterinfo.h"

class AdapterInfo : public QMainWindow
{
	Q_OBJECT

public:
	AdapterInfo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AdapterInfo();
	void GetAdaptInfo();
private:
	Ui::AdapterInfoClass ui;

private slots:
	void on_pushButton_clicked();
};

#endif // ADAPTERINFO_H
