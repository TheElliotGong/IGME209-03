#pragma once
#include "Player.h"

/*Author: Elliot Gong
* Purpose: Create a Fighter class, which is derived from the Player class.
* Restrictions: Must declare proper constructors and insert specific code into
* the class's methods.
* Date: 3/29/2022
*/

class Fighter :
    public Player
{
    //private string variable exclusive for the Fighter Class.
    private:
        string weaponSkill;
    //public constructors, destructors, and methods exclusive for the Fighter Class.
    public:
        Fighter();
        Fighter(int tier, int strength, int speed, string name, string weaponSkill);
        ~Fighter();
        void PrintFighter();
        void Attack(Player* victim);
};

