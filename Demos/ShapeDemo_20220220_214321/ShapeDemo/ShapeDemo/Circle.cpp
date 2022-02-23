#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(float r)
{
	radius = r;
	cout << "Cicle ctor" << endl;

}

Circle::~Circle()
{
	cout << "Circle dtor" << endl;

}

float Circle::getArea()
{
	return radius * radius * 3.14159f;
}
