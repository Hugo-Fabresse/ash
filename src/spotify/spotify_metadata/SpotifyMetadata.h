// ash - src/spotify/spotify_metadata/SpotifyMetadata.h

#ifndef SPOTIFYMETADATA_H
#define SPOTIFYMETADATA_H

#include <QDBusInterface>
#include <QVariant>

#include <memory>

class SpotifyMetadata {
public:
	SpotifyMetadata();

	QString getTitle();

private:
	QVariantMap fetchMetadata();

	std::unique_ptr<QDBusInterface> dbus;
};

#endif // SPOTIFYMETADATA_H

