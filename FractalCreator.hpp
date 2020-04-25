#ifndef FRACTALCREATOR_HPP
#define FRACTALCREATOR_HPP

#include "BitMap.hpp"
#include "Mandelbrot.hpp"
#include "zoomlist.hpp"
#include "zoom.hpp"
#include <string>
#include <vector>
#include <iostream>

class FractalCreator
{
private:
    int m_width;
    int m_height;
    std::vector<int> m_histogram;
    std::vector<std::vector<int>> m_iterationCounter;
    ZoomList m_zoomList;
    BitMap m_bitmap;

public:
    FractalCreator(int width, int height);
    void calculateIterations();
    void drawFractal();
    void addZoom(const Zoom&  zoom);
    void writeBitMap(std::string filename);
};

#endif // FRACTALCREATOR_HPP
