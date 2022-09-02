#include "MNISTImage.hpp"

#include <stdio.h>
#include <iostream>
#include <EasyBMP.hpp>

void MNISTImage::drawImage(std::string filename) { 
    EasyBMP::Image img(kImageSize, kImageSize, filename);
    for(int row = 0; row < kImageSize; row++) {
        for(int col = 0; col < kImageSize; col++) {
            uint8_t pixel_value = 255 - (*this)(row, col);
            img.SetPixel(col, row, EasyBMP::RGBColor(pixel_value, pixel_value, pixel_value));
        }
    }
    img.Write();
}

