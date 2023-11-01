#include "jsgfkitxx/UnparsedSection.hpp"
#include <iostream>

UnparsedSection::UnparsedSection()
{
    //ctor
}

UnparsedSection::UnparsedSection(std::string s)
{
    section = s;
}

UnparsedSection::~UnparsedSection()
{

}

Expansion * UnparsedSection::clone() {
    return new UnparsedSection(this->getSection());
}

std::string UnparsedSection::getSection() const {
    return section;
}

void UnparsedSection::setSection(std::string s) {
    section = s;
}

bool UnparsedSection::hasChild() const {
    return false;
}

unsigned int UnparsedSection::childCount() const {
    return 0;
}

std::shared_ptr<Expansion> UnparsedSection::getChild(const unsigned int index) const {
    return nullptr;
}

void UnparsedSection::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    // Do nothing cause there are no children
}

std::string UnparsedSection::getText() const {
    return "UNPARSED SECTION:" + section;
}

ExpansionType UnparsedSection::getType() const { return UNPARSED_SECTION; }
