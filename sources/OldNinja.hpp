#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location);
        OldNinja(OldNinja &other); 
        OldNinja& operator=(OldNinja &other); 
    };
}

#endif /* OLD_NINJA_HPP */
