// ash - src/app/App.h

#ifndef APP_H
#define APP_H

#include <QLabel>
#include <QPointer>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

class App : public QWidget {
public:
	App();

private:
	void setupWindow();
	void setupArtwork(QWidget *parent);
	void setupProgress(QWidget *parent);
	void setupControls(QWidget *parent);

	QPointer<QLabel> artworkLabel;
	QPointer<QLabel> timeLabel;
	QPointer<QLabel> durationLabel;
	QPointer<QSlider> progressBar;
	QPointer<QPushButton> prevBtn;
	QPointer<QPushButton> playBtn;
	QPointer<QPushButton> nextBtn;
};

#endif // APP_H

