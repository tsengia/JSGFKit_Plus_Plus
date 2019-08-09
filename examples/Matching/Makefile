#Makefile for the example Matching test program.

CC=gcc
CXX=g++
CXXFLAGS=-Wall
JSGF_KIT_CFLAGS=-I/usr/local/include/jsgfkit
JSGF_KIT_LD=-L/usr/local/lib -ljsgfkit

Matching: Matching.cpp
	$(CXX) $(CXXFLAGS) $(JSGF_KIT_CFLAGS) $< $(JSGF_KIT_LD) -o $@

clean:
	rm Matching

