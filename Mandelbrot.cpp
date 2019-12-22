//
// Created by cha-ku on 24/11/19.
//

#include <complex>
#include "Mandelbrot.hpp"

int Mandelbrot::getIterations(double x, double y)
{
    std::complex<double> z = 0;
    std::complex<double> c(x, y);

    int iterations = 0;

    while ( iterations < MAX_ITERATIONS )
    {
        z = z * z + c;
        if (abs(z) > 2)
            break;
        iterations++;
    }

    return iterations;
}