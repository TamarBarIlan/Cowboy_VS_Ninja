#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(const std::string &name, const Point &location, int hitPoints, int speed);
        Ninja(const Ninja &other); // Copy constructor
        Ninja& operator=(const Ninja &other); // Assignment operator
        void move(Character *enemy);
        void slash(Character *enemy);
        int getSpeed();
        std::string print() const override;
    };
}

#endif /* NINJA_HPP */
