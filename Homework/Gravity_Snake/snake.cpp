#include "snake.h"

float xPosition;
float yPosition;


void Update(b2Body* player, b2World* world,  float& targetX, float& targetY, int& targetCount)
{
	world->Step(1.0f / 60.0f, 6, 2);
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
	if (targetX - playerX <= 0.02f || playerX - targetX <= 0.02f
		|| targetY - playerY <= 0.02f || playerY - targetY <= 0.02f)
	{
		targetCount++;
		cout << "Target " << targetX << ", " << targetY << " - - > Snake "
			<< playerX << ", " << playerY << " (hit target)\n";
		//Move the target to a new location.
		MoveTarget(targetX, targetY);
	}
	else
	{
		cout << "Target " << targetX << ", " << targetY << " - - > Snake "
		<< playerX << ", " << playerY<<"\n";
	}
	

}

void ApplyForces(int key, b2Body* player)
{
	b2Vec2 pos = player->GetPosition();
	key = toupper(key);
	switch (key)
	{
		case 'W':
			pos.y -= 5.0f;
			break;
		case 'A':
			pos.x -= 5.0f;
			break;
		case 'D':
			pos.x += 5.0f;
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
	float newX = GenerateRandomNumber(-5.0f, 5.0f);
	float newY = GenerateRandomNumber(-5.0f, 5.0f);
	xPos = newX;
	yPos = newY;
}

float GenerateRandomNumber(float min, float max)
{
	float value = min + static_cast <float> (rand()) /  (RAND_MAX / (max - min));
	value = float(int(value * 10 + 0.5)) / 10;
	return value;
}