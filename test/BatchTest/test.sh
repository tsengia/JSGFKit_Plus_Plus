#!/bin/bash

echo "JSGF Kit++ Batch Grammar Tester"
if [ ! -f parsetest ]; then
	if [ -f ../parsetest ]; then
		cp ../parsetest parsetest
	else
		echo "ERROR: Please build and copy the parsetest example program into this directory!"
		exit -2;
	fi
fi

for g in grammars/*/*; do
	./parsetest $g &> grammar_test.log
	if [ ! $? -eq 0 ]; then
		echo "Test failed on grammar: $g ! Logged to grammar_test.log"
		exit -1;
	fi
done

echo "Tests passed!"
