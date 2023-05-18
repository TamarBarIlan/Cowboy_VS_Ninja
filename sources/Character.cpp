#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Character::Character(const std::string &name, const Point &location, int hitPoints)
    : name(name), location(location), hitPoints(hitPoints)
{
}

Character::Character(const Character &other)
    : name(other.name), location(other.location), hitPoints(other.hitPoints)
{
}

Character& Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        location = other.location;
        hitPoints = other.hitPoints;
    }
    return *this;
}

bool Character::isAlive() const
{
    return hitPoints > 0;
}

double Character::distance(const Character &other) const
{
    return 0.0;
}

void Character::hit(int damage)
{
}

std::string Character::getName() const
{
    return name;
}

Point Character::getLocation() const
{
    return location;
}

int Character::getHitPoints()
{
    return hitPoints;
}
