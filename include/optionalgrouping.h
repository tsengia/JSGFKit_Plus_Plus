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
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild();
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount();

        std::string getText();
};

#endif // OPTIONALGROUPING_H
