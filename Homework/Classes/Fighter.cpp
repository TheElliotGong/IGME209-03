#include "Fighter.h"

/*Author: Elliot Gong
* Purpose: Instantiate the constructors and methods for the Player class.
* Restrictions: Must declare proper constructors and insert specific code into
* the class's methods.
* Date: 3/29/2022
*/

/// <summary>
/// This is the parameterized constructor for the Fighter Class.
/// </summary>
/// <param name="tier">This is the figher's tier.</param>
/// <param name="strength">This is the fighter's strength rating.</param>
/// <param name="speed">This is the fighter's speed rating.</param>
/// <param name="name">This is the figher's name.</param>
/// <param name="weaponSkill">This is the fighter's weapon skill.</param>
Fighter::Fighter(int tier, int strength, int speed, string name, string weaponSkill)
	: Player(tier, strength, speed, name)
{
	this->weaponSkill = weaponSkill;
}
/// <summary>
/// This is the default constructor. It calls the base constructor and sets 
/// the default value for the weapon skill.
/// </summary>
Fighter::Fighter() : Player()
{
	this->weaponSkill = "fists";
}
/// <summary>
/// This is the Fighter Class's destructor, which also prints out a little message.
/// </summary>
Fighter::~Fighter()
{
	cout << "Destroying fighter object.\n";
}
/// <summary>
/// This method prints out a Fighter object's data, calling the base method first and
/// Also prints out the fighter's weapon skill as well.
/// </summary>
void Fighter::PrintFighter()
{
	PrintPlayer();
	cout << "Weapon skill: " << this->weaponSkill << "\n";
}
/// <summary>
/// This method has a Fighter attack a player.
/// </summary>
/// <param name="victim">The player to be attacked.</param>
void Fighter::Attack(Player* victim)
{
	Player::Attack(victim);
	cout << this->GetName() << " attacks " << victim->GetName() << " with " << this->weaponSkill << "\n";
}