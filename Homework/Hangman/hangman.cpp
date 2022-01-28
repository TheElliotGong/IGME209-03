#include "hangman.h"

int wordLength = 9;

void ShowGallows(int limit)
{
	cout << "";
	switch(limit)
	{
		//Draw the hangman gallows based on the # of incorrect guesses.
		//Player is allowed 5 incorrec guesses. IF they make a 6th wrong guess, they lose,
		//and the man is hanged.
		case 0: 
		cout << "        _________\n" 
				"        |   |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n";
		case 1: 
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |\n"
				"        |\n"
				"        |\n"
				"        |\n";
		case 2: 
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |   |\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
		case 3:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
		case 4:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
		case 5:
			cout << "    _________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\n"
				"        |   |\n"
				"        |  /\n"
				"        |\n";
		case 6:
			cout << "    ________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\n"
				"        |   |\n"
				"        |  / \ \n"
				"        |\n";
	}
	cout << "";
	
}

void ShowSolved(char word[10], char correctGuesses[])
{
	char desiredWord[] = "activate";
	//Gets the most recently guessed letter and see if the word contains said letter.



}