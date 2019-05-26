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

const std::string RequiredGrouping::getText() {
    std::string s = "(";
    s.append(childExpansion->getText());
    s.append(")");
    return s;
}

const ExpansionType RequiredGrouping::getType() {
    return REQUIRED_GROUPING;
}

const unsigned int RequiredGrouping::childCount() {
    return hasChild() ? 1 : 0;
}

const bool RequiredGrouping::hasChild() {
    return childExpansion != nullptr;
}

void RequiredGrouping::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

const std::shared_ptr<Expansion> RequiredGrouping::getChild(const unsigned int index) {
    return childExpansion;
}

void RequiredGrouping::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
