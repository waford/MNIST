//
// Created by waford on 8/29/22.
//

#ifndef EIGEN_TEST_MNISTIMAGE_HPP
#define EIGEN_TEST_MNISTIMAGE_HPP

#include <cstdint>
#include <cstring>

class MNISTImage {
    public:
        MNISTImage(uint8_t label, uint32_t* pixels) {
            label_ = label;
            memcpy(pixels_, pixels, image_size*image_size);
        }

    private:
        const std::size_t image_size = 28;
        uint8_t label_;
        uint32_t* pixels_;
};


#endif //EIGEN_TEST_MNISTIMAGE_HPP
