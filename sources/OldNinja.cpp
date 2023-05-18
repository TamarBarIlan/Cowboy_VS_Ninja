#include "OldNinja.hpp"

using namespace ariel;
using namespace std;

OldNinja::OldNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 150, 8)
{
}

OldNinja::OldNinja(OldNinja &other)
    : Ninja(other)
{
}

OldNinja& OldNinja::operator=(OldNinja &other)
{
    if (this != &other)
    {
        Ninja::operator=(other);
    }
    return *this;
}
