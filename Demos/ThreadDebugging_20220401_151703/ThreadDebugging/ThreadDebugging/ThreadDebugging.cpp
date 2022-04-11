// ThreadDebugging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>
#include <vector>
using namespace std;

void Print()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "Print thread " << i << "." << "(" << std::this_thread::get_id() << ")" << endl;
	}
}

void Print2(int cnt)
{
	
	for (size_t i = 0; i < cnt; i++)
	{
		cout << "Print2 thread " << i << "!" << "(" << std::this_thread::get_id() << ")" << endl;
	}
}

void Crash(int x)
{
	Crash(++x);
}

class Player
{
public:
	string Name;
	int health;
	Player(string name) { Name = name; health = 10; }
	void PrintPlayer()
	{
		cout << "Players " << Name << "?" << "(" << std::this_thread::get_id() << ")" << endl;
		for (size_t i = 0; i < health; i++)
		{
			cout << "damage (" << std::this_thread::get_id() << ")" << endl;
		}
	}

};


int main()
{
	cout << "Thread Debugging " << "(" << std::this_thread::get_id() << ")" << endl;
	thread printThread(Print);
	thread otherThread(Print2, 20);
	vector<thread*> threads;
	Player ta("Adi");
	Player teach("Steve");

	threads.push_back(&printThread);
	threads.push_back(&otherThread);
	threads.push_back(new thread(Print));
	threads.push_back(new thread(&Player::PrintPlayer, ta));
	threads.push_back(new thread(&Player::PrintPlayer, teach));
	threads.push_back(new thread(Crash, 0));

	for (size_t i = 0; i < threads.size(); i++)
	{
		threads[i]->join();
	}
	//printThread.join();
	//otherThread.join();
	threads.clear();

	cout << "Done Thread Debugging" << endl;

}
