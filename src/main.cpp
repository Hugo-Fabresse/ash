#include <QCoreApplication>
#include "spotify/spotify_metadata/SpotifyMetadata.h"

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	SpotifyMetadata metadata;
	qDebug() << metadata.getTitle();
	return 0;
}

