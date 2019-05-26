#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <vector>
#include <string>
#include <cstring>
#include <regex>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <fstream>

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

typedef std::vector<std::shared_ptr<MatchInfo>> Matchvector;

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
    private:


    protected:
        // Member data
        std::string name;
        std::vector<std::shared_ptr<Rule>> rules;

        //Matching
        Matchvector getMatchingExpansions(std::shared_ptr<Expansion> e, std::string words[], unsigned int wordCount, unsigned int wordPosition) const;

        // Parsing functions
        static Expansion * parseAlternativeSets(std::vector<Expansion *> & exp);
        static void parseRuleReferences(const std::vector<Expansion *> & expansions, std::vector<Expansion *> & returnExpansions);
        static void parseRequiredGroupings(const std::vector<Expansion *> & expansions, std::vector<Expansion *> & returnExpansions);
        static void parseOptionalGroupings(const std::vector<Expansion *> & expansions, std::vector<Expansion *> & returnExpansions);
        static void parseUnaryOperators(const std::vector<Expansion *> & expansions, std::vector<Expansion *> & returnExpansions);
        static std::vector<Expansion *> parseTokensFromString(std::string part);

    public:
        /** Default constructor */
        Grammar();
        /**
         * Constructor that specifies the grammar name
         * \param [in] string Name of the Grammar
         */
        Grammar(const std::string & grammarName);

        Grammar(std::istream & inputStream);
        Grammar(std::istream * inputStream);

        /** Default destructor */
        ~Grammar();

        bool writeGrammar(std::ofstream & outputStream) const;

        void addRule(std::shared_ptr<Rule> r);
        std::shared_ptr<Rule> getRule(const std::string & name) const;
        std::vector<std::shared_ptr<Rule>> getRules() const;
        bool removeRule(const std::string & ruleName);

        std::string getName() const;
        void setName(const std::string & s);

        std::string getText() const;

        // Parsing
        static Expansion * parseExpansionsFromString(const std::string & input);
        static void parseGrammarFromString(const std::string & s, Grammar & g);
        static void parseGrammar(ifstream f, Grammar & g);

        // Matching
        std::string getMatchingPublicRule(std::string test) const;
        MatchResult match(std::string test) const;
        Matchvector matchesRule(std::shared_ptr<Rule> rule, const std::string & test) const;
        Matchvector matchesRule(const std::string & ruleName, const std::string & test) const;
        std::vector<std::string> getMatchingTags(const std::string & test) const;
        static std::vector<std::string> getMatchingTags(const std::vector<std::shared_ptr<MatchInfo>> & matchInfo);

        // Utility
        void walkGrammar(void (* callback)(Expansion *));
        void walkExpansion(Expansion * e, void (* callback)(Expansion *));

        // Helper functions
        static std::string trimString(std::string input);
        static std::vector<std::string> splitString(const std::string & s, const std::string & rgx_str);
        static bool stringContains(const std::string & part, const std::string & search);
        static bool stringStartsWith(const std::string & s, const std::string & test);
        static bool stringEndsWith(const std::string & s, const std::string & test);
        static std::string replaceAll(const std::string & s, const std::string & re, const std::string & replacement);
        static std::string replaceFirst(const std::string & s, const std::string & re, const std::string & replacement);

        static std::regex specialCharacterRegex;

        static inline std::string &ltrim(std::string &s);
        static inline std::string &rtrim(std::string &s);
};

#endif // GRAMMAR_H
