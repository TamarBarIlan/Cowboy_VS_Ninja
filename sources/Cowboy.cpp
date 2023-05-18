#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy::Cowboy(const std::string &name, Point &location) : Character(name, location, 110), bullets(6) {}

Cowboy::Cowboy(const Cowboy &other) : Character(other), bullets(other.bullets) {}

Cowboy &Cowboy::operator=(const Cowboy &other)
{
    if (this != &other)
    {
        Character::operator=(other);
        bullets = other.bullets;
    }
    return *this;
}

void Cowboy::shoot(Character *enemy)
{
    // Implementation of shoot function
}

bool Cowboy::hasBullets() const
{
    return bullets > 0;
}

void Cowboy::reload()
{
    // Implementation of reload function
}

int Cowboy::getBullets()
{
    return bullets;
}

std::string Cowboy::print() const
{
    return "hi";
}