#include "Character.hpp"

using namespace ariel;
using namespace std;

Character::Character(const std::string &name,const Point &location, int hitPoints)
    : name(name), location(location), hitPoints(hitPoints), inTeam(false)
{
}


Character::Character(Character &other)
    : name(other.name), location(other.location), hitPoints(other.hitPoints)
{
}

Character &Character::operator=(Character &other)
{
    if (this != &other)
    {
        name = other.name;
        location = other.location;
        hitPoints = other.hitPoints;
    }
    return *this;
}

bool Character::isAlive()
{
    return hitPoints > 0;
}

double Character::distance(const Character &other)
{
    return this->location.distance(other.location);
}

void Character::hit(int damage)
{
    this->hitPoints -= damage;
}

std::string Character::getName()
{
    return name;
}

Point Character::getLocation()
{
    return location;
}
void Character::setLocation(Point location)
{
    this->location = location;
}
int Character::getHitPoints()
{
    return hitPoints;
}
bool Character::getInTeam()
{
    return this->inTeam;
}
void Character::setInTeam(bool ans)
{
    this->inTeam = ans;
}

