#include "hangman.h"

void ShowGallows(int limit)
{
	cout << "";
	switch(limit)
	{
		case 0: 
		cout << "       __________\n" 
				"        |   |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n"
			    "        |\n";
		case 1: 
			cout << "       __________\n"
				"        |   |\n"
				"        |   O\n"
				"        |\n"
				"        |\n"
				"        |\n"
				"        |\n";
		case 2: 
			cout << "       __________\n"
				"        |   |\n"
				"        |   O\n"
				"        |   |\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
		case 3:
			cout << "       __________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
		case 4:
			cout << "       __________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\n"
				"        |   |\n"
				"        |\n"
				"        |\n";
		case 5:
			cout << "       __________\n"
				"        |   |\n"
				"        |   O\n"
				"        |  /|\\n"
				"        |   |\n"
				"        |  /\n"
				"        |\n";
		case 6:
			cout << "       __________\n"
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