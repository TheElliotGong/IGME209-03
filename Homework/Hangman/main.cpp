// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "hangman.h"
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //The "blank word" that'll be filled in with the correct letters.
    char guessedWord[10] = "________";
    //The word that the player is trying to guess.
    char word[10] = "activate";
    //Array that stores all the incorrect letters.
    char incorrectGuesses[7];
    //Array that stores the correct letters.
    char correctGuesses[50];
    //Array that stores all the guessed letters.
    char allGuesses[50];
    char input[2];
    //The character the user guesses in each round.
    char guess;
    //Counter for the # of incorrect guesses.
    int limit = 0;
    int wordLength = 8;
    //Index of the arr
    int guessesIndex = 0;
    int correctIndex = 0;
    int incorrectGuessIndex = 0;
    //Intro to the game.
    cout << "Let's play Hangman!\nYour word has 8 letters in it! \n \n";
    
    while (limit < 6 && wordLength > 0)
    {
        //Get the guessed letter from the user.
        cout << "What letter do you guess next? ";
        //Save the inputted character in an array.
        cin >> guess;
        //Get the guessed character from the input array.
        input[0] = guess;
       
        /*while (strchr(allGuesses, guess))
        {
            cout << "You already guessed that letter. Pick another one: ";
            cin >> guess;
            guess = input[0];
        }*/
        //Display the guessed letter for the player.
        cout << "Guess: " << guess << "\n";
        //Add the correctly guessed letter to the appropriate arrays.
       

        if (strchr("activate", guess))
        {
            allGuesses[guessesIndex] = guess;
            correctGuesses[correctIndex] = guess;
            guessesIndex++;
            correctIndex++;
            //strcat_s(correctGuesses, input);
            ShowGallows(limit);
            for (int i = 0; i < 8; i++)
            {
                if (word[i] == guess)
                {
                    guessedWord[i] = guess;
                    wordLength--;
                }     
            }
            //The value of "incorrectLetters" is off.
            cout << "Wrong Guesses: " << incorrectGuesses << "\n"
                 <<"Word to solve: " << guessedWord << "\n"
                 << wordLength << " letters left to guess\n";
        }
        else
        {
            // strcat_s(allGuesses, input);
            //strcat_s(incorrectGuesses, input);
            allGuesses[guessesIndex] = guess;
            incorrectGuesses[incorrectGuessIndex] = guess;
            guessesIndex++;
            incorrectGuessIndex++;
            limit++;
            ShowGallows(limit);

            cout << "Wrong Guesses: " << incorrectGuesses << "\n"
                 << "Word to solve: " << guessedWord << "\n"
                 << wordLength << " letters left to guess\n";
        }
        cout << "";

        
    }
    if (limit == 6)
    {
        cout << "You missed too many guesses. Sorry!";
    }
    if (wordLength == 0)
    {
        cout << "You win!!";
    }

    

}
