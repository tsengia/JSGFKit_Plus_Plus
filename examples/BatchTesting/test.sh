#!/bin/bash

echo "JSGF Kit++ Batch Grammar Tester"
if [ ! -f ParseAndOutputJSGF ]; then
	echo "ERROR: Please build and copy the ParseAndOutputJSGF example program into this directory!"
	exit -2;
fi

for g in test_grammars/*/*; do
	./ParseAndOutputJSGF $g &> grammar_test.log
	if [ ! $? -eq 0 ]; then
		echo "Test failed on grammar: $g ! Logged to grammar_test.log"
		exit -1;
	fi
done

echo "Tests passed!"