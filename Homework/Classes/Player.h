#pragma once
#include <iostream>
#include <string>
using namespace std;

/*Author: Elliot Gong
* Purpose: Create a base Player Class
* Restrictions: Must have several private member variables, a default and parameterized
* constructor, a destructor, a void method and a property.
* Date: 3/29/2022
*/

class Player
{
	//Declare private member variables.
private:
	int tier;
	int strength;
	int speed;
	string name;
	//Declare public methods, constructors, and destructors.
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

