#pragma
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
Screen::Screen() {

}
void Screen::insertBST() {

    ifstream file;
    file.open("dna.csv");

    if (!file.is_open()) {
        cout << "dna file failure" << endl;
    }

    string line, rsid, ch, pos, result;
    int iter = 0;
    int count = 0;
    //gets line, reach each line
    while (getline(file, line)) {

        istringstream stream(line);

        //omit first 13 lines
        if (iter > 12) {
            getline(stream, rsid, ',');
            getline(stream, ch, ',');
            getline(stream, pos, ',');
            getline(stream, result, '"');

            //don't need the rs, just want the integer part
            string withoutRS = rsid.substr(3, rsid.length());

            // push into the tree
            tree.root = tree.insertNode(tree.root, stoi(withoutRS), result);
            count++;
        }
        iter++;
    }
    cout << "count: " << count << endl;
    file.close();
}

void Screen::insertRBT()
{
    fstream file;
    file.open("files/dna.csv");

    if (!file.is_open()) {
        cout << "dna file failure" << endl;
    }

    string line, rsid, ch, pos, result;
    int iter = 0;

    //gets line, reach each line
    while (getline(file, line) && iter < 30) {

        istringstream stream(line);

        //obmit first 13 lines 
        if (iter > 12) {
            getline(stream, rsid, ',');
            getline(stream, ch, ',');
            getline(stream, pos, ',');
            getline(stream, result, '"');

            //don't need the rs, just want the integer part
            string withoutRS = rsid.substr(3, rsid.length());

            // push into the tree
            RBTtree.root = RBTtree.insert(RBTtree.root, stoi(withoutRS), result);
        }
        iter++;
    }

    file.close();
}

