#pragma
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <cmath>
using namespace std;
Screen::Screen() {
    this->bstTime = 0;
    this->rbtTime = 0;
    this->fileToLoad = "";

    
// add value in to searchThese vector
    searchThese.push_back(7620511);
    searchThese.push_back(4959788);
    searchThese.push_back(6549120);
    searchThese.push_back(952399);
}


void Screen::doTheStuff() {
    ///get vector of traits///

    clock_t t = clock();
    tree.searchBST(tree.root, searchThese);
    clock_t bstStop;
    double elapsed = (double)(bstStop - t) / CLOCKS_PER_SEC;
    bstTime += elapsed;                          //bstTime originally -> time to build tree + time to search tree = new bstTime
    bstTime = bstTime / 1000000;
    bstTime = round(bstTime);

    RBTtree.searchRBT(RBTtree.root, searchThese);
    clock_t rbtEnd;
    double relapsed = (double)(rbtEnd - bstStop) / CLOCKS_PER_SEC;
    rbtTime += relapsed;                    //rbtTime originally -> time to build tree + time to search tree = new rstTime
    rbtTime = rbtTime / 1000000;
    rbtTime = round(rbtTime);

}

// call insert function BST
void Screen::insertBST() {
    clock_t bstStart = clock();

    ifstream file;
    file.open(fileToLoad);

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
    
    // stop clock
    clock_t bstStop;
    file.close();
    double elapsedBSTInsert = (double) (bstStop - bstStart) / CLOCKS_PER_SEC;
    bstTime = elapsedBSTInsert;
}


// insert Red black tree
void Screen::insertRBT()
{
    clock_t bstS = clock();

    fstream file;
    file.open("fourthdnafile.csv");

    if (!file.is_open()) {
        cout << "rbt dna file failure" << endl;
    }

    string line, rsid, ch, pos, result;
    int iter = 0;
    int rbtCount = 0;   //debug
    //gets line, reach each line
    while (getline(file, line)) {

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
            rbtCount++;
        }
        iter++;
    }
    clock_t rstStop;
    
    file.close();
    double elapsedRSTInsert = (double) (rstStop - bstS) / CLOCKS_PER_SEC;
    rbtTime = elapsedRSTInsert;
}


// draw the screeen
void Screen::Draw(sf::RenderWindow& window, sf::Vector2i mousePosition, int &count) {
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

    // draw these sprites
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
    sf::RectangleShape b(sf::Vector2f(460, 500));
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
        buttonPress = true;
    }
    //if bottom button clicked
    if (mousePosition.y > heightBB && mousePosition.y < heightTB && mousePosition.x > widthLB && mousePosition.x < widthRB) {
        BottomButton(window);
        buttonPress = true;
    }
    //invisible reset button
    if(mousePosition.y > 0 && mousePosition.y < 100 && mousePosition.x > 0 && mousePosition.x < 100 && count == 0 && buttonPress == true){
        bstTime = 0;
        rbtTime = 0;
        Reset(window);
        buttonPress = false;
    }

}

// initialize screen

void Screen::Initial(string file){
    fileToLoad = "";
    fileToLoad = file;

    if(tree.root != nullptr){
        tree.deleteTree(tree.root);
        tree.root = nullptr;
        tree.traits.clear();
    }

    insertBST();
    insertRBT();

    doTheStuff();
}

