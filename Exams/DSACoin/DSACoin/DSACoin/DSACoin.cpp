// DSACoin.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Elliot Gong, Section 03, Final Exam
* Purpose: Simulate Crypto Mining by reading in a file of crypto files, generating keys, and creating
* 'Coins' to be saved in our 'Wallet'.
* Restrictions: The keys must be generated within 3 seconds. To accomplish this, the process must 
* utilize threads to optimize our mining speed.
* Date: 5/1/2022
*/

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
std::mutex mu;

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
	//These variables will help with creating the string.
	char currentDigit = '0';
	int index = 0;
	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
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
/// This function will read a specific line from the file provided by the given ifstream object.
/// </summary>
/// <param name="reader">The object that opened the desired file.</param>
/// <param name="lineNum">The line to read from.</param>
/// <returns></returns>
string readNextCrypto(ifstream& reader, unsigned int lineNum)
{
	string crypto = "";
	// TODO DSA1
	if (reader.is_open())
	{
		reader.seekg(std::ios::beg);
		for (int i = 0; i < lineNum - 1; i++)
		{
			reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		getline(reader, crypto);
	}
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
void PrintKeys(Wallet& wallet)
{
	if (walletFile.is_open())
	{
		for (Coin* coin : wallet.getWallet())
		{
			walletFile << coin->GetKey() << "\n";
		}
	}
}

void PrintTheKeys(vector<string>& validKeys)
{
	if (walletFile.is_open())
	{
		for (string key : validKeys)
		{
			walletFile << key << "\n";
		}
	}
	
}
void GetKey(string cryptoKey, int& count, double& currentValue, vector<string>& validKeys, vector<double>& coinValues, int index)
{

	string validKey = "";
	do
	{
		validKey = mineKey();
		count++;
	} while (validKey.find(cryptoKey) == string::npos);
	currentValue = calculateValue();
	validKeys[index] = validKey;
	coinValues[index] = currentValue;

}
void GetValidKey(string cryptoKey, int& count, string& validKey, double& coinValue, bool& timeUp)
{
	//Keep generating random keys until one contains the given crypto code.
	do
	{
		//Generate the random key and increment the # of keys created.
		validKey = mineKey();
		count++;
	} while (validKey.find(cryptoKey) == string::npos);
	//Calculate the coin's value and add it to the given vector.
	coinValue = calculateValue();
	if (coinValue == 0.0)
	{
		timeUp = true;
	}

}
void CreateCoin(Wallet& wallet, string cryptoKey, int& count, bool& timeUp)
{
	mu.lock();
	if (timeUp == false)
	{
		string validKey = "";
		double coinValue = 0.0;
		GetValidKey(cryptoKey, count, validKey, coinValue, timeUp);
		Coin* coin = new Coin(validKey, coinValue);
		wallet.AddCoin(coin);
	}
	mu.unlock();
	
}



int main()
{
	start_time = clockTimer.now();
	Wallet myWallet;
	int cnt = 0;
	bool timesUp = false;
	double coinValue = 300000.0;
	int index = 0;
	string currentKey = "";
	// TODO DSA1
	// write the main loop
	//   read the crypto data (a line) from the file
	//   mine keys until you find a "good one"
	//     "good one" contains the crypto data from the file
	//   create a coin for the good keys and add it to your wallet

	//Read in the cryptoFile and store the keys in a vector.
	vector<string> cryptoKeys;
	
	//thread ReadThread(ReadCryptoKeys, ref(cryptoKeys));
	//ReadThread.join();
	//ReadCryptoKeys(cryptoKeys);
    vector<string> validKeys(cryptoKeys.size());
	vector<double> coinValues(cryptoKeys.size());
	vector<thread*> keyThreads;

	do
	{
		currentKey = readNextCrypto(cryptoFile, index);
		index++;
		keyThreads.push_back(new thread(CreateCoin, ref(myWallet), currentKey, ref(cnt), ref(timesUp)));
		
		if (timesUp == true && coinValue == 0.0)
		{
			for (int i = 0; i < keyThreads.size(); i++)
			{
				keyThreads[i]->~thread();
			}
			keyThreads.clear();
			walletFile.close();
			cout << "Sorry! We couldn't generate the keys in time!";
			return 0;
		}
	}while (!currentKey.empty());

	/*
	//Create threads that will generate a valid key for each crypto value that was read in.
	for (int i = 0; i < cryptoKeys.size(); i++)
	{
		//keyThreads.push_back(new thread(GetKey, cryptoKeys[i], ref(cnt), ref(coinValue), ref(validKeys), ref(coinValues), i));
		keyThreads.push_back(new thread(CreateCoin, ref(myWallet), cryptoKeys[i], ref(cnt), ref(timesUp)));
		if (timesUp == true && coinValue == 0.0)
		{
			for (int i = 0; i < keyThreads.size(); i++)
			{
				keyThreads[i]->~thread();
			}
			keyThreads.clear();
			walletFile.close();
			cout << "Sorry! We couldn't generate the keys in time!";
			return 0;
		}
		//If any of the coins has a value of 0, then stop mining entirely.
	}*/
	//Make main thread until each thread relegated to key generation has been completed.
	for (int i = 0; i < keyThreads.size(); i++)
	{
		keyThreads[i]->join();
	}
	//Clear the vector of thread pointers.
	keyThreads.clear();
	//Create some threads to create coins and add them to the wallet in addition to printing out the valid keys.
	//thread CoinThread(CreateCoins, ref(validKeys), ref(coinValues), ref(myWallet));
	//thread PrintThread(PrintTheKeys, ref(validKeys));
	//Call the join methods to ensure the main thread doesn't call any code that is dependent on the completion of 
	//the functions within the threads.
	//CoinThread.join();
	//PrintThread.join();
	
	PrintKeys(myWallet);
	//Close the wallet text file and print out the # of keys searched as well as the value of the wallet.
	walletFile.close();
	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;
	return 0;

	
}
