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
