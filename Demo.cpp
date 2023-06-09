/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/SmartTeam.hpp"

using namespace ariel;

int main()
{
   //****original demo with printim****

   // Point a(32.3, 44), bp(1.3, 3.5);
   // cout << a.print() << endl;
   // cout << bp.print() << endl;
   // assert(a.distance(bp) == bp.distance(a));

   // Cowboy *tom = new Cowboy("Tom", a);
   // Cowboy *enemy = new Cowboy("Enemy", Point(32.3, 44));
   // cout << tom->print() << endl;
   // cout << enemy->print() << endl;
   // tom->shoot(enemy);
   // cout << tom->print() << endl;
   // cout << enemy->print() << endl;

   // OldNinja *sushi = new OldNinja("sushi", bp);
   // cout << "boollets befor shoot = " << tom->getBoollets() << endl;
   // tom->shoot(sushi);
   // cout << "boollets after shoot = " << tom->getBoollets() << endl;
   // cout << tom->print() << endl;
   // cout << tom->getBoollets() << endl;
   // sushi->move(tom);
   // sushi->slash(tom);

   // cout << "-----start Team:-----" << endl;

   // Team team_A(tom);
   // team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // Team team_B(sushi);
   // team_B.add(new TrainedNinja("Hikari", Point(12, 81)));
   // ;
   // int count = 0;
   // while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   // {
   //    count++;
   //    cout << "count = " << count << endl;
   //    team_A.attack(&team_B);
   //    team_B.attack(&team_A);
   //    cout <<"Team A: \n" <<team_A.print() << endl;
   //    cout << "TeamB: \n" << team_B.print() << endl;
   // }

   // if (team_A.stillAlive() > 0)
   //    cout << "winner is team_A" << endl;
   // else
   //    cout << "winner is team_B" << endl;

   // return 0;

   //****original demo****

   // Point a(32.3, 44), b(1.3, 3.5);
   // assert(a.distance(b) == b.distance(a));
   // Cowboy *tom = new Cowboy("Tom", a);
   // OldNinja *sushi = new OldNinja("sushi", b);
   // tom->shoot(sushi);
   // cout << tom->print() << endl;

   // sushi->move(tom);
   // sushi->slash(tom);

   // Team team_A(tom);
   // team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // // Team b(tom); should throw tom is already in team a

   // Team team_B(sushi);
   // team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   // while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   // {
   //    team_A.attack(&team_B);
   //    team_B.attack(&team_A);
   //    cout << team_A.print() << endl;
   //    cout << team_B.print() << endl;
   // }

   // if (team_A.stillAlive() > 0)
   //    cout << "winner is team_A" << endl;
   // else
   //    cout << "winner is team_B" << endl;

   // return 0;

   //****chack SmartTeam****

   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   tom->shoot(sushi);
   cout << tom->print() << endl;

   sushi->move(tom);
   sushi->slash(tom);

   SmartTeam team_A(tom);
   team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // Team b(tom); should throw tom is already in team a

   SmartTeam team_B(sushi);
   team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   {
      team_A.attack(&team_B);
      team_B.attack(&team_A);
      cout << team_A.print() << endl;
      cout << team_B.print() << endl;
   }

   if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
      cout << "winner is team_B" << endl;

   return 0;
}
