#include "Ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(const std::string &name, const Point &location, int hitPoints, int speed)
    : Character(name, location, hitPoints), speed(speed)
{
}

Ninja::Ninja(const Ninja &other)
    : Character(other), speed(other.speed)
{
}

Ninja& Ninja::operator=(const Ninja &other)
{
    if (this != &other)
    {
        Character::operator=(other);
        speed = other.speed;
    }
    return *this;
}

void Ninja::move(Character *enemy)
{
}

void Ninja::slash(Character *enemy)
{
}

int Ninja::getSpeed()
{
    return speed;
}

std::string Ninja::print() const
{
    return "hi";
}
