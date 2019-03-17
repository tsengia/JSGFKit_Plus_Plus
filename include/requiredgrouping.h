#ifndef REQUIREDGROUPING_H
#define REQUIREDGROUPING_H

#include <expansion.h>


class RequiredGrouping : public Expansion
{
    private:
        std::shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        RequiredGrouping();
        RequiredGrouping(std::shared_ptr<Expansion> e);
        /** Default destructor */
        ~RequiredGrouping();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild(unsigned int index = 0);
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount();

        std::string getText();
};

#endif // REQUIREDGROUPING_H
