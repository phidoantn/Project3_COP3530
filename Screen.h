
#include <SFML/Graphics.hpp>

class Screen {
public:
    Screen();
    void Draw(sf::RenderWindow& window, sf::Vector2i mousePosition);
    void TopButton(sf::RenderWindow &window);
    void BottomButton(sf::RenderWindow &window);
};



