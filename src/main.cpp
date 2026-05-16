#include <QApplication>
#include "app/App.h"

int main(int argc, char *argv[]) {
	QApplication myApp(argc, argv);
	App app;

	app.show();
	return myApp.exec();
}

