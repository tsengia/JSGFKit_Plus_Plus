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

ExpansionType UnparsedSection::getType()  { return UNPARSED_SECTION; }
