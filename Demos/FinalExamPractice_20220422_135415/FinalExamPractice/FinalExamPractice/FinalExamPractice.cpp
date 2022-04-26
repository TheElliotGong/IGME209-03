// FinalExamPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <thread>

using namespace std;

struct Player
{
    char* name;
	int health;
	Player()
	{
		name = nullptr;
		health = 0;
	}

	Player(char* n)
	{
		name = new char[strlen(n)+1];
		strcpy_s(name, strlen(n) + 1, n);
		health = strlen(n) + 1;
	}

	~Player()
	{
		delete[] name;
	}

	Player(const Player &other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		health = other.health;
	}
	//Player& operator=(Player&& other)
	//{
	//	if (name != nullptr)
	//		delete[] name;
	//	name = other.name;
	//	other.name = nullptr;

	//	swap(name, other.name);

	//	health = other.health;
	//	return *this;
	//}

	Player& operator=(const Player& other)
	{
		if (this == &other)
			return *this;

		if (name != nullptr)
			delete[] name;

		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);

		health = other.health;
		return *this;
	}

};


int main()
{
    cout << "Final Exam Practice" << endl;

	// static_cast
	// reinterpret_cast
	// dynamic_cast
	// const_cast

	Player teach(const_cast<char*>("steve"));
	teach.health = 1;
	Player ta(teach);
	Player student;
	student = teach;

}

