#ifndef ALTERNATIVESET_H
#define ALTERNATIVESET_H

#include <expansion.h>
#include <token.h>
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
        ExpansionType getType() const override;
        bool hasChild() const;
        std::shared_ptr<Expansion> getChild(const unsigned int index = 0) const;
        std::vector<std::shared_ptr<Expansion>> getChildren() const;
        unsigned int childCount() const;

        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);
        void removeChild(Expansion & e);
        void removeChild(const unsigned int i);
        void addChild(std::shared_ptr<Expansion> e);
        void addChild(std::string token);
        std::string getText() const;
};

#endif // ALTERNATIVESET_H
