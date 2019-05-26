#ifndef OPTIONALGROUPING_H
#define OPTIONALGROUPING_H

#include <expansion.h>


class OptionalGrouping : public Expansion
{
    private:
        std::shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        OptionalGrouping();
        OptionalGrouping(std::shared_ptr<Expansion> e);
        /** Default destructor */
        ~OptionalGrouping();

        Expansion * clone();
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        const ExpansionType getType();
        const bool hasChild();
        const std::shared_ptr<Expansion> getChild(const unsigned int index = 0);
        void setChild(std::shared_ptr<Expansion> e);
        const unsigned int childCount();

        const std::string getText();
};

#endif // OPTIONALGROUPING_H
