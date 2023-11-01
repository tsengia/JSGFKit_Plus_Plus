#ifndef TOKEN_H
#define TOKEN_H
#include "Expansion.hpp"
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
        string getText() const;
        /** Set text
         * \param val New value to set
         */
        void setText(string val);

        ExpansionType getType() const;
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);

        unsigned int childCount() const;
        bool hasChild() const;
        shared_ptr<Expansion> getChild(const unsigned int index = 0) const;
};

#endif // TOKEN_H
