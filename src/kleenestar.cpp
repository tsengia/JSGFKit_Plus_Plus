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

std::string KleeneStar::getText() {
    std::string s = childExpansion->getText();
    s.append("*");
    return s;
}

ExpansionType KleeneStar::getType() {
    return KLEENE_STAR;
}

unsigned int KleeneStar::childCount() {
    return hasChild() ? 1 : 0;
}

bool KleeneStar::hasChild() {
    return childExpansion != nullptr;
}

void KleeneStar::replaceChild(std::shared_ptr<Expansion> newChild, unsigned long index) {
    childExpansion = newChild;
}

std::shared_ptr<Expansion> KleeneStar::getChild(unsigned int index) {
    return childExpansion;
}

void KleeneStar::setChild(std::shared_ptr<Expansion> e) {
    childExpansion.reset();
    childExpansion = e;
}
