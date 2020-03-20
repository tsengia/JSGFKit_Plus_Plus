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

if [ ! -f jsgfmatch ]; then
	if [ -f ../jsgfmatch ]; then
		cp ../jsgfmatch jsgfmatch
	else
		echo "ERROR: Please build and copy the jsgfmatch example program into this directory!"
		exit -2;
	fi
fi
if [ ! -f optionaltest ]; then
	if [ -f ../optionaltest ]; then
		cp ../optionaltest optionaltest
	else
		echo "ERROR: Please build and copy the optionaltest example program into this directory!"
		exit -2;
	fi
fi


echo "Running parsing tests..."
for g in grammars/*/*; do
	./parsetest $g &> grammar_test.log
	if [ ! $? -eq 0 ]; then
		echo "Test failed on grammar: $g ! Logged to grammar_test.log"
		exit -1;
	fi
done

echo "Running optional detection tests..."
while IFS=, read -r grammar rule expectedResult
do
	a=$( echo $rule | ./optionaltest $grammar )
	if [ "$a" != "$expectedResult" ]; then
		echo "For grammar $grammar , the \"$rule\" rule was declared \"$a\", but \"$expectedResult\" was expected!"
		exit -1;
	fi
done < optional_test.csv

echo "Running matching tests..."
echo "Testing rules..."
while IFS=, read -r grammar inputTest expectedResult
do
	a=$( echo $inputTest | ./jsgfmatch -r -f $grammar )
	if [ "$a" != "$expectedResult" ]; then
		echo "For grammar $grammar , input of \"$inputTest\" produced \"$a\", but \"$expectedResult\" was expected!"
		exit -1;
	fi
done < rules_test.csv

echo "Tests passed!"
