// ash - src/main.cpp

#include "app/App.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
	QApplication myApp(argc, argv);

	QFile styleFile("../src/style.qss");
	if (styleFile.open(QFile::ReadOnly)) {
		myApp.setStyleSheet(styleFile.readAll());
	}

	App app;
	app.show();
	return myApp.exec();
}

