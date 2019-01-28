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
    return new KleeneStar(shared_ptr<Expansion>(this->getChild()->clone()));
}

KleeneStar::KleeneStar(shared_ptr<Expansion> e) {
    childExpansion = e;
}

string KleeneStar::getText() {
    string s = childExpansion->getText();
    s.append("*");
    return s;
}

ExpansionType KleeneStar::getType() {
    return KLEENE_STAR;
}

bool KleeneStar::hasChild() {
    return childExpansion != nullptr;
}

shared_ptr<Expansion> KleeneStar::getChild() {
    return childExpansion;
}

void KleeneStar::setChild(shared_ptr<Expansion> e) {
    childExpansion.reset();
    childExpansion = e;
}
