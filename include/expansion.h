#include <string>
#include <string.h>
#include <memory>

#ifndef EXPANSION_H
#define EXPANSION_H

enum ExpansionType {
    UNPARSED_SECTION, EXPANSION, ALTERNATE_SET, SEQUENCE, RULE_REFERENCE, TAG, TOKEN, KLEENE_STAR, PLUS_OPERATOR, REQUIRED_GROUPING, OPTIONAL_GROUPING
};

/**
  * virtual class that serves as a container to be extended by all other Expansions.
  */
class Expansion
{
    public:
        /** Default constructor */
        Expansion();
        virtual ExpansionType getType() const { return EXPANSION; }
        virtual ~Expansion();

        /// Returns the JSGF text representing this Expansion and its children.
        virtual std::string getText() const { return "EXPANSIONDEFAULT"; };

        /// Returns true if the Expansion has a child Expansion. Tokens will always return false.
        virtual bool hasChild() const { return false; };

        /// Returns the number of child expansions this Expansion has. Tokens will always return false.
        virtual unsigned int childCount() const { return 0; };

        /// Returns the child Expansion. Returns nullptr if there is no child Expansion. If there are multiple children, returns the child Expansions at the specified index. Default is index 0.
        virtual std::shared_ptr<Expansion> getChild(const unsigned int index = 0) const { return nullptr; };

        /// Returns a pointer to a deep clone of this Expansion. The clone() method of all children Expansions are also called when cloning this Expansion.
        virtual Expansion * clone() { return nullptr; };

        /// Replaces the child at the specified index with the given Expansion
        virtual void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0) { };
};

#endif // EXPANSION_H
