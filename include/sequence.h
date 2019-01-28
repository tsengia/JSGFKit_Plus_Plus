#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <expansion.h>
#include <list>

using namespace std;

class Sequence : public Expansion
{
    private:
        list<shared_ptr<Expansion>> children; //!< Member variable "children"

    public:
        /** Default constructor */
        Sequence();
        /** Default destructor */
        ~Sequence();

        /** Clone function, makes a deep copy of the Sequence */
        Expansion * clone();

        /** Access children
         * \return The current value of children
         */
        list<shared_ptr<Expansion>> getChildren() { return children; }

        ExpansionType getType() { return SEQUENCE; }

        void addChild(shared_ptr<Expansion> e);
        void removeChild(Expansion & e);

        unsigned short childrenCount() {
            return distance(children.begin(), children.end());
        }

        string getText();
        bool hasChild() { return children.empty(); }
        shared_ptr<Expansion> getChild() { return children.front(); }

        /**
          * Static Helper function that checks to see if the provided expansion is a sequence, and if it is, checks to see if the Sequence has only one child. If it has only one child, it sets the provided shared_pointer to point to the child Expansion.
          * TLDR; Simplifies singular child Sequence's to singular Expansions
          * \param [in,out] s Expansion that will be simplified if it is a Sequence with 1 child expansion
          */
        static void simplifySequence(shared_ptr<Expansion> s) {
            if(typeid(*s) == typeid(Sequence)) {
                Sequence * sq = (Sequence*) s.get();
                if(sq->childrenCount() == 1) { // We have a sequence that has only one child. We need to extract the child, destroy the sequence, and set the expansion to the extracted child
                    s = sq->getChild(); // clone() makes a deep copy
                }
                else {
                    //Do nothing to s
                }
            }
        }
};

#endif // SEQUENCE_H
