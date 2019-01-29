#include "rulereference.h"

RuleReference::RuleReference(std::string ruleN)
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

std::string RuleReference::getText() {
    return "<" + ruleName + ">";
}

/** Access ruleName;
* \return The current value of ruleName;
*/
std::string RuleReference::getRuleName() {
    return ruleName;
}

/** Set ruleName;
* \param val New value to set
*/
void RuleReference::setRuleName(std::string val) {
    ruleName = val;
}

bool RuleReference::hasChild() {
    return false;
}

std::shared_ptr<Expansion> RuleReference::getChild() {
    return nullptr;
}

ExpansionType RuleReference::getType() {
    return RULE_REFERENCE;
}
