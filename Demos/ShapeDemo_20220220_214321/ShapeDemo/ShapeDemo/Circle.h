#pragma once
#include "Shape.h"
class Circle :  public Shape
{
public:
	Circle(float r);
	~Circle();

	virtual float getArea();

private:
	float radius;
};

