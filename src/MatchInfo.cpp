#include "jsgfkitxx/MatchInfo.hpp"

MatchInfo::MatchInfo(std::shared_ptr<Expansion> e, std::string matchingStringPart)
{
    expansion = e;
    matchingSection = matchingStringPart;
}
