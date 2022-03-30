#pragma once
#include "Player.h"
class Fighter :
    public Player
{
    private:
        string weaponSkill;
    public:
        Fighter();
        Fighter(int tier, int strength, int speed, string name, string weaponSkill);
        ~Fighter();
        void PrintFighter();
        void Attack(Player* victim);
};

