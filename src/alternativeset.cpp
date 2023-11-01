#include "jsgfkitxx/AlternativeSet.hpp"

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

unsigned int AlternativeSet::childCount() const {
    return distance(expansions.begin(), expansions.end());
}

std::vector<std::shared_ptr<Expansion>> AlternativeSet::getChildren() const {
    return expansions;
}

std::shared_ptr<Expansion> AlternativeSet::getChild(const unsigned int index) const {
    return expansions[index];
}

ExpansionType AlternativeSet::getType() const {
    return ALTERNATE_SET;
}

bool AlternativeSet::hasChild() const {
    return expansions.empty();
}

void AlternativeSet::addChild(std::shared_ptr<Expansion> e) {
    expansions.push_back(e);
}

void AlternativeSet::addChild(std::string token) {
    expansions.push_back(shared_ptr<Expansion>(new Token(token)));
}

void AlternativeSet::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    expansions[index] = newChild;
}

/// TODO: Test to make sure this method works, it doesnt look quite right...
void AlternativeSet::removeChild(Expansion & e) {
    if(std::count(expansions.begin(), expansions.end(), std::shared_ptr<Expansion>(&e)) != 0) {
        std::find(expansions.begin(), expansions.end(), std::shared_ptr<Expansion>(&e));
    }
}

void AlternativeSet::removeChild(const unsigned int i) {
    expansions.erase(expansions.begin() + i);
}

std::string AlternativeSet::getText() const {
    //TODO: Implement weights

    std::vector<std::shared_ptr<Expansion>>::const_iterator it = expansions.begin();
    std::string s = "(";
    while(it != expansions.end()) {
        s.append((*it)->getText());
        s.append(" | ");
        it++;
    }

    s = s.substr(0, s.size() - 3);
    return s + ")";
}
