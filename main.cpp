#include <iostream>
#include "BitMap.hpp"

int main() {
    BitMap bitMap(800, 600);
    bitMap.write("../test.bmp");
    std::cout << "Finished!\n";
    return 0;
}