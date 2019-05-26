#ifndef RULE_H
#define RULE_H
#include "expansion.h"
#include <string>

class Rule
{
    private:
        bool isVisible; /// If true, the Rule is "public". If false, the Rule is not "public"
        std::string name;
        std::shared_ptr<Expansion> ruleExpansion;

    public:
        /** Default constructor */
        Rule();
        Rule(std::string n, bool visible, std::shared_ptr<Expansion> e);

        /** Default destructor */
        ~Rule();

        void setPrivate() { isVisible = false; } /// Makes the Rule private
        void setPublic() { isVisible = true; } /// Makes the Rule public
        std::shared_ptr<Expansion> getRuleExpansion() const { return ruleExpansion; }
        void setRuleExpansion(std::shared_ptr<Expansion> e) { ruleExpansion = e; }
        void setRuleName(const std::string & newName) { name = newName; }
        std::string getRuleName() { return name; }
        bool isPublic() const { return isVisible; }

        /**
          * Returns a generated line of JSGF that defines this Rule.
          * \return string The generated JSGF text that declares this Rule.
          *
          */
        std::string getRuleString() const;

};

#endif // RULE_H
