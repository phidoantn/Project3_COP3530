#include <SFML/Graphics.hpp>

class Screen {
public:
    Screen();
    void Draw(sf::RenderWindow& window);
    void LeftClick(sf::Vector2i mousePosition);
    void RightClick(sf::Vector2i mousePosition);
};


