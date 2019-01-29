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

std::string Token::getText() {
    return text;
}

bool Token::hasChild() {
    return false;
}

std::shared_ptr<Expansion> Token::getChild() {
    return nullptr;
}

/** Set text
 * \param val New value to set
 */
void Token::setText(std::string val) {
    text = val;
}

ExpansionType Token::getType() {
    return TOKEN;
}
