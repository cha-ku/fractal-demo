//
// Created by cha-ku on 18/11/19.
//

#ifndef FRACTAL_DEMO_BITMAPFILEHEADER_HPP
#define FRACTAL_DEMO_BITMAPFILEHEADER_HPP

#pragma pack(2)

#include <cstdint>

struct BitMapFileHeader
{
    char header[2]{'B' , 'M'};
    std::int32_t fileSize;
    std::int32_t reserved{0};
    std::int32_t dataOffset;
};


#endif //FRACTAL_DEMO_BITMAPFILEHEADER_HPP
