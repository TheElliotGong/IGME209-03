#pragma once
//Include all the necssary header files, including the box2d api
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
using namespace std;
using namespace chrono;
//Declare all functions.
void Update(b2Body* player, b2World* world, float& targetX, float& targetY, int& targetCount);

void Display(float& targetX, float& targetY, float playerX, float playerY, int& targetCount);

void ApplyForces(int key, b2Body* player);

void MoveTarget(float& xPos, float& yPos);

float GenerateRandomNumber(float min, float max);

bool WithinRange(float value, float min, float max);