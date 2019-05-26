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

const std::string PlusOperator::getText() {
    std::string s = childExpansion->getText();
    s.append("+");
    return s;
}

const ExpansionType PlusOperator::getType() {
    return PLUS_OPERATOR;
}

const unsigned int PlusOperator::childCount() {
    return hasChild() ? 1 : 0;
}

const bool PlusOperator::hasChild() {
    return childExpansion != nullptr;
}

void PlusOperator::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

const std::shared_ptr<Expansion> PlusOperator::getChild(const unsigned int index) {
    return childExpansion;
}

void PlusOperator::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
