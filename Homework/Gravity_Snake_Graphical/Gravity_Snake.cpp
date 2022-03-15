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
int targetCount;
//Declare a function typedef used to applying forces to the player.
typedef void (*forceFunctionPointer)(b2Body*);
forceFunctionPointer playerFunctionPointer;
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
	b2Vec2 gravity(0.0f, 6.0f);
	b2World* world = new b2World(gravity);

	//Create the ground.
	b2BodyDef* groundBody = new b2BodyDef;
	groundBody->position.Set(400.f/scale, 596.f/scale);
	groundBody->type = b2_staticBody;
	b2Body* ground = world->CreateBody(groundBody);
	//Create the ceiling.
	b2BodyDef* ceilingBody = new b2BodyDef;
	ceilingBody->position.Set(400.f / scale, 4.f / scale);
	ceilingBody->type = b2_staticBody;
	b2Body* ceiling = world->CreateBody(ceilingBody);
	//Create the shape for the ground body.
	b2PolygonShape* box = new b2PolygonShape;
	box->SetAsBox(400.f/scale, 4.f/scale);
	//create the fixture definition for the ground & ceiling.
	b2FixtureDef groundAndCeilingFixture;
	groundAndCeilingFixture.density = 0.f;
	groundAndCeilingFixture.shape = box;
	//Assign the fixtures to the ground and ceiling.
	ground->CreateFixture(&groundAndCeilingFixture);
	ceiling->CreateFixture(&groundAndCeilingFixture);
	//Create the left wall.
	b2BodyDef* leftWallBody = new b2BodyDef;
	leftWallBody->position.Set(4.f / scale, 300.f / scale);
	leftWallBody->type = b2_staticBody;
	b2Body* leftWall = world->CreateBody(leftWallBody);
	//Create the right wall.
	b2BodyDef* rightWallBody = new b2BodyDef;
	rightWallBody->position.Set(796.f / scale, 300.f / scale);
	rightWallBody->type = b2_staticBody;
	b2Body* rightWall = world->CreateBody(rightWallBody);
	//Define the walls' shape.
	b2PolygonShape* wallShape = new b2PolygonShape;
	wallShape->SetAsBox(4.f, 242.f);
	//Define the walls' fixture.
	b2FixtureDef wallFixture;
	wallFixture.density = 0.f;
	wallFixture.shape = wallShape;
	//Assign the fixtures to the walls.
	rightWall->CreateFixture(&wallFixture);
	leftWall->CreateFixture(&wallFixture);

	//Create the playable snake as a dynamic body and set its position
	b2BodyDef* snake = new b2BodyDef;
	snake->type = b2_dynamicBody;
	snake->position.Set(400.f/scale, 50.f/scale);
	//Create a pointer player and have it point to the snake body.
	b2Body* player = world->CreateBody(snake);
	//Attach a shape to the snake.
	b2CircleShape snakeShape;
	snakeShape.m_radius = 16.f/scale;
	//Add a fixture definition for the snake's box.
	//Set density, friction, and assign the fixturedef to the player.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	player->CreateFixture(&fixtureDef);
	//Define the sfml shape of the player.
	sf::CircleShape snakePlayer(8.0f);
	snakePlayer.setPosition(400, 300);
	snakePlayer.setFillColor(sf::Color::Red);
	//Define the sfml shape of the target.
	sf::RectangleShape targetShape(sf::Vector2f(10.0f, 10.0f));
	targetShape.setFillColor(sf::Color::Yellow);
	//Define the sfml shape of the ground and ceiling.
	sf::RectangleShape groundShape(sf::Vector2f(800.f, 8.f));
	groundShape.setOrigin(400.f, 4.f);
	groundShape.setFillColor(sf::Color::White);
	groundShape.setPosition(groundBody->position.x * scale, groundBody->position.y * scale);
	//Define the sfml shape of the left and right wall.
	sf::RectangleShape wallFigure(sf::Vector2f(8.f, 584.f));
	wallFigure.setOrigin(4.f, 292.f);
	wallFigure.setFillColor(sf::Color::White);
	wallFigure.setPosition(leftWallBody->position.x * scale, leftWallBody->position.y * scale);


	//CKeep track of the number of targets hit.
	int numTargets = 0;
	//Set up the targets.
	SetUpTargets();

	//Create the body definition for the target.
	b2BodyDef* targetBodyDef = new b2BodyDef;
	targetBodyDef->type = b2_staticBody;
	targetBodyDef->position = targetLocations[0];
	//Create the target body object.
	b2Body* target = world->CreateBody(targetBodyDef);
	//Create the shape definition for the target.
	b2PolygonShape* targetPolygon = new b2PolygonShape;
	targetPolygon->SetAsBox(5.f, 5.f);
	//Create the fixture definition for the target.
	b2FixtureDef targetFixtureDef;
	targetFixtureDef.density = 0.f;
	targetFixtureDef.shape = targetPolygon;
	target->CreateFixture(&targetFixtureDef);
	//Create the window after the user input is taken.
	
	//Record the current time at start of the game, after setting up all the box2D objects.
	auto startTime = steady_clock::now();
	//Keep the game playing until the player has hit all targets or closed the window.
	while (window.isOpen() && numTargets < targetCount + 1)
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
		snakePlayer.setPosition(player->GetPosition().x * scale, player->GetPosition().y * scale);
		window.draw(snakePlayer);
		//Draw the target
		window.draw(targetShape);
		//Draw the ground shape.
		window.draw(groundShape);
		//Move the ground shape to the top so it becomes the "ceiling" and draw that.
		groundShape.setPosition(ceilingBody->position.x * scale, ceilingBody->position.y * scale);
		window.draw(groundShape);
		//Move the ground shape back to its original place on the "floor"
		groundShape.setPosition(groundBody->position.x * scale, groundBody->position.y * scale);
		//Draw the "left" wall first.
		window.draw(wallFigure);
		//Move the wall to the right so we can draw the "right" wall.
		wallFigure.setPosition(rightWallBody->position.x * scale, rightWallBody->position.y * scale);
		window.draw(wallFigure);
		//Move the wall back its original position on the left.
		wallFigure.setPosition(leftWallBody->position.x * scale, leftWallBody->position.y * scale);

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
	delete[] targetLocations;
	//End the program.
	return 0;
}

