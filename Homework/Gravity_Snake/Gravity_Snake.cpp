// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "snake.h"

int targetCount = 0;
int main()
{
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);

	/*
	b2BodyDef boxDef;
	boxDef.position.SetZero();

	b2Body* box = world.CreateBody(&boxDef);
	b2PolygonShape area;
	area.SetAsBox(2.5f, 2.5f);*/
	
	//Create the dynamic body that represents the snake player
	b2BodyDef snake;
	snake.type = b2_dynamicBody;
	snake.position.Set(0.0f, 0.0f);
	b2Body* player = world.CreateBody(&snake);

	b2PolygonShape snakeShape;
	snakeShape.SetAsBox(1.0f, 1.0f);
	int key = 0;
	while ( targetCount < 2)
	{
		if (kbhit())
		{
			key = _getch();
			
		}
	}
	
}


