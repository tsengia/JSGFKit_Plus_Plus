#ifndef OPTIONALGROUPING_H
#define OPTIONALGROUPING_H

#include <expansion.h>


class OptionalGrouping : public Expansion
{
    private:
        shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        OptionalGrouping();
        OptionalGrouping(Expansion * e);
        /** Default destructor */
        ~OptionalGrouping();

        Expansion * clone();
        ExpansionType getType() { return OPTIONAL_GROUPING; }
        bool hasChild() { return childExpansion != nullptr; }
        shared_ptr<Expansion> getChild() { return childExpansion; }
        void setChild(Expansion * e) { childExpansion = shared_ptr<Expansion>(e); }

        string getText();
};

#endif // OPTIONALGROUPING_H
