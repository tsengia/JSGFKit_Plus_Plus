#include "sequence.h"
#include <iostream>
Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{
    std::list<std::shared_ptr<Expansion>>::iterator it = children.begin();
    while(it != children.end()) {
        it->reset();
        it++;
    }
}

Expansion * Sequence::clone() {
    Sequence * s = new Sequence();
    std::list<std::shared_ptr<Expansion>> c = this->getChildren();
    for(std::list<std::shared_ptr<Expansion>>::iterator childIterator = c.begin(); childIterator != c.end(); childIterator++) {
        s->addChild(std::shared_ptr<Expansion>((*childIterator)->clone()));
    }
    return s;
}

void Sequence::addChild(std::shared_ptr<Expansion> e) {
    children.push_back(e);
}

void Sequence::removeChild(Expansion & e) {
    children.remove(std::make_shared<Expansion>(e));
}

std::string Sequence::getText() {
    std::list<std::shared_ptr<Expansion>>::iterator it;
    std::string s = "";
    for(it = children.begin(); it != children.end(); it++) {
        s.append((*it)->getText());
        s.append(" ");
    }
    return s;
}

unsigned int Sequence::childCount() {
    return distance(children.begin(), children.end());
}

/** Access children
 * \return The current value of children
 */
std::list<std::shared_ptr<Expansion>> Sequence::getChildren() {
    return children;
}

bool Sequence::hasChild() {
    return children.empty();
}

std::shared_ptr<Expansion> Sequence::getChild() {
    return children.front();
}

/**
  * Static Helper function that checks to see if the provided expansion is a sequence, and if it is, checks to see if the Sequence has only one child. If it has only one child, it sets the provided shared_pointer to point to the child Expansion.
  * TLDR; Simplifies singular child Sequence's to singular Expansions
  * \param [in,out] s Expansion that will be simplified if it is a Sequence with 1 child expansion
  */
void Sequence::simplifySequence(std::shared_ptr<Expansion> s) {
    if(typeid(*s) == typeid(Sequence)) {
        Sequence * sq = (Sequence*) s.get();
        if(sq->childCount() == 1) { // We have a sequence that has only one child. We need to extract the child, destroy the sequence, and set the expansion to the extracted child
            s = sq->getChild(); // clone() makes a deep copy
        }
        else {
            //Do nothing to s
        }
    }
}

ExpansionType Sequence::getType() {
    return SEQUENCE;
}
