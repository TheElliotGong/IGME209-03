// CAtchup2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintHello()
{
    cout << "Hello" << endl;
}
void PrintGoodbye()
{
    cout << "goodbye" << endl;
}

int main()
{
    typedef void (*georgePtr)();

    georgePtr myFunctionPtr = &PrintHello;
    (*myFunctionPtr)();
    myFunctionPtr = &PrintGoodbye;
    myFunctionPtr();

    std::cout << "Hello World!\n";
}

