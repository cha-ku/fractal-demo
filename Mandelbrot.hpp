//
// Created by cha-ku on 24/11/19.
//

#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP


class Mandelbrot
{
public:
    static const int MAX_ITERATIONS{255};
    Mandelbrot() {}
    virtual ~Mandelbrot() {}
    static int getIterations(double x, double y);
};

#endif //MANDELBROT_HPP
