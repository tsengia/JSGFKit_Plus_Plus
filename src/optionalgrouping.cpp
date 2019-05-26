#include "optionalgrouping.h"

OptionalGrouping::OptionalGrouping()
{
    //ctor
}

OptionalGrouping::~OptionalGrouping()
{
    childExpansion.reset();
}

Expansion * OptionalGrouping::clone() {
    return new OptionalGrouping(std::shared_ptr<Expansion>(this->getChild()->clone()));
}

OptionalGrouping::OptionalGrouping(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}

const std::string OptionalGrouping::getText() {
    std::string s = "[";
    s.append(childExpansion->getText());
    s.append("]");
    return s;
}

const ExpansionType OptionalGrouping::getType() {
    return OPTIONAL_GROUPING;
}

const unsigned int OptionalGrouping::childCount() {
    return hasChild() ? 1 : 0;
}

void OptionalGrouping::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

const bool OptionalGrouping::hasChild() {
    return childExpansion != nullptr;
}

const std::shared_ptr<Expansion> OptionalGrouping::getChild(const unsigned int index) {
    return childExpansion;
}

void OptionalGrouping::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
