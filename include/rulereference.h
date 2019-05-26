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
        const std::string getRuleName();

        /** Set ruleName;
         * \param val New value to set
         */
        void setRuleName(std::string val);

        const bool hasChild();
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        const unsigned int childCount();
        Expansion * clone();
        const std::shared_ptr<Expansion> getChild(const unsigned int index = 0);
        const ExpansionType getType();
        const std::string getText();
};

#endif // RULEREFERENCE_H
