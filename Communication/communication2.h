#ifndef COMMUNICATION2_H
#define COMMUNICATION2_H

#include <QtGui/QMainWindow>
#include "ui_communication2.h"

class Communication2 : public QMainWindow
{
	Q_OBJECT

public:
	Communication2(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Communication2();

	 void getNetCardInfoQt();

private:
	Ui::Communication2Class ui;
};

#endif // COMMUNICATION2_H
