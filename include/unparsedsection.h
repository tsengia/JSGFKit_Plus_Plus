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
        bool hasChild() { return false; }
        shared_ptr<Expansion> getChild() { return nullptr; }
        string getSection ();
        void setSection(string s);
        string getText() { return "UNPARSED SECTION:" + section; }
};

#endif // UNPARSEDSECTION_H
