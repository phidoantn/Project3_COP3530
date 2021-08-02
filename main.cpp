#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"
#include <fstream>
#include <sstream>
#include <time.h>

int main() {
    Screen send;

    clock_t bstStart;
    send.insertBST();
    clock_t bstStop;
    double elapsedBSTInsert = (double)(bstStart - bstStop) / CLOCKS_PER_SEC;
    send.setbstTime(elapsedBSTInsert);

    //send.insertRBT(); ///uncomment when rbt is fixed
    clock_t rstStop;
    double elapsedRSTInsert = (double)(bstStop - rstStop) / CLOCKS_PER_SEC;
    send.setrbtTime(elapsedRSTInsert);

    send.doTheStuff();

    sf::RenderWindow window(sf::VideoMode(1350, 750), "cop3530 project3");
    sf::Vector2i mousePositionSave;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    mousePositionSave = mousePosition;                              //save position of click if left click
                }
            }

            window.clear(sf::Color(140, 140, 140));
            send.Draw(window, mousePositionSave);                               //keep drawing board at this position -> until another left click is made
            window.display();
        }
    }
}
