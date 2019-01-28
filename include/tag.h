#ifndef TAG_H
#define TAG_H

#include <expansion.h>
#include <forward_list>
#include <vector>

using namespace std;

class Tag : public Expansion
{
    private:
        shared_ptr<Expansion> childExpansion; //!< Member variable "childExpansion"
        forward_list<string> strings;
        int tagCount;

    public:
        /** Default constructor */
        Tag(shared_ptr<Expansion> e);
        Tag(shared_ptr<Expansion> e, string tag);
        Tag(shared_ptr<Expansion> e, unsigned short tagCount, string tags[]);
        ~Tag();

        Expansion * clone();

        /** Access childExpansion
         * \return The current value of childExpansion
         */
        shared_ptr<Expansion> getChild();

        /**
          * Returns a vector of strings of the tags the child Expansion is tagged with. (All of the strings between the { } )
          */
        vector<string> getTags();

        /** Set childExpansion
         * \param val Disassociates with the current child and tags the new specified child Expansion.
         */
        void setChildExpansion(shared_ptr<Expansion> val);

        ExpansionType getType();

        bool hasChild();
        string getText();
        void addTag(string t); /// Adds the specified tag to the list of tags.
        void removeTag(string t); /// Removes the specified tag from the list of tags if it exists.
        int getTagCount(); /// Returns the number of tags attached to the child Expansion. Can be multiple.
};

#endif // TAG_H
