#ifndef UNPARSEDSECTION_H
#define UNPARSEDSECTION_H

#include <expansion.h>
#include <string>

using namespace std;

/// An internal class used by the parser to generate the Expansions
class UnparsedSection : public Expansion
{
    private:
        string section;

    public:
        /** Default constructor */
        UnparsedSection();
        UnparsedSection(string s);

        /** Default destructor */
        ~UnparsedSection();
        Expansion * clone(); // Really should never be used but should still be implemented

        const ExpansionType getType();

        ///Will always return true
        const bool hasChild();
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);

        const unsigned int childCount();

        /// Will always return nullptr
        const shared_ptr<Expansion> getChild(const unsigned int index = 0);

        const string getSection();
        void setSection(string s);
        const string getText();
};

#endif // UNPARSEDSECTION_H
