// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "hangman.h"
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char guessedWord[10] = "_________";
    char word[10] = "activate";
    char incorrectLetters[7];
    char guesses[70];
    char guess;
    int limit = 0;
    int guessesIndex = 0;
    int incorrectGuessIndex = 0;
    cout << "Let's play Hangman!\nYour word has 9 letters in it! \n \n";
    
    while (limit < 6 && strcmp(guessedWord, word) == false)
    {
        //Get the guessed letter from the user.
        cout << "What letter do you guess next? ";
        cin >> guess;
        cout << "Guess: " << guess;
        //Add the inputted letters to the array of guessed letters.
        //Checks if the word contains the guessed letter.
        if (strchr(word, guess))
        {
            guesses[guessesIndex] = guess;
            guessesIndex++;
            //Draw the gallows as appropriate.
            ShowGallows(limit);
            //Add the instances of the correctly guessed letters to the displayed word.
        }
        else
        {
            
            incorrectLetters[incorrectGuessIndex] = guess;
            incorrectGuessIndex++;
            limit++;
            ShowGallows(limit);
            
            cout << "Wrong guesses: " << incorrectLetters << "\n"
                << "Word to solve: " << guessedWord << "\n \n";
        }
    }
    if (limit == 7)
    {
        cout << "You missed too many guesses. Sorry!";
    }
    if (strcmp(guessedWord, word))
    {
        cout << "You win!!";
    }

    

}
