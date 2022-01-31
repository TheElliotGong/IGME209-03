// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Author: Elliot Gong
  Purpose: Use the external functions to help simulate a game of hangman.
  Restrictions: Must use external functions and get user input to make the game
  functional. Store guesses in appropriate arrays and display drawings and feedback
  to user. Game must keep going until player either wins or loses.
  Date: 1/30/2022*/
#include "hangman.h"
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //The "blank word" that'll be filled in with the correct letters.
    char guessedWord[9] = "________";
    //The word that the player is trying to guess.
    char word[9] = "activate";
    //Array that stores all the incorrect letters.
    char incorrectGuesses[7] = "";
    //Array that stores the correct letters.
    char correctGuesses[50] = "";
    //Array that stores all the guessed letters.
    char allGuesses[50] = "";
    char input[2] = "";
    //The character the user guesses in each round.
    char guess;
    //Counter for the # of incorrect guesses.
    int limit = 0;
    int wordLength = strlen(word);
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
       
        while (strchr(allGuesses, guess))
        {
            cout << "You already guessed that letter. Pick another one: ";
            cin >> guess;
            input[0] = guess;
        }
        //Display the guessed letter for the player.
        cout << "Guess: " << guess << "\n";
        //Add the correctly guessed letter to the appropriate arrays.
       
        //Do this if the word contains the guessed letter.
        if (strchr("activate", guess))
        {
            //Add the correctly guessed letter to the proper arrays and increment
            //the appropriate indexes for said arrays.
            allGuesses[guessesIndex] = guess;
            correctGuesses[correctIndex] = guess;
            guessesIndex++;
            correctIndex++;
            //Draw the gallows again
            ShowGallows(limit);
            //Fill out the blank word with the correctly guessed letters.
            for (int i = 0; i < 8; i++)
            {
                if (word[i] == guess)
                {
                    guessedWord[i] = guess;
                    wordLength--;
                }     
            }
            //Display the info to the player.
            ShowSolved(incorrectGuesses, guessedWord, wordLength);
        }
        //Do this if the guessed letter isn't in the mystery word.
        else
        {
            //Add the incorrectly guessed letter to the proper arrays and increment
           //the appropriate indexes for said arrays.
            allGuesses[guessesIndex] = guess;
            incorrectGuesses[incorrectGuessIndex] = guess;
            guessesIndex++;
            incorrectGuessIndex++;
            //Increment the variable holding # of incorrect guesses made and draw the gallows.
            limit++;
            ShowGallows(limit);
            //Use the ShowSolved function to display data.
            ShowSolved(incorrectGuesses, guessedWord, wordLength);
        }
        cout << "";
    }
    //Print out lose condition message.
    if (limit == 6)
    {
        cout << "You missed too many guesses. Sorry!\nThe word is " << word;
    }
    //Print out the win condition message.
    if (wordLength == 0)
    {
        cout << "You win!! You guessed all the letters to " << word << "!";
    }

    

}
