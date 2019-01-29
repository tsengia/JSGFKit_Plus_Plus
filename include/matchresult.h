#ifndef MATCHRESULT_H
#define MATCHRESULT_H
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <string>
#include "matchinfo.h"
#include "rule.h"

typedef std::list<std::shared_ptr<MatchInfo>> MatchList;

class MatchResult
{
    public:
        /** Default constructor means that no match was found */
        MatchResult();
        /// Construct for when a match is found
        MatchResult(std::shared_ptr<Rule> rule, MatchList ml);
        std::vector<std::string> getMatchingTags();
        const bool matches;
        const std::shared_ptr<Rule> getMatchingRule();

    protected:
        std::shared_ptr<Rule> matchingRule;
        MatchList matchList;
};

#endif // MATCHRESULT_H
