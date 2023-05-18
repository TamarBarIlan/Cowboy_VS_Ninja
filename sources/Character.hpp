#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "Point.hpp"

namespace ariel
{
    class Character
    {
    private:
        std::string name;
        Point location;
        int hitPoints;

    public:
        Character(const std::string &name,const Point &location, int hitPoints);
        Character(Character &other);
        Character &operator=(Character &other);
        virtual ~Character() = default;
        bool isAlive();
        double distance(Character &other);
        void hit(int damage);
        std::string getName();
        Point getLocation();
        int getHitPoints();
        virtual std::string print()
        {
            return "Character: ";
        }
    };
}

#endif /* CHARACTER_HPP */
