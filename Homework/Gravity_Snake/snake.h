#pragma once
#include <iostream>
#include <cstring>
#include "include\Box2D\Box2D.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Declare all functions.
void Update(b2Body* player, b2World* world, float targetX, float targetY);

void Display(float targetX, float targetY, float playerX, float playerY);

void ApplyForces(int key, b2Body* player);

void MoveTarget(float& xPos, float& yPos);

float GenerateRandomNumber(float min, float max);