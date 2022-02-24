// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Include the snake header file.
#include "snake.h"


int main()
{
	//Record the current time at start of program.
	auto startTime = steady_clock::now();
	
	//Reset random so different values will always be randomly generated each time.
	srand(static_cast <unsigned> (time(0)));
	
	//Use float pointers to target location, which within -5 to 5 range for x and y.
	float targetX = GenerateRandomNumber(-5.0f, 5.0f);
	float targetY = GenerateRandomNumber(-5.0f, 5.0f);

	//This variable keeps track of how many targets the player has hit.
	int targetCount = 0;
	//This int will hold the numerical value of the key pressed.
	int key;
	cout << "Let's play Gravity Snake!\n";
	//Create the world
	b2Vec2 gravity(0.0f, -10.0f);
	b2World* world = new b2World(gravity);
	//Create the ground body so the snake won't fall infinitely.
	//Set its size and position and add it to the world.
	b2BodyDef* groundBody = new b2BodyDef;
	groundBody->position.Set(0, -5.5f);
	b2Body* ground = world->CreateBody(groundBody);
	b2PolygonShape* box = new b2PolygonShape;
	box->SetAsBox(120.0f, 0.1f);
	ground->CreateFixture(box, 0.0f);
	//Create the playable snake as a dynamic body and set its position
	b2BodyDef* snake = new b2BodyDef;
	snake->type = b2_dynamicBody;
	snake->position.Set(0.0f, -5.1f);
	//Create a pointer player and have it point to the snake body.
	b2Body* player = world->CreateBody(snake);
	float playerX = player->GetPosition().x;
	float playerY = player->GetPosition().y;
	//Attach a shape to the snake.
	b2PolygonShape snakeShape;
	snakeShape.SetAsBox(0.1f, 0.1f);
	//Add a fixture definition for the snake's box.
	//Set density, friction, and assign the fixturedef to the player.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.5f;
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
			//Otherwise, apply forces to make the player move either by the WASD keys or by pressing enter.
			ApplyForces(key, player);
		}
		Update(player, world, targetX, targetY, numTargets);
		
	}
	//Track the current time at the end of the program, after the player has hit 2 targets.
	auto endTime = steady_clock::now();
	//Print out the time taken to hit both targets.
	cout << "Time taken to hit both targets: " << duration_cast<seconds>(endTime - startTime).count() << " seconds.";
	delete world;
	delete groundBody;
	delete snake;
	return 0;
}


