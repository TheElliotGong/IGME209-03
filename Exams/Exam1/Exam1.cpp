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
#include <stdlib.h>
using namespace std;


//Declare my functions ahead of main.
void AverageScore(float* scores, int count);
void HighScore(float* scores, int count);
void LowScore(float* scores, int count);
void GetScoreCount(char scoreCountInput[], int& intVar);
void GetCurrentScore(char scoreInput[], float& floatVar);
//float CharArrayToFloat(char* array);

int main()
{
    //This int variable keeps track of how many scores there are.
    int numOfScores;
    float currentScore;
    //This array keeps track of the string input used to determine the # of scores.
    char input[30];
    //This array keeps track of the string input used to enter float scores.
    char scoreInput[50];
    //Ask the user for how many scores they want to use.
    //Keep asking them for input if the input is invalid, empty, or if the inputted number 
    //is less than or equal to 0.
    GetScoreCount(input, numOfScores);
    while(numOfScores <= 0 || strlen(input) == 0)
    {
        //Clear input stream for the next sequence.
        //Reprompt the user for input.
        GetScoreCount(input, numOfScores);
    }
    //Create a pointer that points to # of inputted float values.
    float* scores = new float[numOfScores];
    //Ask for input to add values to pointer array.
    for (int i = 0; i < numOfScores; i++)
    {
        //Prompt user input, and parse 
        cout << "No strings, blank input, or numbers less or equal to than 0 allowed. Enter a Score: ";
        cin.getline(scoreInput, 50);
        currentScore = atof(scoreInput);
        while (currentScore <= 0 || strlen(scoreInput) == 0)
        {
            //Reprompt them for input.
            cout << "No strings, blank input, or numbers less or equal to than 0 allowed. Enter a Score: ";
            cin.getline(scoreInput, 50);
            currentScore = atof(scoreInput);
        }
        //After input is finally valid, add it to the pointer array.
        scores[i] = currentScore;
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
/// This method takes a float pointer array and determines the average value of the elements, rounded 
/// to the nearest integer.
/// </summary>
/// <param name="scores">The float pointer that's holding the float values.</param>
/// <param name="count">The # of float variables to sift through</param>
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
/// <param name="count">The # of float variables to sift through</param>
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
/// <param name="count">The # of float variables to sift through</param>
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
/// <summary>
/// This function takes a char array and parses any possible int value from it, and assign
/// that value to the reference int parameter.
/// </summary>
/// <param name="scoreCountInput">The input/char array to parse the desired score count from.</param>
/// <param name="value">The variable to assign any int value to.</param>
void GetScoreCount(char scoreCountInput[], int& intVar)
{
    //Prompt the user for input and save it to the array.
    cout << "Enter the number of scores to use. No strings, empty input, or numbers less than or equal to 0 allowed: ";
    cin.getline(scoreCountInput, 70);
    //Whatever int value was parsed from the int, save it to the reference parameter.
    intVar = atoi(scoreCountInput);
}

void GetCurrentScore(char scoreInput[], float& floatVar)
{

}