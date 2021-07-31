#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"

int main()
{
    Screen send;
    sf::RenderWindow window(sf::VideoMode(1500, 750), "dna");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {        //send instructions for what to do with left click
                    send.LeftClick(mousePosition);
                }

                if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {       //send instructions for what to do with a right click
                    send.RightClick(mousePosition);
                }

            }
        }

        window.clear(sf::Color(140, 140, 140));
        send.Draw(window);
        window.display();
    }
}