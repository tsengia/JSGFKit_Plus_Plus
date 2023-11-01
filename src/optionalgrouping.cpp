#include "jsgfkitxx/OptionalGrouping.hpp"

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

std::string OptionalGrouping::getText() const {
    std::string s = "[";
    s.append(childExpansion->getText());
    s.append("]");
    return s;
}

ExpansionType OptionalGrouping::getType() const {
    return OPTIONAL_GROUPING;
}

unsigned int OptionalGrouping::childCount() const {
    return hasChild() ? 1 : 0;
}

void OptionalGrouping::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

bool OptionalGrouping::hasChild() const {
    return childExpansion != nullptr;
}

std::shared_ptr<Expansion> OptionalGrouping::getChild(const unsigned int index) const {
    return childExpansion;
}

void OptionalGrouping::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
