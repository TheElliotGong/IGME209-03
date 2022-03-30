#include "Fighter.h"

Fighter::Fighter(int tier, int strength, int speed, string name, string weaponSkill)
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
	cout << "Destroying fighter object.\n";
}
void Fighter::PrintFighter()
{
	PrintPlayer();
	cout << "Weapon skill: " << this->weaponSkill << "\n";
}

void Fighter::Attack(Player* victim)
{
	Player::Attack(victim);
	cout << this->GetName() << " attacks " << victim->GetName() << " with " << this->weaponSkill << "\n";
}