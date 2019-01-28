#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

#include <expansion.h>


class PlusOperator : public Expansion
{
    private:
        shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        PlusOperator();
        PlusOperator(shared_ptr<Expansion> e);
        /** Default destructor */
        ~PlusOperator();

        Expansion * clone();
        ExpansionType getType() { return PLUS_OPERATOR; }
        bool hasChild() { return childExpansion != nullptr; }
        shared_ptr<Expansion> getChild() { return childExpansion; }
        void setChild(shared_ptr<Expansion> e) { childExpansion.reset(); childExpansion = e; }

        string getText();
};
#endif // PLUSOPERATOR_H
