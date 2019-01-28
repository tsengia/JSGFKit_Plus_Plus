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
    return new OptionalGrouping(this->getChild()->clone());
}

OptionalGrouping::OptionalGrouping(Expansion * e) {
    childExpansion = shared_ptr<Expansion>(e);
}

string OptionalGrouping::getText() {
    string s = "[";
    s.append(childExpansion->getText());
    s.append("]");
    return s;
}
