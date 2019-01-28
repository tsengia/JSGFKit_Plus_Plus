#include <iostream>
#include "grammar.h"

using namespace std;

/**
  * \file ParseAndOutputJSGF.cpp
  * A simple program that shows how to parse a JSGF string to create a new Grammar object and then generate JSGF text using that Grammar object.
  */

int main()
{
    // string that we will be parsing to create a JSGF Grammar object
    string s = "\
    grammar test-gram;\
    public <command> = hello         {greeting} {hi} there; \
    <yolo> = [blarg | (rarg | hraaanngggg)];\
    <test> = hi {greeting} how are (you {you} | they {others}) today;\
    ";
    //Parsing the string to create a Grammar object
    Grammar * g = Grammar::parseGrammarFromString(s);

    //Generate the JSGF definitiopn for the public command Rule
    cout << "Generating <command> Rule:" << endl;
    cout << g->getRule("command")->getRuleString() << endl << endl;;

    //Generate a text version of our Grammar object
    cout << "PARSED GRAMMAR:" << endl;
    cout << g->getText() << endl << endl;

    delete g; // Created on the free store to remember to clean it up!
    cout << "Test Done" << endl;
    cout << "Press enter to exit" << endl;
    getline(cin, s);
    return 0;
}
