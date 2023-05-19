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
        bool inTeam;

    public:
        Character(const std::string &name, const Point &location, int hitPoints);
        Character(Character &other);
        Character &operator=(Character &other);
        virtual ~Character() = default;
        bool isAlive();
        double distance(const Character &other); 
        void hit(int damage);
        std::string getName();
        Point getLocation();
        void setLocation(Point location);
        int getHitPoints();
        bool getInTeam();
        void setInTeam(bool ans);
        double distance(Character* other);
        virtual std::string print() = 0;
    };
}

#endif /* CHARACTER_HPP */
