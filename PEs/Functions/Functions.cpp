// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//Include the header file we made that contains the name function.
#include "functions.h"

/* Author: Elliot Gong
   Date: 1/17/2022
   Purpose: Test out the usage of functions and header files.
   Restrictions: Must declare a function signature in a header file and 
   include it in the main program.*/

int main()
{
    cout << "Hello World!\n";
    //Call the defined function.
    PrintName();
}
//Define the function declared in the functions header file.
void PrintName()
{
    cout << "I'm Elliot Gong\n";
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
