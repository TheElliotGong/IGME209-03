// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Player.h"
#include "Fighter.h"
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));

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

    p1.~Player();
    p2.~Player();

    delete p3;
    delete p4;

    brawler.~Fighter();
    delete duelist;

    int choice;
    int nameIndex;
    int weaponIndex;
    const char* names[] = {"Donald", "Howie", "Peter", "Carter", "Zack", 
                          "Richard", "Tim", "Fred", "Steven", "Barnes"};
    const char* weapons[] = { "swords", "guns", "bombs", "shields", "spears", "whips", "clubs" };
    Player* players[10];
    for (int i = 0; i < 10; i++)
    {
        weaponIndex = rand() % 7;
        nameIndex = rand() % 10;
        choice = rand() % 2;
        if (choice == 0)
        {
            players[i] = new Player(5, 10, 12, names[nameIndex]);
        }
        else if (choice == 1)
        {
            players[i] = new Fighter(5, 10, 12, names[nameIndex], weapons[weaponIndex]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        players[i + 1]->Attack(players[i]);
        delete players[i];
        players[i] = nullptr;
    }
    cout << players[9]->GetName() << " is the winner!";
    delete players[9];
    players[9] = nullptr;

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
