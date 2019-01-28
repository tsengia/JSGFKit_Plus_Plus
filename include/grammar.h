#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <list>
#include <string>
#include "expansion.h"
#include "rule.h"
#include "unparsedsection.h"
#include "sequence.h"
#include "token.h"
#include "kleenestar.h"
#include "plusoperator.h"
#include "matchinfo.h"
#include "optionalgrouping.h"
#include "requiredgrouping.h"
#include "tag.h"
#include "rulereference.h"
#include "alternativeset.h"
#include "matchinfo.h"
#include <cstring>
#include <regex>
#include <typeinfo>
#include <vector>

using namespace std;

class Grammar
{
    protected:
        string name;
        list<shared_ptr<Rule>> rules;
        static Expansion * parseAlternativeSets(list<Expansion *> & exp);
        static void parseRuleReferences(const list<Expansion *> & expansions, list<Expansion *> & returnExpansions);
        static void parseRequiredGroupings(const list<Expansion *> & expansions, list<Expansion *> & returnExpansions);
        static void parseOptionalGroupings(const list<Expansion *> & expansions, list<Expansion *> & returnExpansions);
        static void parseUnaryOperators(const list<Expansion *> & expansions, list<Expansion *> & returnExpansions);
        static list<Expansion *> parseTokensFromString(string part);

    public:
        /** Default constructor */
        Grammar();
        /**
         * Constructor that specifies the grammar name
         * \param [in] string Name of the Grammar
         */
        Grammar(string grammarName);

        /** Default destructor */
        ~Grammar();

        void addRule(shared_ptr<Rule> r);
        shared_ptr<Rule> getRule(string name);

        string getName() { return name; }
        void setName(string s) { name = s; }
        string getText();

        static string trimString(string const& input);
        static vector<string> splitString(const std::string & s, std::string rgx_str);
        static bool stringContains(string part, string search);
        static bool stringStartsWith(string s, string test);
        static bool stringEndsWith(string s, string test);
        static string replaceAll(string s, string re, string replacement);
        static string replaceFirst(string s, string re, string replacement);
        static Expansion * parseExpansionsFromString(string input);
        static Grammar * parseGrammarFromString(string s);

        list<shared_ptr<MatchInfo>> getMatchingExpansions(shared_ptr<Expansion> e, string words[], unsigned int wordCount, unsigned int wordPosition);
        list<shared_ptr<MatchInfo>> matchesRule(shared_ptr<Rule> rule, string test);
        list<shared_ptr<MatchInfo>> matchesRule(string ruleName, string test);
        shared_ptr<Rule> getMatchingRule(string test);
        vector<string> getMatchingTags(string test);
        static vector<string> getMatchingTags(list<shared_ptr<MatchInfo>> matchInfo);

        static regex specialCharacterRegex;
};

#endif // GRAMMAR_H
