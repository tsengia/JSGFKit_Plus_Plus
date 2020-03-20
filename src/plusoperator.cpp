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

std::string PlusOperator::getText() const {
    std::string s = childExpansion->getText();
    s.append("+");
    return s;
}

ExpansionType PlusOperator::getType() const {
    return PLUS_OPERATOR;
}

unsigned int PlusOperator::childCount() const {
    return hasChild() ? 1 : 0;
}

bool PlusOperator::hasChild() const {
    return childExpansion != nullptr;
}

bool PlusOperator::isOptional() const {
	if(this->hasChild()) {
		return this->getChild(0)->isOptional();
	}
	return false;
}

void PlusOperator::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

std::shared_ptr<Expansion> PlusOperator::getChild(const unsigned int index) const {
    return childExpansion;
}

void PlusOperator::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
