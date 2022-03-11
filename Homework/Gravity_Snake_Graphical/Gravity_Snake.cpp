// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Include the snake header file.
#include "snake.h"

/*Author: Elliot Gong
*Purpose: Simulate the Snake Game in Box2D and add gravity to make the snake "fall". Display the game 
*in text format. Record the time taken to hit the 2 targets to score the player
*Restrictions: Must have the snake hit 2 targets and end the program when it does. Also include 
*Date:2/20/2022*/

//Global variables
int index = 0;
b2Vec2 *targetLocations;
b2Vec2 currentPosition;
//Declare a function typedef used to applying forces to the player.
void (*forceFunctionPointer)(b2Body* player);

int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Gravity Snake");
	window.setTitle("Gravity Snake: Graphical Edition");
	window.setFramerateLimit(60);
	//Reset random so different values will always be randomly generated each time.
	srand(static_cast <unsigned> (time(0)));
	//Draw the snake player using SFML code.
	sf::CircleShape snakePlayer(30.0f);
	snakePlayer.setPosition(500, 500);
	snakePlayer.setFillColor(sf::Color::Red);
	//target.setPosition(targetLocations[0]);
	sf::RectangleShape targetShape(sf::Vector2f(10.0f, 10.0f));
	targetShape.setFillColor(sf::Color::Yellow);
	//This variable keeps track of how many targets the player has hit.
	int targetCount = 0;
	//This int will hold the numerical value of the key pressed.
	//Print out the opening statement.
	//Create the b2world
	b2Vec2 gravity(0.0f, -10.0f);
	b2World* world = new b2World(gravity);
	//Create the ground body so the snake won't fall infinitely.
	//Set its size and position and add it to the world.
	b2BodyDef* groundBody = new b2BodyDef;
	groundBody->position.Set(0, -5.5f);
	b2Body* ground = world->CreateBody(groundBody);
	b2PolygonShape* box = new b2PolygonShape;
	box->SetAsBox(250.0f, 0.2f);
	ground->CreateFixture(box, 0.0f);
	//Create the playable snake as a dynamic body and set its position
	b2BodyDef* snake = new b2BodyDef;
	snake->type = b2_dynamicBody;
	snake->position.Set(0.0f, -5.1f);
	//Create a pointer player and have it point to the snake body.
	b2Body* player = world->CreateBody(snake);
	//Attach a shape to the snake.
	b2PolygonShape snakeShape;
	snakeShape.SetAsBox(0.05f, 0.05f);
	//Add a fixture definition for the snake's box.
	//Set density, friction, and assign the fixturedef to the player.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.5f;
	player->CreateFixture(&fixtureDef);
	//Create a pos variable to keep track of player position.
	int numTargets = 0;
	//Get the desired # of targets from the player.
	string input;
	int size;
	do
	{
		cout << "How many targets do you want? It must be at least 10: ";
		getline(cin, input);
		size = stoi(input);
	} while (size < 10 || input.length() == 0);
	SetUpTargets(size, targetLocations, currentPosition);
	//Record the current time at start of the game, after setting up all the box2D objects.
	auto startTime = steady_clock::now();
	//Set up the targets.
	
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
		world->Step(1.0f / 8000.0f, 6, 2);
		for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{

			}
		}
		
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


