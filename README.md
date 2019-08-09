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

## Documentation
Doxygen documentation comments are in the code, to generate HTML documentation files from it, run `doxygen Doxyfile` and the html docs will be outputted into the `docs` subdirectory.

## Example programs
It is highly suggested to test to make sure compilation and installation completed successfully. A few example programs come with this library and can be found in the `examples` subdirectory.  
To build an example program, `cd` into its directory and simply run `make`.  
If compilation complains about missing headers or undefined references, you will probably need to adjust the `JSGF_KIT_LD` and `JSGF_KIT_CFLAGS` variables in the `Makefile` to point to the correct library path and include directories (just run `pkg-config --cflags jsgfkit` and `pkg-config --libs jsgfkit` and copy the output in).
