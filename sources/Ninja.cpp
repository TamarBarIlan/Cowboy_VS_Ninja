#include "Ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(const std::string &name, const Point &location, int hitPoints, int speed)
    : Character(name, location, hitPoints), speed(speed)
{
}

Ninja::Ninja(Ninja &other)
    : Character(other), speed(other.speed)
{
}

Ninja &Ninja::operator=(Ninja &other)
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
    this->getLocation() = Point::moveTowards(this->getLocation(), enemy->getLocation(), speed);
}

void Ninja::slash(Character *enemy)
{
    if (this->isAlive())
    {
        double distance = this->getLocation().distance(enemy->getLocation());

        if (distance < 1.0)
        {
            enemy->hit(40);
        }
    }
}

int Ninja::getSpeed()
{
    return this->speed;
}

std::string Ninja::print() {
    
    std::stringstream ss;

    ss << "N: ";

    if (this->getHitPoints() <= 0) {
        ss << "(" << this->getName() << ") ";
    } else {
        ss << this->getName() << " " << this->getHitPoints() << " ";
    }

    ss << this->getLocation().print();

    return ss.str();
}
