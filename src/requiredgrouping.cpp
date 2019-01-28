#include "requiredgrouping.h"

RequiredGrouping::RequiredGrouping()
{
    //ctor
}

RequiredGrouping::RequiredGrouping(shared_ptr<Expansion> e)
{
    childExpansion = e;
}

RequiredGrouping::~RequiredGrouping()
{
    childExpansion.reset();
}

Expansion * RequiredGrouping::clone() {
    return new RequiredGrouping(shared_ptr<Expansion>(this->getChild()->clone()));
}

string RequiredGrouping::getText() {
    string s = "(";
    s.append(childExpansion->getText());
    s.append(")");
    return s;
}

ExpansionType RequiredGrouping::getType() {
    return REQUIRED_GROUPING;
}

bool RequiredGrouping::hasChild() {
    return childExpansion != nullptr;
}

shared_ptr<Expansion> RequiredGrouping::getChild() {
    return childExpansion;
}

void RequiredGrouping::setChild(shared_ptr<Expansion> e) {
    childExpansion = e;
}
