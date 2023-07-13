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


int main()
{
    srand((unsigned)time(NULL));
    //Randomly pick a word to be guessed.
    string words[20] = { "activate", "nowhere", "perceive", "synchronize", "celsius", 
                        "elemental", "advisory", "transformer", "birthday", "vehicle",
                        "delivery", "cantelope", "memorable", "raucous", "dominion",
                        "fantastical", "pervasive", "lamenting", "bombastic", "quantum" };
    int randomIndex = rand() % (sizeof(words)/sizeof(words[0]));
    string word = words[randomIndex];
    //Get the word's length
    int lettersRemaining = words[randomIndex].length();
    int wordLength = lettersRemaining;
    //The "blank word" that'll be filled in with the correct letters.
    vector<char> blankWord;
    for (int i = 0; i < wordLength; i++)
    {blankWord.push_back('_');}
    //Array that stores all the incorrect letters.
    vector<char> incorrectGuesses;
    //Array that stores the correct letters.
    vector<char> correctGuesses;
    //Array that stores all the guessed letters.
    vector<char> allGuesses;
    vector<int> charLocations;
    char input;
    //The character the user guesses in each round.
    char guess;
    //Counter for the # of incorrect guesses.
    int limit = 0;

    //Intro to the game.
    cout << "Note: The game will close immediately whether you guess the word correctly or make too many wrong guesses.\n";
    cout << "Let's play Hangman!\nYour word has " << wordLength << " letters in it!\n \n";
    
    while (limit < 6 && lettersRemaining > 0)
    {
        //Get the guessed letter from the user.
        cout << "What letter do you guess next? ";
        //Save the inputted character in an array.
        cin >> guess;
        //Get the guessed character from the input array.
        input = guess;
       
        while (count(allGuesses.begin(), allGuesses.end(), guess))
        {
            cout << "You already guessed that letter. Pick another one: ";
            cin >> guess;
            input = guess;
        }
        //Display the guessed letter for the player.
        cout << "Guess: " << guess << "\n";
        //Add the correctly guessed letter to the appropriate arrays.
       
        //Do this if the word contains the guessed letter.
        if (word.find(guess) != string::npos)
        {
            //Add the correctly guessed letter to the proper arrays and increment
            //the appropriate indexes for said arrays.
            allGuesses.push_back(guess);
            correctGuesses.push_back(guess);
            //Draw the gallows again
            ShowGallows(limit);
            //Fill out the blank word with the correctly guessed letters.
            for (int i = 0; i < wordLength; i++)
            {
                if (word[i]==input)
                {
                    blankWord[i] = guess;
                    lettersRemaining--;
                }     
            }
            //Display the info to the player.
            ShowSolved(incorrectGuesses, blankWord, lettersRemaining);
        }
        //Do this if the guessed letter isn't in the mystery word.
        else
        {
            //Add the incorrectly guessed letter to the proper arrays and increment
           //the appropriate indexes for said arrays.
            allGuesses.push_back(guess);
            incorrectGuesses.push_back(guess);
            //Increment the variable holding # of incorrect guesses made and draw the gallows.
            limit++;
            ShowGallows(limit);
            //Use the ShowSolved function to display data.
            ShowSolved(incorrectGuesses, blankWord, lettersRemaining);
        }
    }
    cout << "\n";
    //Print out lose condition message.
    if (limit == 6)
    {cout << "You missed too many guesses. Sorry!\nThe word is " << word << ".\n";}
    //Print out the win condition message.
    if (lettersRemaining == 0)
    {cout << "You win!! You guessed all the letters!\n";}
    cin.get();
    return 0;
    
    

    //End the method.

}
