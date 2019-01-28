#include <iostream>
#include "grammar.h"

using namespace std;

int main()
{
    string a;
    string s = "\
    grammar test-gram;\
    public <command> = hello         {greeting} {hi} there; \
    <yolo> = [blarg | (rarg | hraaanngggg)];\
    <test> = hi {greeting} how are (you {you} | they {others}) today;\
    ";
    Grammar * g = Grammar::parseGrammarFromString(s);
    cout << "PARSED GRAMMAR:" << endl;
    cout << g->getText() << endl;

    cout << "Rule Match Testing..." << endl;
    getline(cin, a);
    cout << a << endl;
    shared_ptr<Rule> r = g->getMatchingRule(a);
    if(r) {
        cout << "Matched rule: " << r->getRuleName() << endl;
        cout << "Matching tags:" << endl;

        vector<string> t = Grammar::getMatchingTags(g->matchesRule(r, a));
        for(string s : t) {
            cout << "T:" << s << endl;
        }
    }
    else {
        cout << "Found no match!" << endl;
    }


    delete g;
    cout << "Test Done" << endl;
    return 0;
}
