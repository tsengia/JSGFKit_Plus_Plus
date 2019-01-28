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
    return new OptionalGrouping(shared_ptr<Expansion>(this->getChild()->clone()));
}

OptionalGrouping::OptionalGrouping(shared_ptr<Expansion> e) {
    childExpansion = e;
}

string OptionalGrouping::getText() {
    string s = "[";
    s.append(childExpansion->getText());
    s.append("]");
    return s;
}

ExpansionType OptionalGrouping::getType() {
    return OPTIONAL_GROUPING;
}

bool OptionalGrouping::hasChild() {
    return childExpansion != nullptr;
}

shared_ptr<Expansion> OptionalGrouping::getChild() {
    return childExpansion;
}

void OptionalGrouping::setChild(shared_ptr<Expansion> e) {
    childExpansion = e;
}
