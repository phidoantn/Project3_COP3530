#pragma
#include <SFML/Graphics.hpp>
#include "BST.h"
#include "RBT.h"
class Screen {
public:
    BST tree;
    RBT RBTtree;
    Screen();
    void insertBST();
    void insertRBT();
    void Draw(sf::RenderWindow& window, sf::Vector2i mousePosition);
    void TopButton(sf::RenderWindow &window);
    void BottomButton(sf::RenderWindow &window);
};




