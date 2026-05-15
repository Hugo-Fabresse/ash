// ash - src/spotify_controller/SpotifyController.cpp

#include "SpotifyController.h"

SpotifyController::SpotifyController() {
	dbus = std::make_unique<QDBusInterface>("org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player");
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

