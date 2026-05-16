// ash - src/app/App.h

#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPointer>

class App : public QWidget {
public:
	App();

private:
	QPointer<QLabel> artworkLabel;
};

#endif // APP_H

