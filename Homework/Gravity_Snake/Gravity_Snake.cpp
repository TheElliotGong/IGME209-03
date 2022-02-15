// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "snake.h"
double targetX;
double targetY;
int targetCount = 0;

int main()
{

	cout << "Let's play Gravity Snake!\n";
	//Create the world
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);
	//Create the playable snake as a dynamic body.
	b2BodyDef snake;
	snake.type = b2_dynamicBody;
	snake.position.Set(0.0f, 0.0f);
	//Create a pointer and have it point to the snake body.
	b2Body* player = world.CreateBody(&snake);
	//Attach a shape to the snake.
	b2PolygonShape snakeShape;
	snakeShape.SetAsBox(1.0f, 1.0f);
	//Add a fixture definition for the snake's box.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 1.0f;

	int numTargets = 0;
	int key;
	while (numTargets < 2 || (key = _getch()) != 27)
	{
		if (_kbhit())
		{
		
		}
		Update(player, world, targetX, targetY);
	}
	for (int i = 0; i < 60; i++)
	{
		
	}
	
}


