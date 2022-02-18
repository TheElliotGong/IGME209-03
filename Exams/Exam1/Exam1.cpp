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
using namespace std;


//Declare my functions ahead of main.
void AverageScore(float* scores, int count);
void HighScore(float* scores, int count);
void LowScore(float* scores, int count);
int main()
{
    int numOfScores;
    //Ask for how many scores they want to use.
    //Check if user input was a bad case: Either below or equal to 0 or not a number
    cout << "Enter the number of scores to use: ";
    cin >> numOfScores;

    while (cin.fail() || numOfScores <= 0)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter the number of scores to use: ";
        cin >> numOfScores;
    }
/*
    while ( numOfScores <= 0)
    {
        cout << "Enter the number of scores to use: ";
        cin >> numOfScores;
    }
    do
    {
        cout << "Enter the number of scores to use: ";
        cin >> numOfScores;
    } while ( numOfScores <= 0);*/
    
    //Create a pointer that points to # of inputted float values.
    float* scores = new float[numOfScores];
    //Ask for input to add values to pointer array.
    for (int i = 0; i < numOfScores; i++)
    {
        cout << "Enter a score: ";
        cin >> scores[i];
    }
    //Call functions.
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
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += scores[i];
    }
    //Take the average and print it out.
    cout << "Average Score is " << (int)sum / count <<"\n";

}
/// <summary>
/// This method goes through a pointer array of floats and determines the highest element value.
/// </summary>
/// <param name="scores">The float pointer that's holding the float values.</param>
/// <param name="count">The # of variables to read in.</param>
void HighScore(float* scores, int count)
{
    float highestScore = -50;
    for (int i = 0; i < count; i++)
    {
        if (scores[i] > highestScore)
        {
            highestScore = scores[i];
        }
    }
    cout << "High Score is " << highestScore << "\n";
}

void LowScore(float* scores, int count)
{
    float lowestScore = 1000;
    for (int i = 0; i < count; i++)
    {
        if (scores[i] < lowestScore)
        {
            lowestScore = scores[i];
        }
    }
    cout << "Low Score is " << lowestScore << "\n";
}
