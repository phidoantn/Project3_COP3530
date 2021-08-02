#pragma
#include <SFML/Graphics.hpp>
#include "BST.h"
#include "RBT.h"
#include <time.h>
class Screen {
private:
    double bstTime;
    double rbtTime;
public:
    BST tree;
    RBT RBTtree;
    clock_t bstStartAgain;
    clock_t rbtStartAgain;
    Screen();
    void insertBST();
    void insertRBT();
    void Draw(sf::RenderWindow& window, sf::Vector2i mousePosition);
    void TopButton(sf::RenderWindow &window);
    void BottomButton(sf::RenderWindow &window);

    void setbstTime(double b);
    void setrbtTime(double r);

};






