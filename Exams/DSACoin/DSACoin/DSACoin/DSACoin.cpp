// DSACoin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Elliot Gong, Section 03, Final Exam
//

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include "Coin.h"
#include "Wallet.h"
using namespace std;

/// <summary>
/// global variables
/// </summary>
std::chrono::high_resolution_clock clockTimer; 
std::chrono::high_resolution_clock::time_point start_time;
ifstream cryptoFile("cryptoFile.txt");;
ofstream walletFile("walletFile.txt");;


/// <summary>
/// Generates an 80 charater long string with random numbers in each such as
/// "01234567890123456789012345678901234567890123456789012345678901234567890123456789"
/// but with random numbers for each one
/// </summary>
/// <returns></returns>
string mineKey()
{
	string key;
	// TODO DSA1
	//Initialize the random seed.
	srand(time(NULL));
	//Create an array of digit characters.
	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	//These variables will help with creating the string.
	char currentDigit;
	int index;
	//Randomly choose a digit character from the array and add it to the string.
	for (int i = 0; i < 80; i++)
	{
		index = rand() % 10;
		currentDigit = digits[index];
		key.push_back(currentDigit);
	}
	//Return the complete string, which should consist of 80 random digit characters.
	return key;
}

/// <summary>
/// reads the next crypto key from the keybank file
/// </summary>
/// <returns>returns new crypto to use or "" if the file was completely read</returns>
string readNextCrypto(unsigned int lineNum)
{
	cryptoFile.seekg(std::ios::beg);
	for (int i = 0; i < lineNum - 1; ++i)
	{
		cryptoFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	string crypto = "";
	// TODO DSA1
	getline(cryptoFile, crypto);
	return crypto;
}

/// <summary>
/// Generate the value of the coin mined (random)
/// </summary>
/// <returns>return a dollar amount to return for the coin</returns>
double calculateValue()
{
	double coinValue = 0.0;

	// TODO DSA1
	//Find the duration between the current time and the start time and convert it to 
	//a double value representing milliseconds.
	std::chrono::high_resolution_clock::time_point current_time = clockTimer.now();
	std::chrono::duration<double, std::milli> time = current_time - start_time;
	//Use the provided formula to calculate the coin value, which is
	//subtracting the duration from 3 seconds/3000 milliseconds and multiplying that by 100.
	coinValue = (3000 - time.count()) * 100;
	//Convert the value to 0 if it's initially negative.
	if (coinValue < 0.0)
	{
		coinValue = 0.0;
	}
	//Return the coin value.
	return coinValue;
}

int main()
{
	start_time = clockTimer.now();
	srand(2022);
	Wallet myWallet;
	int cnt = 0;

	// TODO DSA1
	// write the main loop
	//   read the crypto data (a line) from the file
	//   mine keys until you find a "good one"
	//     "good one" contains the crypto data from the file
	//   create a coin for the good keys and add it to your wallet
	if (cryptoFile.is_open())
	{
		string currentCryptoKey = readNextCrypto(cnt);
		string generatedKey = mineKey();
		double currentValue;
		if (generatedKey.find(currentCryptoKey) != string::npos)
		{
			currentValue = calculateValue();
			Coin* currentCoin = new Coin(generatedKey, currentValue);
			myWallet.AddCoin(currentCoin);
		}
	}
	
	cout << mineKey() << endl;

	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;

	walletFile << mineKey();
		walletFile.close();
}
