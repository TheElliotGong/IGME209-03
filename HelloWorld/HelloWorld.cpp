// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Editor: Elliot Gong
* Date: 1/12/2022
* Purpose: Create and experiment with our own "Hello World" program.
* Restrictions: Must include stdio.h file and set project as console app.
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

int main()
{
   //Declare my variables.
   int secondsInDecember = 2678400;
   int calculation = 8/3; // results in 2.
   double radius = 6.2;
   double area = M_PI * pow(radius, 2);
   //Print out the statements and calculations.
   printf("Hello World!\n");
   printf("Hey it's me!\n");
   printf("There are %d seconds in December.\n", secondsInDecember);
   printf("The area of a circle with a radius of %f.\n", area);
   /*If an integer quotient results in an improper/mixed fraction,
   * The resulting value is the max number of denominators that can fit within
   * the numerator without going over.
   */
   printf("8 divided by 3 is %d", calculation); 
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
