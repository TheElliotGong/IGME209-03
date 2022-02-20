// Exam1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Author: Elliot Gong
* Section: 03
* Date: 2/15/2022
* Exam #1
*/
#include <iostream>
#include <ctype.h>
#include <cctype>
#include <math.h>
using namespace std;


//Declare my functions ahead of main.
void AverageScore(float* scores, int count);
void HighScore(float* scores, int count);
void LowScore(float* scores, int count);
int main()
{
    
    //Keep track of how many scores the user shall put in.
    int numOfScores;
    //This c++ string will hold the input sequence.
    float input;
    //Ask for how many scores they want to use.
    //Check if user input was a bad case: Either below or equal to 0 or not a number
    cout << "Enter the number of scores to use. It must be greater than 0: ";
    cin >> input;
    /*This saves the length of the char array holding the input.
    int length = sizeof(input) / sizeof(char);
    int badCases = 0;
    //Loop through the char 
    for (int i = 0; i < length; i++)
    {
        if (isdigit(input[i]) == 0)
        {

        }
    }*/
    //Keep asking user for valid number if input is invalid or the inputted number is less than or 
    //equal to 0.
    while (!cin || input <= 0)
    {
        //Clear input and discard extracted characters from input sequence to prevent crashes.
        cin.clear();
        cin.ignore(256, '\n');
        //Ask the user for a valid input value.
        cout << "No strings or numbers less than or equal to 0 allowed. Enter the number of scores to use: ";
        cin >> input;
    }
    //Convert the inputted float to a proper int value.    
    numOfScores = (int)input;
    //Create a pointer that points to # of inputted float values.
    float* scores = new float[numOfScores];
    //Ask for input to add values to pointer array.
    for (int i = 0; i < numOfScores; i++)
    {
        //Ask for a value to be added to pointer array.
        cout << "Enter a score. It must be greater than 0: ";
        cin >> scores[i];
        //Ask for another answer if input is not an int or is less than 0.
        while (!cin || scores[i] <= 0)
        {
            //Clear input and discard extracted characters from input sequence to prevent crashes.
            cin.clear();
            cin.ignore(256, '\n');
            //Ask the user for a valid input value.
            cout << "No strings or numbers less than or equal to 0 allowed. Enter a score: ";
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
    //Initialze and add up sum of scores.
    float sum = 0.0f;
    for (int i = 0; i < count; i++)
    {
        sum += scores[i];
    }
    //Take the average, round it to the nearest lowest integer, and print it out.
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
