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
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild();
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount();

        std::string getText();
};
#endif // PLUSOPERATOR_H
