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
	Coin(string k, double v)
	{
		key = k;
		coinValue = v;
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
	string key;
	double coinValue;
};

