#include "matchtracker.h"

MatchTracker::MatchTracker(std::shared_ptr<std::vector<std::string>> words, unsigned int startIndex)
{
	position = startIndex;
	wordList = words;
}

MatchTracker::MatchTracker(MatchTracker & t) {
	position = t.position;
	wordList = t.wordList;
	matchedTags = t.matchedTags;
	matchedRules = t.matchedRules;
}

MatchTracker MatchTracker::matchExpansion(std::shared_ptr<std::vector<std::string>> words, unsigned int startIndex, std::shared_ptr<Expansion> startExpansion) {
	MatchTracker t(words, startIndex);
	
}