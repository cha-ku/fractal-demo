//
// Created by cha-ku on 18/11/19.
//

#include "BitMap.hpp"
#include "BitMapFileHeader.hpp"
#include "BitMapInfoHeader.hpp"
#include <fstream>

BitMap::BitMap(int width, int height): m_width(width), m_height(height), m_pPixels(new std::uint8_t[width * height * 3]) {}

BitMap::~BitMap() {}

bool BitMap::write(const std::string& filename)
{
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + m_width * m_height * 3;
    fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    std::fstream file;

    file.open(filename, std::ios::out | std::ios::binary);

    if(!file)
    {
        return false;
    }

    file.write((char *)&fileHeader , sizeof(fileHeader));
    file.write((char *)&infoHeader , sizeof(infoHeader));
    file.write((char *)m_pPixels.get() , m_width * m_height * 3); //get() gives the raw pointer under the unique_ptr

    file.close();

    return true;
}

void BitMap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
{
    std::uint8_t *pPixel = m_pPixels.get();

    pPixel += (y * 3) * m_width + (x * 3);

    // Since BMP is little-endian: int 1234 will be stored as 4321
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;

}
