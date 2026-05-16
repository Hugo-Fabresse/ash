// ash - src/spotify/spotify_controller/SpotifyController.cpp

#include "SpotifyController.h"

#include <QtLogging>

SpotifyController::SpotifyController() {
	dbus = std::make_unique<QDBusInterface>("org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player");
	if (!dbus->isValid()) {
		qWarning() << "Error: Spotify is not running.";
	}
}

void SpotifyController::playPause() {
	dbus->call("PlayPause");
}

void SpotifyController::next() {
	dbus->call("Next");
}

void SpotifyController::previous() {
	dbus->call("Previous");
}

