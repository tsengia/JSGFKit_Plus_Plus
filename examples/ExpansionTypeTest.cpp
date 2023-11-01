#include "Grammar.hpp"
#include "Expansion.hpp"

#include <iostream>
#include <string>

using namespace std;

void testCall(Expansion * e) {
    cout << e->getText() << endl;
    if(e->getType() == TOKEN) {
        cout << "TOEKN" << endl;
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
