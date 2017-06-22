# Taktix-Engine
A 2D engine written in C++ using SFML.
# Installation
### Linux
First, you will need to have some libraries installed :

* pthread
* opengl
* xlib
* xrandr
* udev
* freetype
* jpeg
* openal
* flac
* vorbis
* sfml

Once these libraries are installed, just go to the Build/ folder :

`cd Build`

Then you can generate the Makefile using CMake :

`cmake ..`

Finally just compile the project using the Makefile :

`make Taktix`

If everything went fine, you can run the project using :

`./Taktix`

Done !
