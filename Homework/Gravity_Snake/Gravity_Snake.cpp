// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "snake.h"
double targetX = GenerateRandomNumber(-5.0f, 5.0f);
double targetY = GenerateRandomNumber(-5.0f, 5.0f);
int targetCount = 0;
int key;

int main()
{
	cout << "Let's play Gravity Snake!\n";
	//Create the world
	b2Vec2 gravity(0.0f, -9.8f);
	b2World* world = new b2World(gravity);
	//Create the playable snake as a dynamic body.
	b2BodyDef* snake = new b2BodyDef;
	snake->type = b2_dynamicBody;
	snake->position.Set(0.0f, 0.0f);
	//Create a pointer player and have it point to the snake body.
	b2Body* player = world->CreateBody(snake);
	//Attach a shape to the snake.
	b2PolygonShape snakeShape;
	snakeShape.SetAsBox(1.0f, 1.0f);
	//Add a fixture definition for the snake's box.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 1.0f;

	int numTargets = 0;
	//Keep the game playing until the player has hit 2 targets.
	while (numTargets < 2 )
	{
		if (_kbhit())
		{
			//Get the int code for the key pressed.
			key = _getch();
			//If the user pressed escape, the loop ends.
			if (key == 27)
			{
				break;
			}
			ApplyForces(key, player);
		}
		Update(player, world, targetX, targetY);
	}
	
}


