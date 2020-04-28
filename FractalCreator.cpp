#include <numeric>
#include "FractalCreator.hpp"

FractalCreator::FractalCreator(int width, int height) : m_width(width), m_height(height),
  m_histogram(Mandelbrot::MAX_ITERATIONS, 0),
  m_iterationCounter(m_width, std::vector<int>(m_height, 0)),
  m_zoomList(width, height),
  m_bitmap(width, height)
{
  m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
}

void FractalCreator::addZoom(const Zoom& zoom)
{
  m_zoomList.add(zoom);
}

void FractalCreator::calculateIterations()
{
    for (int x = 0; x < m_width; x++)
    {
#pragma omp parallel for
        for (int y = 0; y < m_height; y++)
        {
            std::pair<double, double> coords = m_zoomList.doZoom(x, y);
            //First Pass
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            //Second Pass - part I
            m_iterationCounter[x][y] = iterations;
            //Second Pass - part II
            // iterations always [1, MAX_ITERATIONS]
            m_histogram[iterations]++;
        }
    }

}

void FractalCreator::drawFractal()
{
    int total = std::accumulate(m_histogram.begin(), m_histogram.end(), 0);

    for (int x = 0; x < m_width; x++)
    {
#pragma omp parallel for
        for (int y = 0; y < m_height; y++)
        {
            std::uint8_t red = 0;
            std::uint8_t green = 0;
            std::uint8_t blue = 0;

            int iterationsPerPixel = m_iterationCounter[x][y];
            if (iterationsPerPixel != Mandelbrot::MAX_ITERATIONS)
            {
                if (iterationsPerPixel > 0 && iterationsPerPixel < Mandelbrot::MAX_ITERATIONS/3)
                {
                    double hue = 0.0;
                    for (int i = 0; i <= iterationsPerPixel; i++)
                    {
                        hue += ((double) m_histogram[i]) / total;
                    }
                    blue = 255 * hue;
                }

                if ((iterationsPerPixel >= Mandelbrot::MAX_ITERATIONS/3) && (iterationsPerPixel <= 2 * Mandelbrot::MAX_ITERATIONS/3))
                {
                    double hue = 0.0;
                    for (int i = 0; i <= iterationsPerPixel; i++)
                    {
                        hue += ((double) m_histogram[i]) / total;
                    }
                    green = 255 * hue;
                }

                if (iterationsPerPixel > 2 * Mandelbrot::MAX_ITERATIONS/2)
                {
                    double hue = 0.0;
                    for (int i = 0; i <= iterationsPerPixel; i++)
                    {
                        hue += ((double) m_histogram[i]) / total;
                    }
                    red = 255 * hue;
                }
            }
            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::writeBitMap(std::string filename)
{
    if (!m_bitmap.write(filename))
        std::cerr << "Error writing to " << filename << "\n";
}
