#include "alternativeset.h"

AlternativeSet::AlternativeSet()
{
    //ctor
}

AlternativeSet::~AlternativeSet()
{
    std::vector<std::shared_ptr<Expansion>>::iterator it = expansions.begin();
    while(it != expansions.end()) {
        (*it).reset();
        it++;
    }
}

Expansion * AlternativeSet::clone() {
    AlternativeSet * aset = new AlternativeSet();
    std::vector<std::shared_ptr<Expansion>> c = this->getChildren();
    for(std::vector<std::shared_ptr<Expansion>>::iterator childIterator = c.begin(); childIterator != c.end(); childIterator++) {
        aset->addChild(std::shared_ptr<Expansion>((*childIterator)->clone()));
    }
    return aset;
}

unsigned int AlternativeSet::childCount() {
    return distance(expansions.begin(), expansions.end());
}

std::vector<std::shared_ptr<Expansion>> AlternativeSet::getChildren() {
    return expansions;
}

std::shared_ptr<Expansion> AlternativeSet::getChild(unsigned int index) {
    return expansions[index];
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

void AlternativeSet::addChild(std::string token) {
    expansions.push_back(shared_ptr<Expansion>(new Token(token)));
}

void AlternativeSet::removeChild(Expansion & e) {
    if(std::count(expansions.begin(), expansions.end(), std::shared_ptr<Expansion>(&e)) != 0) {
        std::find(expansions.begin(), expansions.end(), std::shared_ptr<Expansion>(&e));
    }
}

std::string AlternativeSet::getText() {
    //TODO: Implement weights

    std::vector<std::shared_ptr<Expansion>>::iterator it = expansions.begin();
    std::string s;
    while(it != expansions.end()) {
        s.append((*it)->getText());
        s.append(" | ");
        it++;
    }

    return s.substr(0, s.size() - 3);
}
