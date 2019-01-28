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
