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

const std::string RuleReference::getText() {
    return "<" + ruleName + ">";
}

/** Access ruleName;
* \return The current value of ruleName;
*/
const std::string RuleReference::getRuleName() {
    return ruleName;
}

/** Set ruleName;
* \param val New value to set
*/
void RuleReference::setRuleName(std::string val) {
    ruleName = val;
}

const bool RuleReference::hasChild() {
    return false;
}

const unsigned int RuleReference::childCount() {
    return 0;
}

const std::shared_ptr<Expansion> RuleReference::getChild(const unsigned int index) {
    return nullptr;
}

void RuleReference::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    // Do nothing cause there are no children
}

const ExpansionType RuleReference::getType() {
    return RULE_REFERENCE;
}
