#ifndef TOKEN_H
#define TOKEN_H
#include "expansion.h"
#include <iostream>

using namespace std;

class Token : public Expansion
{
    private:
        string text; //!< Member variable "text"

    public:
        /** Default constructor */
        Token();
        Token(string s);
        /** Default destructor */
        ~Token();

        Expansion * clone();

        /** Access text
         * \return The current value of text
         */
        string getText();
        /** Set text
         * \param val New value to set
         */
        void setText(string val);

        ExpansionType getType();

        bool hasChild();
        shared_ptr<Expansion> getChild();
};

#endif // TOKEN_H
