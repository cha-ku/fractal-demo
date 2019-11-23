//
// Created by cha-ku on 18/11/19.
//

#ifndef FRACTAL_DEMO_BITMAP_HPP
#define FRACTAL_DEMO_BITMAP_HPP

#include <string>
#include <cstdint>
#include <memory>

class BitMap
{
public:
    BitMap(int width, int height);
    bool write(const std::string& filename);
    void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
    virtual ~BitMap();

private:
    int m_width{0};
    int m_height{0};
    std::unique_ptr<std::uint8_t[]> m_pPixels{nullptr};
};

#endif //FRACTAL_DEMO_BITMAP_HPP
