#ifndef REQUIREDGROUPING_H
#define REQUIREDGROUPING_H

#include "jsgfkitxx/Expansion.hpp"


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
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        ExpansionType getType() const;
        bool hasChild() const;
	bool isOptional() const;
        std::shared_ptr<Expansion> getChild(const unsigned int index = 0) const;
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount() const;

        std::string getText() const;
};

#endif // REQUIREDGROUPING_H
