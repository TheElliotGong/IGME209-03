// PE5-rework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setTitle("Testing");
    //Create a red circle
    sf::CircleShape circle(50.f);
    circle.setPosition(200, 200);
    circle.setFillColor(sf::Color::Red);
    //Create a green rectangle
    sf::RectangleShape rect(sf::Vector2f(60, 150));
    rect.setPosition(450, 100);
    rect.setFillColor(sf::Color::Green);
    //Create a blue triangle
    sf::CircleShape triangle(40, 3);
    triangle.setPosition(50, 500);
    triangle.setFillColor(sf::Color::Blue);
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
        //End current frame.
        window.display();
    }
    return 0;
}
