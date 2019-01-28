#include "requiredgrouping.h"

RequiredGrouping::RequiredGrouping()
{
    //ctor
}

RequiredGrouping::RequiredGrouping(Expansion * e)
{
    childExpansion = shared_ptr<Expansion>(e);
}

RequiredGrouping::~RequiredGrouping()
{
    childExpansion.reset();
}

Expansion * RequiredGrouping::clone() {
    return new RequiredGrouping(this->getChild()->clone());
}

string RequiredGrouping::getText() {
    string s = "(";
    s.append(childExpansion->getText());
    s.append(")");
    return s;
}
