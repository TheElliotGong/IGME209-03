// PointerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Piece.h"
using namespace std;

const int max_pieces = 2;

int main()
{
    int x, y, z, i;
    Piece pieces[max_pieces] = { };
    Piece* loop = nullptr;
    for (i=0, loop = pieces; i < (max_pieces+1); i++, loop++)
    {
        // pieces[i].weight = (i + 1) * 1000;
        // strcpy_s(loop->Name, (char*)('A' + i));
        loop->weight = (i + 1) * 1000;
        // loop++;
        // loop--;
        // loop += 2;
        int* temp = (int*)loop;
        *temp = (i + 1) * 1000;
        temp[-3] = (i + 1) * 1000;

        pieces[i].weight = (i + 1) * 1000;

    }



    cout << "Hello World!\n";
}

