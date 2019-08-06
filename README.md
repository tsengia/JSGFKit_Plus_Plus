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

## WARNING
This project is still under heavy development! There are many issues (more testing, memory management, runtime errors, etc.).
You can see progress in the "bugfix" branch, but building and using code from the bugfix branch is not recommended as it may not compile and/or still have runtime errors. Just stick to the master branch.

