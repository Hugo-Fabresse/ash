// ash - src/app/IconFactory.cpp

#include "IconFactory.h"

#include <QPainter>
#include <QPixmap>
#include <QPolygonF>

QIcon IconFactory::create(const QString &type) {
	QPixmap pixmap(32, 32);
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);

	if (type == "play") {
		painter.setBrush(QColor("#000000"));
		QPolygonF triangle;
		triangle << QPointF(10, 8) << QPointF(10, 24) << QPointF(24, 16);
		painter.drawPolygon(triangle);
	} else if (type == "pause") {
		painter.setBrush(QColor("#000000"));
		painter.drawRect(9, 8, 4, 16);
		painter.drawRect(19, 8, 4, 16);
	} else if (type == "prev") {
		painter.setBrush(QColor("#B3B3B3"));
		painter.drawRect(8, 10, 2, 12);
		QPolygonF triangle;
		triangle << QPointF(24, 10) << QPointF(24, 22) << QPointF(12, 16);
		painter.drawPolygon(triangle);
	} else if (type == "next") {
		painter.setBrush(QColor("#B3B3B3"));
		painter.drawRect(22, 10, 2, 12);
		QPolygonF triangle;
		triangle << QPointF(8, 10) << QPointF(8, 22) << QPointF(20, 16);
		painter.drawPolygon(triangle);
	}

	painter.end();
	return QIcon(pixmap);
}

