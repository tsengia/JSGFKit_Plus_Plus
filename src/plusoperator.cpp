#include "plusoperator.h"

PlusOperator::PlusOperator()
{
    //ctor
}

PlusOperator::PlusOperator(std::shared_ptr<Expansion> e)
{
    childExpansion = e;
}

PlusOperator::~PlusOperator()
{
    childExpansion.reset();
}

Expansion * PlusOperator::clone() {
    return new PlusOperator(std::shared_ptr<Expansion>(this->getChild()->clone()));
}

std::string PlusOperator::getText() {
    std::string s = childExpansion->getText();
    s.append("+");
    return s;
}

ExpansionType PlusOperator::getType() {
    return PLUS_OPERATOR;
}

unsigned int PlusOperator::childCount() {
    return hasChild() ? 1 : 0;
}

bool PlusOperator::hasChild() {
    return childExpansion != nullptr;
}

void PlusOperator::replaceChild(std::shared_ptr<Expansion> newChild, unsigned long index) {
    childExpansion = newChild;
}

std::shared_ptr<Expansion> PlusOperator::getChild(unsigned int index) {
    return childExpansion;
}

void PlusOperator::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
