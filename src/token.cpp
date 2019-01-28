#include "token.h"

using namespace std;
Token::Token()
{
    //ctor
}

Token::Token(string s) {
    text = s;
}

Token::~Token()
{

}

Expansion * Token::clone() {
    return new Token(this->getText());
}

string Token::getText() {
    return text;
}

bool Token::hasChild() {
    return false;
}

shared_ptr<Expansion> Token::getChild() {
    return nullptr;
}
