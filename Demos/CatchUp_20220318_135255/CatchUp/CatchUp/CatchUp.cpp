// CatchUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    cout << "Catch Up Demo" << endl;

    int* maze = new int[50000];
    int cnt = 0;
    int allocateCount = 1;
    while (true)
    {
        if (_kbhit())
            break;
        cnt++;
        if (cnt % 40000 == 0)
        {
            delete[] maze;
            maze = new int[allocateCount * 20000];
            allocateCount++;
        }
    }
    delete[] maze;
    _getch();
}

