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
        OptionalGrouping(shared_ptr<Expansion> e);
        /** Default destructor */
        ~OptionalGrouping();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        shared_ptr<Expansion> getChild();
        void setChild(shared_ptr<Expansion> e);

        string getText();
};

#endif // OPTIONALGROUPING_H
