#include "matchresult.h"
#include "grammar.h"

MatchResult::MatchResult() : matches(false) { }

MatchResult::MatchResult(std::shared_ptr<Rule> rule, MatchList ml) : matches(true)
{
    matchingRule = rule;
    matchList = ml;
}

std::vector<std::string> MatchResult::getMatchingTags() {
    return Grammar::getMatchingTags(matchList);
}

const std::shared_ptr<Rule> MatchResult::getMatchingRule() {
    return matchingRule;
}
