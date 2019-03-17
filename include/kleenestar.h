#ifndef KLEENESTAR_H
#define KLEENESTAR_H

#include <expansion.h>


class KleeneStar : public Expansion
{
    private:
        std::shared_ptr<Expansion> childExpansion;

    public:
        /** Default constructor */
        KleeneStar();
        KleeneStar(std::shared_ptr<Expansion> e);
        /** Default destructor */
        ~KleeneStar();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild();
        void setChild(std::shared_ptr<Expansion> e);
        unsigned int childCount();

        std::string getText();
};

#endif // KLEENESTAR_H
