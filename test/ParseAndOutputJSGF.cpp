#include <iostream>
#include "jsgfkitxx/Grammar.hpp"

using namespace std;

/**
  * \file ParseAndOutputJSGF.cpp
  * A simple program that shows how to parse a JSGF string to create a new Grammar object and then generate JSGF text using that Grammar object.
  *	You can either use it with no command line options and it will use a built in sample grammar.
  * It can also open up a file given via the command line, parse it, and echo it.
  */

int main(int argc, char *argv[])
{
    // string that we will be parsing to create a JSGF Grammar object
    string s = "\
    grammar test-gram;\
    public <command> = hello         {greeting} {hi} there; \
    <yolo> = [blarg | (rarg | hraaanngggg)];\
    <test> = hi {greeting} how are (you {you} | they {others}) today;\
    ";
	Grammar g;
	if(argc > 1) {
		std::ifstream inputFile;
		inputFile.open(argv[1]);
		if(inputFile.good()) {
			Grammar::parseGrammar(inputFile, g);
		}
	}
	else {
		//Parsing the string to create a Grammar object
		Grammar::parseGrammarFromString(s, g);
	}

    //Generate a text version of our Grammar object
    cout << "PARSED GRAMMAR:" << endl;
    cout << g.getText() << endl << endl;

    cout << "Test Done" << endl;
    return 0;
}
