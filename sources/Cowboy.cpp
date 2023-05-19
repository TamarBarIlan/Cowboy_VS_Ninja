#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy::Cowboy(const string &name, const Point &location)
    : Character(name, location, 110), boollets(6)
{
}

Cowboy::Cowboy(Cowboy &other) : Character(other), boollets(other.boollets)
{
}

Cowboy &Cowboy::operator=(Cowboy &other)
{
    if (this != &other)
    {
        Character::operator=(other);
        boollets = other.boollets;
    }
    return *this;
}

void Cowboy::shoot(Character *enemy)
{
    if (!(this->hasboolets()))
    {
        return;
    }
    if (!(this->isAlive()))
    {
        throw runtime_error("Dead character cant do shoot");
    }
    if (!(enemy->isAlive()))
    {
        throw runtime_error("Cowboy is either dead or has no bullets");
    }
    if (enemy == this)
    {
        throw runtime_error("No self harm");
    }
    enemy->hit(10);
    this->boollets -= 1;
}

bool Cowboy::hasboolets()
{
    return boollets > 0;
}

void Cowboy::reload()
{

    if(this->isAlive() == false)
    {
        throw runtime_error("The cowboy is dead cant reload");
    }
    else
    {
        this->boollets += 6;
        if(this->boollets > 6)
        {
            this->boollets = 6;
        }
    }
}

int Cowboy::getBoollets()
{
    return boollets;
}

std::string Cowboy::print()
{

    std::stringstream ss;

    ss << "C: ";

    if (this->getHitPoints() <= 0)
    {
        ss << "(" << this->getName() << ") ";
    }
    else
    {
        ss << this->getName() << " " << this->getHitPoints() << " ";
    }

    ss << this->getLocation().print();

    return ss.str();
}