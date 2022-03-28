#include "Player.h"

Player::Player(int tier, int strength, int speed, const char* name)
{
	this->tier = tier;
	this->strength = strength;
	this->speed = speed;
	this->name = name;
}
Player::Player()
{
	this->tier = 10;
	this->strength = 10;
	this->speed = 10;
	this->name = "Unknown";

}

Player::~Player()
{
	cout << "Destroying player object.";
}
void Player::PrintPlayer()
{
	cout << "Name: " << this->name << "\nTier: " << this->tier
		 << "\nStrength: " << this->strength << "\nSpeed: " << this->speed <<"\n";
}