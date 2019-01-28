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
        ExpansionType getType() { return ALTERNATE_SET; }
        bool hasChild() { return expansions.empty(); }
        shared_ptr<Expansion> getChild() { return (*expansions.begin()); }
        list<shared_ptr<Expansion>> getChildren() { return expansions; }
        unsigned short childCount() {
            return distance(expansions.begin(), expansions.end());
        }

        void removeChild(Expansion & e) { expansions.remove(shared_ptr<Expansion>(&e)); }
        void addChild(shared_ptr<Expansion> e);
        string getText();
};

#endif // ALTERNATIVESET_H
