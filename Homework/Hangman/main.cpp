// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "hangman.h"

int main()
{
    char guessedWord[10] = "_________";
    char word[10] = "activate";
    char correctLetters[70];
    char incorrectLetters[70];
    char guess;
    int limit = 0;

    cout << "Let's play Hangman!\nYour word has 9 letters in it!";
    cout << "";
    cout << "What letter do you guess next? ";
    cin >> guess;
    
    cout << "Guess: " << guess;
    while (limit < 7)
    {
        if (strchr(word, guess))
        {
            ShowGallows(limit);
            for (int i = 0; i < 9; i++)
            {
                if (word[i] == guess)
                {
                    guessedWord[i] = guess;
                }
            }
            cout << "Wrong Guesses: " << incorrectLetters << "\n"
                << "Word to solve: " << guessedWord << "\n \n";

            
        }
        else
        {
            limit++;
            ShowGallows(limit);
            
            cout << "Wrong guesses: " << incorrectLetters;
        }

    }
    if (limit == 7)
    {
        cout << "You missed too many guesses. Sorry!";
    }
    return 0;

    

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
