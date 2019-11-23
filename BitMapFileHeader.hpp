//
// Created by cha-ku on 18/11/19.
//

#ifndef FRACTAL_DEMO_BITMAPFILEHEADER_HPP
#define FRACTAL_DEMO_BITMAPFILEHEADER_HPP

#include <cstdint>

#pragma pack(push, 1)
struct BitMapFileHeader
{
    std::uint16_t header{0x4D42};
    std::int32_t fileSize;
    std::int16_t reserved1{0};
    std::int16_t reserved2{0};
    std::int32_t dataOffset;
};
#pragma pack(pop)
#endif //FRACTAL_DEMO_BITMAPFILEHEADER_HPP
