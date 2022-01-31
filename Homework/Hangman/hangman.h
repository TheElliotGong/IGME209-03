#pragma once
/*Author: Elliot Gong
  Purpose: Declare functions in header file.
  Restrictions: Must have at least 2 required functions, with necessary parameters.
  Date: 1/30/2022*/

//Declare the functions.

//This function draws the gallows and hanged man.
void ShowGallows(int limit);

//This function displays info regarding the solved word and the user's guesses.
void ShowSolved(char incorrectGuesses[], char guessedWord[], int wordLength);
