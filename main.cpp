#include <iostream>
#include "BitMap.hpp"
#include "Mandelbrot.hpp"
#include "zoomlist.hpp"
#include <vector>
#include <math.h>

int main()
{
    const int HEIGHT = 600;
    const int WIDTH = 800;

    BitMap bitMap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    std::vector<int> histogram (Mandelbrot::MAX_ITERATIONS, 0);
    std::vector<std::vector<int>> iterationCounter;
    iterationCounter.resize(WIDTH, std::vector<int> (HEIGHT, 0));

    ZoomList myZoomList(WIDTH, HEIGHT);
    myZoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    myZoomList.add(Zoom(265, 214, 4.0/WIDTH));

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            std::pair<double, double> coords = myZoomList.doZoom(x, y);
            //First Pass
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            //Second Pass - part I
            iterationCounter[x][y] = iterations;
            //Second Pass - part II
            // iterations always [1, MAX_ITERATIONS]
            histogram[iterations]++;
        }
    }

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        total += histogram[i];

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            std::uint8_t red = 0;
            std::uint8_t green = 0;
            std::uint8_t blue = 0;

            int iterationsPerPixel = iterationCounter[x][y];
            if (iterationsPerPixel != Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;
                for (int i = 0; i <= iterationsPerPixel; i++)
                    hue += ((double) histogram[i]) / total;
                green = pow(255, hue);
            }
            bitMap.setPixel(x, y, red, green, blue);

        }
    }
    bitMap.write("../test.bmp");
    std::cout << "Finished!\n";
    return 0;
}
