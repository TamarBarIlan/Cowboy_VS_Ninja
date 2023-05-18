#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(const std::string &nameVal, Point &locationVal);
        Cowboy(const Cowboy &other); 
        Cowboy &operator=(const Cowboy &other); 
        void shoot(Character *enemy);
        bool hasBullets() const;
        void reload();
        int getBullets();
        std::string print() const override;
    };
}

#endif /* COWBOY_HPP */