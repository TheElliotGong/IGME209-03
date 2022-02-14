#include "Viking.h"

Viking::Viking()
{
	name = nullptr;
	clan = nullptr;
	weapon = nullptr;
}

Viking::~Viking()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (clan != nullptr)
	{
		delete[] clan;
	}
	if (weapon != nullptr)
	{
		delete[] weapon;
	}
}
