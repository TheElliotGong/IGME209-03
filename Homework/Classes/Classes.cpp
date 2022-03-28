// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Player.h"
#include "Fighter.h"
int main()
{
    Player p1 = Player();
    Player p2 = Player(8, 15, 30, "Eddie");
    Player* p3 = new Player();
    Player* p4 = new Player(10, 12, 45, "Jordan");

    Fighter brawler = Fighter(15, 30, 12, "Alex", "Axes");
    Fighter* duelist = new Fighter(14, 20, 35, "Robert", "Rapiers");

    p1.PrintPlayer();
    p2.PrintPlayer();
    p3->PrintPlayer();
    p4->PrintPlayer();

    brawler.PrintFighter();
    duelist->PrintFighter();

    delete p3;
    delete p4;
    delete duelist;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
