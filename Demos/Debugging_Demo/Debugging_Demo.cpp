// Debugging_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
    cout << "Hello"; //Sometimes, try splitting line up to see which part of it isn't working.
    cout << std::endl;
    
    int num = 10.f;
    int den = 0.f;

    float res = num / den;
    print(res);
    int x;
    cin >> x;
}

void print(float x)
{
    cout << x;
}