#Makefile for the example ExpansionReplacementTest program.

CC=gcc
CXX=g++
CXXFLAGS=-Wall
JSGF_KIT_CFLAGS=-I/usr/local/include/jsgfkit
JSGF_KIT_LD=-L/usr/local/lib -ljsgfkit

ExpansionReplacementTest: ExpansionReplacementTest.cpp
	$(CXX) $(CXXFLAGS) $(JSGF_KIT_CFLAGS) $< $(JSGF_KIT_LD) -o $@

clean:
	rm ExpansionReplacementTest

