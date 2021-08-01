#pragma
#include <SFML/Graphics.hpp>
#include "BST.h"
class Screen {
public:
    BST tree;
    Screen();
    void insertBST();
    void Draw(sf::RenderWindow& window, sf::Vector2i mousePosition);
    void TopButton(sf::RenderWindow &window);
    void BottomButton(sf::RenderWindow &window);
};




