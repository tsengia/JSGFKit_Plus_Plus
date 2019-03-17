#ifndef MATCHRESULT_H
#define MATCHRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <vector>
#include <string>
#include "matchinfo.h"
#include "rule.h"

typedef std::vector<std::shared_ptr<MatchInfo>> Matchvector;

class MatchResult
{
    public:
        /** Default constructor means that no match was found */
        MatchResult();
        /// Construct for when a match is found
        MatchResult(std::shared_ptr<Rule> rule, Matchvector ml);
        std::vector<std::string> getMatchingTags();
        /// If true, a match was found. If false, no match was found.
        const bool matches;
        const std::shared_ptr<Rule> getMatchingRule();

    protected:
        std::shared_ptr<Rule> matchingRule;
        Matchvector matchvector;
};

#endif // MATCHRESULT_H
