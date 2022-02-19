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
    //Keep asking for a proper int if the user inputs a string or if the 
    //inputted number is less than or equal to 0.
    while (cin.fail() || numOfScores <= 0)
    {
        //Clear input and discard extracted characters from input sequence to prevent crashes.
        cin.clear();
        cin.ignore(256, '\n');
        //Ask the user for a valid input value.
        cout << "No strings or numbers less than or equal to 0 allowed. Enter the number of scores to use: ";
        cin >> numOfScores;
    }
    //Create a pointer that points to # of inputted float values.
    float* scores = new float[numOfScores];
    //Ask for input to add values to pointer array.
    for (int i = 0; i < numOfScores; i++)
    {
        //Ask for a value to be added to pointer array.
        cout << "Enter a score: ";
        cin >> scores[i];
        //Ask for another answer if input is not an int or is less than 0.
        while (cin.fail() || scores[i] <= 0)
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
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += scores[i];
    }
    //Take the average, round it to the nearest int, and print it out.
    cout << "Average Score is " << static_cast<int>(sum)/count <<"\n";

}
/// <summary>
/// This method goes through a pointer array of floats and determines the highest element value.
/// </summary>
/// <param name="scores">The float pointer that's holding the float values.</param>
/// <param name="count">The # of variables to read in.</param>
void HighScore(float* scores, int count)
{
    //Set a variable to hold the highest value.
    float highestScore = -10000;
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
    float lowestScore = 10000;
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
