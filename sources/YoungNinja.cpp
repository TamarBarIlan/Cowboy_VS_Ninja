#include "YoungNinja.hpp"

using namespace ariel;
using namespace std;

YoungNinja::YoungNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 100, 14)
{
}

YoungNinja::YoungNinja(const YoungNinja &other)
    : Ninja(other)
{
}

YoungNinja& YoungNinja::operator=(const YoungNinja &other)
{
    if (this != &other)
    {
        Ninja::operator=(other);
    }
    return *this;
}
