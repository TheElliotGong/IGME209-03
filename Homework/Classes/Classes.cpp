// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Include the header files.
#include "Player.h"
#include "Fighter.h"
#include <stdlib.h>
#include <time.h>
int main()
{
    //Set the srand at the beginning to reset random generation.
    srand(time(NULL));
    //Print out the tournament name.
    cout << "Welcome to the Tournament of Failures!!\n";
    //Create some basic player and fighter objects/pointers.
    Player p1 = Player();
    Player p2 = Player(8, 15, 30, "Eddie");
    Player* p3 = new Player();
    Player* p4 = new Player(10, 12, 45, "Jordan");
    Fighter brawler = Fighter(15, 30, 12, "Alex", "Axes");
    Fighter* duelist = new Fighter(14, 20, 35, "Robert", "Rapiers");
    //Call the Print methods of the objects.
    p1.PrintPlayer();
    p2.PrintPlayer();
    p3->PrintPlayer();
    p4->PrintPlayer();
    brawler.PrintFighter();
    duelist->PrintFighter();
    //Delete the objects.
    p1.~Player();
    p2.~Player();
    delete p3;
    delete p4;
    brawler.~Fighter();
    delete duelist;
    //Create some int variables to use for indexing.
    int choice;
    int nameIndex;
    int weaponIndex;
    //Create some string arrays to hold names and weapon skills.
    string names[] = {"Donald", "Howie", "Peter", "Carter", "Zack", 
                          "Richard", "Tim", "Fred", "Steven", "Barnes"};
    string weapons[] = { "swords", "guns", "bombs", "shields", "spears", "whips", "clubs" };
    //Create a pointer array of player objects.
    Player* players[10];
    //For each spot in the player pointre array, create a randomly generated Player or Fighter object.
    for (int i = 0; i < 10; i++)
    {
        //Assign a randomly generated index to the local int variables.
        weaponIndex = rand() % 7;
        nameIndex = rand() % 10;
        //This determines if a newly created object should be a player or a fighter.
        //Once the choice has been made, create the Player or Fighter object using a random name and/or weapon skill.
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
    //Have each player attack the one preceding them in the array. When players are attacked, they also 'die'. 
    //When that happens, delete the objects and set the pointers to null.
    for (int i = 0; i < 9; i++)
    {
        players[i + 1]->Attack(players[i]);
        delete players[i];
        players[i] = nullptr;
    }
    //In this case, the last player should be the last one standing, so declare them the winner.
    cout << players[9]->GetName() << " is the winner!\n";
    delete players[9];
    players[9] = nullptr;
    return 0;
}

