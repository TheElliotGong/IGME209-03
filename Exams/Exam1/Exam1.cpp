// Exam1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Author: Elliot Gong
* Section: 03
* Date: 2/15/2022
* Exam #1
*/
#include <iostream>
using namespace std;


//Declare my functions ahead of main.
void AverageScore(float* scores, int count);
void HighScore(float* scores, int count);
void LowScore(float* scores, int count);
int main()
{
    int numOfScores;
    //Ask for how many scores they want to use.
    do
    {
        cout << "Enter the number of scores to use: ";
        cin >> numOfScores;
    } while (numOfScores <= 0); //If the inputted number is less than or equal to 0, 
                                //keep asking them for a valid #.
    
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