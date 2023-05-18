#include "TrainedNinja.hpp"

using namespace ariel;
using namespace std;

TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 120, 12)
{
}

TrainedNinja::TrainedNinja(TrainedNinja &other)
    : Ninja(other)
{
}

TrainedNinja& TrainedNinja::operator=(TrainedNinja &other)
{
    if (this != &other)
    {
        Ninja::operator=(other);
    }
    return *this;
}
