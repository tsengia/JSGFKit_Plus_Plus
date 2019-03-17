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

std::shared_ptr<Expansion> Token::getChild(unsigned int index) {
    return nullptr;
}

/** Set text
 * \param val New value to set
 */
void Token::setText(std::string val) {
    text = val;
}

unsigned int Token::childCount() {
    return 0;
}

ExpansionType Token::getType() {
    return TOKEN;
}
