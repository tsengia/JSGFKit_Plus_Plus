#include "rulereference.h"

RuleReference::RuleReference(string ruleN)
{
    ruleName = ruleN;
}

RuleReference::~RuleReference()
{
    //dtor
}

Expansion * RuleReference::clone() {
    return new RuleReference(this->getRuleName());
}

string RuleReference::getText() {
    return "<" + ruleName + ">";
}

/** Access ruleName;
* \return The current value of ruleName;
*/
string RuleReference::getRuleName() {
    return ruleName;
}

/** Set ruleName;
* \param val New value to set
*/
void RuleReference::setRuleName(string val) {
    ruleName = val;
}

bool RuleReference::hasChild() {
    return false;
}

shared_ptr<Expansion> RuleReference::getChild() {
    return nullptr;
}

ExpansionType RuleReference::getType() {
    return RULE_REFERENCE;
}
