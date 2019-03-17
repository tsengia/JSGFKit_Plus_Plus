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
        ExpansionType getType() { return EXPANSION; }
        virtual ~Expansion();

        /// Returns the JSGF text representing this Expansion and its children.
        virtual std::string getText() { return "EXPANSION DEFAULT"; }

        /// Returns true if the Expansion has a child Expansion. Tokens will always return false.
        virtual bool hasChild() { return false; }

        /// Returns the number of child expansions this Expansion has. Tokens will always return false.
        virtual unsigned int childCount() { return 0; }

        /// Returns the child Expansion. Returns nullptr if there is no child Expansion. If there are multiple children, returns the first child Expansion in the list.
        virtual std::shared_ptr<Expansion> getChild() { return nullptr; }

        /// Returns a pointer to a deep clone of this Expansion. The clone() method of all children Expansions are also called when cloning this Expansion.
        virtual Expansion * clone() { return nullptr; }
};

#endif // EXPANSION_H
