#ifndef RULEREFERENCE_H
#define RULEREFERENCE_H

#include <expansion.h>


class RuleReference : public Expansion
{
    private:
        string ruleName; //!< Member variable "ruleName;"

    public:
        /** Default constructor */
        RuleReference(string ruleN);

        /** Default destructor */
        ~RuleReference();

        /** Access ruleName;
         * \return The current value of ruleName;
         */
        string getRuleName() { return ruleName; }

        /** Set ruleName;
         * \param val New value to set
         */
        void setRuleName(string val) { ruleName = val; }

        bool hasChild() { return false; }
        Expansion * clone();
        shared_ptr<Expansion> getChild() { return nullptr; }
        ExpansionType getType() { return RULE_REFERENCE; }
        string getText();
};

#endif // RULEREFERENCE_H