void ProcessInput(b2Body* player)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		 playerFunctionPointer = &ApplyForceUp;
		 //ApplyForceUp(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		playerFunctionPointer = &ApplyForceDown;
		//ApplyForceDown(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerFunctionPointer = &ApplyForceLeft;
		//ApplyForceLeft(player);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		playerFunctionPointer = &ApplyForceRight;
		//ApplyForceRight(player);
	}
	if (playerFunctionPointer != nullptr)
	{
		playerFunctionPointer(player);
	}
	

}

void ApplyForceUp(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0.0f, -30.0f), false);
}


void ApplyForceDown(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0.0f, 30.0f), false);
}


void ApplyForceLeft(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(-15.0f, 0.0f), false);
}


void ApplyForceRight(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(15.0f, 0.0f), false);
}

void StopMoving(b2Body* player)
{
	player->SetLinearVelocity(b2Vec2_zero);
}

void ReverseGravity(b2World* world)
{
	world->SetGravity(b2Vec2(0, 10.0f));
}

void SetUpTargets()
{
	string input;
	int size;

	//Ask the user for the desired target count.
	do
	{
		cout << "How many targets do you want? It must be at least 10: ";
		getline(cin, input);
		size = stoi(input);
	} while (size < 10 || input.length() == 0);
	targetCount = size;
	targetLocations = new b2Vec2[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		if (i == size)
		{
			targetLocations[i] = b2Vec2(13.f/scale, 587.f/scale);
		}
		else
		{
			targetLocations[i] = b2Vec2(GenerateRandomNumber(13.f, 787.f)/scale, GenerateRandomNumber(13.f, 587.f)/scale );
			//targetLocations[i] = b2Vec2(GenerateRandomNumber(0, 800)/scale, GenerateRandomNumber(0, 600)/scale);
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
