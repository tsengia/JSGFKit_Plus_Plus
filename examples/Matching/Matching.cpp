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
    bool done = false;
    while(!done) {
        cout << "Type in a query and see if it matches one of the rules:";
        string response;
        getline(cin, response); // Get an input test string from the user

        MatchResult result = g.match(response); // Match the test string against the command

        if(!result.matches) { // If no match
            cout << "Your response doesn't match the <command> Rule!" << endl;
        }
        else {
            cout << "Your response matched the <" << result.getMatchingRule()->getRuleName() << "> Rule!" << endl;
            cout << "Matching tags: ";
            vector<string> tags = result.getMatchingTags(); // Get a vector/vector of the tags that this test string matched
            for(string s : tags) { // Print them out
                cout << s << ", ";

                if(s == "quit_tag") {
		    cout << endl;
                    done = true;
                    break;
                }
            }
	    cout << endl;
        }
    }

    return 0;
}
