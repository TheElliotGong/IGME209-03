#include "snake.h"

float xPosition;
float yPosition;

void Update(b2Body* player, b2World world,  float targetX, float targetY)
{
	world.Step(1.0f / 60.0f, 8, 3);
	b2Vec2 pos = player->GetPosition();
	Display(targetX, targetY, pos.x, pos.y);

}

void Display(float targetX, float targetY, float playerX, float playerY)
{
	cout << "Target " << targetX << ", " << targetY << " - - > Snake "
		<< playerX << ", " << playerY<<"\n";
}

void ApplyForces(char key, b2Body player)
{
	
}

void MoveTarget(float& xPos, float& yPos)
{
	
}

float GenerateRandomNumber(float min, float max)
{
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}