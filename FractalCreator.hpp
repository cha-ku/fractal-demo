#ifndef FRACTALCREATOR_HPP
#define FRACTALCREATOR_HPP

#include "zoom.hpp"
#include <string>

class FractalCreator
{
public:
  FractalCreator(int width, int height);
  void calculateIterations();
  void drawFractal();
  void addZoom(const Zoom&  zoom);
  void writeBitMap(std::string filename);
};

#endif // FRACTALCREATOR_HPP
