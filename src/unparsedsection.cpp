#include "unparsedsection.h"
#include <iostream>
UnparsedSection::UnparsedSection()
{
    //ctor
}

UnparsedSection::UnparsedSection(string s)
{
    section = s;
}

UnparsedSection::~UnparsedSection()
{

}

Expansion * UnparsedSection::clone() {
    return new UnparsedSection(this->getSection());
}

string UnparsedSection::getSection() {
    return section;
}

void UnparsedSection::setSection(string s) {
    section = s;
}

bool UnparsedSection::hasChild() {
    return false;
}

shared_ptr<Expansion> UnparsedSection::getChild() {
    return nullptr;
}

string UnparsedSection::getText() {
    return "UNPARSED SECTION:" + section;
}

ExpansionType UnparsedSection::getType()  { return UNPARSED_SECTION; }
