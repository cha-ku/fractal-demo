//
// Created by cha-ku on 24/11/19.
//

#ifndef FRACTAL_DEMO_MANDELBROT_HPP
#define FRACTAL_DEMO_MANDELBROT_HPP


class Mandelbrot
{
public:
    static const int MAX_ITERATIONS = 1000;
    Mandelbrot() {};
    virtual ~Mandelbrot() {};
    static int getIterations(double x, double y);
};

#endif //FRACTAL_DEMO_MANDELBROT_HPP
