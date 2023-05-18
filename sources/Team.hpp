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
        std::vector<std::unique_ptr<Character>> fighters; 
        Character *leader;

    public:
        Team(Character *leader);
        ~Team() = default;
        void add(Character *fight);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        void print() const;
    };

    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
    };
}

#endif /* TEAM_HPP */
