#include "tag.h"
#include <iostream>
using namespace std;

string Tag::getText() {
    string s = childExpansion->getText();
    std::forward_list<string>::iterator it;
    for(it = strings.begin(); it != strings.end(); it++){
        s.append(" {" + *it + "}");
    }
    return s;
}

bool Tag::hasChild() {
    return true;
}

void Tag::addTag(string t) {
    strings.push_front(t);
}

void Tag::removeTag(string t) {
    strings.remove(t);
}

int Tag::getTagCount()
{
    return tagCount;
}

Expansion * Tag::clone() {
    Tag * t = new Tag(shared_ptr<Expansion>(this->getChild()->clone()));
    forward_list<string> tags = strings;
    forward_list<string>::iterator it;
    for(it = tags.begin(); it != tags.end(); it++){
        t->addTag(*it);
    }
    return t;
}

Tag::~Tag() {
    childExpansion.reset();
}

Tag::Tag(shared_ptr<Expansion> e)
{
    childExpansion = e;
    tagCount = 0;
}

Tag::Tag(shared_ptr<Expansion> e, string tag) {
    childExpansion = e;
    strings.push_front(tag);
    tagCount++;
}

Tag::Tag(shared_ptr<Expansion> e, unsigned short numberOfTags, string tags[]) {
    childExpansion = e;
    for(unsigned short i = 0; i < numberOfTags; i++) {
        strings.push_front(tags[i]);
    }
    tagCount += numberOfTags;
}
