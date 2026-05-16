// ash - src/app/IconFactory.h

#ifndef ICONFACTORY_H
#define ICONFACTORY_H

#include <QIcon>
#include <QString>

class IconFactory {
public:
	static QIcon create(const QString &type);
};

#endif // ICONFACTORY_H

