#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	cout << "Shape ctor" << endl;
}

Shape::~Shape()
{
	cout << "Shape dtor" << endl;
}

float Shape::getArea()
{
	return 0.0f;
}
