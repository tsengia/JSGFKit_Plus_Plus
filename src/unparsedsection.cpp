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

std::string UnparsedSection::getSection() {
    return section;
}

void UnparsedSection::setSection(std::string s) {
    section = s;
}

bool UnparsedSection::hasChild() {
    return false;
}

unsigned int UnparsedSection::childCount() {
    return 0;
}

std::shared_ptr<Expansion> UnparsedSection::getChild() {
    return nullptr;
}

std::string UnparsedSection::getText() {
    return "UNPARSED SECTION:" + section;
}

ExpansionType UnparsedSection::getType()  { return UNPARSED_SECTION; }
