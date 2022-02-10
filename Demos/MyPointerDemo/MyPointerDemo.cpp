// MyPointerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Piece.h"
using namespace std;

const int maxPieces = 24;
int main()
{
    int x, y, z, i;
    Piece pieces[maxPieces] = {};
    Piece* loop = nullptr;

    for (i = 0, loop = pieces; i < maxPieces && loop != nullptr; i++, loop++)
    {
        //pieces[i].weight = (i + 1 ) * 1000;
       // strcpy_s(loop->Name, (char*)('A' + i));
        loop->weight = (i + 1) * 1000; //This is faster than if we normally loop through an array.

        loop[i].weight = (i + 1) * 1000; //Does the same thing as above, just slower.
    }   

    std::cout << "Hello World!\n";
}

