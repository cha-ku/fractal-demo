#ifndef ZOOMLIST_HPP
#define ZOOMLIST_HPP

#include <vector>
#include "zoom.hpp"

class ZoomList
{
public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);

private:
    int m_width{0};
    int m_height{0};
    double m_xCenter{0.0};
    double m_yCenter{0.0};
    double m_scale{1.0};
    std::vector<Zoom> zoom_storage;
};

#endif // ZOOMLIST_HPP
