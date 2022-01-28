#include "hangman.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
using namespace std;


void ShowGallows(int limit)
{
	cout << "";
	switch(limit)
	{
		//Draw the hangman gallows based on the # of incorrect guesses.
		//Player is allowed 5 incorrect guesses. IF they make a 6th wrong guess, they lose,
		//and the man is hanged.
		case 0: 
		cout << "        _________\n" 
				"        |   |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n";
			break;
		case 1: 
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |\n"
				"        |\n"
				"        |\n"
				"        |\n";
			break;
		case 2: 
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |   |\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
			break;
		case 3:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
			break;
		case 4:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
			break;
		case 5:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\\n"
				"        |   |\n"
				"        |  /\n"
				"        |\n";
			break;
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
	cout << "";
	
}

void ShowSolved(char word[10], char guessedWord[10], char guesses[], char incorrectGuesses[])
{
	int wordLength = 9;
	//Gets the most recently guessed letter and see if the word contains said letter.
	
	char lastguess = guesses[strlen(guesses) - 1];
	for (int i = 0; i < 9; i++)
	{
		//Fill in the blank spot(s) with the letter that was correctly guessed.
		if (word[i] == lastguess)
		{
			guessedWord[i] = lastguess;
			wordLength--;
		}
	}
	cout << "Wrong Guesses: " << incorrectGuesses << "\n"
		<< "Word to solve: " << guessedWord << "\n"
		<< wordLength << " letters left to guess.";

}