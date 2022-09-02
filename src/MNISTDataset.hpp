//
// Created by waford on 8/29/22.
//

#ifndef EIGEN_TEST_MNISTDATASET_HPP
#define EIGEN_TEST_MNISTDATASET_HPP

#include <vector>
#include <string>
#include <fstream>

#include "MNISTImage.hpp"

class MNISTDataset {
    public:
        MNISTDataset(std::string datasetName);
        void parseData();
    private:
        inline static const std::string kDatasetDirectory = "data";
        static const int kImageMagicNumber = 2051;
        static const int kLabelMagicNumber = 2049; 
        std::string datasetName;
        std::string directoryPath;
        std::ifstream image_stream;
        std::ifstream label_stream;
        std::vector<MNISTImage> MNISTImages;

        void init();
        void parseImageStream();
        void readBigEndianStream(std::ifstream &stream, int32_t * data, size_t num_ints);
        inline void swapEndiness(int32_t & value) { 
            int leftmost = (value & 0x000000FF) << 3*8;
            int leftmiddle = (value & 0x0000FF00) << 1*8;
            int rightmiddle = (value & 0x00FF0000) >> 1*8;
            int rightmost = (value & 0xFF000000) >> 3*8; 
            value =  (leftmost | leftmiddle | rightmiddle | rightmost);
        }
};

#endif //EIGEN_TEST_MNISTDATASET_HPP
