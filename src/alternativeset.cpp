#include "alternativeset.h"

AlternativeSet::AlternativeSet()
{
    //ctor
}

AlternativeSet::~AlternativeSet()
{
    list<shared_ptr<Expansion>>::iterator it = expansions.begin();
    while(it != expansions.end()) {
        (*it).reset();
        it++;
    }
}

Expansion * AlternativeSet::clone() {
    AlternativeSet * aset = new AlternativeSet();
    list<shared_ptr<Expansion>> c = this->getChildren();
    for(list<shared_ptr<Expansion>>::iterator childIterator = c.begin(); childIterator != c.end(); childIterator++) {
        aset->addChild(shared_ptr<Expansion>((*childIterator)->clone()));
    }
    return aset;
}

void AlternativeSet::addChild(shared_ptr<Expansion> e) {
    expansions.push_back(e);
}

string AlternativeSet::getText() {
    //TODO: Implement weights

    list<shared_ptr<Expansion>>::iterator it = expansions.begin();
    string s;
    while(it != expansions.end()) {
        s.append((*it)->getText());
        s.append(" | ");
        it++;
    }

    return s.substr(0, s.size() - 3);
}
