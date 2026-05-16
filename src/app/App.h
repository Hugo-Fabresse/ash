// ash - src/app/App.h

#ifndef APP_H
#define APP_H

#include "spotify/spotify_controller/SpotifyController.h"
#include "spotify/spotify_metadata/SpotifyMetadata.h"

#include <QLabel>
#include <QNetworkAccessManager>
#include <QPointer>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QWidget>

class App : public QWidget {
public:
	App();

private:
	void setupWindow();
	void setupArtwork(QWidget *parent);
	void setupProgress(QWidget *parent);
	void setupControls(QWidget *parent);
	void updateMetadata();

	QPointer<QLabel> artworkLabel;
	QPointer<QLabel> timeLabel;
	QPointer<QLabel> durationLabel;
	QPointer<QSlider> progressBar;
	QPointer<QPushButton> prevBtn;
	QPointer<QPushButton> playBtn;
	QPointer<QPushButton> nextBtn;

	SpotifyController controller;
	SpotifyMetadata metadata;
	QTimer timer;
	QNetworkAccessManager networkManager;
	QString currentArtUrl;
};

#endif // APP_H

