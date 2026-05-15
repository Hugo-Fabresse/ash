#include <QCoreApplication>
#include "spotify_controller/SpotifyController.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    SpotifyController controller;
    controller.playPause();
    return 0;
}

