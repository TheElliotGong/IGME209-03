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
//Declare a pointer used to hold multiple scores.
float* scores;
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
    
    //Create an array of values for the pointer to access like an array.
    scores = new float[numOfScores];

}

void AverageScore(float* scores, int count)
{

}