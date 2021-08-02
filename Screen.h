#pragma
#include <SFML/Graphics.hpp>
#include "BST.h"
#include "RBT.h"
#include <time.h>
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

    clock_t bstStart;
    clock_t rbtStart;
};



