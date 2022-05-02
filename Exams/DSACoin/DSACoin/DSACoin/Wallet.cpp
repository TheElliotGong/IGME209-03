#include "Wallet.h"

void Wallet::AddCoin(Coin* newCoin)
{
	// TODO DSA1
	// add the coin to the wallet
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
	for (Coin* coin : wallet)
	{
		delete coin;
	}
}
