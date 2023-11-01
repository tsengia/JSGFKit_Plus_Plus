#include "jsgfkitxx/Rule.hpp"
#include "jsgfkitxx/Grammar.hpp"

Rule::Rule()
{
    //ctor
}

Rule::Rule(std::string n, bool visible, std::shared_ptr<Expansion> e)
{
    name = n;
    isVisible = visible;
    ruleExpansion = e;
}

Rule::~Rule()
{
    ruleExpansion.reset();
}

std::string Rule::getRuleString() const {
    if(isVisible) {
        return Grammar::trimString("public <" + name + "> = " + ruleExpansion->getText()) + ";";
    }
    else {
        return Grammar::trimString("<" + name + "> = " + ruleExpansion->getText()) + ";";
    }

}
