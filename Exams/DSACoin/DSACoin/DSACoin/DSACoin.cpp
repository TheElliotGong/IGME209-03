// DSACoin.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Elliot Gong, Section 03, Final Exam
* Purpose: Simulate Crypto Mining by reading in a file of crypto files, generating keys, and creating
* 'Coins' to be saved in our 'Wallet'.
* Restrictions: Ideally, the keys would be generated within 3 seconds. To accomplish this, the process must 
* utilize threads to optimize our mining speed.
* 
* The chosen approach reads the entire cryto file sequentially. Then, we generate threads that generate
* a valid key for each crypto code. Execution time may vary, as some keys may be "valid" before others. 
* In addition, all the valid keys will be different after each run in both debug and release mode.
* Then, we create 2 new threads, one for creating and adding Coins to the Wallet, the other for printing out
* valid keys to the wallet file. 
* 
* 
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
	int index = 0;
	char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	//Use the random header to properly perform random number generation, as rand() is not recommended.
	random_device rng;
	mt19937 generator(rng());
	uniform_int_distribution<> distribution(0, 9);
	//Randomly choose a digit character from the array and add it to the string.
	for (int i = 0; i < 80; i++)
	{
		//index = rand() % 10;
		index = distribution(generator);
		key.push_back(digits[index]);
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
string readNextCrypto(vector<string>& cryptoKeys)
{
	string crypto = "";
	// TODO DSA1
	//Select the line in the crypto file to read from and read that line.
	if (cryptoFile.is_open())
	{
		getline(cryptoFile, crypto);
	}
	cryptoKeys.push_back(crypto);
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
void CreateCoins(vector<string>& keys, vector<string>& cryptoKeys, vector<double>& values, Wallet& wallet)
{
	for (int i = 0; i < keys.size(); i++)
	{
		Coin* coin = new Coin(keys[i], cryptoKeys[i],values[i]);
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
		for (Coin* coin : wallet.GetWallet())
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
/// <summary>
/// This function determines the valid key for the given crypto code and saves the coin 
/// </summary>
/// <param name="cryptoKey"></param>
/// <param name="count"></param>
/// <param name="currentValue"></param>
/// <param name="validKeys"></param>
/// <param name="coinValues"></param>
/// <param name="index"></param>
/// <param name="timesUp"></param>
void GetKey(string cryptoKey, int& count, double& currentValue, vector<string>& validKeys, vector<double>& coinValues, int index, bool& timesUp)
{

	string validKey = "";
	do
	{
		validKey = mineKey();
		count++;
	} while (validKey.find(cryptoKey) == string::npos);
	currentValue = calculateValue();
	timesUp = (currentValue > 0.0) ? false : true;
	validKeys[index] = validKey;
	coinValues[index] = currentValue;

}
/// <summary>
/// This function randomly generates a valid key for the given crypto code.
/// </summary>
/// <param name="cryptoKey">The crypto code that must be in the generated key.</param>
/// <param name="count">The variable keeping track of how many keys have been generated.</param>
/// <param name="validKey">The variable that will hold the valid key value.</param>
/// <param name="coinValue">The coin value that will be assigned to the generated key.</param>
/// <param name="timeUp">The variable checking if 3 seconds have passed.</param>
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
/// <summary>
/// This function determines the key and value for a given crypto code, and uses that info to
/// create a coin and add it to the desired wallet.
/// </summary>
/// <param name="wallet"></param>
/// <param name="cryptoKey"></param>
/// <param name="count"></param>
/// <param name="timeUp"></param>
void CreateCoin(Wallet& wallet, string cryptoKey, int& count, bool& timeUp)
{
	//lock_guard<mutex> lck(mu);
	if (timeUp == false)
	{
		string validKey = "";
		double coinValue = 0.0;
		GetValidKey(cryptoKey, count, validKey, coinValue, timeUp);
		Coin* coin = new Coin(validKey, cryptoKey, coinValue);
		wallet.AddCoin(coin);
	}
}
int main()
{
	start_time = clockTimer.now();
	srand(2022);

	Wallet myWallet;
	int cnt = 0;
	int lineNum = 1;
	double coinValue = 300000.0;
	bool timesUp = false;
	string currentKey = "";
	// TODO DSA1
	// write the main loop
	//   read the crypto data (a line) from the file
	//   mine keys until you find a "good one"
	//     "good one" contains the crypto data from the file
	//   create a coin for the good keys and add it to your wallet

	//Read in the cryptoFile and store the keys in a vector.
	vector<string> cryptoKeys;
	//ReadCryptoKeys(cryptoKeys);
    //vector<string> validKeys(cryptoKeys.size());
	//vector<double> coinValues(cryptoKeys.size());
	vector<thread*> keyThreads;
	
	/*Note: This approach properly utilizes the readnextcrypto method.
	*/

	//Mine keys for each value in the crypto file until 3 seconds have passed or there are no more values to be read.
	do
	{
		currentKey = readNextCrypto(cryptoKeys);
		if (currentKey == "" || timesUp == true)
		{
			break;
		}
		keyThreads.push_back(new thread(CreateCoin, ref(myWallet), currentKey, ref(cnt), ref(timesUp)));	
	} while (currentKey != "" || timesUp == false);
	if (timesUp == true)
	{
		for (thread* thread : keyThreads)
		{
			thread->~thread();
		}
	}
	/*
	//Create threads that will generate a valid key for each crypto value that was read in.
	for (int i = 0; i < cryptoKeys.size(); i++)
	{
		keyThreads.push_back(new thread(GetKey, cryptoKeys[i], ref(cnt), ref(coinValue), ref(validKeys), ref(coinValues), i, ref(timesUp)));
		//keyThreads.push_back(new thread(CreateCoin, ref(myWallet), cryptoKeys[i], ref(cnt), ref(timesUp)));		
		//Stop mining if the keys couldn't be generated within 3 seconds.
		if (timesUp == true && coinValue == 0.0)
		{
			//Terminate the threads and close the wallet text file.
			for (int i = 0; i < keyThreads.size(); i++)
			{
				keyThreads[i]->~thread();
			}
			keyThreads.clear();
			walletFile.close();
			//Print out a small message and close the main thread.
			cout << "Sorry! We couldn't generate the keys in time!";
			return 0;
		}
	}*/
	//Make main thread until each thread relegated to key generation has been completed.
	for (int i = 0; i < keyThreads.size(); i++)
	{
		keyThreads[i]->join();
	}
	//Clear the vector of thread pointers.
	keyThreads.clear();
	//Create some threads to create coins and add them to the wallet in addition to printing out the valid keys.
	//thread CoinThread(CreateCoins, ref(validKeys), ref(cryptoKeys), ref(coinValues), ref(myWallet));
	//thread PrintThread(PrintTheKeys, ref(validKeys));
	//thread PrintingThread(PrintKeys, ref(myWallet));
	//Call the join methods to ensure the main thread doesn't call any code that is dependent on the completion of 
	//the functions within the threads.
	//CoinThread.join();
	//PrintThread.join();
	//PrintingThread.join();
	PrintKeys(myWallet);
	//Close the wallet text file and print out the # of keys searched as well as the value of the wallet.
	walletFile.close();
	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;
	return 0;

	
}
