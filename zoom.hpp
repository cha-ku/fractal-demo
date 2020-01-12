#ifndef ZOOM_HPP
#define ZOOM_HPP


struct Zoom
{
    int m_x{0};
    int m_y{0};
    double m_scale{1.0};
    Zoom(int x, int y, double scale) : m_x(x), m_y(y), m_scale(scale) {}
};

#endif // ZOOM_H
