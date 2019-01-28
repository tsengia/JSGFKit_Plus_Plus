#include "grammar.h"
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
    <action> = face {face_tag} | move {move_tag} | fire laser {fire_tag};\
    <direction> = left | right | up | down;\
    ";

    cout << "Parsing example Grammar..." << endl;
    Grammar * g = Grammar::parseGrammarFromString(s);

    cout << "Parsed:" << endl;
    cout << g->getText() << endl; // Grammar::getText returns a JSGF text to define the grammar

    cout << "Type in a query and see if it matches one of the rules:";
    string response;
    getline(cin, response); // Get an input test string from the user

    MatchList results = g->matchesRule(g->getRule("command"), response); // Match the test string against the command

    if(results.empty()) { // If the results list is empty, then it doesn't match the rule
        cout << "Your response doesn't match the <command> Rule!" << endl;
    }
    else {
        cout << "Your response matched the <command> Rule!" << endl;
        cout << "Matching tags: ";
        vector<string> tags = Grammar::getMatchingTags(results); // Get a vector/list of the tags that this test string matched
        for(string s : tags) { // Print them out
            cout << s << ", ";
        }
    }

    delete g; // Always remember to delete objects made on the heap!
    return 0;
}
