// Exam1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Author: Elliot Gong
* Section: IGME 209-03
* Date: 2/15/2022
* Exam #1
*/
#include <iostream>
#include <ctype.h>
#include <cctype>
#include <math.h>
#include <stdio.h>
using namespace std;


//Declare my functions ahead of main.
void AverageScore(float* scores, int count);
void HighScore(float* scores, int count);
void LowScore(float* scores, int count);
//float CharArrayToFloat(char* array);

int main()
{
    //This int variable keeps track of how many scores there are.
    int numOfScores;
    //Ask the user for how many scores they want to use.
    cout << "Enter the number of scores to use. No strings or numbers less than or equal to 0 allowed: ";
    cin >> numOfScores;
    //Keep asking them for input if the input is invalid or if the inputted number is less than or 
    //equal to 0.
    while (!cin || numOfScores <= 0)
    {
        //Clear input stream for the next sequence.
        cin.clear();
        cin.ignore(256, '\n');
        //Reprompt the user for input.
        cout << "Enter the number of scores to use. No strings or numbers less than or equal to 0 allowed: ";
        cin >> numOfScores;
    }
    //Create a pointer that points to # of inputted float values.
    float* scores = new float[numOfScores];
    //Ask for input to add values to pointer array.
    for (int i = 0; i < numOfScores; i++)
    {
        //Clear any potential invalid input left over from the previous input sequence.
        //If this is the first score to be entered, than any leftover data from inputting
        //the # of scores to be read will thankfully be cleared away.
        cin.clear();
        cin.ignore(256, '\n');
        //Ask users for a score.
        cout << "Enter a score: ";
        cin >> scores[i];
        //Keep asking for a score if the input is invalid.
        while (!cin || scores[i] < 0 )
        {
            //Clear the input again to make room for the next sequence.
            cin.clear();
            cin.ignore(256, '\n');
            //Reprompt them for input.
            cout << "Input cannot be a string. Try again: ";
            cin >> scores[i];
        }
    }
    //Call all 3 functions.
    AverageScore(scores, numOfScores);
    HighScore(scores, numOfScores);
    LowScore(scores, numOfScores);
    //Free up memory
    delete[] scores;
    return 0;
}
/// <summary>
/// This method takes a float pointer array and determines the average value of the elements.
/// </summary>
/// <param name="scores">The float pointer that's holding the float values.</param>
/// <param name="count">The # of variables to read in.</param>
void AverageScore(float* scores, int count)
{
    //Initialze a local float variable. 
    float sum = 0.0f;
    //Loop through float pointer and add up sum of values to local variable.
    for (int i = 0; i < count; i++)
    {
        sum += scores[i];
    }
    //Divide local variable by # of scores, round it to the nearest integer, and print it out.
    cout << "Average Score is " << roundf(sum/count) <<"\n";

}
/// <summary>
/// This method goes through a pointer array of floats and determines the highest element value.
/// </summary>
/// <param name="scores">The float pointer that's holding the float values.</param>
/// <param name="count">The # of variables to read in.</param>
void HighScore(float* scores, int count)
{
    //Set a variable to hold the highest value.
    float highestScore = -10000.0f;
    //Loop through the float pointer to determine the highest value.
    for (int i = 0; i < count; i++)
    {
        //Replace the value of the high score if the pointee value is higher.
        if (scores[i] > highestScore)
        {
            highestScore = scores[i];
        }
    }
    //Print out the final highest score.
    cout << "High Score is " << highestScore << "\n";
}
/// <summary>
/// This method goes through a pointer array of floats and determines the lowest element value.
/// </summary>
/// <param name="scores">The float pointer that's holding the float values.</param>
/// <param name="count">The # of variables to read in.</param>
void LowScore(float* scores, int count)
{
    //Set a variable to hold the lowest value.
    float lowestScore = 10000.0f;
    //Loop through the float pointer to determine the lowest value.
    for (int i = 0; i < count; i++)
    {
        //Replace the value of the lower score if the pointee value is lower.
        if (scores[i] < lowestScore)
        {
            lowestScore = scores[i];
        }
    }
    //Print out the final lowest score.
    cout << "Low Score is " << lowestScore << "\n";
}

