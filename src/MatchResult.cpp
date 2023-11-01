#include "jsgfkitxx/MatchResult.hpp"
#include "jsgfkitxx/Grammar.hpp"

MatchResult::MatchResult() : matches(false) { }

MatchResult::MatchResult(std::shared_ptr<Rule> rule, MatchVector ml) : matches(true)
{
    matchingRule = rule;
    matchVector = ml;
}

std::vector<std::string> MatchResult::getMatchingTags() {
    return Grammar::getMatchingTags(matchVector);
}

const std::shared_ptr<Rule> MatchResult::getMatchingRule() {
    return matchingRule;
}
