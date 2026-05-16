# ash

a bare spotify pip controller. what's left when you burn everything else away.

## what it does

frameless floating widget. album art, playback controls, progress bar. nothing else.

communicates with spotify via d-bus / mpris. no daemon, no config, no bloat.

## dependencies

- qt6 (widgets, dbus, network)
- a running spotify instance

## build

```bash
mkdir build && cd build
cmake ..
make
```

## usage

```bash
ash
```

## controls

play/pause, next, previous. all from the widget.

