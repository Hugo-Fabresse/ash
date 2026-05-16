// ash - src/app/App.cpp

#include "App.h"

App::App() : QWidget() {
	setupWindow();

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);

	QWidget *topWidget = new QWidget(this);
	QWidget *bottomWidget = new QWidget(this);
	mainLayout->addWidget(topWidget);
	mainLayout->addWidget(bottomWidget);

	setupArtwork(topWidget);
	setupProgress(bottomWidget);
	setupControls(bottomWidget);
}

void App::setupWindow() {
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setFixedSize(220, 340);
}

void App::setupArtwork(QWidget *parent) {
	artworkLabel = new QLabel(parent);
	artworkLabel->setFixedSize(190, 190);
	artworkLabel->setStyleSheet("background: #282828; border-radius: 12px;");

	QVBoxLayout *topLayout = new QVBoxLayout(parent);
	topLayout->setContentsMargins(15, 15, 15, 12);
	topLayout->addWidget(artworkLabel, 0, Qt::AlignCenter);
}

void App::setupProgress(QWidget *parent) {
	QVBoxLayout *bottomLayout = new QVBoxLayout(parent);
	bottomLayout->setContentsMargins(20, 10, 20, 25);
	bottomLayout->setSpacing(8);

	QHBoxLayout *progressLayout = new QHBoxLayout();
	progressLayout->setSpacing(10);

	timeLabel = new QLabel("0:00", parent);
	progressBar = new QSlider(Qt::Horizontal, parent);
	durationLabel = new QLabel("0:00", parent);

	progressLayout->addWidget(timeLabel);
	progressLayout->addWidget(progressBar, 1);
	progressLayout->addWidget(durationLabel);

	bottomLayout->addLayout(progressLayout);
}

void App::setupControls(QWidget *parent) {
	QHBoxLayout *controlsLayout = new QHBoxLayout();
	controlsLayout->setSpacing(0);
	controlsLayout->setContentsMargins(0, 15, 0, 0);

	prevBtn = new QPushButton("⏮", parent);
	playBtn = new QPushButton("⏯", parent);
	nextBtn = new QPushButton("⏭", parent);

	controlsLayout->addWidget(prevBtn);
	controlsLayout->addStretch();
	controlsLayout->addWidget(playBtn);
	controlsLayout->addStretch();
	controlsLayout->addWidget(nextBtn);

	// Add to parent's existing layout
	QVBoxLayout *parentLayout = qobject_cast<QVBoxLayout*>(parent->layout());
	if (parentLayout) {
		parentLayout->addLayout(controlsLayout);
	}
}
