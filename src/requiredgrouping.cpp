#include "requiredgrouping.h"

RequiredGrouping::RequiredGrouping()
{
    //ctor
}

RequiredGrouping::RequiredGrouping(std::shared_ptr<Expansion> e)
{
    childExpansion = e;
}

RequiredGrouping::~RequiredGrouping()
{
    childExpansion.reset();
}

Expansion * RequiredGrouping::clone() {
    return new RequiredGrouping(std::shared_ptr<Expansion>(this->getChild()->clone()));
}

std::string RequiredGrouping::getText() {
    std::string s = "(";
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

std::shared_ptr<Expansion> RequiredGrouping::getChild() {
    return childExpansion;
}

void RequiredGrouping::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
