#include "Wallet.h"
/*Elliot Gong, Section 03, Final Exam
* Purpose: Initialize the required methods for the Wallet class.
* Restrictions: Must write code for the AddCoin method, the GetValue method, and the destructor.
* Date: 5/3/2022
*/

/// <summary>
/// This method 'adds' a Coin to the wallet.
/// </summary>
/// <param name="newCoin">Takes in a coin pointer that will be part of the wallet object.</param>
void Wallet::AddCoin(Coin* newCoin)
{
	// TODO DSA1
	// add the coin to the appropriate vector.
	wallet.push_back(newCoin);
}
/// <summary>
/// This method returns the total value of the wallet.
/// </summary>
/// <returns></returns>
double Wallet::GetValue()
{
	// TODO DSA1
	// sum the total value of the wallet's coins and return it.
	double total = 0.0;
	for(Coin* coin : wallet)
	{
		total += coin->GetValue();
	}
	return total;
}
/// <summary>
/// This is the destructor for the Wallet class.
/// </summary>
Wallet::~Wallet()
{
	// TODO DSA1
	//Loop through the vector and delete each Coin pointer.
	for (Coin* coin : wallet)
	{
		delete coin;
	}
	//Clear the vector.
	wallet.clear();
}
