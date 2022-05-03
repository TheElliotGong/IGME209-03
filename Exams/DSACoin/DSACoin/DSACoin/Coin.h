#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;

class Coin
{
public:
	Coin(string k, string c, double v)
	{
		code = c;
		key = k;
		coinValue = v;
	}
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
private:
	string code;
	string key;
	double coinValue;
};

