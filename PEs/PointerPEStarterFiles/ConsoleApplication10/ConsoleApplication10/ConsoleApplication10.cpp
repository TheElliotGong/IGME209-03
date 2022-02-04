// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "Position - X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	cout << "Boss address: " << &boss << endl;
	cout << "Player address: " << &pOne << endl;
	cout << "Fake Monster address: " << &fakeMonster << endl;

	boss->xPos = -5;
	boss->yPos = 30;

	pOne->xPos = 65;
	pOne->yPos = 24;

	fakeMonster->xPos = 3;
	fakeMonster->yPos = -11;

	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();

	// add code here

	//This delete statements are causing the program to crash.
	/*
	delete boss;
	delete pOne;
	delete fakeMonster;*/

	_getch();
    return 0;
}

