#ifndef MATCHINFO_H
#define MATCHINFO_H
#include "expansion.h"
#include <string>
using namespace std;

class MatchInfo
{
     private:
        shared_ptr<Expansion> expansion; //!< Member variable "expansion"
        string matchingSection; //!< Member variable "matchingSection"

    public:
        /** Default constructor */
        MatchInfo(shared_ptr<Expansion> e, string matchingStringPart);

        /** Access expansion
         * \return The current value of expansion
         */
        shared_ptr<Expansion> getExpansion() { return expansion; }
        /** Set expansion
         * \param val New value to set
         */
        void setExpansion(Expansion * val) { expansion.reset(); expansion = shared_ptr<Expansion> (val); }
        /** Access matchingSection
         * \return The current value of matchingSection
         */
        string getMatchingSection() { return matchingSection; }
        /** Set matchingSection
         * \param val New value to set
         */
        void setMatchingSection(string val) { matchingSection = val; }
};

#endif // MATCHINFO_H
