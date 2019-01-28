#ifndef KLEENESTAR_H
#define KLEENESTAR_H

#include <expansion.h>


class KleeneStar : public Expansion
{
    private:
        shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        KleeneStar();
        KleeneStar(shared_ptr<Expansion> e);
        /** Default destructor */
        ~KleeneStar();

        Expansion * clone();
        ExpansionType getType() { return KLEENE_STAR; }
        bool hasChild() { return childExpansion != nullptr; }
        shared_ptr<Expansion> getChild() { return childExpansion; }
        void setChild(shared_ptr<Expansion> e) { childExpansion.reset(); childExpansion = e; }

        string getText();
};

#endif // KLEENESTAR_H
