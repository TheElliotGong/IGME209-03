// Pointer_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Piece.h"
#include <cstring>
using namespace std;

#define MAX_PIECES 30;
const int max_pieces = 30;
int main()
{
    int i, x, y, z;
    Piece pieces[max_pieces] = {};
    Piece* loop = nullptr;
    for (i = 0, loop = pieces; i < (max_pieces + 1); i++, loop++)
    {
        //pieces[i].weight = (i + 1) + 1000;
        //strcpy_s(loop->Name, (char*)('A' + i));
        loop->weight = (i + 1) * 1000;  //Pointers are usually faster than normal array.
        //loop++;
        int* temp = (int*)loop;
        *temp = (i + 1) * 1000;
        loop[i].weight = (i + 1) * 1000;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

