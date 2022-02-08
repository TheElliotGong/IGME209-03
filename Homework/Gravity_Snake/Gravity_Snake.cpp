// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "snake.h"

int targetCount = 2;
int main()
{
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);

	b2BodyDef boxDef;
	boxDef.position.SetZero();

	b2Body* box = world.CreateBody(&boxDef);
	b2PolygonShape area;
	area.SetAsBox(2.5f, 2.5f);
	getch();

}


