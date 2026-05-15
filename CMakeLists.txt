cmake_minimum_required(VERSION 3.16)
project(ash)

find_package(Qt6 REQUIRED COMPONENTS Core DBus)

add_executable(ash
    src/main.cpp
    src/spotify_controller/SpotifyController.cpp
)

target_link_libraries(ash Qt6::Core Qt6::DBus)

