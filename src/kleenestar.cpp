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

bool KleeneStar::hasChild() {
    return childExpansion != nullptr;
}

std::shared_ptr<Expansion> KleeneStar::getChild() {
    return childExpansion;
}

void KleeneStar::setChild(std::shared_ptr<Expansion> e) {
    childExpansion.reset();
    childExpansion = e;
}
