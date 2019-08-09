#include "grammar.h"
#include "expansion.h"

#include <iostream>
#include <string>

using namespace std;

void testCall(Expansion * e) {
    cout << Grammar::printExpansionType(e) << ":" << e->getText() << endl;
}

int main() {
    Grammar g;
    Grammar::parseGrammarFromString("grammar test;\
                                    public <r> = one;", g);
    g.walkGrammar(testCall);
    return 0;
}
