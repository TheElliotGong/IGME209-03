// FileDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Player
{
    int str;
    int intel;
    int wis;
    int dex;
    int con;
    int cha;
};
int main()
{
    std::cout << "File Demo!\n";
    Player p;

    p.str = rand() % 20;
    p.intel = rand() % 20;
    p.wis = rand() % 20;
    p.dex = rand() % 20;
    p.con = rand() % 20;
    p.cha = rand() % 20;


    ofstream outFile("player.data");
    outFile << p.str << " " << p.intel << " " << p.wis << " " << p.dex << " " << p.con << " " << p.cha;
    outFile.close();

    ifstream inFile("player.data");
    Player g;
    inFile >> g.str >> g.intel >> g.wis >> g.dex >> g.con >> g.cha;
    outFile.close();


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
