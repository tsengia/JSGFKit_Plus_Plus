#include "plusoperator.h"

PlusOperator::PlusOperator()
{
    //ctor
}

PlusOperator::PlusOperator(shared_ptr<Expansion> e)
{
    childExpansion = e;
}

PlusOperator::~PlusOperator()
{
    childExpansion.reset();
}

Expansion * PlusOperator::clone() {
    return new PlusOperator(shared_ptr<Expansion>(this->getChild()->clone()));
}

string PlusOperator::getText() {
    string s = childExpansion->getText();
    s.append("+");
    return s;
}
