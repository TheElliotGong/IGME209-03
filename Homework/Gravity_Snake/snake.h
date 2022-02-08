#pragma once
#include <iostream>
#include <cstring>
#include "include\Box2D\Box2D.h"
#include <conio.h>
#include <stdio.h>
using namespace std;
void Update();

void Display();

void ApplyForces();

void MoveTarget(float& xPos, float& yPos);