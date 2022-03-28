#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	int tier;
	int strength;
	int speed;
	const char* name;
public:
	Player();
	Player(int tier, int strength, int speed, const char* name);
	~Player();
	void PrintPlayer();
	virtual void Attack(Player* victim);
	const char* GetName()
	{
		return name;
	}
};

