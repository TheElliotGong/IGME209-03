#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include "Coin.h"
using namespace std;
/*Elliot Gong, Section 03, Final Exam
* Purpose: Tweak the Wallet class as necessary to handle Coins.
* Restrictions: Must initialize necessary methods.
* Date: 5/1/2022
*/
class Wallet
{
public:
	/// <summary>
	/// Adds a new coin to the wallet
	/// </summary>
	/// <param name="newCoin"></param>
	void AddCoin(Coin* newCoin);
	/// <summary>
	/// Gets the value of the wallet
	/// </summary>
	/// <returns></returns>
	double GetValue();
	//Create a property that returns the vector of Coin pointers.
	vector<Coin*> getWallet()
	{
		return wallet;
	}
	/// <summary>
	/// clean up the wallet
	/// </summary>
	~Wallet();
private:
	vector<Coin*> wallet;
};

