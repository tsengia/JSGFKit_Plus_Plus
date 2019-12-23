# JSGFKit_Plus_Plus
A static cross-platform library for parsing, generating, manipulating, and matching strings against JSGF grammars.
This is a C++ port of the Java JSGFKit with a few additional features.

## Building
JSGF Kit++ can use both the `autotools` buildsystem and CMake.
To build the static library with `autotools`, simply enter the directory and run:

    ./configure
    make -j 4
    sudo make install

Remember that `make -j <number of threads>` lets you set the number of threads you want to run at a time for a faster build.

If you would like to build with CMake, simply enter the directory and run:  

    cmake CMakeLists.txt
    make -j 4
    sudo make install
 
## Linking and Including
To include and link against the JSGF Kit++ static library, use `pkg-config`:

    pkg-config --libs --cflags jsgfkit

## Windows
To compile on Windows, install CMake and run `cmake CMakeLists.txt` from the command line in the source directory to generate the Visual Studio project files to compile with.

## Documentation
Doxygen documentation comments are in the code, to generate HTML documentation files from it, run `doxygen Doxyfile` and the html docs will be outputted into the `docs` subdirectory.

## Example programs
It is highly suggested to test to make sure compilation and installation completed successfully. A few example programs come with this library and can be found in the `examples` subdirectory.  
To build an example program, `cd` into its directory and simply run `make`.  
If compilation complains about missing headers or undefined references, you will probably need to adjust the `JSGF_KIT_LD` and `JSGF_KIT_CFLAGS` variables in the `Makefile` to point to the correct library path and include directories (just run `pkg-config --cflags jsgfkit` and `pkg-config --libs jsgfkit` and copy the output in).

## Purpose
The original purpose of this program was to manipulate JSGF grammars for use with the CMU pocketsphinx toolkit, which has a built in JSGF parser that transforms JSGF grammars into finite state grammars (FSGs), but in the process the Tag unary operator is lost. These tags provide valuable context information when matching speaker/user input against command grammars, and this library solves the issue by allowing the program to match the resulting string from cmu sphinx against a grammar and returning the matching tags. This library also provides methods of easily manipulating grammars and dynamically generating them.
