#include "SmartTeam.hpp"
#include <random>
using namespace ariel;
using namespace std;

SmartTeam::SmartTeam(Character *leader) : Team(leader)
{
}

void SmartTeam::attack(Team *enemyTeam)
{
    this->chooseLeader();
    Team::attack(enemyTeam);
}

void SmartTeam::chooseLeader()
{
    std::unordered_map<Character *, int> proximityCounts;

    for (const auto &fighter : this->getFighters())
    {
        Ninja *ninja = dynamic_cast<Ninja *>(fighter);
        if (ninja != nullptr && ninja->isAlive())
        {
            Character *closestChar = findClosest(ninja->getLocation());
            if (closestChar != nullptr)
            {
                proximityCounts[closestChar]++;
            }
        }
    }

    Character *nextLeader = nullptr;
    int maxCount = 0;
    for (const auto &pair : proximityCounts)
    {
        if (pair.second > maxCount)
        {
            nextLeader = pair.first;
            maxCount = pair.second;
        }
    }

    // If no suitable leader is found among characters that are closest to the most ninjas,
    // pick a random living character as the leader.
    if (nextLeader == nullptr)
    {
        std::vector<Character *> livingFighters;
        for (const auto &fighter : this->getFighters())
        {
            if (fighter->isAlive())
            {
                livingFighters.push_back(fighter);
            }
        }

        for (const auto &fighter : this->getFighters())
        {
            if (fighter->isAlive())
            {
                nextLeader = fighter;
                break;
            }
        }
    }

    // If there are no living characters in the team, the team has lost.
    // if (nextLeader == nullptr)
    // {
    //     throw std::runtime_error("No suitable leader could be found");
    // }

    this->setLeader(nextLeader);
}

Character *SmartTeam::findNextVictim(Character *leader)
{
    std::unordered_map<Character *, int> enemyCounts;
    bool ninjaAlive = false; 

    for (const auto &fighter : this->getFighters())
    {
        Ninja *ninja = dynamic_cast<Ninja *>(fighter);
        if (ninja != nullptr && ninja->isAlive())
        {
            ninjaAlive = true; // if a living ninja is found, set flag to true
            Character *closestEnemy = findClosest(ninja->getLocation());
            if (closestEnemy != nullptr)
            {
                enemyCounts[closestEnemy]++;
            }
        }
    }

    // if no living ninja is found, choose a living cowboy as the victim
    if (!ninjaAlive)
    {
        for (const auto &fighter : this->getFighters())
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
            if (cowboy != nullptr && cowboy->isAlive())
            {
                return cowboy; // return the first living cowboy
            }
        }
    }

    Character *nextVictim = nullptr;
    int maxCount = 0;
    for (const auto &pair : enemyCounts)
    {
        if (pair.second > maxCount)
        {
            nextVictim = pair.first;
            maxCount = pair.second;
        }
    }

    // if no living character (neither ninja nor cowboy) is found, behave like Team
    if (nextVictim == nullptr)
    {
        return Team::findNextVictim(leader);
    }

    return nextVictim;
}
