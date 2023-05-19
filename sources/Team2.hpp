#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

#include <vector>

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
        void add(Character* fighter) override;
    };
}

#endif /* TEAM2_HPP */
