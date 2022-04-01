#include "Player.h"


/*Author: Elliot Gong
* Purpose: Instantiate the methods and constructors for the Player Class
* Restrictions: Must declare proper constructors and insert specific code into
* the class's methods.
* Date: 3/29/2022
*/

/// <summary>
/// This is the Player Class's parameterized constructor.
/// </summary>
/// <param name="tier">This is the player's tier.</param>
/// <param name="strength">This is the player's strength rating.</param>
/// <param name="speed">This is the player's speed rating.</param>
/// <param name="name">This is the player's name.</param>
Player::Player(int tier, int strength, int speed, string name)
{
	this->tier = tier;
	this->strength = strength;
	this->speed = speed;
	this->name = name;
}
/// <summary>
/// This is the default constructor for the Player Class.
/// </summary>
Player::Player()
{
	//Give default values to all the variables.
	this->tier = 10;
	this->strength = 10;
	this->speed = 10;
	this->name = "Unknown";

}
/// <summary>
/// This is the Player's class special destructor, which also prints out a little message.
/// </summary>
Player::~Player()
{
	cout << "Destroying player object.\n";
}
/// <summary>
/// This method prints out a Player object's bio.
/// </summary>
void Player::PrintPlayer()
{
	cout << "Name: " << this->name << "\nTier: " << this->tier
		 << "\nStrength: " << this->strength << "\nSpeed: " << this->speed <<"\n";
}
 /// <summary>
 /// This method has the referenced Player "attack" another Player object.
 /// </summary>
 /// <param name="victim">The Player object to attack.</param>
 void Player::Attack(Player* victim)
{
	 cout << this->name << " attacks " << victim->GetName() << "\n";
}