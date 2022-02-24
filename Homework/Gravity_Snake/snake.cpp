#include "snake.h"

float xPosition;
float yPosition;


void Update(b2Body* player, b2World* world,  float& targetX, float& targetY, int& targetCount)
{
	world->Step(1.0f / 10000.0f, 6, 2);
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
	
	//Check if the target and player have collided.

	//If player is on the target's left
	if ( (WithinRange(playerX, targetX - 0.03f, targetX) && WithinRange(playerY, targetY - 0.03f, targetY + 0.03f))
		//If player is on the target's right.
		|| (WithinRange(playerX, targetX , targetX + 0.03f) && WithinRange(playerY, targetY - 0.03f, targetY + 0.03f))
		//If player is above the target
		|| (WithinRange(playerX, targetX - 0.03f, targetX + 0.03f) && WithinRange(playerY, targetY, targetY + 0.03f))
		//If player is below the target
		|| (WithinRange(playerX, targetX - 0.03f, targetX + 0.03f) && WithinRange(playerY, targetY - 0.03f, targetY)))
	{
		targetCount++;
		cout << "Target " << targetX << ", " << targetY << " - - > Snake "
			<< fixed<<setprecision(2)<<playerX << ", " << fixed << setprecision(2) << playerY << " (hit target)\n";
		//Move the target to a new location.
		MoveTarget(targetX, targetY);
	}
	else
	{
		cout << "Target " << targetX << ", " << targetY << " - - > Snake "
		<< fixed << setprecision(2) << playerX << ", " << fixed << setprecision(2) << playerY <<"\n";
	}
}
/// <summary>
/// This method "pushes" the player based on keyboard input, using the was keys.
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
			player->ApplyForceToCenter(b2Vec2(0.0f, 6.0f), false);
			break;
		case 'a':
			//If the player presses the a key, move the player left.
			player->ApplyForceToCenter(b2Vec2(-6.0f, 0.0f), false);
			break;
			//If the player presses the d key, move the player right.
		case 'd':
			player->ApplyForceToCenter(b2Vec2(6.0f, 0.0f), false);
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

bool WithinRange(float value, float min, float max)
{
	return ((value - max) * (value - min) <= 0);
}