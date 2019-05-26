#include "unparsedsection.h"
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

const std::string UnparsedSection::getSection() {
    return section;
}

void UnparsedSection::setSection(std::string s) {
    section = s;
}

const bool UnparsedSection::hasChild() {
    return false;
}

const unsigned int UnparsedSection::childCount() {
    return 0;
}

const std::shared_ptr<Expansion> UnparsedSection::getChild(const unsigned int index) {
    return nullptr;
}

void UnparsedSection::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    // Do nothing cause there are no children
}

const std::string UnparsedSection::getText() {
    return "UNPARSED SECTION:" + section;
}

const ExpansionType UnparsedSection::getType()  { return UNPARSED_SECTION; }
