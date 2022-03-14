// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Include the snake header file.
#include "snake.h"

/*Author: Elliot Gong
*Purpose: Simulate the Snake Game in Box2D and add gravity to make the snake "fall". Display the game 
*in text format. Record the time taken to hit the 2 targets to score the player
*Restrictions: Must have the snake hit 2 targets and end the program when it does. Also include 
*Date:2/20/2022*/
int index;
b2Vec2* targetLocations;
b2Vec2 currentPosition;
//Declare a function typedef used to applying forces to the player.
void (*forceFunctionPointer)(b2Body* player);
static const float scale = 30.0f;

int main()
{
	//Create the sfml window.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Snake");
	window.setTitle("Gravity Snake: Graphical Edition");
	window.setFramerateLimit(60);
	//Reset random so different values will always be randomly generated each time.
	srand(static_cast <unsigned> (time(0)));
	//This variable keeps track of how many targets the player has hit.
	int targetCount = 0;
	//This int will hold the numerical value of the key pressed.
	//Create the b2world
	b2Vec2 gravity(0.0f, -10.0f);
	b2World* world = new b2World(gravity);

	//Create the ground body so the snake won't fall infinitely.
	b2BodyDef* groundBody = new b2BodyDef;
	groundBody->type = b2_staticBody;
	groundBody->position.Set(400.f/scale, 500.f/scale);
	b2Body* ground = world->CreateBody(groundBody);
	//Create the shape for the ground body.
	b2PolygonShape* box = new b2PolygonShape;
	box->SetAsBox(16.f/scale, 16.f/scale);
	//create the fixture definition for the ground.
	b2FixtureDef groundFixture;
	groundFixture.density = 0.f;
	groundFixture.shape = box;
	ground->CreateFixture(&groundFixture);
	
	//Create the playable snake as a dynamic body and set its position
	b2BodyDef* snake = new b2BodyDef;
	snake->type = b2_dynamicBody;
	snake->position.Set(400.f, 300.f);
	//Create a pointer player and have it point to the snake body.
	b2Body* player = world->CreateBody(snake);
	//Attach a shape to the snake.
	b2CircleShape snakeShape;
	snakeShape.m_radius = 10.f;
	//Add a fixture definition for the snake's box.
	//Set density, friction, and assign the fixturedef to the player.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	player->CreateFixture(&fixtureDef);
	
	//Create the b2object for the target.
	b2BodyDef* targetDef = new b2BodyDef;
	targetDef->type = b2_staticBody;
	
	b2Body* target = world->CreateBody(targetDef);


	//Define the sfml shape of the player.
	sf::CircleShape snakePlayer(10.0f);
	snakePlayer.setPosition(500, 500);
	snakePlayer.setFillColor(sf::Color::Red);

	sf::RectangleShape targetShape(sf::Vector2f(10.0f, 10.0f));
	targetShape.setFillColor(sf::Color::Yellow);
	
	//Create a pos variable to keep track of player position.
	int numTargets = 0;
	//Get the desired # of targets from the player.
	string input;
	int size;

	//Ask the user for the desired target count.
	do
	{
		cout << "How many targets do you want? It must be at least 10: ";
		getline(cin, input);
		size = stoi(input);
	} while (size < 10 || input.length() == 0 );
	//Set up the targets.
	SetUpTargets(size);
	//Record the current time at start of the game, after setting up all the box2D objects.
	auto startTime = steady_clock::now();
	//Keep the game playing until the player has hit all targets or closed the window.
	while (window.isOpen() && numTargets < size + 1)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		ProcessInput(player);
		world->Step(1.0f / 60.0f, 8, 3);
		//Draw the b2bodies using sfml.
		for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{
				snakePlayer.setPosition(BodyIterator->GetPosition().x, BodyIterator->GetPosition().y);
				window.draw(snakePlayer);
			}
			else
			{
				window.draw(targetShape);
			}
		}
		window.display();

		
	}
	//Keep the game playing until the player has hit 2 targets.
	

	//Track the current time at the end of the program, after the player has hit 2 targets.
	auto endTime = steady_clock::now();
	//Determine the time spent trying to get the snake to hit the 2 targets.
	long time = duration_cast<seconds>(endTime - startTime).count();
	//Based on the amount of time spent on the game, print out different messages.
	//If they complete the game within 20 seconds, give them a "3 star" grade.
	if (time <= 20)
	{
		cout << "Time taken to hit both targets: " << time << " seconds. Good job! You earned 3 stars!";
	}
	//If they complete the game within 40 seconds, give them a "2 star" grade.
	else if (20 < time <= 40)
	{
		cout << "Time taken to hit both targets: " << time << " seconds. Not bad! You earned 2 stars!";
	}
	//If they take longer than 40 seconds, give them a "1 star" grade.
	else if (40 < time)
	{
		cout << "Time taken to hit both targets: " << time << " seconds. So close! You earned 1 star!";
	}
	//Delete the pointer objects.

	//End the program.
	return 0;
}

float GenerateRandomNumber(float min, float max)
{
	//Calculate the random float and round it out.
	float value = min + (rand()) / (RAND_MAX / (max - min));
	value = float(int(value * 10 + 0.5)) / 10;
	return value;
}
/// <summary>
/// This function checks if a float value is within a specified range.
/// </summary>
/// <param name="value">The float that'll be checked to see if it's within the range.</param>
/// <param name="min">The minimum value of the range.</param>
/// <param name="max">The maximum value of the range.</param>
/// <returns></returns>
bool WithinRange(float value, float min, float max)
{
	//Calculate if the value is in between the min and the max
	return ((value - max) * (value - min) <= 0);
}

void ProcessInput(b2Body* player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		forceFunctionPointer = &ApplyForceUp;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		forceFunctionPointer = &ApplyForceDown;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		forceFunctionPointer = &ApplyForceLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		forceFunctionPointer = &ApplyForceRight;
	}
	(*forceFunctionPointer)(player);

}

void ApplyForceUp(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0.0f, 50.0f), false);
}


void ApplyForceDown(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0.0f, -50.0f), false);
}


void ApplyForceLeft(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(-50.0f, 0.0f), false);
}


void ApplyForceRight(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(50.0f, 0.0f), false);
}

void StopMoving(b2Body* player)
{
	player->SetLinearVelocity(b2Vec2_zero);
}

void ReverseGravity(b2World* world)
{
	world->SetGravity(b2Vec2(0, 10.0f));
}

void SetUpTargets(int size)
{
	targetLocations = new b2Vec2[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		if (i == size)
		{
			targetLocations[i] = b2Vec2(-1000, 1000);
		}
		else
		{
			targetLocations[i] = b2Vec2(GenerateRandomNumber(0, 1000), GenerateRandomNumber(0, 1000));
		}
	}
	currentPosition = targetLocations[0];
}

bool SelectNextTarget(int size)
{
	if (index < size + 1)
	{
		index++;
		currentPosition = targetLocations[index];
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

