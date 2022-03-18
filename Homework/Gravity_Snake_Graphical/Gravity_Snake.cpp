// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Include the snake header file.
#include "snake.h"

/*Author: Elliot Gong
*Purpose: Simulate the Snake Game in Box2D and add gravity to make the snake "fall". Display the game 
*in text format. Record the time taken to hit the 2 targets to score the player
*Restrictions: Must have the snake hit 2 targets and end the program when it does. Also include 
*Date:2/20/2022*/
int index = 0;
b2Vec2* targetLocations;
b2Vec2 currentPosition;
int targetCount;
int keyPress = 0;
bool targetsLeft;
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
	//This int will hold the numerical value of the key pressed.
	//Create the b2world
	b2Vec2 gravity(0, -6.f);
	b2World* world = new b2World(gravity);

	//Create the ground.
	b2BodyDef* groundBody = new b2BodyDef;
	groundBody->position.Set(400.f / scale, 4.f/scale);
	groundBody->type = b2_staticBody;
	b2Body* ground = world->CreateBody(groundBody);
	//Create the ceiling.
	b2BodyDef* ceilingBody = new b2BodyDef;
	ceilingBody->position.Set(400.f / scale, 596.f/scale);
	ceilingBody->type = b2_staticBody;
	b2Body* ceiling = world->CreateBody(ceilingBody);
	//Create the shape for the ground body.
	b2PolygonShape* box = new b2PolygonShape;
	box->SetAsBox(400.f / scale, 4.f / scale);
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
	wallShape->SetAsBox(4.f / scale , 292.f/scale);
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
	snake->position.Set(400.f / scale, 200.f / scale);
	//Create a pointer player and have it point to the snake body.
	b2Body* player = world->CreateBody(snake);
	//Attach a shape to the snake.
	b2CircleShape snakeShape;
	snakeShape.m_radius = 8.f / scale;
	//Add a fixture definition for the snake's box.
	//Set density, friction, and assign the fixturedef to the player.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeShape;
	fixtureDef.density = 0.4f;
	fixtureDef.friction = 1.0f;
	player->CreateFixture(&fixtureDef);
	


	//Define the sfml shape of the player.
	sf::CircleShape snakePlayer(8.f);
	snakePlayer.setOrigin(8.f, 8.f);
	snakePlayer.setPosition(400, 300);
	snakePlayer.setFillColor(sf::Color::Red);
	
	//Set up the targets.
	SetUpTargets();
	//Create the body definition for the target.
    b2BodyDef* targetBodyDef = new b2BodyDef;
	targetBodyDef->type = b2_staticBody;
	targetBodyDef->position = currentPosition;
	//Create the target body object.
	b2Body* target = world->CreateBody(targetBodyDef);
	//Create the shape definition for the target.
	b2PolygonShape* targetPolygon = new b2PolygonShape;
	targetPolygon->SetAsBox(5.f/scale, 5.f/scale);
	//Create the fixture definition for the target.
	b2FixtureDef targetFixtureDef;
	targetFixtureDef.density = 0.f;
	targetFixtureDef.shape = targetPolygon;
	target->CreateFixture(&targetFixtureDef);
	
	//Define the sfml shape of the target.
	sf::RectangleShape targetShape(sf::Vector2f(10.0f, 10.0f));
	targetShape.setOrigin(5, 5);
	targetShape.setPosition(currentPosition.x * scale, 600 - currentPosition.y * scale);
	targetShape.setFillColor(sf::Color::Yellow);
	//Define the sfml shape of the ground and ceiling.
	sf::RectangleShape groundShape(sf::Vector2f(800.f, 8.f));
	groundShape.setOrigin(400.f, 4.f);
	groundShape.setFillColor(sf::Color::Green);
	groundShape.setPosition(groundBody->position.x * scale, 600 - (groundBody->position.y * scale));

	//Define the sfml shape of the left and right wall.
	sf::RectangleShape wallFigure(sf::Vector2f(8.f, 584.f));
	wallFigure.setOrigin(4.f, 292.f);
	wallFigure.setFillColor(sf::Color::Green);
	wallFigure.setPosition(leftWallBody->position.x * scale, leftWallBody->position.y * scale);

	
	//Create the window after the user input is taken.

	//Record the current time at start of the game, after setting up all the box2D objects.
	auto startTime = steady_clock::now();
	//Keep the game playing until the player has hit all targets or closed the window.
	while (window.isOpen() && targetsLeft)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		ProcessInput(player, keyPress);
		CheckCollision(player, target, targetBodyDef, currentPosition, targetShape);
		world->Step(1.0f / 60.0f, 8, 3);
		//Change the position of the sfml snake shape according to the box2 snake object
		snakePlayer.setPosition(player->GetPosition().x * scale, 600 - (player->GetPosition().y * scale));
		window.draw(snakePlayer);
		//Draw the target
		window.draw(targetShape);
		//Draw the ground shape.
		window.draw(groundShape);
		//Move the ground shape to the top so it becomes the "ceiling" and draw that.
		groundShape.setPosition(ceilingBody->position.x * scale, 600 - (ceilingBody->position.y * scale));
		window.draw(groundShape);
		groundShape.setPosition(groundBody->position.x * scale, 600 - (groundBody->position.y * scale));
		//Move the ground shape back to its original place on the "floor"
		//Draw the "left" wall first.
		window.draw(wallFigure);
		//Move the wall to the right so we can draw the "right" wall.
		wallFigure.setPosition(rightWallBody->position.x * scale, rightWallBody->position.y * scale);
		window.draw(wallFigure);
		//Move the wall back its original position on the left.
		wallFigure.setPosition(leftWallBody->position.x * scale, leftWallBody->position.y * scale);
		
		window.display();
		keyPress = 0;
		
		
	}StopMoving(*player);

	//Track the current time at the end of the program, after the player has hit 2 targets.
	auto endTime = steady_clock::now();
	//Determine the time spent trying to get the snake to hit the 2 targets.
	long time = duration_cast<seconds>(endTime - startTime).count();
	//Based on the amount of time spent on the game, print out different messages.
	//If they complete the game within 20 seconds, give them a "3 star" grade.
	if (time <= 20 && index == targetCount)
	{
		cout << "Time taken to hit both targets: " << time << " seconds. Good job! You earned 3 stars!";
	}
	//If they complete the game within 40 seconds, give them a "2 star" grade.
	else if (20 < time <= 40 && index == targetCount)
	{
		cout << "Time taken to hit both targets: " << time << " seconds. Not bad! You earned 2 stars!";
	}
	//If they take longer than 40 seconds, give them a "1 star" grade.
	else if (40 < time && index == targetCount)
	{
		cout << "Time taken to hit both targets: " << time << " seconds. So close! You earned 1 star!";
	}
	//Delete the pointer objects.
	delete[] targetLocations;
	
	delete groundBody;
	delete ceilingBody;
	delete leftWallBody;
	delete rightWallBody;
	
	//End the program.
	return 0;
}

