#include "kleenestar.h"

KleeneStar::KleeneStar()
{
    //ctor
}

KleeneStar::~KleeneStar()
{
    childExpansion.reset();
}

Expansion * KleeneStar::clone() {
    return new KleeneStar(std::shared_ptr<Expansion>(this->getChild()->clone()));
}

KleeneStar::KleeneStar(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}

const std::string KleeneStar::getText() {
    std::string s = childExpansion->getText();
    s.append("*");
    return s;
}

const ExpansionType KleeneStar::getType() {
    return KLEENE_STAR;
}

const unsigned int KleeneStar::childCount() {
    return hasChild() ? 1 : 0;
}

const bool KleeneStar::hasChild() {
    return childExpansion != nullptr;
}

void KleeneStar::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    childExpansion = newChild;
}

const std::shared_ptr<Expansion> KleeneStar::getChild(const unsigned int index) {
    return childExpansion;
}

void KleeneStar::setChild(std::shared_ptr<Expansion> e) {
    childExpansion.reset();
    childExpansion = e;
}
