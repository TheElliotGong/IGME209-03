#pragma once
class Player
{
private:
	int tier;
	int strength;
	int speed;
	char* name;
public:
	Player(int tier, int strength, int speed, char* name);
	void PrintPlayer();
};

