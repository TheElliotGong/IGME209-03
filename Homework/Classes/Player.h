#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	int tier;
	int strength;
	int speed;
	string name;
public:
	Player();
	Player(int tier, int strength, int speed, string name);
	~Player();
	void PrintPlayer();
	virtual void Attack(Player* victim);
	string GetName()
	{
		return name;
	}
};

