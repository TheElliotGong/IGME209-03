#include "Fighter.h"

Fighter::Fighter(int tier, int strength, int speed, const char* name, const char* weaponSkill)
	: Player(tier, strength, speed, name)
{
	this->weaponSkill = weaponSkill;
}
Fighter::Fighter() : Player()
{
	this->weaponSkill = "fists";
}
Fighter::~Fighter()
{
	cout << "Destroying fighter object.";
}
void Fighter::PrintFighter()
{
	PrintPlayer();
	cout << "Weapon skill: " << this->weaponSkill << "\n";
}