//
// Created by cha-ku on 18/11/19.
//

#ifndef FRACTAL_DEMO_BITMAPINFOHEADER_HPP
#define FRACTAL_DEMO_BITMAPINFOHEADER_HPP

#include <cstdint>

#pragma pack(push, 1)

struct BitMapInfoHeader
{
    std::int32_t headerSize{40};
    std::int32_t width;
    std::int32_t height;
    std::int16_t planes{1};
    std::int16_t bitsPerPixel{24};
    std::int32_t compression{0};
    std::int32_t dataSize{0};
    std::int32_t horizontalResolution{2400};
    std::int32_t verticalResolution{2400};
    std::int32_t colours{0};
    std::int32_t importantColours{0};
};

#pragma pack(pop)
#endif //FRACTAL_DEMO_BITMAPINFOHEADER_HPP
