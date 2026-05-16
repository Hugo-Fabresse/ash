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

	QVBoxLayout *bottomLayout = new QVBoxLayout(bottomWidget);
	bottomLayout->setContentsMargins(20, 10, 20, 25);
	bottomLayout->setSpacing(8);

	QHBoxLayout *progressLayout = new QHBoxLayout();
	progressLayout->setSpacing(10);

	timeLabel = new QLabel("0:00", bottomWidget);
	progressBar = new QSlider(Qt::Horizontal, bottomWidget);
	durationLabel = new QLabel("0:00", bottomWidget);

	progressLayout->addWidget(timeLabel);
	progressLayout->addWidget(progressBar, 1);
	progressLayout->addWidget(durationLabel);

	bottomLayout->addLayout(progressLayout);
}

