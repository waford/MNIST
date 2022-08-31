//
// Created by waford on 8/29/22.
//

#ifndef EIGEN_TEST_MNISTDATASET_HPP
#define EIGEN_TEST_MNISTDATASET_HPP

#include <vector>
#include <string>
#include "MNISTImage.hpp"

class MNISTDataset {
    public:
        MNISTDataset(std::string name, std::string image_url, std::string label_url);
    private:
        inline static const std::string kDatasetDirectory = "datasets";
        std::vector<MNISTImage> MNISTImages;

        static void touchDatasetDirectory(std::string name);
};

#endif //EIGEN_TEST_MNISTDATASET_HPP
