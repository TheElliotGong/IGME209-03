// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;
/* Author: Elliot Gong
   Purpose: Practice using C style strings and some of the
   string functions.
   Date: 1/20/2022
   Restrictions: Must include the string.h file and 
   use the specified functions.*/
int main()
{
    //Declare my Marry Poppins catchphrase.
    char word[80] = "supercalifraglistic";
    char word2[80] = " expialidocious";
    //Declare the variables for tracking the string's length
    //and the # of 'i's it contains.
    int stringLength = strlen(word);
    int numberOfIs = 0;
    //Print out the results of my functions.
    cout << "Hello World!\n";
    cout << "The word " << word << " has " << stringLength << " letters.\n";
    strcat_s(word, 50, word2); //Add the rest of the phrase to the first string.
    cout << "The combined phrase is " << word <<"\n";
    //Loop through the phrase and count how many 'i's are in the string.
    for (char letter : word)
    {
        if (letter == 'i')
        {
            numberOfIs++;
        }
    }
    //Print out the # of 'i's in the phrase.
    cout << "There are " << numberOfIs << " instances of the letter i in the phrase.";
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
