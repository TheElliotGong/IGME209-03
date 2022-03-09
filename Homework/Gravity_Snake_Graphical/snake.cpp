#include "snake.h"

/*Author: Elliot Gong
* Purpose: Initialize the functions declared in the header file.
* Restrictions: Must update the b2world and apply forces to the player based on keyboard input.
* Date: 2/20/2022
*/
int index = 0; 
vector<b2Vec2*> targetLocations;

/// <summary>
/// This method updates the box2d world and its objects as well as printing out the positions of the 
/// player and target.
/// </summary>
/// <param name="player">The player object, whose position will be checked to see if it collides with
/// the target.</param>
/// <param name="world">The b2world holding the player object.</param>
/// <param name="targetX">The target's x coordinate.</param>
/// <param name="targetY">The target's y coordinate.</param>
/// <param name="targetCount">The num of targets hit.</param>
void Update(b2Body* player, b2World* world,  float& targetX, float& targetY, int& targetCount)
{
	//Use the b2World class's step function to update the world.
	world->Step(1.0f / 8000.0f, 6, 2);
	//Get the player object's position and pass that into the display function along with
	//the other parameters.
	b2Vec2 pos = player->GetPosition();
	Display(targetX, targetY, pos.x, pos.y, targetCount);

}
/// <summary>
/// This method displays the positions of the player and target.
/// </summary>
/// <param name="targetX">The target's x coordinate.</param>
/// <param name="targetY">The target's y coordinate.</param>
/// <param name="playerX">The player's x coordinate.</param>
/// <param name="playerY">The player's y coordinate.</param>
void Display(float& targetX, float& targetY, float playerX, float playerY, int& targetCount)
{
	//Check if the target and player have collided. They must be within 0.25 units of each other for it 
	//to count as a collision.
	//If player is on the target's left
	if ( (WithinRange(playerX, targetX - 0.05f, targetX) && WithinRange(playerY, targetY - 0.05f, targetY + 0.05f))
		//If player is on the target's right.
		|| (WithinRange(playerX, targetX , targetX + 0.05f) && WithinRange(playerY, targetY - 0.05f, targetY + 0.05f))
		//If player is above the target
		|| (WithinRange(playerX, targetX - 0.05f, targetX + 0.05f) && WithinRange(playerY, targetY, targetY + 0.05f))
		//If player is below the target
		|| (WithinRange(playerX, targetX - 0.05f, targetX + 0.05f) && WithinRange(playerY, targetY - 0.05f, targetY)))
	{
		//Increment the reference value that keeps track of the # of targets hit.
		targetCount++;
		//Print out the the matching player and target locations on a new line.
		cout << "Target " << targetX << ", " << targetY << " - - > Snake "
			<< fixed<<setprecision(2)<<playerX << ", " << fixed << setprecision(2) << playerY << " (hit target)\n";
		//Move the target to a new location.
		MoveTarget(targetX, targetY);
	}
	//Otherwise, keep printing out the locations of the target and player on the same line.
	else
	{
		cout << "Target " << targetX << ", " << targetY << " - - > Snake "
		<< fixed << setprecision(2) << playerX << ", " << fixed << setprecision(2) << playerY <<"\r";
	}
}
/// <summary>
/// This method applies different forces to the player based on keyboard input, using the was keys.
/// </summary>
/// <param name="key>The int value of the pressed key</param>
/// <param name="player">The b2body object to apply the force to.</param>
void ApplyForces(int key, b2Body* player)
{
	//Apply different forces on the player based on the key code.
	switch (key)
	{
		case 'w':
			///If the player presses the w key, move the player up.
			player->ApplyForceToCenter(b2Vec2(0.0f, 50.0f), false);
			break;
		case 's':
			player->ApplyForceToCenter(b2Vec2(0.0f, -50.0f), false);
			break;
		case 'a':
			//If the player presses the a key, move the player left.
			player->ApplyForceToCenter(b2Vec2(-15.0f, 0.0f), false);
			break;
			//If the player presses the d key, move the player right.
		case 'd':
			player->ApplyForceToCenter(b2Vec2(15.0f, 0.0f), false);
			break;
	}
}
/// <summary>
/// Move the target to a new random position using reference operators to tweak
/// the original vvariables holding the initial target position.
/// </summary>
/// <param name="xPos">The variable holding the target's x position.</param>
/// <param name="yPos">The variable holding the target's y position.</param>
void MoveTarget(float& xPos, float& yPos)
{
	//Create 2 random floats for the x and y coordinates.
	float newX = GenerateRandomNumber(-5.0f, 5.0f);
	float newY = GenerateRandomNumber(-5.0f, 5.0f);
	//Assign these 2 float values to the reference parameters.
	xPos = newX;
	yPos = newY;
}
/// <summary>
/// This method returns a random float between a defined min and max.
/// </summary>
/// <param name="min">The minimum possible value of the random float.</param>
/// <param name="max">The maximum possible value of the random float.</param>
/// <returns></returns>
float GenerateRandomNumber(float min, float max)
{
	//Calculate the random float and round it out.
	float value = min +  (rand()) /  (RAND_MAX / (max - min));
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
	void (*forceFunctionPointer)(b2Body * player);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		forceFunctionPointer = &ApplyForceUp;
		forceFunctionPointer(player);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		forceFunctionPointer = &ApplyForceDown;
		forceFunctionPointer(player);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		forceFunctionPointer = &ApplyForceLeft;
		forceFunctionPointer(player);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		forceFunctionPointer = &ApplyForceRight;
		forceFunctionPointer(player);
	}
	
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
void SetUpNextTarget()
{
	string input;
	int size;
	do
	{
		cout << "How many targets do you want? It must be at least 10: ";
		getline(cin, input);
		size = stoi(input);
	} while (size < 10 || input.length() == 0);

	for (int i = 0; i < size + 1; i++)
	{
		targetLocations.push_back(new b2Vec2(GenerateRandomNumber(0, 1000), GenerateRandomNumber(0, 1000)));
	}
}

bool SelectNewTargets()
{
	index++;
}