#pragma once
//Include all the necessary header files, including the box2d api.
#include <iostream>
#include <cstring>
#include "include\Box2D\Box2D.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include<iomanip>
#include <chrono>
#include <ctype.h>
#include <cctype>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
using namespace std;
using namespace chrono;

/*Author: Elliot Gong
* Purpose: Declare the functions needed for the Gravity Snake game.
* Restrictions: Must use the required functions.
* Date: 2/20/2022
*/

//Declare all functions.
void Update(b2Body* player, b2World* world, float& targetX, float& targetY, int& targetCount);
void Display(float& targetX, float& targetY, float playerX, float playerY, int& targetCount);
void ApplyForces(int key, b2Body* player);
void MoveTarget(float& xPos, float& yPos);
//These header functions will be used to help get a random float within a range and determine if a
//float is within a range.
float GenerateRandomNumber(float min, float max);
bool WithinRange(float value, float min, float max);
//SFML Snake Game Functions

void ApplyForceUp(b2Body* player);
void ApplyForceDown(b2Body* player);
void ApplyForceLeft(b2Body* player);
void ApplyForceRight(b2Body* player);
void StopMoving(b2Body& player);
void ReverseGravity(b2World* world);
void SetUpTargets();
bool SelectNextTarget(b2BodyDef* targetBodyDef);
void ProcessInput(b2Body* player, int& keyPresses);
void CheckCollision(b2Body* player, b2Body* target, b2BodyDef* targetDef, b2Vec2& currentPosition);


