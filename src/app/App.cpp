// ash - src/app/App.cpp

#include "App.h"

App::App() : QWidget() {
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setFixedSize(220, 340);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);

	QWidget *topWidget = new QWidget(this);
	QWidget *bottomWidget = new QWidget(this);
	mainLayout->addWidget(topWidget);
	mainLayout->addWidget(bottomWidget);

	artworkLabel = new QLabel(topWidget);
	artworkLabel->setFixedSize(190, 190);
	artworkLabel->setStyleSheet("background: #282828; border-radius: 12px;");

	QVBoxLayout *topLayout = new QVBoxLayout(topWidget);
	topLayout->setContentsMargins(15, 15, 15, 12);
	topLayout->addWidget(artworkLabel, 0, Qt::AlignCenter);
}

