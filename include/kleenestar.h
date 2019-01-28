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
        ExpansionType getType();
        bool hasChild();
        shared_ptr<Expansion> getChild();
        void setChild(shared_ptr<Expansion> e);

        string getText();
};

#endif // KLEENESTAR_H
