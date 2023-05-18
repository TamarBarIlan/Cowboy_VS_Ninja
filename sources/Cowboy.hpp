#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int boollets;

    public:
        Cowboy(const std:: string &name, const Point &location);
        Cowboy(Cowboy &other);
        Cowboy &operator=(Cowboy &other);
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        int getBoollets();
        std::string print() override;
    };
}

#endif /* COWBOY_HPP */