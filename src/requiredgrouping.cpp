#include "jsgfkitxx/RequiredGrouping.hpp"

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

std::string RequiredGrouping::getText() const {
    std::string s = "(";
    s.append(childExpansion->getText());
    s.append(")");
    return s;
}

ExpansionType RequiredGrouping::getType() const {
    return REQUIRED_GROUPING;
}

unsigned int RequiredGrouping::childCount() const {
    return hasChild() ? 1 : 0;
}

bool RequiredGrouping::hasChild() const {
    return childExpansion != nullptr;
}

void RequiredGrouping::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

std::shared_ptr<Expansion> RequiredGrouping::getChild(const unsigned int index) const {
    return childExpansion;
}

void RequiredGrouping::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
