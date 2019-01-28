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
        ExpansionType getType();
        bool hasChild();
        shared_ptr<Expansion> getChild();
        void setChild(shared_ptr<Expansion> e);

        string getText();
};
#endif // PLUSOPERATOR_H