void Screen::Reset(sf::RenderWindow &window){
    cout << "Enter file to load :" << endl;
    string enter;
    cin >> enter;

    enter += ".csv";
    Initial(enter);
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
    ss1.setString("DNA Sequence:");
    ss1.setCharacterSize(35);
    ss1.setFillColor(sf::Color::Black);
    ss1.setPosition(850.f, 140.f);
    ss1.setStyle(sf::Text::Bold);

    window.draw(ss1);

    /// dna helix ///
    sf::Texture tex;
    if (!tex.loadFromFile("images/dnahelix.png")) {
        cout << "helix did not load correctly" << endl;
    }
    sf::Sprite helix;
    helix.setTexture(tex);
    helix.setScale(sf::Vector2f(2.2f, 2.2f));
    helix.setPosition(580.f, 130.f);

    window.draw(helix);

    string A1, A2, A3, A4;                               //to save the rsid values plus the associated allele thing
    A1 = "7620511: " + tree.traits.at(0);
    A2 = "4959788: " + tree.traits.at(1);
    A3 = "6549120: " + tree.traits.at(2);
    A4 = "952399: " + tree.traits.at(3);

    sf::Text basePairs;
    basePairs.setFont(font);
    basePairs.setCharacterSize(25);
    basePairs.setPosition(860, 225);
    basePairs.setFillColor(sf::Color::Black);

    basePairs.setString(A1 + "\n" + "\n" + A2 + "\n" + "\n" + A3 + "\n" + "\n" + A4 + "\n" + "\n" + "TIME WITH BST: " + to_string(bstTime) + "\n" + "\n" + "TIME WITH RBT: " + to_string(rbtTime) + "\n");

    window.draw(basePairs);
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
    ss2.setString("Traits: ");
    ss2.setCharacterSize(35);
    ss2.setFillColor(sf::Color::Black);
    ss2.setPosition(850.f, 140.f);
    ss2.setStyle(sf::Text::Bold);

    window.draw(ss2);


    /// man/woman ///
    sf::Texture tex2;
    if (!tex2.loadFromFile("images/body.png")) {
        cout << "head did not load correctly" << endl;
    }
    sf::Sprite body;
    body.setTexture(tex2);
    body.setPosition(500.f, 1.f);
    body.setScale(sf::Vector2f(2.0f, 2.0f));

    window.draw(body);

    //use the bst vector to display sprites, but the time should be the same bc the traits vectors are the same size and should hold the same stuff

    string f, s, t, fo;         //specific trait + trait
    string g, e, h, p;          //specific trait (to be added to string above
    ///gender
    bool female = true;
    if (tree.traits.at(0) == "GG") {  //"boy"
        sf::Texture s;
        if (!s.loadFromFile("images/shirt.png")) {
            cout << "blue shirt did not load correctly" << endl;
        }
        sf::Sprite blueshirt;
        blueshirt.setTexture(s);
        blueshirt.setScale(sf::Vector2f(1.0f, 1.0f));
        blueshirt.setPosition(562.f, 186.f);
        female = false;

        window.draw(blueshirt);
        g = "male";
    } else {
        sf::Texture b;
        if (!b.loadFromFile("images/yellow.png")) {
            cout << "pink shirt did not load correctly" << endl;
        }
        sf::Sprite pinkshirt;
        pinkshirt.setTexture(b);
        pinkshirt.setScale(sf::Vector2f(0.15f, 0.15f));
        pinkshirt.setPosition(605.f, 230.f);

        window.draw(pinkshirt);
        g = "female";
    }
    sf::Texture j;
    if (!j.loadFromFile("images/bluejeans.png")) {
        cout << "jeans did not load correctly" << endl;
    }
    sf::Sprite jeans;
    jeans.setTexture(j);
    jeans.setScale(sf::Vector2f(1.5f, 1.5f));
    jeans.setPosition(520.f, 380.f);

    window.draw(jeans);
    f = "Gender: " + g;


    ///eyes///
    if (tree.traits.at(1) == "CT") {
        sf::Texture h;
        if (!h.loadFromFile("images/BE.png")) {
            cout << "brown eyes did not load correctly" << endl;
        }
        sf::Sprite browneyes;
        browneyes.setTexture(h);
        browneyes.setScale(sf::Vector2f(0.01f, 0.01f));
        browneyes.setPosition(622.f, 127.f);

        window.draw(browneyes);
        e = "brown";
    } else if (tree.traits.at(1) == "GG") {
        sf::Texture y;
        if (!y.loadFromFile("images/blue.png")) {
            cout << "blue eyes did not load correctly" << endl;
        }
        sf::Sprite blueeyes;
        blueeyes.setTexture(y);
        blueeyes.setScale(sf::Vector2f(0.01f, 0.01f));
        blueeyes.setPosition(622.f, 127.f);

        window.draw(blueeyes);
        e = "blue";
    } else if (tree.traits.at(1) == "TT") {
        sf::Texture g;
        if (!g.loadFromFile("images/blackeyes.png")) {
            cout << "black eyes did not load correctly" << endl;
        }
        sf::Sprite blackeyes;
        blackeyes.setTexture(g);
        blackeyes.setScale(sf::Vector2f(0.037f, 0.037f));
        blackeyes.setPosition(610.f, 125.f);

        window.draw(blackeyes);
        e = "black";
    } else {
        sf::Texture u;
        if (!u.loadFromFile("images/greeneyes.png")) {
            cout << "green eyes did not load correctly" << endl;
        }
        sf::Sprite greeneyes;
        greeneyes.setTexture(u);
        greeneyes.setScale(sf::Vector2f(0.015f, 0.015f));
        greeneyes.setPosition(618.f, 130.f);

        window.draw(greeneyes);
        e = "green";
    }
    s = "Eyes: " + e;


    ///hair///
    if (tree.traits.at(2) == "GG") {            //brown
        if (female) {
            sf::Texture z;
            if (!z.loadFromFile("images/brownhair.png")) {
                cout << "brown hair girl did not load correctly" << endl;
            }
            sf::Sprite brownhairgirl;
            brownhairgirl.setTexture(z);
            brownhairgirl.setScale(sf::Vector2f(0.3f, 0.3f));
            brownhairgirl.setPosition(565.f, 65.f);

            window.draw(brownhairgirl);
            h = "brown";
        } else {
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
    } else if (tree.traits.at(2) == "GG") {       //blonde
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
        } else {
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
    } else if (tree.traits.at(2) == "TT") {            //black
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
        } else {
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
    } else {                          //red
        if (female) {
            sf::Texture n;
            if (!n.loadFromFile("images/red.png")) {
                cout << "red hair girl did not load correctly" << endl;
            }
            sf::Sprite redhairgirl;
            redhairgirl.setTexture(n);
            redhairgirl.setScale(sf::Vector2f(0.45f, 0.45f));
            redhairgirl.setPosition(593.f, 50.f);

            window.draw(redhairgirl);
            h = "red";
        } else {
            sf::Texture v;
            if (!v.loadFromFile("images/redhair.png")) {
                cout << "red hair guy did not load correctly" << endl;
            }
            sf::Sprite redhairguy;
            redhairguy.setTexture(v);
            redhairguy.setScale(sf::Vector2f(0.14f, 0.14f));
            redhairguy.setPosition(615.f, 80.f);

            window.draw(redhairguy);
            h = "red";
        }
    }
    t = "Hair: " + h;

    ///personality///
    if (tree.traits.at(3) == "AG") {
        sf::Texture c;
        if (!c.loadFromFile("images/rr.png")) {
            cout << "smile did not load correctly" << endl;
        }
        sf::Sprite smile;
        smile.setTexture(c);
        smile.setScale(sf::Vector2f(0.02f, 0.02f));
        smile.setPosition(637.f, 150.f);

        window.draw(smile);
        p = "happy";
    } else {
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
    fo = "Mood/Personality: " + p;

    sf::Text dnaSequence;
    dnaSequence.setFont(font);
    dnaSequence.setCharacterSize(25);
    dnaSequence.setFillColor(sf::Color::Black);
    dnaSequence.setPosition(860, 225);
    dnaSequence.setString(f + "\n" + "\n" + s + "\n" + "\n" + t + "\n" + "\n" + fo + "\n" + "\n" + "TIME WITH BST: " +
                          to_string(bstTime) + "\n" + "\n" + "TIME WITH RBT: " + to_string(rbtTime) + "\n");

    window.draw(dnaSequence);
}
