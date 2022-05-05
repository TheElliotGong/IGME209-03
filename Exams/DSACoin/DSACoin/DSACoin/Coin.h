#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;
/*Elliot Gong, Section 03, Final Exam
* Purpose: Edit the Coin class if needed.
* Restrictions: A coin must have a valid key and a value.
* Date: 5/1/2022
*/
class Coin
{
public:
	/// <summary>
	/// This is the parameterized constructor for the Coin class.
	/// </summary>
	/// <param name="k">The valid key that contains the given crypto code.</param>
	/// <param name="c">The crypto code associated with this coin.</param>
	/// <param name="v">The coin's value.</param>
	Coin(string k, string c, double v)
	{
		code = c;
		key = k;
		coinValue = v;
	}
	//Properties that return the Coin class's variables.
	string GetCode()
	{
		return code;
	}
	string GetKey()
	{
		return key;
	}
	double GetValue()
	{
		return coinValue;
	}
	//Variables associated with the Coin class.
private:
	string code;
	string key;
	double coinValue;
};

