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

std::string OptionalGrouping::getText() {
    std::string s = "[";
    s.append(childExpansion->getText());
    s.append("]");
    return s;
}

ExpansionType OptionalGrouping::getType() {
    return OPTIONAL_GROUPING;
}

unsigned int OptionalGrouping::childCount() {
    return hasChild() ? 1 : 0;
}

bool OptionalGrouping::hasChild() {
    return childExpansion != nullptr;
}

std::shared_ptr<Expansion> OptionalGrouping::getChild(unsigned int index) {
    return childExpansion;
}

void OptionalGrouping::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
