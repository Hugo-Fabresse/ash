// ash - src/app/App.cpp

#include "App.h"
#include "IconFactory.h"

#include <QHBoxLayout>
#include <QNetworkReply>
#include <QPainter>
#include <QPainterPath>
#include <QVBoxLayout>

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

	connect(&timer, &QTimer::timeout, this, &App::updateMetadata);
	timer.start(500);
}

void App::setupWindow() {
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setFixedSize(220, 340);
}

void App::setupArtwork(QWidget *parent) {
	artworkLabel = new QLabel(parent);
	artworkLabel->setObjectName("artworkLabel");
	artworkLabel->setFixedSize(190, 190);

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
	timeLabel->setObjectName("timeLabel");
	progressBar = new QSlider(Qt::Horizontal, parent);
	durationLabel = new QLabel("0:00", parent);
	durationLabel->setObjectName("durationLabel");

	progressLayout->addWidget(timeLabel);
	progressLayout->addWidget(progressBar, 1);
	progressLayout->addWidget(durationLabel);

	bottomLayout->addLayout(progressLayout);
}

void App::setupControls(QWidget *parent) {
	QHBoxLayout *controlsLayout = new QHBoxLayout();
	controlsLayout->setSpacing(0);
	controlsLayout->setContentsMargins(0, 15, 0, 0);

	prevBtn = new QPushButton(parent);
	prevBtn->setObjectName("prevBtn");
	prevBtn->setFixedSize(50, 50);
	prevBtn->setIconSize(QSize(32, 32));
	prevBtn->setIcon(IconFactory::create("prev"));

	playBtn = new QPushButton(parent);
	playBtn->setObjectName("playBtn");
	playBtn->setFixedSize(64, 64);
	playBtn->setIconSize(QSize(32, 32));
	playBtn->setIcon(IconFactory::create("play"));

	nextBtn = new QPushButton(parent);
	nextBtn->setObjectName("nextBtn");
	nextBtn->setFixedSize(50, 50);
	nextBtn->setIconSize(QSize(32, 32));
	nextBtn->setIcon(IconFactory::create("next"));

	controlsLayout->addWidget(prevBtn);
	controlsLayout->addStretch();
	controlsLayout->addWidget(playBtn);
	controlsLayout->addStretch();
	controlsLayout->addWidget(nextBtn);

	QVBoxLayout *parentLayout = qobject_cast<QVBoxLayout*>(parent->layout());
	if (parentLayout) {
		parentLayout->addLayout(controlsLayout);
	}

	connect(playBtn, &QPushButton::clicked, [this]() { controller.playPause(); });
	connect(prevBtn, &QPushButton::clicked, [this]() { controller.previous(); });
	connect(nextBtn, &QPushButton::clicked, [this]() { controller.next(); });
}

void App::updateMetadata() {
	qint64 position = metadata.getPosition() / 1000000;
	qint64 duration = metadata.getDuration() / 1000000;

	progressBar->setMaximum(duration);
	progressBar->setValue(position);

	timeLabel->setText(QString("%1:%2").arg(position / 60).arg(position % 60, 2, 10, QChar('0')));
	durationLabel->setText(QString("%1:%2").arg(duration / 60).arg(duration % 60, 2, 10, QChar('0')));

	QString status = metadata.getPlaybackStatus();
	if (status == "Playing") {
		playBtn->setIcon(IconFactory::create("pause"));
	} else {
		playBtn->setIcon(IconFactory::create("play"));
	}

	QString artUrl = metadata.getArtUrl();
	if (artUrl != currentArtUrl) {
		currentArtUrl = artUrl;
		QNetworkReply *reply = networkManager.get(QNetworkRequest(QUrl(artUrl)));
		connect(reply, &QNetworkReply::finished, [this, reply]() {
			QPixmap pixmap;
			pixmap.loadFromData(reply->readAll());
			QPixmap scaled = pixmap.scaled(190, 190, Qt::KeepAspectRatio, Qt::SmoothTransformation);

			QPixmap rounded(190, 190);
			rounded.fill(Qt::transparent);
			QPainter painter(&rounded);
			painter.setRenderHint(QPainter::Antialiasing);
			QPainterPath path;
			path.addRoundedRect(0, 0, 190, 190, 12, 12);
			painter.setClipPath(path);
			painter.drawPixmap(0, 0, scaled);
			painter.end();

			artworkLabel->setPixmap(rounded);
			reply->deleteLater();
		});
	}
}

