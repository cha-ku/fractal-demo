#include "zoomlist.hpp"

void ZoomList::add(const Zoom &zoom)
{
    zoom_storage.push_back(zoom);

    m_xCenter += (zoom.m_x - m_width/2) * m_scale;
    m_yCenter += (zoom.m_y - m_height/2) * m_scale;
    m_scale *= zoom.m_scale;
}

std::pair<double, double> ZoomList::doZoom(int x, int y)
{
    double xFractal = (x - m_width/2) * m_scale + m_xCenter;
    double yFractal = (y - m_height/2) * m_scale + m_yCenter;
    return std::pair<double, double>(xFractal, yFractal);
}
