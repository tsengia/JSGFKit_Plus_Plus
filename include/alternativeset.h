#ifndef ALTERNATIVESET_H
#define ALTERNATIVESET_H

#include <expansion.h>
#include <list>
#include <string>
using namespace std;

class AlternativeSet : public Expansion
{
    private:
        list<float> weights; //TODO: Implement this
        list<shared_ptr<Expansion>> expansions;

    public:
        /** Default constructor */
        AlternativeSet();
        /** Default destructor */
        ~AlternativeSet();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        shared_ptr<Expansion> getChild();
        list<shared_ptr<Expansion>> getChildren();
        unsigned short childCount();

        void removeChild(Expansion & e);
        void addChild(shared_ptr<Expansion> e);
        string getText();
};

#endif // ALTERNATIVESET_H
