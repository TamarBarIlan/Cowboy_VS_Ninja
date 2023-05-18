#include "Team.hpp"
using namespace ariel;
using namespace std;

Team::Team(Character* leader) : leader(leader)
{
}

void Team::add(Character* character)
{
    // std::unique_ptr<Character> character_ptr(character);
}

void Team::attack(Team* enemyTeam)
{
    // Team& enemy = *enemyTeam;
}

int Team::stillAlive() const
{
    return 0;
}

void Team::print() const
{
}

Team2::Team2(Character* leader) : Team(leader) {}
SmartTeam::SmartTeam(Character* leader) : Team(leader) {}
