#include "alternativeset.h"

AlternativeSet::AlternativeSet()
{
    //ctor
}

AlternativeSet::~AlternativeSet()
{
    std::list<std::shared_ptr<Expansion>>::iterator it = expansions.begin();
    while(it != expansions.end()) {
        (*it).reset();
        it++;
    }
}

Expansion * AlternativeSet::clone() {
    AlternativeSet * aset = new AlternativeSet();
    std::list<std::shared_ptr<Expansion>> c = this->getChildren();
    for(std::list<std::shared_ptr<Expansion>>::iterator childIterator = c.begin(); childIterator != c.end(); childIterator++) {
        aset->addChild(std::shared_ptr<Expansion>((*childIterator)->clone()));
    }
    return aset;
}

unsigned short AlternativeSet::childCount() {
    return distance(expansions.begin(), expansions.end());
}

std::list<std::shared_ptr<Expansion>> AlternativeSet::getChildren() {
    return expansions;
}

std::shared_ptr<Expansion> AlternativeSet::getChild() {
    return (*expansions.begin());
}

ExpansionType AlternativeSet::getType() {
    return ALTERNATE_SET;
}

bool AlternativeSet::hasChild() {
    return expansions.empty();
}

void AlternativeSet::addChild(std::shared_ptr<Expansion> e) {
    expansions.push_back(e);
}

void AlternativeSet::removeChild(Expansion & e) {
    expansions.remove(std::shared_ptr<Expansion>(&e));
}

std::string AlternativeSet::getText() {
    //TODO: Implement weights

    std::list<std::shared_ptr<Expansion>>::iterator it = expansions.begin();
    std::string s;
    while(it != expansions.end()) {
        s.append((*it)->getText());
        s.append(" | ");
        it++;
    }

    return s.substr(0, s.size() - 3);
}
