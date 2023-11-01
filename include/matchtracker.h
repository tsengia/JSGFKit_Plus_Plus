#ifndef MATCHINFO_H
#define MATCHINFO_H
#include "expansion.h"
#include <string>
#include <vector>

class MatchTracker
{
    private:

    protected:
	std::shared_ptr<std::vector<std::string>> wordList;

    public:
        /** Default constructor */
        MatchTracker(std::shared_ptr<std::vector<std::string>> words, unsigned int startIndex);

	MatchTracker(MatchTracker & t);

        ///Stores the index of the current word that is trying to be matched
        unsigned int position;

	///Stores a vector of matched tags
	std::vector<std::string> matchedTags;
	
	///Stores a vector of matched rules
	std::vector<std::string> matchedRules;

	static MatchTracker matchExpansion(std::shared_ptr<std::vector<std::string>> words, unsigned int startIndex, std::shared_ptr<Expansion> startExpansion);

	bool reachedEnd;
	bool successful;
};
#endif // MATCHINFO_H