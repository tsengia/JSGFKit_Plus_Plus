#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

#include <expansion.h>


class PlusOperator : public Expansion
{
    private:
        std::shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        PlusOperator();
        PlusOperator(std::shared_ptr<Expansion> e);
        /** Default destructor */
        ~PlusOperator();

        Expansion * clone();
        void replaceChild(std::shared_ptr<Expansion> newChild, unsigned long index = 0);
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild(unsigned int index = 0);
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount();

        std::string getText();
};
#endif // PLUSOPERATOR_H
