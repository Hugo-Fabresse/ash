// ash - src/app/APP.cpp

#include "App.h"

App::App() : QWidget() {
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setFixedSize(220, 340);
}

