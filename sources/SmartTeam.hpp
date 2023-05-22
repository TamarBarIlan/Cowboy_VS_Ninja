#ifndef SmartTEAM_HPP
#define SmartTEAM_HPP

#include <unordered_map>
#include "Team.hpp"
#include <vector>

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
        void chooseLeader();
        Character *findNextVictim(Character *leader) override;
        void attack(Team *enemyTeam) override;
    };
}

#endif /* SmartTEAM_HPP */
