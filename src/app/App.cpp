// ash - src/app/APP.cpp

#include "App.h"

App::App() : QWidget() {
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setFixedSize(220, 340);

	mainLayout.setContentsMargins(0, 0, 0, 0);
	mainLayout.setSpacing(0);
	mainLayout.addWidget(&topWidget);
	mainLayout.addWidget(&bottomWidget);
	setLayout(&mainLayout);
}

