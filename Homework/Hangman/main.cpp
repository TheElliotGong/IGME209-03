// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <cstring>
#include "hangman.h"
using namespace std;

char word[] = "hey";
int main()
{

    char word[100] = "activate";
    char correctLetters[100];
    char incorrectLetters[100];
    int wordLength = 8;
    char guesses[100];

    cout << "Let's play Hangman!\nYour word has " 
         << wordLength << " letters in it.\n";
    
    cout << "";
    cout << "What letter do you guess next?\nGuess: ";
    std::cin.getline(guesses, 2);

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
