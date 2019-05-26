#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <expansion.h>
#include <vector>
#include <algorithm>

class Sequence : public Expansion
{
    private:
        std::vector<std::shared_ptr<Expansion>> children; //!< Member variable "children"

    public:
        /** Default constructor */
        Sequence();
        /** Default destructor */
        ~Sequence();

        /** Clone function, makes a deep copy of the Sequence */
        Expansion * clone();
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        const ExpansionType getType();
        const bool hasChild();
        const std::shared_ptr<Expansion> getChild(const unsigned int index = 0);
        const std::string getText();

        /** Access children
         * \return The current value of children
         */
        const std::vector<std::shared_ptr<Expansion>> getChildren();

        void addChild(std::shared_ptr<Expansion> e);
        void removeChild(Expansion & e);
        const unsigned int childCount();

        /**
          * Static Helper function that checks to see if the provided expansion is a sequence, and if it is, checks to see if the Sequence has only one child. If it has only one child, it sets the provided shared_pointer to point to the child Expansion.
          * TLDR; Simplifies singular child Sequence's to singular Expansions
          * \param [in,out] s Expansion that will be simplified if it is a Sequence with 1 child expansion
          */
        static void simplifySequence(std::shared_ptr<Expansion> s);
};

#endif // SEQUENCE_H
