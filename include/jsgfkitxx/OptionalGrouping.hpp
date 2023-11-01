#ifndef OPTIONALGROUPING_H
#define OPTIONALGROUPING_H

#include "jsgfkitxx/Expansion.hpp"


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
        ExpansionType getType() const;
        bool hasChild() const;
        std::shared_ptr<Expansion> getChild(const unsigned int index = 0) const;
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount() const;

        std::string getText() const;
};

#endif // OPTIONALGROUPING_H
