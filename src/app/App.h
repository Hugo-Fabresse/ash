// ash - src/app/App.h

#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QVBoxLayout>

class App : public QWidget {
public:
	App();

private:
	QVBoxLayout mainLayout;
	QWidget topWidget;
	QWidget bottomWidget;
};

#endif // APP_H

