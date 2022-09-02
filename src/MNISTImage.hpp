//
// Created by waford on 8/29/22.
//

#ifndef EIGEN_TEST_MNISTIMAGE_HPP
#define EIGEN_TEST_MNISTIMAGE_HPP

#include <cstdint>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

class MNISTImage {
    public:
        MNISTImage(uint8_t label, uint8_t* pixels) {
            label_ = label;
            memcpy(pixels_, pixels, kImageSize*kImageSize);
        }

        uint8_t operator() (size_t row, size_t col) {
            return pixels_[kImageSize * row + col];
        }
        void drawImage(std::string filename);

        uint8_t label() {return label_;}

    private:
        static const std::size_t kImageSize = 28;
        uint8_t label_;
        uint8_t pixels_[kImageSize * kImageSize];
};


#endif //EIGEN_TEST_MNISTIMAGE_HPP
