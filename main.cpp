#include <SFML/Graphics.hpp>
#include <SFML/Keyboard.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <math.h>

using namespace std;

static double c=1.;
static double dt=10e-04;

static double ysize=100.;

#include "Block.h"


int main()
{
    static double dx=c*dt*1.1;
    double xi=-2.;
    double xf=20.;
    double xactual=xi;

    vector<Block> space;

    float tim=0;

    int pause_status=0;

    while(xactual<=xf)
    {
        if(abs(xactual)<0.5)
        {
            space.push_back(Block(xactual,0.5));
        }
        else
        {
            space.push_back(Block(xactual,0));
        }
        xactual+=dx;
    }

    sf::Font font;
    if (!font.loadFromFile("UbuntuMono-R.ttf"))
    {
        std::cout << "Error loading font\n" ;
    }

    sf::Text atext;
    atext.setFont(font);
    atext.setCharacterSize(50);
    atext.setStyle(sf::Text::Bold);
    atext.setFillColor(sf::Color::White);
    atext.setPosition(-70,70);

    string s="0";

    #include "window.h"

    return 0;
}
