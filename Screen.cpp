#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
Screen::Screen() {
}

void Screen::Draw(sf::RenderWindow &window, sf::Vector2i mousePosition) {
    sf::Font font;
    if(!font.loadFromFile("font.otf")){
        cout << "error loading font" << endl;
    }
    /// buttons ///
    sf::RectangleShape button(sf::Vector2f(300, 75));
    button.setPosition(115.f, 350.f);
    button.setFillColor(sf::Color(0, 76, 153));
    sf::Text b1title;
    b1title.setFont(font);
    b1title.setString("Build DNA");
    b1title.setCharacterSize(40);
    b1title.setFillColor(sf::Color::White);
    b1title.setPosition(160.f, 360.f);

    sf::RectangleShape button2(sf::Vector2f(300, 75));
    button2.setPosition(115.f, 500.f);
    button2.setFillColor(sf::Color(0, 76, 153));
    sf::Text b2title;
    b2title.setFont(font);
    b2title.setString("Build Traits");
    b2title.setCharacterSize(40);
    b2title.setFillColor(sf::Color::White);
    b2title.setPosition(135.f, 510.f);

    window.draw(button);
    window.draw(b1title);
    window.draw(button2);
    window.draw(b2title);

    /// title ///
    sf::Text text;
    sf::Text traits;
    text.setFont(font);
    traits.setFont(font);
    text.setString("DNA vs");
    traits.setString("Traits");
    text.setCharacterSize(100);
    traits.setCharacterSize(100);
    text.setFillColor(sf::Color(0, 76, 153));
    traits.setFillColor(sf::Color(0, 76, 153));
    text.setOutlineColor(sf::Color::Yellow);
    traits.setOutlineColor(sf::Color::Yellow);
    text.setOutlineThickness(1);
    traits.setOutlineThickness(1);
    text.setPosition(100.f, 100.f);
    traits.setPosition(100.f, 185.f);
    text.setStyle(sf::Text::Bold);
    traits.setStyle(sf::Text::Bold);

    window.draw(text);
    window.draw(traits);

    /// box ///
    sf::RectangleShape b(sf::Vector2f(400, 500));
    b.setPosition(850.f, 200.f);
    b.setFillColor(sf::Color::Transparent);
    b.setOutlineColor(sf::Color::Black);
    b.setOutlineThickness(2);

    window.draw(b);

    int heightB = 350;  //dimensions for top button
    int heightT = 425;
    int widthL = 115;
    int widthR = 415;

    int heightBB = 500; //dimensions for bottom button
    int heightTB = 575; //(extra B for bottom button)
    int widthLB = 115;
    int widthRB = 415;

    //if top button clicked
    if(mousePosition.y  > heightB && mousePosition.y < heightT && mousePosition.x > widthL && mousePosition.x < widthR){
        TopButton(window);
    }
    //if bottom button clicked
    if(mousePosition.y  > heightBB && mousePosition.y < heightTB && mousePosition.x > widthLB && mousePosition.x < widthRB){
        BottomButton(window);
    }


}

void Screen::TopButton(sf::RenderWindow &window) {
    sf::Font font;
    if(!font.loadFromFile("font.otf")){
        cout << "error loading font" << endl;
    }
        /// subtitles ///
        sf::Text s1;
        s1.setFont(font);
        s1.setString("Build DNA");
        s1.setCharacterSize(45);
        s1.setFillColor(sf::Color::Black);
        s1.setPosition(680.f, 40.f);
        s1.setStyle(sf::Text::Bold);
        s1.setStyle(sf::Text::Underlined);

        window.draw(s1);

        /// sub-subtitles ///
        sf::Text ss1;
        ss1.setFont(font);
        ss1.setString("Traits:");
        ss1.setCharacterSize(35);
        ss1.setFillColor(sf::Color::Black);
        ss1.setPosition(850.f, 140.f);
        ss1.setStyle(sf::Text::Bold);

        window.draw(ss1);

        /// dna helix ///
        sf::Texture tex;
        if(!tex.loadFromFile("dnahelix.jpeg")){
            cout << "helix did not load correctly" << endl;
        }
        sf::Sprite helix;
        helix.setTexture(tex);
        helix.setScale(sf::Vector2f(0.3f, 0.3f));
        helix.setPosition(580.f, 160.f);

        window.draw(helix);

    }


void Screen::BottomButton(sf::RenderWindow &window) {
    sf::Font font;
    if(!font.loadFromFile("font.otf")){
        cout << "error loading font" << endl;
    }
        /// subtitles ///
        sf::Text s2;
        s2.setFont(font);
        s2.setString("Build Traits");
        s2.setCharacterSize(45);
        s2.setFillColor(sf::Color::Black);
        s2.setPosition(760.f, 40.f);
        s2.setStyle(sf::Text::Bold);
        s2.setStyle(sf::Text::Underlined);

        window.draw(s2);

        /// sub-subtitles ///
        sf::Text ss2;
        ss2.setFont(font);
        ss2.setString("DNA Sequence:");
        ss2.setCharacterSize(35);
        ss2.setFillColor(sf::Color::Black);
        ss2.setPosition(850.f, 140.f);
        ss2.setStyle(sf::Text::Bold);

        window.draw(ss2);


        /// man/woman ///
        sf::Texture tex2;
        if(!tex2.loadFromFile("body2.png")){
            cout << "head did not load correctly" << endl;
        }
        sf::Sprite body;
        body.setTexture(tex2);
        body.setPosition(500.f, 1.f);
        body.setScale(sf::Vector2f(2.0f, 2.0f));

        window.draw(body);

}
