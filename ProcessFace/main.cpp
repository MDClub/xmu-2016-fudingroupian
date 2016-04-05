#include "processface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProcessFace w;
	//w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
	w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint);
	w.show();
	return a.exec();
}
