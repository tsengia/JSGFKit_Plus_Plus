#include "grammar.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

    string s = "grammar matching-test;\
    public <command> = <action> <direction>;\
    <action> = face {face_tag} | move {move_tag} | fire laser {fire_tag};\
    <direction> = left | right | up | down;\
    ";

    cout << "Parsing example Grammar..." << endl;
    Grammar * g = Grammar::parseGrammarFromString(s);

    cout << "Parsed:" << endl;
    cout << g->getText() << endl;

    cout << "Type in a query and see if it matches one of the rules:";
    string response;
    getline(cin, response);
    list<shared_ptr<MatchInfo>> results = g->matchesRule(g->getRule("command"), response);
    if(results.empty()) {
        cout << "Your response doesn't match any of the rules!" << endl;
    }
    else {
        cout << "Your reponse matched the <command> Rule!" << endl;
        cout << "Matching tags: ";
        vector<string> tags = Grammar::getMatchingTags(results);
        for(string s : tags) {
            cout << s << ", ";
        }
    }
    return 0;
}
