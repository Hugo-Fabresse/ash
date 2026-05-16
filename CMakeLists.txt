cmake_minimum_required(VERSION 3.16)
project(ash)

find_package(Qt6 REQUIRED COMPONENTS Core DBus Widgets)

add_executable(ash
	src/main.cpp
	src/app/App.cpp
	src/spotify/spotify_controller/SpotifyController.cpp
	src/spotify/spotify_metadata/SpotifyMetadata.cpp
)

target_link_libraries(ash Qt6::Core Qt6::DBus Qt6::Widgets)

