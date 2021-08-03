#pragma
#include <SFML/Graphics.hpp>
#include "BST.h"
#include "RBT.h"
#include <cmath>
#include <time.h>
class Screen {
private:
    double bstTime;
    double rbtTime;
public:
    BST tree;
    RBT RBTtree;
    string fileToLoad;
    vector<int> searchThese;
    bool buttonPress = true;
    Screen();
    void insertBST();
    void insertRBT();
    void doTheStuff();
    void Draw(sf::RenderWindow& window, sf::Vector2i mousePosition, int &count);
    void TopButton(sf::RenderWindow &window);
    void BottomButton(sf::RenderWindow &window);
    void Initial(string file);
    void Reset(sf::RenderWindow &window);

};
