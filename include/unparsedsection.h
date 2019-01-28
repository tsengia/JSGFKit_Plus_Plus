#ifndef UNPARSEDSECTION_H
#define UNPARSEDSECTION_H

#include <expansion.h>
#include <string>

using namespace std;

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

        ExpansionType getType();

        ///Will always return true
        bool hasChild();

        /// Will always return nullptr
        shared_ptr<Expansion> getChild();

        string getSection();
        void setSection(string s);
        string getText();
};

#endif // UNPARSEDSECTION_H
