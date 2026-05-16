// ash - src/app/App.h

#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPointer>

class App : public QWidget {
public:
	App();

private:
	QPointer<QLabel> artworkLabel;
	QPointer<QLabel> timeLabel;
	QPointer<QLabel> durationLabel;
	QPointer<QSlider> progressBar;
};

#endif // APP_H

