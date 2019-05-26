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

std::string RuleReference::getText() const {
    return "<" + ruleName + ">";
}

/** Access ruleName;
* \return The current value of ruleName;
*/
std::string RuleReference::getRuleName() const {
    return ruleName;
}

/** Set ruleName;
* \param val New value to set
*/
void RuleReference::setRuleName(std::string val) {
    ruleName = val;
}

bool RuleReference::hasChild() const {
    return false;
}

unsigned int RuleReference::childCount() const {
    return 0;
}

std::shared_ptr<Expansion> RuleReference::getChild(const unsigned int index) const {
    return nullptr;
}

void RuleReference::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    // Do nothing cause there are no children
}

ExpansionType RuleReference::getType() const {
    return RULE_REFERENCE;
}
