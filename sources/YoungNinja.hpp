#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location);
        YoungNinja(const YoungNinja &other); 
        YoungNinja& operator=(const YoungNinja &other);
    };
}

#endif /* YOUNG_NINJA_HPP */
