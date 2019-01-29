#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <list>
#include <string>
#include <cstring>
#include <regex>
#include <typeinfo>
#include <vector>
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
#include "matchresult.h"

typedef std::list<std::shared_ptr<MatchInfo>> MatchList;

/**
  * \mainpage
  * JSGF Kit++ is a C++ port of the Java JSGF Kit library.
  * JSGF Kit++ can parse JSGF grammars to produce Grammar objects.
  * These Grammar objects can be manipulated by adding or removing Rule objects and manipulating the rule Expansion for each Rule.
  * Test/input strings can be tested/matched against Rules inside of grammars, and JSGF Kit++ provides functions to extract the tags that the test string matches.
  * Please see the examples folder for example programs for parsing, manipulating, and testing strings against Grammar objects using JSGF Kit Plus Plus.
  *
  */

class Grammar
{
    protected:
        // Member data
        std::string name;
        std::list<std::shared_ptr<Rule>> rules;

        //Matching
        MatchList getMatchingExpansions(std::shared_ptr<Expansion> e, std::string words[], unsigned int wordCount, unsigned int wordPosition);

        // Parsing functions
        static Expansion * parseAlternativeSets(std::list<Expansion *> & exp);
        static void parseRuleReferences(const std::list<Expansion *> & expansions, std::list<Expansion *> & returnExpansions);
        static void parseRequiredGroupings(const std::list<Expansion *> & expansions, std::list<Expansion *> & returnExpansions);
        static void parseOptionalGroupings(const std::list<Expansion *> & expansions, std::list<Expansion *> & returnExpansions);
        static void parseUnaryOperators(const std::list<Expansion *> & expansions, std::list<Expansion *> & returnExpansions);
        static std::list<Expansion *> parseTokensFromString(std::string part);

    public:
        /** Default constructor */
        Grammar();
        /**
         * Constructor that specifies the grammar name
         * \param [in] string Name of the Grammar
         */
        Grammar(std::string grammarName);

        /** Default destructor */
        ~Grammar();

        void addRule(std::shared_ptr<Rule> r);
        std::shared_ptr<Rule> getRule(std::string name);

        std::string getName();
        void setName(std::string s);

        std::string getText();

        // Parsing
        static Expansion * parseExpansionsFromString(std::string input);
        static void parseGrammarFromString(std::string s, Grammar & g);

        // Matching
        MatchResult match(std::string test);
        MatchList matchesRule(std::shared_ptr<Rule> rule, std::string test);
        MatchList matchesRule(std::string ruleName, std::string test);
        std::vector<std::string> getMatchingTags(std::string test);
        static std::vector<std::string> getMatchingTags(std::list<std::shared_ptr<MatchInfo>> matchInfo);

        // Helper functions
        static std::string trimString(std::string const& input);
        static std::vector<std::string> splitString(const std::string & s, std::string rgx_str);
        static bool stringContains(std::string part, std::string search);
        static bool stringStartsWith(std::string s, std::string test);
        static bool stringEndsWith(std::string s, std::string test);
        static std::string replaceAll(std::string s, std::string re, std::string replacement);
        static std::string replaceFirst(std::string s, std::string re, std::string replacement);

        static std::regex specialCharacterRegex;
};

#endif // GRAMMAR_H
