#include "sequence.h"
#include <iostream>
Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{
    list<shared_ptr<Expansion>>::iterator it = children.begin();
    while(it != children.end()) {
        it->reset();
        it++;
    }
}

Expansion * Sequence::clone() {
    Sequence * s = new Sequence();
    list<shared_ptr<Expansion>> c = this->getChildren();
    for(list<shared_ptr<Expansion>>::iterator childIterator = c.begin(); childIterator != c.end(); childIterator++) {
        s->addChild(shared_ptr<Expansion>((*childIterator)->clone()));
    }
    return s;
}

void Sequence::addChild(shared_ptr<Expansion> e) {
    children.push_back(e);
}

void Sequence::removeChild(Expansion & e) {
    children.remove(make_shared<Expansion>(e));
}

string Sequence::getText() {
    list<shared_ptr<Expansion>>::iterator it;
    string s = "";
    for(it = children.begin(); it != children.end(); it++) {
        s.append((*it)->getText());
        s.append(" ");
    }
    return s;
}
