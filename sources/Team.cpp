#include "Team.hpp"

using namespace std;
namespace ariel
{

    Team::Team(Character *leader) : leader(leader)
    {
        // this->fighters.push_back(leader);
        this->add(leader);
    }

    void Team::add(Character *fighter)
    {
        if (fighter->getInTeam() == true)
        {
            throw runtime_error("This member already a member");
        }
        else if (fighters.size() == 10)
        {
            throw runtime_error("There are no more places in the group");
        }
        else
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
            {
                fighters.insert(fighters.begin(), fighter);
            }
            else
            {
                fighters.push_back(fighter);
            }
            // this->fighters.push_back(fighter);
            fighter->setInTeam(true);
        }
    }

    int Team::stillAlive() const
    {
        int count = 0;
        for (const auto &fighter : this->fighters)
        {
            if (fighter->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    Character *Team::findClosest(Point location)
    {
        Character *closest = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (const auto &fighter : this->fighters)
        {
            if (fighter->isAlive() && fighter->getLocation().distance(leader->getLocation()) < minDistance)
            {
                closest = fighter;
                minDistance = fighter->getLocation().distance(leader->getLocation());
            }
        }
        return closest;
    }

    Character *Team::findNextVictim(Character *leader)
    {
        return findClosest(leader->getLocation());
    }

    void Team::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr || leader == nullptr)
        {
            throw invalid_argument("Enemy/leader is nullptr");
        }
        if (!enemyTeam->stillAlive())
        {
            throw std::runtime_error("can not attach dead team");
        }
        if (!this->leader->isAlive())
        {
            this->leader = findClosest(this->leader->getLocation());
        }

        Character *victim = enemyTeam->findNextVictim(this->leader);
        // while (victim != nullptr && this->stillAlive() > 0)
        // {
        for (auto &fighter : this->fighters)
        {
            if (fighter->isAlive())
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                if (cowboy != nullptr)
                {
                    if (cowboy->hasboolets())
                    {
                        cowboy->shoot(victim);
                    }
                    else
                    {
                        cowboy->reload();
                    }
                }
                else
                {
                    Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                    if (ninja != nullptr)
                    {
                        if (ninja->distance(*victim) <= 1)
                        {
                            ninja->slash(victim);
                        }
                        else
                        {
                            ninja->move(victim);
                        }
                    }
                }
                if (!victim->isAlive())
                {
                    victim = enemyTeam->findNextVictim(this->leader);
                    if (victim == nullptr)
                    {
                        break;
                    }
                }
            }
        }
        // }
        // cout << "this Team after attack : \n" << this->print() << endl;
        // cout << "enemy Team after attack : \n" << enemyTeam->print() << endl;
    }

    std::string Team::print() const
    {
        std::string result;
        for (const auto &fighter : this->fighters)
        {
            result += fighter->print();
            result += "\n";
        }
        return result;
    }

    vector<Character*>& Team::getFighters()
    {
        return this->fighters;
    }
}

// #include "Team.hpp"

// using namespace std;

// namespace ariel
// {
//     Team::Team(Character * leader) : leader(leader)
//     {
//     }

//     void Team::add(Character * character)
//     {
//         // std::unique_ptr<Character> character_ptr(character);
//     }

//     void Team::attack(Team * enemyTeam)
//     {
//         // Team& enemy = *enemyTeam;
//     }

//     int Team::stillAlive() const
//     {
//         return 0;
//     }

//     std::string Team::print() const
//     {
//     }
// }