#ifndef ALTERNATIVESET_H
#define ALTERNATIVESET_H

#include <expansion.h>
#include <vector>
#include <string>
#include <algorithm>

class AlternativeSet : public Expansion
{
    private:
        std::vector<float> weights; //TODO: Implement this
        std::vector<std::shared_ptr<Expansion>> expansions;

    public:
        /** Default constructor */
        AlternativeSet();
        /** Default destructor */
        ~AlternativeSet();

        Expansion * clone();
        ExpansionType getType();
        bool hasChild();
        std::shared_ptr<Expansion> getChild(unsigned int index = 0);
        std::vector<std::shared_ptr<Expansion>> getChildren();
        unsigned int childCount();

        void removeChild(Expansion & e);
        void addChild(std::shared_ptr<Expansion> e);
        std::string getText();
};

#endif // ALTERNATIVESET_H
