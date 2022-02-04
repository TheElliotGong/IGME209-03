// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "snake.h"
#include "include\Box2D\Box2D.h"

using namespace std;

int main()
{
	b2Vec2 gravity(0.0f, -10.0f);

	b2World world(gravity);
	cout << "Hello World!";
}


