// ash - src/spotify_controller/SpotifyController.h

#ifndef SPOTIFYCONTROLLER_H
#define SPOTIFYCONTROLLER_H

#include <QDBusInterface>
#include <memory>

class SpotifyController {

public:
	SpotifyController();

	void playPause();
	void next();
	void previous();

private:

	std::unique_ptr<QDBusInterface> dbus;
};

#endif // SPOTIFYCONTROLLER_H

