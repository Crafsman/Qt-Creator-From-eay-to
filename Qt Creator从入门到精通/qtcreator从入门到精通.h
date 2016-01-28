#ifndef QTCREATOR_______H
#define QTCREATOR_______H

#include <QtGui/QMainWindow>
#include "ui_qtcreator从入门到精通.h"

class QtCreator从入门到精通 : public QMainWindow
{
	Q_OBJECT

public:
	QtCreator从入门到精通(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtCreator从入门到精通();

private:
	Ui::QtCreator从入门到精通Class ui;
};

#endif // QTCREATOR_______H
