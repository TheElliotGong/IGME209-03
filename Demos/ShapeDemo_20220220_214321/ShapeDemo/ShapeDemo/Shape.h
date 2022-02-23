#pragma once
class Shape
{
public:
	Shape();
	~Shape();

	virtual float getArea();

private:
	float area;
};

