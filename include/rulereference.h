#ifndef RULEREFERENCE_H
#define RULEREFERENCE_H

#include <expansion.h>


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
        std::string getRuleName();

        /** Set ruleName;
         * \param val New value to set
         */
        void setRuleName(std::string val);

        bool hasChild();
        Expansion * clone();
        std::shared_ptr<Expansion> getChild();
        ExpansionType getType();
        std::string getText();
};

#endif // RULEREFERENCE_H
