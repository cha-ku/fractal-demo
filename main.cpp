#include <iostream>
#include "BitMap.hpp"
#include "Mandelbrot.hpp"

int main()
{
    const int HEIGHT = 600;
    const int WIDTH = 800;

    BitMap bitMap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double xFractal = (x - WIDTH/2) * 2.0/WIDTH;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            std::uint8_t colour = (std::uint8_t) (256 * (double) iterations/Mandelbrot::MAX_ITERATIONS);

            //enhance the colour
            colour = colour * colour * colour;

            bitMap.setPixel(x, y, 0, colour, 0);

            if (colour < min)
                min = colour;

            if (colour > max)
                max = colour;
        }
    }
    bitMap.write("../test.bmp");
    std::cout << "Minimum: " << min << " Maximum: " << max << "\n";
    std::cout << "Finished!\n";
    return 0;
}