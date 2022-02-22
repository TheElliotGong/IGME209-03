// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "snake.h"


int main()
{
	//Define target location, which within -5 to 5 range for x and y.
	double targetX = GenerateRandomNumber(-5.0f, 5.0f);
	double targetY = GenerateRandomNumber(-5.0f, 5.0f);
	//This variable keeps track of how many targets the player has hit.
	int targetCount = 0;
	//This int will hold the numerical value of the key pressed.
	int key;
	cout << "Let's play Gravity Snake!\n";
	//Create the world
	b2Vec2 gravity(0.0f, -9.8f/60);
	b2World* world = new b2World(gravity);
	//Create the ground body so the snake won't fall infinitely.
	b2BodyDef* groundBody = new b2BodyDef;
	groundBody->position.Set(0, -10.0f);
	b2Body* ground = world->CreateBody(groundBody);
	b2PolygonShape* box = new b2PolygonShape;
	box->SetAsBox(50.0f, 10.0f);
	ground->CreateFixture(box, 0.0f);
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
	player->CreateFixture(&fixtureDef);

	//Create a pos variable to keep track of player position.
	 b2Vec2 playerPos = player->GetPosition();
	int numTargets = 0;
	//Keep the game playing until the player has hit 2 targets.
	while (numTargets < 2 )
	{
		if (_kbhit())
		{
			//Get the int code for the key pressed.
			key = _getch();
			//If the user pressed escape, the loop ends.
			if (key == 13)
			{
				break;
			}
			//Otherwise, apply forces to make the player move.
			ApplyForces(key, player);
		}

		Update(player, world, targetX, targetY);
		if (targetX - player->GetPosition().x <= 0.02 || targetX + 0.02 >= player->GetPosition().x ||
			targetY - player->GetPosition().y <= 0.02 || targetY + 0.02 >= player->GetPosition().y)
		{

		}
	}
	

}


