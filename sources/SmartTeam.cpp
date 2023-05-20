#include "SmartTeam.hpp"
using namespace ariel;
using namespace std;

SmartTeam::SmartTeam(Character *leader) : Team(leader)
{
    this->chooseLeader();
}

void SmartTeam::chooseLeader()
{
    int maxHitPoints = 0;
    int maxSpeed = 0;
    Character *potentialLeader = nullptr;

    for (const auto &fighter : this->getFighters())
    {
        if (fighter->isAlive())
        {
            int currentHitPoints = fighter->getHitPoints();
            int currentSpeed = 0;

            // Check if the fighter is a ninja, and if so get their speed
            Ninja *ninja = dynamic_cast<Ninja *>(fighter);
            if (ninja != nullptr)
            {
                currentSpeed = ninja->getSpeed();
            }

            // Check if this fighter has the highest combination of hit points and speed so far
            if ((currentHitPoints + currentSpeed) > (maxHitPoints + maxSpeed))
            {
                maxHitPoints = currentHitPoints;
                maxSpeed = currentSpeed;
                potentialLeader = fighter;
            }
        }
    }

    // If a potential leader was found, set them as the leader
    if (potentialLeader != nullptr)
    {
        this->setLeader(potentialLeader);
    }
}

Character *SmartTeam::findNextVictim(Character *leader)
{
    // Keep track of how many times each enemy is the closest enemy to a ninja.
    std::unordered_map<Character *, int> enemyCounts;

    for (const auto &fighter : this->getFighters())
    {
        // Check if the fighter is a ninja.
        Ninja *ninja = dynamic_cast<Ninja *>(fighter);
        if (ninja != nullptr && ninja->isAlive())
        {
            // If so, find the closest enemy to this ninja.
            Character *closestEnemy = findClosest(ninja->getLocation());
            if (closestEnemy != nullptr)
            {
                // If there is a closest enemy, increment their count.
                enemyCounts[closestEnemy]++;
            }
        }
    }

    // Find the enemy that was the closest to the most ninjas.
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

    return nextVictim;
}