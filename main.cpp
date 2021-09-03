#include <QtWidgets/QApplication>
#include "Gen_pow_Qt.h"

int main(int argc, char* argv[])
{
	qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1"); // to fix high dpi problem
	QApplication a(argc, argv);
	Gen_pow_Qt w;
	w.show();
	return a.exec();
	//Gen_power window;
}