void Screen::Draw(sf::RenderWindow& window, sf::Vector2i mousePosition) {
    sf::Font font;
    if (!font.loadFromFile("font.otf")) {
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
    if (mousePosition.y > heightB && mousePosition.y < heightT && mousePosition.x > widthL && mousePosition.x < widthR) {
        TopButton(window);
    }
    //if bottom button clicked
    if (mousePosition.y > heightBB && mousePosition.y < heightTB && mousePosition.x > widthLB && mousePosition.x < widthRB) {
        BottomButton(window);
    }


}

void Screen::TopButton(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("font.otf")) {
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
    if (!tex.loadFromFile("files/dnahelix.png")) {
        cout << "helix did not load correctly" << endl;
    }
    sf::Sprite helix;
    helix.setTexture(tex);
    helix.setScale(sf::Vector2f(2.2f, 2.2f));
    helix.setPosition(580.f, 130.f);

    window.draw(helix);

}


void Screen::BottomButton(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("font.otf")) {
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
    if (!tex2.loadFromFile("body.png")) {
        cout << "head did not load correctly" << endl;
    }
    sf::Sprite body;
    body.setTexture(tex2);
    body.setPosition(500.f, 1.f);
    body.setScale(sf::Vector2f(2.0f, 2.0f));

    window.draw(body);

    ///build tree
    insertBST();
    ///get vector of traits
    tree.searchBST(tree.root);

    string f, s, t, fo;         //specific trait + trait
    string g, e, h, p;          //specific trait (to be added to string above
    ///gender
    bool female = true;
    if (tree.traits.at(0) == "GG") {  //"boy"
        sf::Texture s;
        if (!s.loadFromFile("images/yy.jpg")) {
            cout << "blue shirt did not load correctly" << endl;
        }
        sf::Sprite blueshirt;
        blueshirt.setTexture(s);
        blueshirt.setScale(sf::Vector2f(0.4f, 0.4f));
        blueshirt.setPosition(510.f, 170.f);
        female = false;

        window.draw(blueshirt);
        g = "male";
    }
    else {
        sf::Texture b;
        if (!b.loadFromFile("images/pinkshirt.png")) {
            cout << "pink shirt did not load correctly" << endl;
        }
        sf::Sprite pinkshirt;
        pinkshirt.setTexture(b);
        pinkshirt.setScale(sf::Vector2f(1.0f, 1.0f));
        pinkshirt.setPosition(580.f, 130.f);

        window.draw(pinkshirt);
        g = "Female";
    }
    f = g + " gender";


    ///eyes///
    if (tree.traits.at(1) == "CT") {
        sf::Texture h;
        if (!h.loadFromFile("images/browneyes.jpeg")) {
            cout << "brown eyes did not load correctly" << endl;
        }
        sf::Sprite browneyes;
        browneyes.setTexture(h);
        browneyes.setScale(sf::Vector2f(0.2f, 0.2f));
        browneyes.setPosition(580.f, 130.f);

        window.draw(browneyes);
        e = "brown";
    }
    else if (tree.traits.at(1) == "CC") {
        sf::Texture y;
        if (!y.loadFromFile("images/blueeyes.jpeg")) {
            cout << "blue eyes did not load correctly" << endl;
        }
        sf::Sprite blueeyes;
        blueeyes.setTexture(y);
        blueeyes.setScale(sf::Vector2f(1.0f, 1.0f));
        blueeyes.setPosition(580.f, 130.f);

        window.draw(blueeyes);
        e = "blue";
    }
    else if (tree.traits.at(1) == "TT") {
        sf::Texture g;
        if (!g.loadFromFile("images/blackeyes.jpeg")) {
            cout << "black eyes did not load correctly" << endl;
        }
        sf::Sprite blackeyes;
        blackeyes.setTexture(g);
        blackeyes.setScale(sf::Vector2f(1.0f, 1.0f));
        blackeyes.setPosition(580.f, 130.f);

        window.draw(blackeyes);
        e = "black";
    }
    else {
        sf::Texture u;
        if (!u.loadFromFile("images/greeneyes.jpeg")) {
            cout << "green eyes did not load correctly" << endl;
        }
        sf::Sprite greeneyes;
        greeneyes.setTexture(u);
        greeneyes.setScale(sf::Vector2f(1.0f, 1.0f));
        greeneyes.setPosition(580.f, 130.f);

        window.draw(greeneyes);
        e = "green";
    }
    s = e + " eyes";


    ///hair///
    if (tree.traits.at(2) == "GG") {            //brown
        if (female) {
            sf::Texture z;
            if (!z.loadFromFile("images/brownhairgirl.png")) {
                cout << "brown hair girl did not load correctly" << endl;
            }
            sf::Sprite brownhairgirl;
            brownhairgirl.setTexture(z);
            brownhairgirl.setScale(sf::Vector2f(0.5f, 0.5f));
            brownhairgirl.setPosition(600.f, 100.f);

            window.draw(brownhairgirl);
            h = "brown";
        }
        else {
            sf::Texture q;
            if (!q.loadFromFile("images/brownhairguy.png")) {
                cout << "brown hair guy did not load correctly" << endl;
            }
            sf::Sprite brownhairguy;
            brownhairguy.setTexture(q);
            brownhairguy.setScale(sf::Vector2f(0.15f, 0.15f));
            brownhairguy.setPosition(600.f, 45.f);

            window.draw(brownhairguy);
            h = "brown";
        }
    }
    else if (tree.traits.at(2) == "GT") {       //blonde
        if (female) {
            sf::Texture a;
            if (!a.loadFromFile("images/blondehairgirl.png")) {
                cout << "blonde hair girl did not load correctly" << endl;
            }
            sf::Sprite blondehairgirl;
            blondehairgirl.setTexture(a);
            blondehairgirl.setScale(sf::Vector2f(1.0f, 1.0f));
            blondehairgirl.setPosition(580.f, 130.f);

            window.draw(blondehairgirl);
            h = "blonde";
        }
        else {
            sf::Texture w;
            if (!w.loadFromFile("images/blondehairguy.png")) {
                cout << "blonde hair guy did not load correctly" << endl;
            }
            sf::Sprite blondehairguy;
            blondehairguy.setTexture(w);
            blondehairguy.setScale(sf::Vector2f(1.0f, 1.0f));
            blondehairguy.setPosition(580.f, 130.f);

            window.draw(blondehairguy);
            h = "blonde";
        }
    }
    else if (tree.traits.at(2) == "TT") {            //black
        if (female) {
            sf::Texture d;
            if (!d.loadFromFile("images/blackhairgirl.png")) {
                cout << "black hair girl did not load correctly" << endl;
            }
            sf::Sprite blackhairgirl;
            blackhairgirl.setTexture(d);
            blackhairgirl.setScale(sf::Vector2f(1.0f, 1.0f));
            blackhairgirl.setPosition(580.f, 130.f);

            window.draw(blackhairgirl);
            h = "black";
        }
        else {
            sf::Texture f;
            if (!f.loadFromFile("images/blackhairguy.png")) {
                cout << "black hair guy did not load correctly" << endl;
            }
            sf::Sprite blackhairguy;
            blackhairguy.setTexture(f);
            blackhairguy.setScale(sf::Vector2f(1.0f, 1.0f));
            blackhairguy.setPosition(580.f, 130.f);

            window.draw(blackhairguy);
            h = "black";
        }
    }
    else {                          //red
        if (female) {
            sf::Texture n;
            if (!n.loadFromFile("images/redhairgirl.png")) {
                cout << "red hair girl did not load correctly" << endl;
            }
            sf::Sprite redhairgirl;
            redhairgirl.setTexture(n);
            redhairgirl.setScale(sf::Vector2f(1.0f, 1.0f));
            redhairgirl.setPosition(580.f, 130.f);

            window.draw(redhairgirl);
            h = "red";
        }
        else {
            sf::Texture v;
            if (!v.loadFromFile("images/redhairguy.png")) {
                cout << "red hair guy did not load correctly" << endl;
            }
            sf::Sprite redhairguy;
            redhairguy.setTexture(v);
            redhairguy.setScale(sf::Vector2f(1.0f, 1.0f));
            redhairguy.setPosition(580.f, 130.f);

            window.draw(redhairguy);
            h = "red";
        }
    }
    t = h + " hair";

    ///personality///
    if (tree.traits.at(3) == "AG") {
        sf::Texture c;
        if (!c.loadFromFile("images/smile.jpeg")) {
            cout << "smile did not load correctly" << endl;
        }
        sf::Sprite smile;
        smile.setTexture(c);
        smile.setScale(sf::Vector2f(0.1f, 0.1f));
        smile.setPosition(610.f, 130.f);

        window.draw(smile);
        p = "happy";
    }
    else {
        sf::Texture m;
        if (!m.loadFromFile("images/sad.png")) {
            cout << "sad did not load correctly" << endl;
        }
        sf::Sprite sad;
        sad.setTexture(m);
        sad.setScale(sf::Vector2f(1.0f, 1.0f));
        sad.setPosition(580.f, 130.f);

        window.draw(sad);
        p = "sad";
    }
    fo = p + " personality";

    string A1, A2, A3, A4;                               //to save the rsid values plus the associated allele thing
    A1 = "7620511: " + tree.traits.at(0);
    A2 = "4959788: " + tree.traits.at(1);
    A3 = "6549120: " + tree.traits.at(2);
    A4 = "952399: " + tree.traits.at(3);

    sf::Text dnaSequence;
    dnaSequence.setFont(font);
    dnaSequence.setCharacterSize(25);
    dnaSequence.setFillColor(sf::Color::Black);
    dnaSequence.setPosition(900, 250);
    dnaSequence.setString(f + "\n" + A1 + "\n" + s + "\n" + A2 + "\n" + t + "\n" + A3 + "\n" + fo + "\n" + A4);

    window.draw(dnaSequence);


}
