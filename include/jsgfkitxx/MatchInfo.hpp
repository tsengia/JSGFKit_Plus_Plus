#ifndef MATCHINFO_H
#define MATCHINFO_H
#include "Expansion.hpp"
#include <string>

class MatchInfo
{
     private:
        std::shared_ptr<Expansion> expansion; //!< Member variable "expansion"
        std::string matchingSection; //!< Member variable "matchingSection"

    public:
        /** Default constructor */
        MatchInfo(std::shared_ptr<Expansion> e, std::string matchingStringPart);

        /** Access expansion
         * \return The current value of expansion
         */
        std::shared_ptr<Expansion> getExpansion() { return expansion; }
        /** Set expansion
         * \param val New value to set
         */
        void setExpansion(Expansion * val) { expansion.reset(); expansion = std::shared_ptr<Expansion> (val); }

        /** Access matchingSection
         * \return The current value of matchingSection
         */
        std::string getMatchingSection() { return matchingSection; }
        /** Set matchingSection
         * \param val New value to set
         */
        void setMatchingSection(std::string val) { matchingSection = val; }
};

#endif // MATCHINFO_H
