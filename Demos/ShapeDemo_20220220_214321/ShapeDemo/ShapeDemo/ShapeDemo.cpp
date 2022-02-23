// ShapeDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Shape.h"
#include "Circle.h"

int main()
{
    srand(time(NULL));
    Circle c(rand() % 10);
    {
        Shape* d = &c;
        Shape g = (Shape)c;
        cout << "area = " << d->getArea() << endl;
    }
    cout << "outside brackets" << endl;
    
}

