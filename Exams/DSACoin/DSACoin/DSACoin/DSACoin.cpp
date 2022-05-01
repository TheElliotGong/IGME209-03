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
#include <cstdlib>
#include <random>
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
/// <returns>an 80 character long string with random digits.</returns>
string mineKey()
{
	string key = "";
	// TODO DSA1
	//Initialize the random seed.
	//Create an array of digit characters.
	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	//These variables will help with creating the string.
	char currentDigit = '0';
	int index = 0;
	//Use the random header to properly perform random number generation, as rand() is not recommended.
	random_device rng;
	mt19937 generator(rng());
	uniform_int_distribution<int> distribution(0, 9);
	//Randomly choose a digit character from the array and add it to the string.
	for (int i = 0; i < 80; i++)
	{
		index = distribution(generator);
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
	// TODO DSA1
	string crypto = "";
	return crypto;
}

/// <summary>
/// Generate the value of the coin mined (random)
/// </summary>
/// <returns>return a dollar amount to return for the coin</returns>
double calculateValue()
{
	// TODO DSA1
	//Find the duration between the current time and the start time and convert it to 
	//a double value representing milliseconds.
	std::chrono::high_resolution_clock::time_point current_time = clockTimer.now();
	//Use the provided formula to calculate the coin value, which is
	//subtracting the duration from 3 seconds/3000 milliseconds and multiplying that by 100.
	double coinValue = (3000 - chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count()) * 100;
	//Convert the value to 0 if it's initially negative.
	if (coinValue < 0.0)
	{
		coinValue = 0.0;
	}
	//Return the coin value.
	return coinValue;
}

void ReadCryptoKeys(vector<string>& list)
{
	string line = "";
	if (cryptoFile.is_open())
	{
		while (getline(cryptoFile, line))
		{
			list.push_back(line);
		}
	}
}
void CreateCoins(vector<string>& keys, vector<double>& values, Wallet& wallet)
{
	for (int i = 0; i < keys.size(); i++)
	{
		Coin* coin = new Coin(keys[i], values[i]);
		wallet.AddCoin(coin);
	}
	
}
/// <summary>
/// This function will print out the valid crypto keys to the 
/// </summary>
/// <param name="keys"></param>
void PrintKeys(vector<string>& keys)
{
	if (walletFile.is_open())
	{
		for (string key : keys)
		{
			walletFile << key << "\n";
		}
	}
}

void GetValidKey(string cryptoKey, int& count, string& validKey, double& coinValue, vector<double>& coinValues, int index)
{
	do
	{
		validKey = mineKey();
		count++;
	} while (validKey.find(cryptoKey) == string::npos);
	coinValue = calculateValue();
	coinValues[index] = coinValue;

}




int main()
{
	start_time = clockTimer.now();
	srand(time(NULL));
	Wallet myWallet;
	int cnt = 0;
	
	
	// TODO DSA1
	// write the main loop
	//   read the crypto data (a line) from the file
	//   mine keys until you find a "good one"
	//     "good one" contains the crypto data from the file
	//   create a coin for the good keys and add it to your wallet

	//Read in the cryptoFile and store the keys in a vector.
	vector<string> cryptoKeys;
	
	

	thread ReadThread(ReadCryptoKeys, ref(cryptoKeys));
	ReadThread.join();
	vector<string> validKeys(cryptoKeys.size());
	vector<double> coinValues(cryptoKeys.size());
	vector<thread*> keyThreads;
	//The max value of a coin.
	double coinValue = 300000.0;
	//Create threads that will generate a valid key for each crypto value that was read in.
	for (int i = 0; i < cryptoKeys.size(); i++)
	{
		keyThreads.push_back(new thread(GetValidKey, cryptoKeys[i], ref(cnt), ref(validKeys[i]), ref(coinValue), ref(coinValues), i));
		//If any of the coins has a value of 0, then stop mining entirely.
		if (coinValue == 0.0)
		{
			return 0;
		}
	}
	//Make main thread until each thread relegated to key generation has been completed.
	for (int i = 0; i < keyThreads.size(); i++)
	{
		keyThreads[i]->join();
	}
	//Clear the vector of thread pointers.
	keyThreads.clear();
	//Create some threads to create coins and add them to the wallet in addition to printing out the valid keys.
	thread CoinThread(CreateCoins, ref(validKeys), ref(coinValues), ref(myWallet));
	thread PrintThread(PrintKeys, ref(validKeys));
	//Call the join methods to ensure the main thread doesn't call any code that is dependent on the completion of 
	//the functions within the threads.
	CoinThread.join();
	PrintThread.join();
	//Close the wallet text file and print out the # of keys searched as well as the value of the wallet.
	walletFile.close();
	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;
	return 0;

	
}
