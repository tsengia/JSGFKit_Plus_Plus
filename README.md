# JSGFKit_Plus_Plus
A C++ port of the Java JSGFKit with a few additional features.

## Building
JSGF Kit++ uses the `autotools` buildsystem.  
To build the static library, simply enter the directory and run:
	./configure
	make -j 4
	make install

Remember that `make -j <number of threads>` lets you set the number of threads you want to run at a time for a faster build.

## Linking and Including
To include and link against the JSGF Kit++ static library, use `pkg-config`:
	pkg-config --libs --cflags jsgfkit


