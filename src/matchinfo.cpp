#include "matchinfo.h"

MatchInfo::MatchInfo(std::shared_ptr<Expansion> e, std::string matchingStringPart)
{
    expansion = e;
    matchingSection = matchingStringPart;
}