void ProcessInput(b2Body* player, int& keyPresses)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		keyPresses = 1;
		playerFunctionPointer = &ApplyForceUp;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		keyPresses = 1;
		playerFunctionPointer = &ApplyForceDown;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		keyPresses = 1;
		playerFunctionPointer = &ApplyForceLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		keyPresses = 1;
		playerFunctionPointer = &ApplyForceRight;
	}
	if (playerFunctionPointer != nullptr && keyPresses == 1)
	{
		playerFunctionPointer(player);
	}
}

void ApplyForceUp(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0.0f, 30/scale), false);
}


void ApplyForceDown(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(0.0f, -30/scale), false);
}

void ApplyForceLeft(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(-20/scale, 0.0f), false);
}


void ApplyForceRight(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(20/scale, 0.0f), false);
}

void StopMoving(b2Body& player)
{
	player.SetLinearVelocity(b2Vec2_zero);
}

void ReverseGravity(b2World* world)
{
	//Reverse the y component of the world's gravity.
	world->SetGravity(b2Vec2(0, -1 * world->GetGravity().y));
}

void SetUpTargets()
{
	string input;
	//Ask the user for the desired target count.
	do
	{
		cout << "How many targets do you want? It must be at least 10: ";
		getline(cin, input);
		targetCount = stoi(input);
	} while (targetCount < 10 || input.length() == 0);
	//Add an extra target to the array.
	targetCount += 1;
	targetLocations = new b2Vec2[targetCount];
	for (int i = 0; i < targetCount; i++)
	{
		if (i == targetCount - 1)
		{
			//The last target should be in the top left corner of the screen.
			targetLocations[i] = b2Vec2(13.f/scale, 587.f/scale);
		}
		else
		{
			targetLocations[i] = b2Vec2(GenerateRandomNumber(13.f, 787.f)/scale, GenerateRandomNumber(13.f, 587.f)/scale );
		}
	}
	//Set current position of the target as the first element in the vector array.
	currentPosition = targetLocations[0];
	targetsLeft = true;

}

bool SelectNextTarget(b2BodyDef* targetBodyDef, sf::RectangleShape& targetShape)
{
	if (index == targetCount - 1)
	{
		return true;
	}
	else
	{
		index++;
		currentPosition = targetLocations[index];
		targetBodyDef->position.Set(currentPosition.x, currentPosition.y);
		targetShape.setPosition(targetBodyDef->position.x * scale, 600 - (targetBodyDef->position.y * scale));
		return true;
	}
}

void CheckCollision(b2Body* player, b2Body* target, b2BodyDef* targetBody, b2Vec2& currentPosition, sf::RectangleShape& targetShape)
{
	//If the player is on the target's left.
	if ((WithinRange(player->GetPosition().x, target->GetPosition().x - 13.f / scale, target->GetPosition().x) && WithinRange(player->GetPosition().y, target->GetPosition().y - 13.f / scale, target->GetPosition().y + 13.f / scale))
		//If player is on the target's right.
		|| (WithinRange(player->GetPosition().x, target->GetPosition().x, target->GetPosition().x + 13.f/scale) && WithinRange(player->GetPosition().y, target->GetPosition().y - 13.f / scale, target->GetPosition().y + 13.f / scale))
		//If player is above the target
		|| (WithinRange(player->GetPosition().x, target->GetPosition().x - 13.f/scale, target->GetPosition().x + 13.f / scale) && WithinRange(player->GetPosition().y, target->GetPosition().y, target->GetPosition().y + 0.05f))
		//If player is below the target
		|| (WithinRange(player->GetPosition().x, target->GetPosition().x - 13.f / scale, target->GetPosition().x + 13.f / scale) && WithinRange(player->GetPosition().y, target->GetPosition().y - 13.f/scale, target->GetPosition().y)))
	{
		//Update the global bool variable 
		targetsLeft = SelectNextTarget(targetBody, targetShape);
	}
}
/// <summary>
/// This function helps generate a random float within a defined range.
/// </summary>
/// <param name="min">The maximum possible value of the randomly generated </param>
/// <param name="max">The minimum possible value of the randomly generated float.</param>
/// <returns></returns>
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

