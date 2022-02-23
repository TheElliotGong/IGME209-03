#pragma once
#include <iostream>
#include <cstring>
#include "include\Box2D\Box2D.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

//Declare all functions.
void Update(b2Body* player, b2World* world, float& targetX, float& targetY, int& targetCount);

void Display(float& targetX, float& targetY, float playerX, float playerY, int& targetCount);

void ApplyForces(int key, float& playerX, float& playerY);

void MoveTarget(float& xPos, float& yPos);

float GenerateRandomNumber(float min, float max);