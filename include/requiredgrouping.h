#ifndef REQUIREDGROUPING_H
#define REQUIREDGROUPING_H

#include <expansion.h>


class RequiredGrouping : public Expansion
{
    private:
        shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        RequiredGrouping();
        RequiredGrouping(Expansion * e);
        /** Default destructor */
        ~RequiredGrouping();

        Expansion * clone();
        ExpansionType getType() { return REQUIRED_GROUPING; }
        bool hasChild() { return childExpansion != nullptr; }
        shared_ptr<Expansion> getChild() { return childExpansion; }
        void setChild(Expansion * e) { childExpansion.reset(); childExpansion = shared_ptr<Expansion>(e); }

        string getText();
};

#endif // REQUIREDGROUPING_H
