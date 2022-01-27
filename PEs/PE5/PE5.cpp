// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        //window.draw(triangle);
        //End current frame.
        window.display();
    }
    
    

    
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
