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
        string getRuleName();

        /** Set ruleName;
         * \param val New value to set
         */
        void setRuleName(string val);

        bool hasChild();
        Expansion * clone();
        shared_ptr<Expansion> getChild();
        ExpansionType getType();
        string getText();
};

#endif // RULEREFERENCE_H
