#include <SFML/Graphics.hpp>
#include <SFML/Keyboard.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <math.h>
#include <string>

int main()
{
    sf::Font font;
    if (!font.loadFromFile("UbuntuMono-R.ttf"))
    {
        std::cout << "Error loading font\n" ;
    }
    static float frameCount=0;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Holololo");
    //window.pushGLStates();

    sf::Text atext;
    atext.setFont(font);
    atext.setCharacterSize(20);
    atext.setStyle(sf::Text::Bold);
    atext.setFillColor(sf::Color::White);
    atext.setPosition(0,0);

    std::string s="0";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(30);
        window.clear();


        s=std::to_string(frameCount);

        std::cout << frameCount << "\t" << s << std::endl;

        atext.setString(s);

        //draw the string
        window.draw(atext);

        window.display();
        frameCount++;
    }

}
