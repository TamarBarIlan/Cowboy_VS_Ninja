#include "Team2.hpp"
using namespace ariel;
using namespace std;

Team2::Team2(Character* leader) : Team(leader) {}

void Team2::add(Character *fighter)
    {
        if (fighter->getInTeam() == true)
        {
            throw runtime_error("This member already a member");
        }
        else if (getFighters().size() == 10)
        {
            throw runtime_error("There are no more places in the group");
        }
        else
        {
            this->getFighters().push_back(fighter);
            fighter->setInTeam(true);
        }
    }