
#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#include <iostream>
#include <vector>
#include <memory>

namespace ariel
{
    class Team
    {
    private:
        std::vector<Character*> fighters; 
        Character *leader;

    public:
        Team(Character *leader);
        ~Team() = default;
        virtual void add(Character *fighter);
        virtual void attack(Team *enemyTeam);
        int stillAlive() const;
        std::string print() const;
        virtual Character* findNextVictim(Character* leader);
        Character* findClosest(Point location);
        std::vector<Character*>& getFighters();
        void setLeader(Character *leader);
    };

}

#endif /* TEAM_HPP */