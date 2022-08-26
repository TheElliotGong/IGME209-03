// PE5-final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Author: Elliot Gong
* Purpose: Use the SFML library to draw shapes in a new separate window.
* Restrictions: Download SFML, add include and lib folders to project, and add them in 
* project property settings.
* Date: 1/27/2022
*/
#include <iostream>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

int main()
{
    //Create a window that'll show the drawn shapes.
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setTitle("Shapes");
    //Create a red circle
    sf::CircleShape circle(50.f);
    circle.setPosition(200, 200);
    circle.setFillColor(sf::Color::Red);
    //Create a green rectangle
    sf::RectangleShape rect(sf::Vector2f(60, 150));
    rect.setPosition(450, 100);
    rect.setFillColor(sf::Color::Green);
    //Create a blue triangle
    sf::CircleShape triangle(60, 3);
    triangle.setPosition(350, 300);
    triangle.setFillColor(sf::Color::Blue);
    //Create a yellow pentagon
    sf::CircleShape pentagon(80, 5);
    pentagon.setPosition(550, 400);
    pentagon.setFillColor(sf::Color::Yellow);
    //Leave the window open until the user closes it.
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Clear window with black color
        window.clear(sf::Color::Black);
        //Draw the red circle.
        window.draw(circle);
        //Draw the green rectangle.
        window.draw(rect);
        //Draw a blue triangle
        window.draw(triangle);
        //Draw a yellow pentagon
        window.draw(pentagon);
        //End current frame.
        window.display();
    }
    //End the method by returning the default value.
    return 0;
}


