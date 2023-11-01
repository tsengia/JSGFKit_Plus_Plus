#include "jsgfkitxx/Sequence.hpp"
#include <iostream>
Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{

}

Expansion * Sequence::clone() {
    Sequence * s = new Sequence();
    std::vector<std::shared_ptr<Expansion>> c = this->getChildren();
    for(std::vector<std::shared_ptr<Expansion>>::iterator childIterator = c.begin(); childIterator != c.end(); childIterator++) {
        s->addChild(std::shared_ptr<Expansion>((*childIterator)->clone()));
    }
    return s;
}

void Sequence::addChild(std::shared_ptr<Expansion> e) {
    children.push_back(e);
}

///TODO: Implement this, and probably should be done better
void Sequence::removeChild(Expansion & e) {
    if(std::count(children.begin(), children.end(), std::shared_ptr<Expansion>(&e)) != 0) {
        std::find(children.begin(), children.end(), std::shared_ptr<Expansion>(&e));
    }
}

std::string Sequence::getText() const {
    std::vector<std::shared_ptr<Expansion>>::const_iterator it;
    std::string s = "";
    for(it = children.begin(); it != children.end(); it++) {
        s.append((*it)->getText());
        s.append(" ");
    }
    return s;
}

unsigned int Sequence::childCount() const {
    return distance(children.begin(), children.end());
}

/** Access children
 * \return The current value of children
 */
std::vector<std::shared_ptr<Expansion>> Sequence::getChildren() const {
    return children;
}

bool Sequence::hasChild() const {
    return children.empty();
}

std::shared_ptr<Expansion> Sequence::getChild(const unsigned int index) const {
    return children[index];
}

/**
  * Static Helper function that checks to see if the provided expansion is a sequence, and if it is, checks to see if the Sequence has only one child. If it has only one child, it sets the provided shared_pointer to point to the child Expansion.
  * TLDR; Simplifies singular child Sequence's to singular Expansions
  * \param [in,out] s Expansion that will be simplified if it is a Sequence with 1 child expansion
  */
void Sequence::simplifySequence(std::shared_ptr<Expansion> s) {
    if(s->getType() == SEQUENCE) {
        Sequence * sq = (Sequence*) s.get();
        if(sq->childCount() == 1) { // We have a sequence that has only one child. We need to extract the child, destroy the sequence, and set the expansion to the extracted child
            s = sq->getChild(); // clone() makes a deep copy
        }
        else {
            //Do nothing to s
        }
    }
}

void Sequence::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    children[index] = newChild;
}

ExpansionType Sequence::getType() const {
    return SEQUENCE;
}
