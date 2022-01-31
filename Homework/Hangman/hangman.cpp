#include "hangman.h"

/*Author: Elliot Gong
  Purpose: Initialize the functions declared in the hangman.h file.
  Restrictions: Must use the same parameters declared for the function declarations in 
  the header file.
  Date: 1/30/2022*/

//Add in the appropriate default/string header files
#include <iostream>
#include <cstring>
#include <string.h>
//Also use the std namespace to simplify printing and input.
using namespace std;

/// <summary>
/// This method draws the hangman gallows based on the # of incorrect guesses the player made.
/// </summary>
/// <param name="limit"></param>
void ShowGallows(int limit)
{
	cout << "\n";
	//Draw the hangman gallows based on the # of incorrect guesses.
		//Player is allowed 5 incorrect guesses. IF they make a 6th wrong guess, they lose,
		//and the man is hanged.
	switch(limit)
	{
		//Plain gallows. Appears if user has not guessed incorrectly yet.
		case 0: 
		cout << "        _________\n" 
				"        |   |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n";
			break;
		//Head appears when 1 incorrect guess is made.
		case 1: 
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |\n"
				"        |\n"
				"        |\n"
				"        |\n";
			break;
		//Head + body, when 2 incorrect guesses occur.
		case 2: 
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |   |\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
			break;
		//Head + body + left arm, when 3 incorrect guesses occur.
		case 3:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
			break;
		//Head, body, and arms. Player has made 4 incorrect guesses.
		case 4:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
			break;
		//Fully body minus right leg. Player can't make anymore incorrect guesses.
		case 5:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\\n"
				"        |   |\n"
				"        |  /\n"
				"        |\n";
			break;
		//Full body is hanged. Player has lost.
		case 6:
			cout << "    ________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\\n"
				"        |   |\n"
				"        |  / \\ \n"
				"        |\n";
			break;
	}
	cout << "\n";
	
}
/// <summary>
/// Print out the feedback to the user after they guess a letter in hangman.
/// </summary>
/// <param name="incorrectGuesses">The array containing all the incorrectly guessed letters.</param>
/// <param name="guessedWord">The blank word that'll gradually be filled in with correctly guessed letters.</param>
/// <param name="wordLength">The # of remaining letters to guess.</param>
void ShowSolved(char incorrectGuesses[], char guessedWord[], int wordLength)
{
	//Print out the info using the cout call.
	cout << "Wrong Guesses: " << incorrectGuesses << "\n"
		<< "Word to solve: " << guessedWord << "\n"
		<< wordLength << " letters left to guess\n";

}



