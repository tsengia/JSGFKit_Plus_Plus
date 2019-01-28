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
        RequiredGrouping(shared_ptr<Expansion> e);
        /** Default destructor */
        ~RequiredGrouping();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        shared_ptr<Expansion> getChild();
        void setChild(shared_ptr<Expansion> e);

        string getText();
};

#endif // REQUIREDGROUPING_H
