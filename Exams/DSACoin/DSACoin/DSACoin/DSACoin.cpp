// DSACoin.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Elliot Gong, Section 03, Final Exam
* Purpose: Simulate Crypto Mining by reading in a file of crypto files, generating keys, and creating
* 'Coins' to be saved in our 'Wallet'.
* Restrictions: Ideally, the keys would be generated within 3 seconds. To accomplish this, the process must 
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
/// global variables such as the timer, the file reader/writers, and the objects from the random class
/// to assist with true random number generation.
/// </summary>
std::chrono::high_resolution_clock clockTimer; 
std::chrono::high_resolution_clock::time_point start_time;
ifstream cryptoFile("cryptoFile.txt");
ofstream walletFile("walletFile.txt");
std::mutex mu;
//These help with random generation.
random_device rng;
mt19937 generator(rng());
uniform_int_distribution<> distribution(0, 9);
//This char array stores the 10 digits that will be used to generate a random key.
char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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
	//Use the random header to properly perform random number generation, as rand() is not recommended.
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
/// <param name="cryptoKeys">The vector to hold the crypto codes.</param>
/// <returns>Returns the next value from the crypto text file.</returns>
string readNextCrypto(vector<string>& cryptoKeys)
{
	string crypto = "";
	// TODO DSA1
	//Select the line in the crypto file to read from and read that line.
	if (cryptoFile.is_open())
	{
		getline(cryptoFile, crypto);
	}
	//Add the crypto value to the vector to confirm it was read.
	if (crypto != "")
	{
		cryptoKeys.push_back(crypto);
	}
	return crypto;
	
}

/// <summary>
/// Generate the value of the coin mined (random)
/// </summary>
/// <returns>return a dollar amount to be assigned to a coin</returns>
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


/// <summary>
/// This function will print out the valid crypto keys to the 
/// </summary>
/// <param name="wallet">The wallet object that holds the desired coins/keys.</param>
void PrintKeys(Wallet& wallet)
{
	//Write out the coins' keys to the text file.
	if (walletFile.is_open())
	{
		for (Coin* coin : wallet.GetWallet())
		{
			walletFile << coin->GetKey() << "\n";
		}
	}
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
	//If the coin's value is 0, then 3 seconds must have passed.
	if (coinValue == 0.0)
	{
		timeUp = true;
	}

}
/// <summary>
/// This function determines the key and value for a given crypto code, and uses that info to
/// create a coin and add it to the desired wallet.
/// </summary>
/// <param name="wallet">The wallet object that will store the created coin.</param>
/// <param name="cryptoKey">The given crypto code to 'crack'.</param>
/// <param name="count">The # of keys being generated.</param>
/// <param name="timeUp">The bool variable keeping track if 3 seconds have passed.</param>
void CreateCoin(Wallet& wallet, string cryptoKey, int& count, bool& timeUp)
{
	//lock_guard<mutex> lck(mu);
	if (timeUp == false)
	{
		//These variables will hold a coin's value and key.
		string validKey = "";
		double coinValue = 0.0;
		//Call the GetValidKey function to randomly generate the valid key.
		GetValidKey(cryptoKey, count, validKey, coinValue, timeUp);
		//Create the coin object and add it to the wallet.
		Coin* coin = new Coin(validKey, cryptoKey, coinValue);
		wallet.AddCoin(coin);
	}
}
int main()
{
	start_time = clockTimer.now();
	//srand(time(NULL));
	//The wallet object to hold our keys. 
	Wallet myWallet;
	//This will keep track of the # of keys created.
	int cnt = 0;
	//This will check if 3 seconds have passed.
	bool timesUp = false;
	//This will hold the current crypto code that was read in.
	string currentKey = "";
	// TODO DSA1
	// write the main loop
	//   read the crypto data (a line) from the file
	//   mine keys until you find a "good one"
	//     "good one" contains the crypto data from the file
	//   create a coin for the good keys and add it to your wallet

	//These vectors will store the read crypto codes and threads used to generate keys.
	vector<string> cryptoKeys;
	vector<thread*> keyThreads;
	//Mine keys for each value in the crypto file until 3 seconds have passed or there are no more values to be read.
	do
	{
		//Read the next crypto from the file.
		currentKey = readNextCrypto(cryptoKeys);
		//Break the loop prematurely if all codes have been read or if time is up.
		if (currentKey == "" || timesUp == true)
		{
			break;
		}
		//Otherwise, create a new thread that will create a coin using the current crypto code.
		keyThreads.push_back(new thread(CreateCoin, ref(myWallet), currentKey, ref(cnt), ref(timesUp)));	
	} while (currentKey != "" || timesUp == false);
	//End the threads if the keys can't be found within 3 seconds.
	if (timesUp == true)
	{
		for (thread* thread : keyThreads)
		{
			thread->~thread();
		}
	}
	//Make the main thread wait until each thread relegated to key generation has been completed.
	for (int i = 0; i < keyThreads.size(); i++)
	{
		keyThreads[i]->join();
	}
	//Clear the vector of thread pointers and print the coins' keys to the wallet file.
	keyThreads.clear();
	PrintKeys(myWallet);
	//Close the wallet text file and print out the # of keys searched as well as the value of the wallet.
	walletFile.close();
	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;
	return 0;
}
