#include "jsgfkitxx/Token.hpp"

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

std::string Token::getText() const {
    return text;
}

bool Token::hasChild() const {
    return false;
}

bool Token::isOptional() const {
    return false;
}

std::shared_ptr<Expansion> Token::getChild(const unsigned int index) const {
    return nullptr;
}

/** Set text
 * \param val New value to set
 */
void Token::setText(std::string val) {
    text = val;
}

unsigned int Token::childCount() const {
    return 0;
}

void Token::replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index) {
    // Do nothing because Token's don't have children
}

ExpansionType Token::getType() const {
    return TOKEN;
}
