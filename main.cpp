#include <iostream>
#include "grammar.h"

using namespace std;

int main()
{
    string a;
    string s = "#JSGF v1.0;\
grammar sphinx-mode;\
public <command> = <pause> {pause} | <resume> {resume} | <push-to-talk> {push-to-talk} | <toggle> {toggle};\
<pause> = pause speech recognition;\
<resume> = resume speech recognition;\
<toggle> = toggle speech recognition;\
<push-to-talk> = ((enable | enter | begin | start) {enable} | (disable | exit | end | stop) {disable}) push to talk [mode];";
    Grammar g;
    Grammar::parseGrammarFromString(s, g);
    cout << "PARSED GRAMMAR:" << endl;
    cout << g.getText() << endl;

    cout << "Rule Match Testing..." << endl;
    getline(cin, a);
    cout << a << endl;
    /*
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
*/

    cout << "Test Done" << endl;
    return 0;
}
