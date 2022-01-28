#include "hangman.h"
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;


void ShowGallows(int limit)
{
	cout << "\n";
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
	cout << "\n";
	
}

void ShowSolved(char guess, char word[10], char guesses[], char incorrectGuesses[])
{
	int wordLength = 8;
	char word[9] = "activate";
	//If the word containes the guessed letter, .
	if (strchr("activate", guess))
	{
		for (int i = 0; i < 8; i++)
		{
			if (word[i] == guess)
				word[i] = guess;
		}
	}
	else
	{

	}

}