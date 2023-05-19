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
        void add(Character *fight);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        std::string print() const;
        Character* findNextVictim(Character* leader);
        Character* findClosest(Point location);
    };

}

#endif /* TEAM_HPP */
