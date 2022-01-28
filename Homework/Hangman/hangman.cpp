#include "hangman.h"

void ShowGallows(int limit)
{
	cout << "";
	switch(limit)
	{
		//Draw the hangman gallows based on the # of incorrect guesses.
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
				"        |  / \\n"
				"        |\n";
	}
	cout << "";
	
}

void ShowSolved(char word[], char guesses[])
{

}