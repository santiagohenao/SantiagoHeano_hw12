#include <SFML/Graphics.hpp>
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
    double xf=2.;
    double xactual=xi;

    vector<Block> space;

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


    #include "window.h"

    return 0;
}
