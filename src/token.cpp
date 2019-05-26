#include "token.h"

Token::Token()
{
    //ctor
}

Token::Token(std::string s) {
    text = s;
}

Token::~Token()
{

}

Expansion * Token::clone() {
    return new Token(this->getText());
}

const std::string Token::getText() {
    return text;
}

const bool Token::hasChild() {
    return false;
}

const std::shared_ptr<Expansion> Token::getChild(const unsigned int index) {
    return nullptr;
}

/** Set text
 * \param val New value to set
 */
void Token::setText(std::string val) {
    text = val;
}

const unsigned int Token::childCount() {
    return 0;
}

void Token::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    // Do nothing because Token's don't have children
}

const ExpansionType Token::getType() {
    return TOKEN;
}
