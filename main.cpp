#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"

int main() {
    Screen send;
    string input;
    cout << "Enter file to load: " << endl;
    cin >> input;
    input += ".csv";
    int iter = 0;
    send.Initial(input);
        
    // main window
        sf::RenderWindow window(sf::VideoMode(1350, 750), "cop3530 project3");
        sf::Vector2i mousePositionSave;

        while (window.isOpen()) {
            sf::Event event;
            
            // window actions base on events
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        mousePositionSave = mousePosition;                              //save position of click if left click
                    }
                }
                // redraw window
                window.clear(sf::Color(140, 140, 140));
                send.Draw(window, mousePositionSave, iter);                              //keep drawing board at this position -> until another left click is made
                window.display();

        }
    }

}
