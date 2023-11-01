#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

#include "jsgfkitxx/Expansion.hpp"


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
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        ExpansionType getType() const;
        bool hasChild() const;
	bool isOptional() const;
        std::shared_ptr<Expansion> getChild(const unsigned int index = 0) const;
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount() const;

        std::string getText() const;
};
#endif // PLUSOPERATOR_H
