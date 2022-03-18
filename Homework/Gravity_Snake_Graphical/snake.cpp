#include "snake.h"

/*Author: Elliot Gong
* Purpose: Update the current functions to accomodate for the SFML Graphical functions.
* Restrictions: Must update the b2world and apply forces to the player based on keyboard input.
* Date: 3/15/2022
*/

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
/// 

void Update(b2Body* player, b2World* world,  float& targetX, float& targetY, int& targetCount)
{
	//Use the b2World class's step function to update the world.
	world->Step(1.0f / 8000.0f, 6, 2);
	//Get the player object's position and pass that into the display function along with
	//the other parameters.
	b2Vec2 pos = player->GetPosition();
	//Display(targetX, targetY, pos.x, pos.y, targetCount);

}
/// <summary>
/// This method displays the positions of the player and target.
/// </summary>
/// <param name="targetX">The target's x coordinate.</param>
/// <param name="targetY">The target's y coordinate.</param>
/// <param name="playerX">The player's x coordinate.</param>
/// <param name="playerY">The player's y coordinate.</param>

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

