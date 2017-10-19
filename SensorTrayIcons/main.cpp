#include "SensorTrayIcons.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CSensorTrayIcons w;
	w.show();
	return a.exec();
}
