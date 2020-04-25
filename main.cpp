#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include "FractalCreator.hpp"

int main()
{
    const int HEIGHT = 600;
    const int WIDTH = 800;

    FractalCreator myFractal(WIDTH, HEIGHT);
    myFractal.addZoom(Zoom(372, 126, 4.0/WIDTH));
    myFractal.calculateIterations();
    myFractal.drawFractal();
    myFractal.writeBitMap("../test.bmp");
    return 0;
}
