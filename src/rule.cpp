#include "rule.h"
#include "grammar.h"

Rule::Rule()
{
    //ctor
}

Rule::Rule(string n, bool visible, shared_ptr<Expansion> e)
{
    name = n;
    isVisible = visible;
    ruleExpansion = e;
}

Rule::~Rule()
{
    ruleExpansion.reset();
}

string Rule::getRuleString() {
    if(isVisible) {
        return Grammar::trimString("public <" + name + "> = " + ruleExpansion->getText()) + ";";
    }
    else {
        return Grammar::trimString("<" + name + "> = " + ruleExpansion->getText()) + ";";
    }

}
