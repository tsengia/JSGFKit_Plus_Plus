#ifndef RULE_H
#define RULE_H
#include "expansion.h"
#include <string>
using namespace std;

class Rule
{
    private:
        bool isVisible; /// If true, the Rule is "public". If false, the Rule is not "public"
        string name;
        shared_ptr<Expansion> ruleExpansion;

    public:
        /** Default constructor */
        Rule();
        Rule(string n, bool visible, shared_ptr<Expansion> e);

        /** Default destructor */
        ~Rule();

        void setPrivate() { isVisible = false; } /// Makes the Rule private
        void setPublic() { isVisible = true; } /// Makes the Rule public
        shared_ptr<Expansion> getRuleExpansion() { return ruleExpansion; }
        void setRuleExpansion(shared_ptr<Expansion> e) { ruleExpansion = e; }
        void setRuleName(string newName) { name = newName; }
        string getRuleName() { return name; }
        bool isPublic() { return isVisible; }

        /**
          * Returns a generated line of JSGF that defines this Rule.
          * \return string The generated JSGF text that declares this Rule.
          *
          */
        string getRuleString();

};

#endif // RULE_H
