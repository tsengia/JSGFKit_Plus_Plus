#ifndef RULEREFERENCE_H
#define RULEREFERENCE_H

#include "jsgfkitxx/Expansion.hpp"


class RuleReference : public Expansion
{
    private:
        std::string ruleName; //!< Member variable "ruleName;"

    public:
        /** Default constructor */
        RuleReference(std::string ruleN);

        /** Default destructor */
        ~RuleReference();

        /** Access ruleName;
         * \return The current value of ruleName;
         */
        std::string getRuleName() const;

        /** Set ruleName;
         * \param val New value to set
         */
        void setRuleName(std::string val);

        bool hasChild() const;
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        unsigned int childCount() const;
        Expansion * clone();
        std::shared_ptr<Expansion> getChild(const unsigned int index = 0) const;
        ExpansionType getType() const;
        std::string getText() const;
};

#endif // RULEREFERENCE_H
