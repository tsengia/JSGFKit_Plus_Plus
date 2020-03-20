#include <iostream>
#include "grammar.h"

using namespace std;

/**
  * \file IsOptionalTest.cpp
  * A simple program that tests to see if the user specified rule is optional or not.
  */

int main(int argc, char *argv[])
{
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
		cerr << "Please specify the grammar file!" << endl;
		return -1;
	}

    //Generate a text version of our Grammar object
    //cout << "PARSED GRAMMAR:" << endl;
    //cout << g.getText() << endl << endl;

    string test;
    getline(cin,test);

    shared_ptr<Rule> r = g.getRule(test);
    if(r != nullptr) {
	string s = r->getRuleExpansion()->isOptional() ? "optional" : "required";
        cout << s << endl;
    }
    else {
       cerr << "Could not find rule: "<< test << "!" << endl;
       return -1;
    }

    return 0;
}
