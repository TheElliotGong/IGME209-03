#pragma once
#include "Player.h"
class Fighter :
    public Player
{
    private:
        const char* weaponSkill;
    public:
        Fighter();
        Fighter(int tier, int strength, int speed, const char* name, const char* weaponSkill);
        ~Fighter();
        void PrintFighter();
};

