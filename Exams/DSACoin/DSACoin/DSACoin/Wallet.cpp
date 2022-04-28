#include "Wallet.h"

void Wallet::AddCoin(Coin* newCoin)
{
	// TODO DSA1
	// add the coin to the wallet
	wallet.push_back(newCoin);
}

double Wallet::GetValue()
{
	// TODO DSA1
	// sum the total of all the coins
	double total = 0.0;
	for(Coin* coin : wallet)
	{
		total += coin->getValue();
	}
	return total;
}

Wallet::~Wallet()
{
	// TODO DSA1
}
