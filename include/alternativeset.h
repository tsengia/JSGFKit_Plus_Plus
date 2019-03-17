#ifndef ALTERNATIVESET_H
#define ALTERNATIVESET_H

#include <expansion.h>
#include <list>
#include <string>

class AlternativeSet : public Expansion
{
    private:
        std::list<float> weights; //TODO: Implement this
        std::list<std::shared_ptr<Expansion>> expansions;

    public:
        /** Default constructor */
        AlternativeSet();
        /** Default destructor */
        ~AlternativeSet();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild();
        std::list<std::shared_ptr<Expansion>> getChildren();
        unsigned int childCount();

        void removeChild(Expansion & e);
        void addChild(std::shared_ptr<Expansion> e);
        std::string getText();
};

#endif // ALTERNATIVESET_H
