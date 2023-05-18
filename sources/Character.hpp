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
        Character(const std::string &name, const Point &location, int hitPoints);
        Character(const Character &other); 
        Character& operator=(const Character &other); 
        virtual ~Character() = default;
        bool isAlive() const;
        double distance(const Character &other) const;
        void hit(int damage);
        std::string getName() const;
        Point getLocation() const;
        int getHitPoints();
        virtual std::string print() const
        {
            return "Character: ";
        }
    };
}

#endif /* CHARACTER_HPP */
