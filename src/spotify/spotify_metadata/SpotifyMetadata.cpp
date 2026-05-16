// ash - src/spotify/spotify_metadata/SpotifyMetadata.cpp

#include "SpotifyMetadata.h"

#include <QDBusArgument>
#include <QDBusMessage>
#include <QDBusVariant>
#include <QtLogging>

SpotifyMetadata::SpotifyMetadata() {
	dbus = std::make_unique<QDBusInterface>("org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.freedesktop.DBus.Properties");
	if (!dbus->isValid()) {
		qWarning() << "Error: Spotify is not running.";
	}
}

QVariantMap SpotifyMetadata::fetchMetadata() {
	QDBusMessage reply = dbus->call("Get", "org.mpris.MediaPlayer2.Player", "Metadata");
	QDBusVariant dbusVariant = reply.arguments().at(0).value<QDBusVariant>();
	const QDBusArgument &arg = dbusVariant.variant().value<QDBusArgument>();
	QVariantMap map;
	arg >> map;
	return map;
}

QString SpotifyMetadata::getTitle() {
	return fetchMetadata()["xesam:title"].toString();
}

QString SpotifyMetadata::getPlaybackStatus() {
	QDBusMessage reply = dbus->call("Get", "org.mpris.MediaPlayer2.Player", "PlaybackStatus");
	return reply.arguments().at(0).value<QDBusVariant>().variant().toString();
}

qint64 SpotifyMetadata::getPosition() {
	QDBusMessage reply = dbus->call("Get", "org.mpris.MediaPlayer2.Player", "Position");
	return reply.arguments().at(0).value<QDBusVariant>().variant().toLongLong();
}

qint64 SpotifyMetadata::getDuration() {
	return fetchMetadata()["mpris:length"].toLongLong();
}

QString SpotifyMetadata::getArtUrl() {
	return fetchMetadata()["mpris:artUrl"].toString();
}

