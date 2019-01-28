#include "matchinfo.h"

MatchInfo::MatchInfo(shared_ptr<Expansion> e, string matchingStringPart)
{
    expansion = e;
    matchingSection = matchingStringPart;
}
