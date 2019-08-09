#Makefile for the example ExpansionTypeTest program.

CC=gcc
CXX=g++
CXXFLAGS=-Wall
JSGF_KIT_CFLAGS=-I/usr/local/include/jsgfkit
JSGF_KIT_LD=-L/usr/local/lib -ljsgfkit

ExpansionTypeTest: ExpansionTypeTest.cpp
	$(CXX) $(CXXFLAGS) $(JSGF_KIT_CFLAGS) $< $(JSGF_KIT_LD) -o $@

clean:
	rm ExpansionTypeTest