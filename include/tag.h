#ifndef TAG_H
#define TAG_H

#include <algorithm>
#include <expansion.h>
#include <vector>

class Tag : public Expansion
{
    private:
        std::shared_ptr<Expansion> childExpansion; //!< Member variable "childExpansion"
        std::vector<std::string> strings;
        int tagCount;

    public:
        /** Default constructor */
        Tag(std::shared_ptr<Expansion> e);
        Tag(std::shared_ptr<Expansion> e, std::string tag);
        Tag(std::shared_ptr<Expansion> e, unsigned short tagCount, std::string tags[]);
        ~Tag();

        Expansion * clone();

        /** Access childExpansion
         * \return The current value of childExpansion
         */
        std::shared_ptr<Expansion> getChild(unsigned int index = 0);

        /**
          * Returns a vector of strings of the tags the child Expansion is tagged with. (All of the strings between the { } )
          */
        std::vector<std::string> getTags();

        /** Set childExpansion
         * \param val Disassociates with the current child and tags the new specified child Expansion.
         */
        void setChildExpansion(std::shared_ptr<Expansion> val);

        ExpansionType getType();

        bool hasChild();
        unsigned int childCount();
        std::string getText();
        void addTag(std::string t); /// Adds the specified tag to the vector of tags.
        void removeTag(std::string t); /// Removes the specified tag from the vector of tags if it exists.
        int getTagCount(); /// Returns the number of tags attached to the child Expansion. Can be multiple.
};

#endif // TAG_H
