#include "jsgfkitxx/Grammar.hpp"
#include "jsgfkitxx/Expansion.hpp"

#include <iostream>
#include <string>

using namespace std;

void testCall(Expansion * e) {
    cout << e->getText() << endl;
    if(e->getType() == TOKEN) {
        cout << "TOKEN" << endl;
    }
}

int main() {
    cout << "sa" << endl;
    Grammar g;
    Grammar::parseGrammarFromString("grammar test;\
                                    public <r> = one;", g);
    cout << "s" << endl;
    g.walkGrammar(testCall);
    return 0;
}
