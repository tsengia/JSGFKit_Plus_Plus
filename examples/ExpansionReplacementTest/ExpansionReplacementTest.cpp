#include "Grammar.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
  * \file
  * An example that shows how to match test string against Rules and extract the tags that the input matched.
  * Functions used: Grammar::matchesRule(), Grammar::getMatchingTags()
  *
  */

int main() {
    // A string representing the grammar that we will be using.
    string s = "grammar matching-test;\
    public <command> = <action> <direction>;\
    <action> = face {face_tag} | move {move_tag} | fire laser {fire_tag} | quit {quit_tag};\
    <direction> = left | right | up | down;\
    ";

    cout << "Parsing example Grammar..." << endl;
    Grammar g;
    Grammar::parseGrammarFromString(s, g);

    cout << "Parsed:" << endl;
    cout << g.getText() << endl; // Grammar::getText returns a JSGF text to define the grammar

    cout << "Replacing the 'laser' token with fire (laser | water gun | engines)..." << endl;

    shared_ptr<AlternativeSet> replacement(new AlternativeSet());
    replacement->addChild(shared_ptr<Expansion>(new Token("laser")));
    replacement->addChild(shared_ptr<Expansion>(new Token("water gun")));
    replacement->addChild(shared_ptr<Expansion>(new Token("engines")));

    g.getRule("action")->getRuleExpansion()->getChild(2)->getChild(1)->replaceChild(replacement, 1);

    cout << endl << "New grammar:" << endl;
    cout << g.getText() << endl;

    return 0;
}
